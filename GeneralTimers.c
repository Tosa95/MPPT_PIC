#include <xc.h>
#include "GeneralTimers.h"
#include "ClockControl.h"
#include "addressableBits.h"

#define TIMER_SIZE 65536

#define NS_CALC_LIMIT 1000

typedef struct tagTCONBITS {
    union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned :2;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :6;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
    };
    };
} TCONBITS;

typedef volatile unsigned int  PR_t;
typedef volatile unsigned int  TMR_t;

static TCONBITS *cons [4] = {(TCONBITS*)&T2CONbits, (TCONBITS*)&T3CONbits, (TCONBITS*)&T4CONbits, (TCONBITS*)&T5CONbits};
static PR_t *prs [4] = {(PR_t*)&PR2, (PR_t*)&PR3, (PR_t*)&PR4, (PR_t*)&PR5};
static TMR_t *tmrs [4] = {(TMR_t*)&TMR2,(TMR_t*)&TMR3,(TMR_t*)&TMR4,(TMR_t*)&TMR5};
static int modes [3][2] = {{0, 0}, {0, 1}, {1, 0}};
static addressableBit ifs[4] = {{&IFS0, 7, 7}, {&IFS0, 8, 8}, {&IFS1, 11, 11}, {&IFS1, 12, 12}};
static addressableBit iec[4] = {{&IEC0, 7, 7}, {&IEC0, 8, 8}, {&IEC1, 11, 11}, {&IEC1, 12, 12}};
static addressableBit ipc[4] = {{&IPC1, 12, 14}, {&IPC2, 0, 2}, {&IPC6, 12, 14}, {&IPC7, 0, 2}};
static tmrClbk_t clbks[4] = {0, 0, 0, 0};

static const int prescaler [4] = {1, 8, 64, 256};

/*
 * Imposta il comportamento del timer in fase di idle
 */
void setTimerIdleBehaviour (timerID_t id, timerIdleBehaviour_t idl);

/*
 * Imposta la modalità
 */
void setTimerMode (timerID_t id, timerMode_t m);

/*
 * Imposta il registro di periodo
 */
void setTimerPeriod(timerID_t id, long int pr);

/*
 * Imposta il prescaler
 */
void setTimerPrescaler (timerID_t id, int prescaler);

/*
 * Controlla se l'intervallo è sufficiente per conteggiare il tempo indicato
 */
int checkTimerInterval (timerID_t id, timeUS_t t);

/*
 * Inizializza il timer
 */
void initTimer (timerID_t id, timerMode_t m, timerIdleBehaviour_t idl)
{
    setTimerEnabled (id, TIMER_OFF);

    setTimerMode (id, m);
    setTimerIdleBehaviour(id, idl);
}

/*
 * Imposta il periodo di conteggio del timer
 */
timeUS_t setTimerInterval  (timerID_t id, timeUS_t t)
{
long int actStep, requestedSteps;

    setTimerEnabled(id, TIMER_OFF);

    int i;

    if (t > NS_CALC_LIMIT)
    {
        for (i = 0; i < 4; i++)
        {
            setTimerPrescaler (id, i);

            if (checkTimerInterval(id, t))
            {

                requestedSteps = getRequestedSteps(id, t);
                resetTimer(id);
                setTimerPeriod(id, requestedSteps-1);

                actStep = getTimerStep(id)/1000;

                return actStep * requestedSteps;
            }
        }


        setTimerPrescaler (id, 3);

        actStep = getTimerStep(id)/1000;

        setTimerPeriod(id, TIMER_SIZE - 1);
        resetTimer(id);

        return TIMER_SIZE * actStep;
    }
    else
    {
        t *= 1000;
        for (i = 0; i < 4; i++)
        {
            setTimerPrescaler (id, i);

            if (checkTimerIntervalNS(id, t))
            {

                requestedSteps = getRequestedStepsNS(id, t);
                resetTimer(id);
                setTimerPeriod(id, requestedSteps-1);

                actStep = getTimerStep(id)/1000;

                return actStep * requestedSteps;
            }
        }


        setTimerPrescaler (id, 3);

        actStep = getTimerStep(id)/1000;

        setTimerPeriod(id, TIMER_SIZE - 1);
        resetTimer(id);

        return TIMER_SIZE * actStep;
    }
}

/*
 * Ritorna il periodo di conteggio del timer
 */
timeUS_t getTimerInterval (timerID_t id)
{
    timeUS_t step = getTimerStep(id)/1000;
    int pr = *prs[id];

    if (step != 0)
    {
        timeUS_t res = pr * step;
        return res;
    }
    else
    {
        timeNS_t stepNS = getTimerStep(id);
        timeUS_t res = (pr * stepNS)/1000;
        return res;
    }

}

/*
 * Ritorna la frequenza di incremento del timer, non l'intervallo di completamento
 * del conteggio
 */
