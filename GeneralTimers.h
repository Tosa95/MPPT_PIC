/*
 * File:   GeneralTimers.h
 * Author: Davide
 *
 * Created on 25 luglio 2014, 10.46
 */

#ifndef GENERALTIMERS_H
#define	GENERALTIMERS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdTypes.h"



typedef enum
{
    TIMER2_ID = 0,
    TIMER3_ID,
    TIMER4_ID,
    TIMER5_ID
}timerID_t;

typedef enum
{
    TIMER_OFF = 0,
    TIMER_ON = 1
}timerEnabled_t;

typedef enum
{
    TIMER_TIMER = 0,
    TIMER_GATED_TIMER = 1,
    TIMER_SYNCHRONOUS_COUNTER = 2
}timerMode_t;

typedef enum
{
    TIMER_IDLE_CONTINUE = 0,
    TIMER_IDLE_STOP = 1
}timerIdleBehaviour_t;

typedef void (*tmrClbk_t)();

/*
 * Inizializza il timer
 */
void initTimer (timerID_t id, timerMode_t m, timerIdleBehaviour_t idl);

/*
 * Imposta il periodo di conteggio del timer
 */
timeUS_t setTimerInterval (timerID_t id, timeUS_t t);

/*
 * Ritorna la frequenza di incremento del timer, non l'intervallo di completamento
 * del conteggio
 */
freqHZ_t getTimerFreq (timerID_t id);

/*
 * Ritorna il periodo di incremento del timer, non il tempo di completamento
 * del conteggio
 */
timeNS_t getTimerStep (timerID_t id);

/*
 * Imposta a 0 il conteggio del timer
 */
void resetTimer (timerID_t id);

/*
 * Attiva/disattiva il timer
 */
void setTimerEnabled (timerID_t id, timerEnabled_t en);

/*
 * Controlla se il timer è andato in overflow
 */
int timerCompleted (timerID_t id);

/*
 * Resetta il flag di overflow
 */
void resetTimerCompleted (timerID_t id);

/*
 * Blocca l'esecuzione fino al termine del conteggio del timer
 */
void waitForTimerCompletion (timerID_t id);

/*
 * Calcola il numero di conteggi necessari per avere l'intervallo richiesto
 */
long int getRequestedSteps (timerID_t id, timeUS_t t);

/*
 * Calcola il numero di conteggi necessari per avere l'intervallo richiesto
 */
long int getRequestedStepsNS (timerID_t id, timeNS_t t);

/*
 * Ritorna il periodo di conteggio del timer
 */
timeUS_t getTimerInterval (timerID_t id);

/*
 * Ritorna il tempo attuale di conteggio in US
 */
timeUS_t getTimerActTime (timerID_t id);

/**
 * @brief Attiva l'interrupt del timer
 *
 * @param id id del timer
 * @param priority priorità (da 0 a 7)
 * @param clbk funzione da chiamare all'interrupt
 */
void enableTimerInterrupt (timerID_t id,int priority, tmrClbk_t clbk);

/**
 * Disabilita l'interrupt
 *
 * @param id id del timer
 */
void disableTimerInterrupt (timerID_t id);

#ifdef	__cplusplus
}
#endif

#endif	/* GENERALTIMERS_H */

