#include <xc.h>

#include <stdlib.h>
#include "ClockControl.h"
#include "timer3.h"

#define MIN_PRESCALER 0
#define MAX_PRESCALER 3

#define TIMER_SIZE 4294967296

#define SECOND_US 1000000
#define SECOND_NS 1000000000

static void (*tmr45Clbk)();

static const int prescaler [4] = {1, 8, 64, 256};

void timer45Init ()
{
    T4CONbits.TON = 0;

    T4CONbits.TGATE = 0;
    T4CONbits.TCS = 1;
    T4CONbits.TCKPS = 0;

    T4CONbits.T32 = 1;

    tmr45Clbk = NULL;

    //IEC1bits.T5IE = 0;

    IPC7bits.T5IP = 3;
}

void setTimer45Prescaler (char prsc)
{

    if (prsc < MIN_PRESCALER) prsc = MIN_PRESCALER;
    if (prsc > MAX_PRESCALER) prsc = MAX_PRESCALER;

    if (T4CONbits.TCKPS != prsc)
        T4CONbits.TCKPS = prsc;

}

inline void timer45Start ()
{
    T4CONbits.TON = 1;
}

inline void timer45Stop ()
{
    T4CONbits.TON = 0;
}

inline void timer45Reset ()
{
    TMR4 = 0;
    TMR5 = 0;
}

inline unsigned long int getTimer45Count ()
{
    return TMR4 + (TMR5<<16);
}

void timer45WaitUntilEnd ()
{
    IEC1bits.T5IE = 0;

    while (IFS1bits.T5IF != 1);

    IFS1bits.T5IF = 0;

    IEC1bits.T5IE = 1;
}

void setTimer45Callback (void (*clbk)())
{
    tmr45Clbk = clbk;
}

int getTimer45Prescaler ()
{
    return prescaler[T4CONbits.TCKPS];
}
