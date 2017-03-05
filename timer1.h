/* 
 * File:   timer1.h
 * Author: Davide
 *
 * Created on 18 giugno 2013, 11.30
 */

#ifndef TIMER1_H
#define	TIMER1_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "timers.h"

    #define TIMER1_INSTANT_START __asm__("BSET T1CON, #0x0F")
    #define TIMER1_INSTANT_STOP __asm__("BCLR T1CON, #0x0F")
    #define TIMER1_INSTANT_RESET __asm__("CLR TMR1")
    #define TIMER1_INSTANT_WAIT __asm__("TMR1_LBL:\n\tBTSS IFS0, #0x03\n\tBRA TMR1_LBL\nBCLR IFS0, #0x03")

    /*
     * Imposta il prescaler del timer1
     *
     * input:
     *  - prsc: seleziona il prescaler da utilizzare:
     *          - 0 = 1:1
     *          - 1 = 1:8
     *          - 2 = 1:64
     *          - 3 = 1:256
     *
     */
    void setTimer1Prescaler (char prsc);

    /*
     * Imposta l'intervallo di tempo necessario per completare il conteggio del timer1
     *
     * input:
     *  - uS: l'intervallo di tempo desiderato (in uS)
     *
     * output:
     *  - intervallo reale impostato
     */
    long int setTimer1Interval (long int uS);

    /*
     * Inizializza il timer1.
     */
    void timer1Init (timerMode md, timerGate gt, timerSync sy);

    /*
     * Inizializza il timer1. [OLD]
     */
    void timer1Init_OLD ();

    /*
     * Blocca l'esecuzione per il numero di nanosecondi richiesto
     *
     * input:
     *  - uS: intervallo richiesto (in uS)
     */
    void timer1Delay (long int uS);

    /*
     * Fa partire il timer1
     */
    inline void timer1Start ();

    /*
     * Ferma il timer1
     */
    inline void timer1Stop ();

    /*
     * Resetta il conteggio del timer1
     */
    inline void timer1Reset ();

    /*
     * ritorna il conteggio attuale del timer1
     *
     * output:
     *  - conteggio attuale del timer1
     */
    inline unsigned long int getTimer1Count ();

    /*
     * Blocca l'esecuzione fino al termine del conteggio attualmente in corso
     */
    void timer1WaitUntilEnd ();

    /*
     * Imposta la funzione da richiamare al termine del conteggio di timer1
     *
     * input:
     *  - clbk: puntatore alla funzione da chiamare (NULL per nessuna funzione)
     */
    void setTimer1Callback (void (*clbk)());
    
    /*
     * Ritorna il tempo trascorso dall'avvio del conteggio (in us)
     * 
     * output:
     *  - tempo trascorso dall'avvio del conteggio (us)
     */
    long int timer1ElaspedTime ();

    /*
     * Ritorna l'attuale frequenza interna del timer1
     *
     * output:
     *  - frequenza attuale a cui lavora il timer1
     */
    inline long int getTimer1Freq ();

    /*
     * Ritorna il prescaler attualmente impostato per il timer1
     */
    int getTimer1Prescaler ();

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER1_H */

