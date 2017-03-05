#include <xc.h>

#include <stdlib.h>
#include "ClockControl.h"
#include "timer3.h"

#define MIN_PRESCALER 0
#define MAX_PRESCALER 3

#define TIMER_SIZE 65536

#define SECOND_US 1000000
#define SECOND_NS 1000000000

static void (*tmr3Clbk)();

static const int prescaler [4] = {1, 8, 64, 256};

static long int tryTimer3Prescaler (int prsc, long int interval);
static long int tryTimer3PrescalerNS (int prsc, long int interval);

static long int getTimer3Step ();
static long int getTimer3StepNS ();

static int getTimer3Prescaler ();

//void __attribute__((__interrupt__, __auto_psv__))  _T3Interrupt (void)
//{
//    if (tmr3Clbk != NULL)
//    {
//        tmr3Clbk();
//    }
//
//    IFS0bits.T3IF = 0;
//}

void timer3Init ()
{
    T3CONbits.TON = 0;

    T3CONbits.TGATE = 0;
    T3CONbits.TCS = 0;
    T3CONbits.TCKPS = 0;

    tmr3Clbk = NULL;

    //IEC0bits.T3IE = 0;

    IPC2bits.T3IP = 3;
}

void setTimer3Prescaler (char prsc)
{

    if (prsc < MIN_PRESCALER) prsc = MIN_PRESCALER;
    if (prsc > MAX_PRESCALER) prsc = MAX_PRESCALER;

    if (T3CONbits.TCKPS != prsc)
        T3CONbits.TCKPS = prsc;

}

long int setTimer3IntervalNS (long int nS)
{
long int actStep, requestedSteps, ris;

    //T2CONbits.TON = 0;

    if ((ris = tryTimer3PrescalerNS (getTimer3Prescaler(), nS)) >= 0)
    {
        return ris;
    }
    else
    {
    int i;

        if ((ris = tryTimer3PrescalerNS (getTimer3Prescaler(), nS)) >= 0)
        {
            return ris;
        }

    }

    setTimer3Prescaler (3);

    actStep = getTimer3StepNS();

    PR3 = TIMER_SIZE - 1;
    if (TMR3 > requestedSteps - 1) TMR3 = requestedSteps - 1;

    return TIMER_SIZE * actStep;
}

long int setTimer3Interval (long int uS)
{
long int actStep, requestedSteps, ris;

    //T2CONbits.TON = 0;

    if ((ris = tryTimer3Prescaler (getTimer3Prescaler(), uS)) >= 0)
    {
        return ris;
    }
    else
    {
    int i;

        if ((ris = tryTimer3Prescaler (getTimer3Prescaler(), uS)) >= 0)
        {
            return ris;
        }

    }

    setTimer3Prescaler (3);

    actStep = getTimer3Step();

    PR3 = TIMER_SIZE - 1;
    if (TMR3 > requestedSteps - 1) TMR3 = requestedSteps - 1;

    return TIMER_SIZE * actStep;
}

void timer3Delay (long int uS)
{
    setTimer3Interval (uS);

    IEC0bits.T3IE = 0;

    timer3Reset();
    timer3Start();

    while (IFS0bits.T3IF != 1);

    IFS0bits.T3IF = 0;

    timer3Stop();
    timer3Reset();

    IEC0bits.T3IE = 1;
}

inline long int getTimer3Freq ()
{
long int ris, freq, div;

    freq = getClockFreq();

    div = 2 * prescaler [T3CONbits.TCKPS];

    ris = freq / div;

    return ris;
}

inline void timer3Start ()
{
    T3CONbits.TON = 1;
}

inline void timer3Stop ()
{
    T3CONbits.TON = 0;
}

inline void timer3Reset ()
{
    TMR3 = 0;
}

inline long int getTimer3Count ()
{
    return TMR3;
}

void timer3WaitUntilEnd ()
{
    IEC0bits.T3IE = 0;

    while (IFS0bits.T3IF != 1);

    IFS0bits.T3IF = 0;

    IEC0bits.T3IE = 1;
}

void setTimer3Callback (void (*clbk)())
{
    tmr3Clbk = clbk;
}

long int timer3ElaspedTime ()
{
long int actStep = SECOND_US / getTimer3Freq();

    return actStep * TMR3;
}

long int timer3ElaspedTimeNS()
{
unsigned long int actStep = SECOND_NS / getTimer3Freq();

    return actStep * TMR3;
}

static long int tryTimer3Prescaler (int prsc, long int interval)
{
long int actStep, requestedSteps;

    if (getTimer3Prescaler() != prsc) setTimer3Prescaler(prsc);

    actStep = getTimer3Step();

    if (actStep != 0)
        requestedSteps = interval / actStep;

    if (requestedSteps <= TIMER_SIZE && actStep != 0)
    {
        if (TMR3 > requestedSteps - 1) TMR3 = requestedSteps - 1;
        PR3 = requestedSteps - 1;

        return actStep * requestedSteps;
    }
    else
    {
        return -1;
    }
}

static long int tryTimer3PrescalerNS (int prsc, long int interval)
{
long int actStep, requestedSteps;

    if (getTimer3Prescaler() != prsc) setTimer3Prescaler(prsc);

    actStep = getTimer3StepNS();

    if (actStep != 0)
        requestedSteps = interval / actStep;

    if (requestedSteps <= TIMER_SIZE && actStep != 0)
    {
        if (TMR3 > requestedSteps - 1) TMR3 = requestedSteps - 1;
        PR3 = requestedSteps - 1;

        return actStep * requestedSteps;
    }
    else
    {
        return -1;
    }
}

static int getTimer3Prescaler ()
{
    return T3CONbits.TCKPS;
}

static long int getTimer3Step ()
{
    return SECOND_US / getTimer3Freq();
}

static long int getTimer3StepNS ()
{
    return SECOND_NS / getTimer3Freq();
}