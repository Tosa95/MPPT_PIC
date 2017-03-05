#include <xc.h>

#include <stdlib.h>
#include "ClockControl.h"
#include "timer4.h"

#define MIN_PRESCALER 0
#define MAX_PRESCALER 3

#define TIMER_SIZE 65536

#define SECOND_US 1000000
#define SECOND_NS 1000000000

static void (*tmr4Clbk)();

static const int prescaler [4] = {1, 8, 64, 256};

static long int tryTimer4Prescaler (int prsc, long int interval);
static long int tryTimer4PrescalerNS (int prsc, long int interval);

static long int getTimer4Step ();
static long int getTimer4StepNS ();

static int getTimer4Prescaler ();

//void __attribute__((__interrupt__, __auto_psv__))  _T4Interrupt (void)
//{
//    if (tmr4Clbk != NULL)
//    {
//        tmr4Clbk();
//    }
//
//    IFS1bits.T4IF = 0;
//}

void timer4Init ()
{
    T4CONbits.TON = 0;

    T4CONbits.TGATE = 0;
    T4CONbits.TCS = 0;
    T4CONbits.TCKPS = 0;

    tmr4Clbk = NULL;

    //IEC1bits.T4IE = 1;

    IPC6bits.T4IP = 6;
}

void setTimer4Prescaler (char prsc)
{

    if (prsc < MIN_PRESCALER) prsc = MIN_PRESCALER;
    if (prsc > MAX_PRESCALER) prsc = MAX_PRESCALER;

    if (T4CONbits.TCKPS != prsc)
        T4CONbits.TCKPS = prsc;

}

long int setTimer4IntervalNS (long int nS)
{
long int actStep, requestedSteps, ris;

    if ((ris = tryTimer4PrescalerNS (getTimer4Prescaler(), nS)) >= 0)
    {
        return ris;
    }
    else
    {
    int i;

        for (i = MIN_PRESCALER; i < MAX_PRESCALER; i++)
        {
            if ((ris = tryTimer4PrescalerNS (i, nS)) >= 0)
            {
                return ris;
            }
        }

    }

    setTimer4Prescaler (3);

    actStep = getTimer4StepNS();

    PR4 = TIMER_SIZE - 1;
    if (TMR4 > requestedSteps - 1) TMR4 = requestedSteps - 1;

    return TIMER_SIZE * actStep;
}

long int setTimer4Interval (long int uS)
{
long int actStep, requestedSteps, ris;

    if ((ris = tryTimer4Prescaler (getTimer4Prescaler(), uS)) >= 0)
    {
        return ris;
    }
    else
    {
    int i;

        for (i = MIN_PRESCALER; i < MAX_PRESCALER; i++)
        {
            if ((ris = tryTimer4Prescaler (i, uS)) >= 0)
            {
                return ris;
            }
        }

    }

    setTimer4Prescaler (3);

    actStep = getTimer4Step();

    PR4 = TIMER_SIZE - 1;
    if (TMR4 > requestedSteps - 1) TMR4 = requestedSteps - 1;

    return TIMER_SIZE * actStep;
}

void timer4Delay (long int uS)
{
    setTimer4Interval (uS);

    IEC1bits.T4IE = 0;

    timer4Reset();
    timer4Start();

    while (IFS1bits.T4IF != 1);

    IFS1bits.T4IF = 0;

    timer4Stop();
    timer4Reset();

    IEC1bits.T4IE = 1;
}

inline long int getTimer4Freq ()
{
long int ris;

    ris = getClockFreq() / (2 * prescaler [T4CONbits.TCKPS]);

    return ris;
}

inline void timer4Start ()
{
    T4CONbits.TON = 1;
}

inline void timer4Stop ()
{
    T4CONbits.TON = 0;
}

inline void timer4Reset ()
{
    TMR4 = 0;
}

inline long int getTimer4Count ()
{
    return TMR4;
}

void timer4WaitUntilEnd ()
{
    IEC1bits.T4IE = 0;

    while (IFS1bits.T4IF != 1);

    IFS1bits.T4IF = 0;

    IEC1bits.T4IE = 1;
}

void setTimer4Callback (void (*clbk)())
{
    tmr4Clbk = clbk;
}

long int timer4ElaspedTime ()
{
long int actStep = SECOND_US / getTimer4Freq();

    return actStep * TMR4;
}

unsigned long int timer4ElaspedTimeNS()
{
unsigned long int actStep = SECOND_NS / getTimer4Freq(), ris;

    ris = actStep * TMR4;

    return ris;
}

static long int tryTimer4Prescaler (int prsc, long int interval)
{
long int actStep, requestedSteps;

    if (getTimer4Prescaler() != prsc) setTimer4Prescaler(prsc);

    actStep = getTimer4Step();

    if (actStep != 0)
        requestedSteps = interval / actStep;

    if (requestedSteps <= TIMER_SIZE && actStep != 0)
    {
        if (TMR4 > requestedSteps - 1) TMR4 = requestedSteps - 1;
        PR4 = requestedSteps - 1;

        return actStep * requestedSteps;
    }
    else
    {
        return -1;
    }
}

static long int tryTimer4PrescalerNS (int prsc, long int interval)
{
long int actStep, requestedSteps;

    if (getTimer4Prescaler() != prsc) setTimer4Prescaler(prsc);

    actStep = getTimer4StepNS();

    if (actStep != 0)
        requestedSteps = interval / actStep;

    if (requestedSteps <= TIMER_SIZE && actStep != 0)
    {
        if (TMR4 > requestedSteps - 1) TMR4 = requestedSteps - 1;
        PR4 = requestedSteps - 1;

        return actStep * requestedSteps;
    }
    else
    {
        return -1;
    }
}

static int getTimer4Prescaler ()
{
    return T4CONbits.TCKPS;
}

static long int getTimer4Step ()
{
    return SECOND_US / getTimer4Freq();
}

static long int getTimer4StepNS ()
{
    return SECOND_NS / getTimer4Freq();
}

inline long int getTimer4MaxTime ()
{
    return getTimer4Step() * PR4;
}