freqHZ_t getTimerFreq (timerID_t id)
{
    long int ris;

    ris = getClockFreq() / (2 * prescaler [cons[id]->TCKPS]);

    return ris;
}

/*
 * Ritorna il periodo di incremento del timer, non il tempo di completamento
 * del conteggio
 */
timeNS_t getTimerStep (timerID_t id)
{
    return SECOND_NS/getTimerFreq(id);
}

/*
 * Imposta il prescaler
 */
void setTimerPrescaler (timerID_t id, int prescaler)
{
    cons[id]->TCKPS = prescaler;
}

/*
 * Controlla se l'intervallo è sufficiente per conteggiare il tempo indicato
 */
int checkTimerInterval (timerID_t id, timeUS_t t)
{
long int requestedSteps;
timeUS_t actStep = getTimerStep(id)/1000;

    if (actStep != 0)
    {
        requestedSteps = t / actStep;

        if (requestedSteps <= TIMER_SIZE)
            return 1;
    }
    return 0;
}

/*
 * Calcola il numero di conteggi necessari per avere l'intervallo richiesto
 */
long int getRequestedSteps (timerID_t id, timeUS_t t)
{
long int requestedSteps;

    if(t > NS_CALC_LIMIT)
    {
        requestedSteps = t / (getTimerStep(id)/1000);

        return requestedSteps;
    }
    else
    {
        return getRequestedStepsNS(id, t*1000);
    }
}

/*
 * Imposta a 0 il conteggio del timer
 */
void resetTimer (timerID_t id)
{
    *(tmrs[id]) = 0;
}

/*
 * Attiva/disattiva il timer
 */
void setTimerEnabled (timerID_t id, timerEnabled_t en)
{
    cons[id]->TON = en;
}

/*
 * Imposta il registro di periodo
 */
void setTimerPeriod(timerID_t id, long int pr)
{
    *(prs[id]) = pr;
}

/*
 * Imposta la modalità
 */
void setTimerMode (timerID_t id, timerMode_t m)
{
    cons[id]->TCS = modes[m][0];
    cons[id]->TGATE = modes[m][1];
}

/*
 * Imposta il comportamento del timer in fase di idle
 */
void setTimerIdleBehaviour (timerID_t id, timerIdleBehaviour_t idl)
{
    cons[id]->TSIDL = idl;
}

/*
 * Controlla se il timer è andato in overflow
 */
int timerCompleted (timerID_t id)
{
    return getBit(ifs[id]);
}

/*
 * Resetta il flag di overflow
 */
void resetTimerCompleted (timerID_t id)
{
    setBit(ifs[id], 0);
}

/*
 * Blocca l'esecuzione fino al termine del conteggio del timer
 */
void waitForTimerCompletion (timerID_t id)
{
    while (!timerCompleted(id));

    resetTimerCompleted(id);
}

/*
 * Calcola il numero di conteggi necessari per avere l'intervallo richiesto
 */
long int getRequestedStepsNS (timerID_t id, timeNS_t t)
{
long int requestedSteps;

    requestedSteps = t / (getTimerStep(id));

    return requestedSteps;
}

/*
 * Controlla se l'intervallo è sufficiente per conteggiare il tempo indicato
 */
int checkTimerIntervalNS (timerID_t id, timeNS_t t)
{
long int requestedSteps;
timeNS_t actStep = getTimerStep(id);

    if (actStep != 0)
    {
        requestedSteps = t / actStep;

        if (requestedSteps <= TIMER_SIZE)
            return 1;
    }
    return 0;
}

/*
 * Ritorna il tempo attuale di conteggio in US
 */
timeUS_t getTimerActTime (timerID_t id)
{
    return (*tmrs[id]) * (getTimerStep(id)/1000);
}

void __attribute__((__interrupt__, __auto_psv__)) _T2Interrupt ()
{
    if (clbks[0] != 0)
        clbks[0]();

    setBit(ifs[0], 0);
}

void __attribute__((__interrupt__, __auto_psv__)) _T3Interrupt ()
{
    if (clbks[1] != 0)
        clbks[1]();

    setBit(ifs[1], 0);
}

void __attribute__((__interrupt__, __auto_psv__)) _T4Interrupt ()
{
    if (clbks[2] != 0)
        clbks[2]();

    setBit(ifs[2], 0);
}

void __attribute__((__interrupt__, __auto_psv__)) _T5Interrupt ()
{
    if (clbks[3] != 0)
        clbks[3]();

    setBit(ifs[3], 0);
}

void enableTimerInterrupt (timerID_t id,int priority, tmrClbk_t clbk)
{
    setBit(ipc[id], priority);
    setBit(iec[id], 1);
    clbks[id] = clbk;
}

void disableTimerInterrupt (timerID_t id)
{
    setBit(ipc[id], 0);
    setBit(iec[id], 0);
    clbks[id] = 0;
}
