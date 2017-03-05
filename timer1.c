#include <xc.h>

#include <stdlib.h>
#include "ClockControl.h"
#include "timer1.h"


#define MIN_PRESCALER 0
#define MAX_PRESCALER 3

#define TIMER_SIZE 65536

#define SECOND_US 1000000

static void (*tmr1Clbk)();

static const int prescaler [4] = {1, 8, 64, 256};

void __attribute__((__interrupt__, __auto_psv__))  _T1Interrupt (void)
{
    if (tmr1Clbk != NULL)
    {
        tmr1Clbk();
    }

    IFS0bits.T1IF = 0;
}

void timer1Init (timerMode md, timerGate gt, timerSync sy)
{   
    T1CONbits.TON = 0;
    
    T1CONbits.TGATE = gt;
    T1CONbits.TCS = md;
    T1CONbits.TSYNC = sy;

    T1CONbits.TCKPS = 0;
    
    tmr1Clbk = NULL;
    
    IEC0bits.T1IE = 1;

    IPC0bits.T1IP = 3;
}

void timer1Init_OLD ()
{
    T1CONbits.TON = 0;

    T1CONbits.TGATE = 0;
    T1CONbits.TCS = 0;
    T1CONbits.TSYNC = 0;

    T1CONbits.TCKPS = 0;

    tmr1Clbk = NULL;

    IEC0bits.T1IE = 1;

    IPC0bits.T1IP = 3;
}

void setTimer1Prescaler (char prsc)
{

    if (prsc < MIN_PRESCALER) prsc = MIN_PRESCALER;
    if (prsc > MAX_PRESCALER) prsc = MAX_PRESCALER;
    
    T1CONbits.TCKPS = prsc;
    
}

long int setTimer1Interval (long int uS)
{
long int actStep, timerFreq = getTimer1Freq(), requestedSteps;

    T1CONbits.TON = 0;

    actStep = SECOND_US / timerFreq;

    if (actStep != 0)
        requestedSteps = uS / actStep;
    
    if (requestedSteps <= TIMER_SIZE && actStep != 0)
    {
        TMR1 = 0;
        PR1 = requestedSteps - 1;
        
        return actStep * requestedSteps;
    }
    else
    {
    int i;
        
        for (i = 0; i < 4; i++)
        {
            setTimer1Prescaler (i);
            
            timerFreq = getTimer1Freq();
            
            actStep = SECOND_US / timerFreq;
    
            if (actStep != 0)
                requestedSteps = uS / actStep;

            if (requestedSteps <= TIMER_SIZE && actStep != 0)
            {
                TMR1 = 0;
                PR1 = requestedSteps - 1;

                return actStep * requestedSteps;
            } 
        }
        
    }
    
    setTimer1Prescaler (3);
    
    timerFreq = getTimer1Freq();
            
    actStep = SECOND_US / timerFreq;
    
    PR1 = TIMER_SIZE - 1;
    TMR1 = 0;
    
    return TIMER_SIZE * actStep;
}

void timer1Delay (long int uS)
{
    setTimer1Interval (uS);
    
    IEC0bits.T1IE = 0;

    timer1Reset();
    timer1Start();
    
    while (IFS0bits.T1IF != 1);
    
    IFS0bits.T1IF = 0;

    timer1Stop();
    timer1Reset();
    
    IEC0bits.T1IE = 1;
}

inline long int getTimer1Freq ()
{
long int ris;
    
    ris = getClockFreq() / (2 * prescaler [T1CONbits.TCKPS]);
    
    return ris;
}

inline void timer1Start ()
{
    T1CONbits.TON = 1;
}

inline void timer1Stop ()
{
    T1CONbits.TON = 0;
}

inline void timer1Reset ()
{
    TMR1 = 0;
}

inline unsigned long int getTimer1Count ()
{
    return TMR1;
}

void timer1WaitUntilEnd ()
{
    IEC0bits.T1IE = 0;

    while (IFS0bits.T1IF != 1);

    IFS0bits.T1IF = 0;

    IEC0bits.T1IE = 1;
}

void setTimer1Callback (void (*clbk)())
{
    tmr1Clbk = clbk;
}

long int timer1ElaspedTime ()
{
long int actStep = SECOND_US / getTimer1Freq();

    return actStep * TMR1;
}

int getTimer1Prescaler ()
{
    return prescaler[T1CONbits.TCKPS];
}