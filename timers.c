#include "stdlib.h"
#include "string.h"

#include "timers.h"
#include "timer1.h"
#include "timer2.h"

#define TIMERS_NO 2

int timersUsed [TIMERS_NO];
timer timers [TIMERS_NO];

timer err = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

void timersInit()
{
int i;

    for (i = 0; i < TIMERS_NO; i++)
    {
        timersUsed[i] = 0;
    }

    timers[0].init = timer1Init_OLD;
    timers[0].delay = timer1Delay;
    timers[0].getCount = getTimer1Count;
    timers[0].reset = timer1Reset;
    timers[0].setCallback = setTimer1Callback;
    timers[0].setInterval = setTimer1Interval;
    timers[0].setPrescaler = setTimer1Prescaler;
    timers[0].start = timer1Start;
    timers[0].stop = timer1Stop;
    timers[0].elaspedTime = timer1ElaspedTime;
    timers[0].waitUntilEnd = timer1WaitUntilEnd;
    timers[0].getFreq = getTimer1Freq;

    timers[1].init = timer2Init;
    timers[1].delay = timer2Delay;
    timers[1].getCount = getTimer2Count;
    timers[1].reset = timer2Reset;
    timers[1].setCallback = setTimer2Callback;
    timers[1].setInterval = setTimer2Interval;
    timers[1].setPrescaler = setTimer2Prescaler;
    timers[1].start = timer2Start;
    timers[1].stop = timer2Stop;
    timers[1].elaspedTime = timer2ElaspedTime;
    timers[1].waitUntilEnd = timer2WaitUntilEnd;
    timers[1].getFreq = getTimer2Freq;

    
    for (i = 0; i < TIMERS_NO; i++)
    {
        timers[i].init();
    }

}

int getTimer (timerID id, timer *tmr)
{
    if (id < TIMERS_NO && timersUsed[id] == 0)
    {
        (*tmr) = timers[id];
        return 1;
    }
    else
    {
        (*tmr) = err;
        return 0;
    }
}

void freeTimer (timerID id)
{
    if (id < TIMERS_NO)
    {
        timersUsed [id] = 0;
    }
}