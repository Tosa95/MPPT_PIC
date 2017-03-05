/* 
 * File:   timer3.h
 * Author: Davide
 *
 * Created on 25 giugno 2013, 11.10
 */

#ifndef TIMER3_H
#define	TIMER3_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

#define TIMER3_INSTANT_START __asm__("BSET T3CON, #0x0F")
#define TIMER3_INSTANT_STOP __asm__("BCLR T3CON, #0x0F")
#define TIMER3_INSTANT_RESET __asm__("CLR TMR3")
#define TIMER3_INSTANT_WAIT while(IFS0bits.T3IF == 0);IFS0bits.T3IF = 0
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
    void setTimer3Prescaler (char prsc);

    /*
     * Imposta l'intervallo di tempo necessario per completare il conteggio del timer3
     *
     * input:
     *  - uS: l'intervallo di tempo desiderato (in uS)
     *
     * output:
     *  - intervallo reale impostato
     */
    long int setTimer3Interval (long int uS);

    /*
     * Imposta l'intervallo di tempo necessario per completare il conteggio del timer3
     *
     * input:
     *  - nS: l'intervallo di tempo desiderato (in nS)
     *
     * output:
     *  - intervallo reale impostato
     */
    long int setTimer3IntervalNS (long int nS);

    /*
     * Inizializza il timer3.
     */
    void timer3Init ();

    /*
     * Blocca l'esecuzione per il numero di nanosecondi richiesto
     *
     * input:
     *  - uS: intervallo richiesto (in uS)
     */
    void timer3Delay (long int uS);

    /*
     * Fa partire il timer3
     */
    inline void timer3Start ();

    /*
     * Ferma il timer3
     */
    inline void timer3Stop ();

    /*
     * Resetta il conteggio del timer3
     */
    inline void timer3Reset ();

    /*
     * ritorna il conteggio attuale del timer3
     *
     * output:
     *  - conteggio attuale del timer3
     */
    inline long int getTimer3Count ();

    /*
     * Blocca l'esecuzione fino al termine del conteggio attualmente in corso
     */
    void timer3WaitUntilEnd ();

    /*
     * Imposta la funzione da richiamare al termine del conteggio di timer3
     *
     * input:
     *  - clbk: puntatore alla funzione da chiamare (NULL per nessuna funzione)
     */
    void setTimer3Callback (void (*clbk)());

    /*
     * Ritorna il tempo trascorso dall'avvio del conteggio (in us)
     *
     * output:
     *  - tempo trascorso dall'avvio del conteggio (us)
     */
    long int timer3ElaspedTime ();

    /*
     * Ritorna l'attuale frequenza interna del timer3
     *
     * output:
     *  - frequenza attuale a cui lavora il timer3
     */
    inline long int getTimer3Freq ();

    long int timer3ElaspedTimeNS();

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER3_H */

