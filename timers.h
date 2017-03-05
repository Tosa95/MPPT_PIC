/* 
 * File:   timers.h
 * Author: Davide
 *
 * Created on 24 giugno 2013, 15.01
 */

#ifndef TIMERS_H
#define	TIMERS_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct
    {

        void (*setPrescaler) (char prsc);

        long int (*setInterval) (long int uS);

        void (*init) ();

        void (*delay) (long int uS);

        void (*start) ();

        void (*stop) ();

        void (*reset) ();

        long int (*getCount) ();

        void (*waitUntilEnd) ();

        void (*setCallback) (void (*clbk)());

        long int (*elaspedTime) ();

        long int (*getFreq) ();

    }timer;

    typedef enum
    {
        TIMER1 = 0,
        TIMER2 = 1,
        TIMER3 = 3
    }timerID;

    typedef enum
    {
        TIMER_AS_TIMER = 0,
        TIMER_AS_COUNTER = 1
    }timerMode;

    typedef enum
    {
        TIMER_GATE_ON = 1,
        TIMER_GATE_OFF = 0
    }timerGate;

    typedef enum
    {
        TIMER_SYNC_ON = 1,
        TIMER_SYNC_OFF = 0
    }timerSync;

    /*
     * Inizializza la libreria
     */
    void timersInit();

    /*
     * Ritorna una struttura attraverso la quale è possibile utilizzare il timer
     *
     * input:
     *  - id: identificatore del timer
     *
     * output:
     *  - tmr: struttura contenente i metodi necessari al controllo del timer.
     *  - ritorna un valore non nullo se l'operazione ha avuto successo, 0 altrimenti.
     */
    int getTimer (timerID id, timer *tmr);

    /*
     * Libera un timer per permetterne l'utilizzo in altre parti del programma
     */
    void freeTimer (timerID id);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMERS_H */

