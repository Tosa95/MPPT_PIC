/**
 * @file
 *
 * @ingroup TimeCounter
 * 
 * @brief Implementazione del modulo TimeCounter
 * 
 * @{
 */

#include "TimeCounter.h"
#include "GeneralTimers.h"
#include <limits.h>

///@brief Id del timer in uso
#define TIMER_ID TIMER5_ID
///@brief Intervallo impostato sul timer
#define TIMER_INTERVAL_US 60000
#define COUNTER_MODULE_US 100000000000L

static discreteTimeUS_t REAL_INTERVAL = 0;

/**
 * @brief Tempo passato (a cui va sommato il tempo attuale del timer
 */
discreteTimeUS_t count = 0; 

void timerCallback ();

void initTimeCounter ()
{
    setTimerMode(TIMER_ID, TIMER_TIMER);
    REAL_INTERVAL = setTimerInterval(TIMER_ID, TIMER_INTERVAL_US);
    enableTimerInterrupt(TIMER_ID, 7, timerCallback);

    setTimerEnabled(TIMER_ID, TIMER_ON);
}

discreteTimeUS_t getTimeUS ()
{
    setTimerEnabled(TIMER_ID, TIMER_OFF);
    discreteTimeUS_t tmr = (discreteTimeUS_t)getTimerActTime(TIMER_ID);
    discreteTimeUS_t ris = count + tmr;
    setTimerEnabled(TIMER_ID, TIMER_ON);
    return ris;
}

discreteTimeUS_t getTimeDifferenceUS (discreteTimeUS_t tAfter, discreteTimeUS_t tBefore)
{
    long long int diff;

    diff = (long long int)tAfter - (long long int)tBefore;

    if (diff >= 0)
        return diff;
    else
        return (COUNTER_MODULE_US - tBefore) + tAfter;
}

discreteTimeUS_t getTimeDifferenceToNowUS (discreteTimeUS_t t)
{
    return getTimeDifferenceUS(getTimeUS(), t);
}

/**
 * @brief Callback per il timer
 */
void timerCallback ()
{
    count += REAL_INTERVAL;
    count %= COUNTER_MODULE_US;
}



///@}