#include <xc.h>
#include <stdlib.h>

#include "clockControl.h"

#include "basicTimersControl.h"

#include "addressableBits.h"

#include "timersCommonTypes.h"
#include "timerStruct.h"

#include "timers.h"

#define TIMER_SIZE 65536

#define MIN_PRESCALER 0
#define MAX_PRESCALER 3

    typedef struct
    {
        addressableBit TON;
        addressableBit TSIDL;
        addressableBit TGATE;
        addressableBit TCKPS;
        addressableBit TCS;

        volatile unsigned int *TMR;
        volatile unsigned int *PR;

        addressableBit IFSB;
        addressableBit IECB;
        addressableBit IPCB;

    }basicAdditionalData;

    static const int prescaler [4] = {1, 8, 64, 256};

    //Funzioni private
    
    static unsigned long int tryBasicTimerPrescalerUS (timer tmr, int prsc, long int interval);
    static unsigned long int tryBasicTimerPrescalerNS (timer tmr, int prsc, long int interval);

    static unsigned long int getBasicTimerStepUS (timer tmr);
    static unsigned long int getBasicTimerStepNS (timer tmr);

    static timerPrescaler getBasicTimerPrescaler (timer tmr);
    
    void setBasicTimerPrescaler (timer tmr, timerPrescaler prsc);
    
    basicAdditionalData *getBad (timerID id);
    
    //Aggiunta timer di base alla libreria

    basicAdditionalData * getBad (timerID id)
    {
    basicAdditionalData *ris;

        ris = (basicAdditionalData *)malloc (sizeof(basicAdditionalData));

        switch (id)
        {
            case TIMER1_ID:

                ris->TON = getAddressableBit (&T1CON, 15, 15);
                ris->TSIDL = getAddressableBit (&T1CON, 13, 13);
                ris->TGATE = getAddressableBit (&T1CON, 6, 6);
                ris->TCKPS = getAddressableBit (&T1CON, 4, 5);
                ris->TCS = getAddressableBit (&T1CON, 1, 1);

                ris->TMR = &TMR1;
                ris->PR = &PR1;

                ris->IFSB = getAddressableBit (&IFS0, 3, 3);
                ris->IECB = getAddressableBit (&IEC0, 3, 3);
                ris->IPCB = getAddressableBit (&IPC0, 12, 14);

                break;

             case TIMER2_ID:

                ris->TON = getAddressableBit (&T2CON, 15, 15);
                ris->TSIDL = getAddressableBit (&T2CON, 13, 13);
                ris->TGATE = getAddressableBit (&T2CON, 6, 6);
                ris->TCKPS = getAddressableBit (&T2CON, 4, 5);
                ris->TCS = getAddressableBit (&T2CON, 1, 1);

                ris->TMR = &TMR2;
                ris->PR = &PR2;

                ris->IFSB = getAddressableBit (&IFS0, 7, 7);
                ris->IECB = getAddressableBit (&IEC0, 7, 7);
                ris->IPCB = getAddressableBit (&IPC1, 12, 14);

                break;

            case TIMER3_ID:

                ris->TON = getAddressableBit (&T3CON, 15, 15);
                ris->TSIDL = getAddressableBit (&T3CON, 13, 13);
                ris->TGATE = getAddressableBit (&T3CON, 6, 6);
                ris->TCKPS = getAddressableBit (&T3CON, 4, 5);
                ris->TCS = getAddressableBit (&T3CON, 1, 1);

                ris->TMR = &TMR3;
                ris->PR = &PR3;

                ris->IFSB = getAddressableBit (&IFS0, 8, 8);
                ris->IECB = getAddressableBit (&IEC0, 8, 8);
                ris->IPCB = getAddressableBit (&IPC2, 0, 2);

                break;

            case TIMER4_ID:

                ris->TON = getAddressableBit (&T4CON, 15, 15);
                ris->TSIDL = getAddressableBit (&T4CON, 13, 13);
                ris->TGATE = getAddressableBit (&T4CON, 6, 6);
                ris->TCKPS = getAddressableBit (&T4CON, 4, 5);
                ris->TCS = getAddressableBit (&T4CON, 1, 1);

                ris->TMR = &TMR4;
                ris->PR = &PR4;

                ris->IFSB = getAddressableBit (&IFS1, 11, 11);
                ris->IECB = getAddressableBit (&IEC1, 11, 11);
                ris->IPCB = getAddressableBit (&IPC6, 12, 14);

                break;

            case TIMER5_ID:

                ris->TON = getAddressableBit (&T5CON, 15, 15);
                ris->TSIDL = getAddressableBit (&T5CON, 13, 13);
                ris->TGATE = getAddressableBit (&T5CON, 6, 6);
                ris->TCKPS = getAddressableBit (&T5CON, 4, 5);
                ris->TCS = getAddressableBit (&T5CON, 1, 1);

                ris->TMR = &TMR5;
                ris->PR = &PR5;

                ris->IFSB = getAddressableBit (&IFS1, 12, 12);
                ris->IECB = getAddressableBit (&IEC1, 12, 12);
                ris->IPCB = getAddressableBit (&IPC7, 0, 2);

                break;

            default:

                ris->TON = getAddressableBit (NULL, 0, 0);
                ris->TSIDL = getAddressableBit (NULL, 0, 0);
                ris->TGATE = getAddressableBit (NULL, 0, 0);
                ris->TCKPS = getAddressableBit (NULL, 0, 0);
                ris->TCS = getAddressableBit (NULL, 0, 0);

                ris->TMR = NULL;
                ris->PR = NULL;

                ris->IFSB = getAddressableBit (NULL, 0, 0);
                ris->IECB = getAddressableBit (NULL, 0, 0);
                ris->IPCB = getAddressableBit (NULL, 0, 0);

                break;
        }

        return ris;
    }

    /*
     * Aggiunge tutti i timer di base disponibili alla libreria
     */
    void addBasicTimers ()
    {
    struct _timer actTmr;

    int i;

        for (i = 0; i < 5; i++)
        {
            actTmr.id = (timerID)i;

            actTmr.additionalData = getBad (i);

            actTmr.init = initBasicTimer;

            actTmr.setState = setBasicTimerState;
            actTmr.setGate = setBasicTimerGate;
            actTmr.setMode = setBasicTimerMode;
            actTmr.setInterruptState = setBasicTimerInterruptState;
            actTmr.setIntervalNS = setBasicTimerIntervalNS;
            actTmr.setIntervalUS = setBasicTimerIntervalUS;
            actTmr.setLimit = setBasicTimerLimit;
            actTmr.setPrescaler = setBasicTimerPrescaler;

            actTmr.getElaspedTimeNS = getBasicTimerElaspedTimeNS;
            actTmr.getElaspedTimeUS = getBasicTimerElaspedTimeUS;
            actTmr.getFreq = getBasicTimerFreq;
            actTmr.getCount = getBasicTimerCount;

            actTmr.waitForEnd = basicTimerWaitForEnd;
            actTmr.delayNS = basicTimerDelayNS;
            actTmr.delayUS = basicTimerDelayUS;
            actTmr.reset = resetBasicTimer;

            addTimer(&actTmr);
        }

    }

    //Inizializzazione

    /*
     * Inizializza il timer
     *
     * input:
     *  - tmr: il timer utilizzato
     */
    void initBasicTimer (timer tmr)
    {

    }

    //Metodi di impostazione

    /*
     * Accende/Spegne il timer
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - stt: lo stato voluo (acceso/spento)
     */
    void setBasicTimerState (timer tmr, timerState stt)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;

        setBit(dt->TON, stt);
    }

    /*
     * Decide se utilizzare o meno il gate
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - gt: stato del gate (usato o no)
     */
    void setBasicTimerGate (timer tmr, timerGate gt)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;

        setBit(dt->TGATE, gt);
    }

    /*
     * Decide la modalità del timer (timer/contatore)
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - md: modalità da utilizzare (timer/contatore)
     */
    void setBasicTimerMode (timer tmr, timerMode md)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;

        setBit (dt->TCS, md);
    }

    /*
     * Decide se attivare o meno l'interrupt per il timer
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - is: stato dell'interrupt (attivato/disattivato)
     */
    void setBasicTimerInterruptState (timer tmr, timerInterruptState is, int interruptPriority)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;
        
        setBit (dt->IECB, is); 
        setBit (dt->IPCB, interruptPriority);
    }

    /*
     * Imposta l'intervallo per il timer selezionato (nS)
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - interval: intervallo desiderato (nS)
     *
     * output:
     *  - l'intervallo realmente ottenuto (nS)
     */
    timerNS setBasicTimerIntervalNS (timer tmr, timerNS interval)
    {
    basicAdditionalData *dt;
    long int actStep, requestedSteps, ris;

        dt = (basicAdditionalData *) tmr->additionalData;

        if ((ris = tryBasicTimerPrescalerNS (tmr, getBasicTimerPrescaler(tmr), interval)) >= 0)
        {
            return ris;
        }
        else
        {
            if ((ris = tryBasicTimerPrescalerNS (tmr, getBasicTimerPrescaler(tmr), interval)) >= 0)
            {
                return ris;
            }

        }

        setBasicTimerPrescaler (tmr, 3);

        actStep = getBasicTimerStepNS (tmr);

        setBasicTimerLimit(tmr, TIMER_SIZE - 1);

        if (*dt->TMR > TIMER_SIZE - 1) *dt->TMR = TIMER_SIZE - 1;

        return TIMER_SIZE * actStep;
    }

    /*
     * Imposta l'intervallo per il timer selezionato (uS)
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - interval: intervallo desiderato (uS)
     *
     * output:
     *  - l'intervallo realmente ottenuto (uS)
     */
    timerUS setBasicTimerIntervalUS (timer tmr, timerUS interval)
    {
    basicAdditionalData *dt;
    long int actStep, requestedSteps, ris;

        dt = (basicAdditionalData *) tmr->additionalData;

        if ((ris = tryBasicTimerPrescalerUS (tmr, getBasicTimerPrescaler(tmr), interval)) >= 0)
        {
            return ris;
        }
        else
        {
            if ((ris = tryBasicTimerPrescalerUS (tmr, getBasicTimerPrescaler(tmr), interval)) >= 0)
            {
                return ris;
            }

        }

        setBasicTimerPrescaler (tmr, 3);

        actStep = getBasicTimerStepUS (tmr);

        setBasicTimerLimit(tmr, TIMER_SIZE - 1);
        
        if (*dt->TMR > TIMER_SIZE - 1) *dt->TMR = TIMER_SIZE - 1;

        return TIMER_SIZE * actStep;
    }

    /*
     * Imposta il limite al conteggio del timer. Quando esso raggiungerà tale valore
     * verrà scatenato un interrupt (se abilitato) e il timer verrà resettato
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - lim: il limite al conteggio
     */
    void setBasicTimerLimit (timer tmr, timerLimit lim)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;
        
        *dt->PR = lim;
    }

    /*
     * Imposta il prescaler del timer
     * 
     * input:
     *  - tmr: il timer utilizzato
     *  - prsc: il prescaler desiderato
     */
    void setBasicTimerPrescaler (timer tmr, timerPrescaler prsc)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;

        if (prsc < MIN_PRESCALER) prsc = MIN_PRESCALER;
        if (prsc > MAX_PRESCALER) prsc = MAX_PRESCALER;

        if (getBit(dt->TCKPS) != prsc)
            setBit(dt->TCKPS, prsc);
    }
    
    //Metodi di osservazione

    /*
     * Ritorna il tempo trascorso dall'avvio del timer  (nS)
     *
     * input:
     *  - tmr: il timer utilizzato
     *
     * output:
     *  - tempo trascorso dall'avvio del timer (nS)
     */
    timerNS getBasicTimerElaspedTimeNS (timer tmr)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;

        return (unsigned int)*dt->TMR * getBasicTimerStepNS (tmr);
    }

    /*
     * Ritorna il tempo trascorso dall'avvio del timer  (uS)
     *
     * input:
     *  - tmr: il timer utilizzato
     *
     * output:
     *  - tempo trascorso dall'avvio del timer (uS)
     */
    timerUS getBasicTimerElaspedTimeUS (timer tmr)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;

        return *dt->TMR * getBasicTimerStepUS (tmr);
    }

    /*
     * Ritorna l'attuale frequenza di lavoro del timer
     *
     * input:
     *  - tmr: il timer utilizzato
     *
     * output:
     *  - la frequenza attuale del timer (Hz)
     */
    timerHZ getBasicTimerFreq (timer tmr)
    {
    basicAdditionalData *dt;    
    long int ris;

        dt = (basicAdditionalData *) tmr->additionalData;
        ris = getClockFreq() / (2 * prescaler [getBit(dt->TCKPS)]);

        return ris;    
    }

    /*
     * Ritorna l'attuale conteggio del timer
     * 
     * input:
     *  - tmr: il timer utilizzato
     * 
     * output:
     *  - conteggio attuale del timer
     */
    timerCount getBasicTimerCount (timer tmr)
    {
        return *((basicAdditionalData *)tmr->additionalData)->TMR;
    }
    
    //Metodi di utilità

    /*
     * Attende il termine del conteggio
     *
     * input:
     *  - tmr: il timer utilizzato
     */
    void basicTimerWaitForEnd (timer tmr)
    {
    basicAdditionalData *dt;
    int wasInterruptEnabled;

        dt = (basicAdditionalData *) tmr->additionalData;

        wasInterruptEnabled = getBit(dt->IECB);
        if(wasInterruptEnabled) setBit (dt->IECB, 0);

        while (getBit(dt->IFSB) == 0);
        
        setBit(dt->IFSB, 0);

        if(wasInterruptEnabled) setBit (dt->IECB, 1);
    }

    /*
     * Blocca il conteggio per il numero di nS desiderato
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - interval: il tempo da aspettare (nS)
     */
    void basicTimerDelayNS (timer tmr, timerNS interval)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;

        setBasicTimerIntervalNS (tmr, interval);

        resetBasicTimer(tmr);

        basicTimerWaitForEnd(tmr);
    }

    /*
     * Blocca il conteggio per il numero di uS desiderato
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - interval: il tempo da aspettare (uS)
     */
    void basicTimerDelayUS (timer tmr, timerUS interval)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;

        setBasicTimerIntervalUS (tmr, interval);

        resetBasicTimer(tmr);

        basicTimerWaitForEnd(tmr);
    }

    /*
     * Pone a 0 il conteggio del timer
     *
     * input:
     *  - tmr: il timer utilizzato
     */
    void resetBasicTimer (timer tmr)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;

        *dt->TMR = 0;
    }
    
    static timerUS tryBasicTimerPrescalerUS (timer tmr, int prsc, long int interval)
    {
    basicAdditionalData *dt;   
    long int actStep, requestedSteps;

        dt = (basicAdditionalData *) tmr->additionalData;

        if (getBasicTimerPrescaler(tmr) != prsc) setBasicTimerPrescaler(tmr, prsc);

        actStep = getBasicTimerStepUS(tmr);

        if (actStep != 0)
            requestedSteps = interval / actStep;

        if (requestedSteps <= TIMER_SIZE && actStep != 0)
        {
            if (*dt->TMR > requestedSteps - 1) *dt->TMR = requestedSteps - 1;
            *dt->PR = requestedSteps - 1;

            return actStep * requestedSteps;
        }
        else
        {
            return 0;
        }
    }

    static timerNS tryBasicTimerPrescalerNS (timer tmr, int prsc, long int interval)
    {
    basicAdditionalData *dt;
    long int actStep, requestedSteps;

        dt = (basicAdditionalData *) tmr->additionalData;

        if (getBasicTimerPrescaler(tmr) != prsc) setBasicTimerPrescaler(tmr, prsc);

        actStep = getBasicTimerStepNS(tmr);

        if (actStep != 0)
            requestedSteps = interval / actStep;

        if (requestedSteps <= TIMER_SIZE && actStep != 0)
        {
            if (*dt->TMR > requestedSteps - 1) *dt->TMR = requestedSteps - 1;
            *dt->PR = requestedSteps - 1;


            return actStep * requestedSteps;
        }
        else
        {
            return -1;
        }
    }

    static timerPrescaler getBasicTimerPrescaler (timer tmr)
    {
    basicAdditionalData *dt;

        dt = (basicAdditionalData *) tmr->additionalData;

        return getBit(dt->TCKPS);
    }

    static unsigned long int getBasicTimerStepUS (timer tmr)
    {
        return secondUS / getBasicTimerFreq(tmr);
    }

    static unsigned long int getBasicTimerStepNS (timer tmr)
    {
        return secondNS / getBasicTimerFreq(tmr);
    }