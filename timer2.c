#include <xc.h>

#include <stdlib.h>
#include "ClockControl.h"
#include "timer2.h"

#define MIN_PRESCALER 0
#define MAX_PRESCALER 3

#define TIMER_SIZE 65536

#define SECOND_US 1000000.0

static void (*tmr2Clbk)();

static const int prescaler [4] = {1, 8, 64, 256};

//void __attribute__((__interrupt__, __auto_psv__))  _T2Interrupt (void)
//{
//    if (tmr2Clbk != NULL)
//    {
//        tmr2Clbk();
//    }
//
//    IFS0bits.T1IF = 0;
//}

void timer2Init ()
{
    T2CONbits.TON = 0;

    T2CONbits.TGATE = 0;
    T2CONbits.TCS = 0;
    T2CONbits.TCKPS = 0;

    tmr2Clbk = NULL;

    //IEC0bits.T2IE = 1;

    IPC1bits.T2IP = 3;
}

void setTimer2Prescaler (char prsc)
{

    if (prsc < MIN_PRESCALER) prsc = MIN_PRESCALER;
    if (prsc > MAX_PRESCALER) prsc = MAX_PRESCALER;

    if (T2CONbits.TCKPS != prsc)
        T2CONbits.TCKPS = prsc;

}

long int setTimer2Interval (long int uS)
{
long int actStep, timerFreq = getTimer2Freq(), requestedSteps;

    actStep = SECOND_US / timerFreq;

    if (actStep != 0)
        requestedSteps = uS / actStep;

    if (requestedSteps <= TIMER_SIZE && actStep != 0)
    {
        if (TMR2 > requestedSteps - 1) TMR2 = requestedSteps - 1;
        PR2 = requestedSteps - 1;

        return actStep * requestedSteps;
    }
    else
    {
    int i;

        for (i = 0; i < 4; i++)
        {
            setTimer2Prescaler (i);

            timerFreq = getTimer2Freq();

            actStep = SECOND_US / timerFreq;

            if (actStep != 0)
                requestedSteps = uS / actStep;

            if (requestedSteps <= TIMER_SIZE && actStep != 0)
            {
                if (TMR2 > requestedSteps - 1) TMR2 = requestedSteps - 1;
                PR2 = requestedSteps - 1;

                return actStep * requestedSteps;
            }
        }

    }

    setTimer2Prescaler (3);

    timerFreq = getTimer2Freq();

    actStep = SECOND_US / timerFreq;

    PR2 = TIMER_SIZE - 1;
    if (TMR2 > requestedSteps - 1) TMR2 = requestedSteps - 1;

    return TIMER_SIZE * actStep;
}

void timer2Delay (long int uS)
{
    setTimer2Interval (uS);

    IEC0bits.T2IE = 0;

    timer2Reset();
    timer2Start();

    while (IFS0bits.T2IF != 1);

    IFS0bits.T2IF = 0;

    timer2Stop();
    timer2Reset();

    IEC0bits.T2IE = 1;
}

inline long int getTimer2Freq ()
{
long int ris;

    ris = getClockFreq() / (2 * prescaler [T2CONbits.TCKPS]);

    return ris;
}

inline void timer2Start ()
{
    T2CONbits.TON = 1;
}

inline void timer2Stop ()
{
    T2CONbits.TON = 0;
}

inline void timer2Reset ()
{
    TMR2 = 0;
}

inline long int getTimer2Count ()
{
    return TMR2;
}

void timer2WaitUntilEnd ()
{
    IEC0bits.T2IE = 0;

    while (IFS0bits.T2IF != 1);

    IFS0bits.T2IF = 0;

    IEC0bits.T2IE = 1;
}

void setTimer2Callback (void (*clbk)())
{
    tmr2Clbk = clbk;
}

long int timer2ElaspedTime ()
{
long int actStep = SECOND_US / getTimer2Freq();

    return actStep * TMR2;
}
