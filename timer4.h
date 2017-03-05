/* 
 * File:   timer4.h
 * Author: Davide
 *
 * Created on 6 luglio 2013, 13.57
 */

#ifndef TIMER4_H
#define	TIMER4_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

#define TIMER4_INSTANT_START __asm__("BSET T4CON, #0x0F")
#define TIMER4_INSTANT_STOP __asm__("BCLR T4CON, #0x0F")
#define TIMER4_INSTANT_RESET __asm__("CLR TMR4")
#define TIMER4_INSTANT_WAIT while(IFS1bits.T4IF == 0);IFS1bits.T4IF = 0
    //#define TIMER3_INSTANT_WAIT __asm__("Cycle:\n\tBTSS IFS0, #0x08\n\tBRA Cycle\nBCLR IFS0, #0x08");

    /*
     * Imposta il prescaler del timer3
     *
     * input:
     *  - prsc: seleziona il prescaler da utilizzare:
     *          - 0 = 1:1
     *          - 1 = 1:8
     *          - 2 = 1:64
     *          - 3 = 1:256
     *
     */
    void setTimer4Prescaler (char prsc);

    /*
     * Imposta l'intervallo di tempo necessario per completare il conteggio del timer3
     *
     * input:
     *  - uS: l'intervallo di tempo desiderato (in uS)
     *
     * output:
     *  - intervallo reale impostato
     */
    long int setTimer4Interval (long int uS);

    /*
     * Imposta l'intervallo di tempo necessario per completare il conteggio del timer3
     *
     * input:
     *  - nS: l'intervallo di tempo desiderato (in nS)
     *
     * output:
     *  - intervallo reale impostato
     */
    long int setTimer4IntervalNS (long int nS);

    /*
     * Inizializza il timer3.
     */
    void timer4Init ();

    /*
     * Blocca l'esecuzione per il numero di nanosecondi richiesto
     *
     * input:
     *  - uS: intervallo richiesto (in uS)
     */
    void timer4Delay (long int uS);

    /*
     * Fa partire il timer3
     */
    inline void timer4Start ();

    /*
     * Ferma il timer3
     */
    inline void timer4Stop ();

    /*
     * Resetta il conteggio del timer3
     */
    inline void timer4Reset ();

    /*
     * ritorna il conteggio attuale del timer3
     *
     * output:
     *  - conteggio attuale del timer3
     */
    inline long int getTimer4Count ();

    /*
     * Blocca l'esecuzione fino al termine del conteggio attualmente in corso
     */
    void timer4WaitUntilEnd ();

    /*
     * Imposta la funzione da richiamare al termine del conteggio di timer3
     *
     * input:
     *  - clbk: puntatore alla funzione da chiamare (NULL per nessuna funzione)
     */
    void setTimer4Callback (void (*clbk)());

    /*
     * Ritorna il tempo trascorso dall'avvio del conteggio (in us)
     *
     * output:
     *  - tempo trascorso dall'avvio del conteggio (us)
     */
    long int timer4ElaspedTime ();

    /*
     * Ritorna l'attuale frequenza interna del timer3
     *
     * output:
     *  - frequenza attuale a cui lavora il timer3
     */
    inline long int getTimer4Freq ();

    unsigned long int timer4ElaspedTimeNS();

    inline long int getTimer4MaxTime ();

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER4_H */

