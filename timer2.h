/* 
 * File:   timer2.h
 * Author: Davide
 *
 * Created on 24 giugno 2013, 14.53
 */

#ifndef TIMER2_H
#define	TIMER2_H

#ifdef	__cplusplus
extern "C" {
#endif

    /*
     * Imposta il prescaler del timer2
     *
     * input:
     *  - prsc: seleziona il prescaler da utilizzare:
     *          - 0 = 1:1
     *          - 1 = 1:8
     *          - 2 = 1:64
     *          - 3 = 1:256
     *
     */
    void setTimer2Prescaler (char prsc);

    /*
     * Imposta l'intervallo di tempo necessario per completare il conteggio del timer2
     *
     * input:
     *  - uS: l'intervallo di tempo desiderato (in uS)
     *
     * output:
     *  - intervallo reale impostato
     */
    long int setTimer2Interval (long int uS);

    /*
     * Inizializza il timer2.
     */
    void timer2Init ();

    /*
     * Blocca l'esecuzione per il numero di nanosecondi richiesto
     *
     * input:
     *  - uS: intervallo richiesto (in uS)
     */
    void timer2Delay (long int uS);

    /*
     * Fa partire il timer2
     */
    inline void timer2Start ();

    /*
     * Ferma il timer2
     */
    inline void timer2Stop ();

    /*
     * Resetta il conteggio del timer2
     */
    inline void timer2Reset ();

    /*
     * ritorna il conteggio attuale del timer2
     *
     * output:
     *  - conteggio attuale del timer2
     */
    inline long int getTimer2Count ();

    /*
     * Blocca l'esecuzione fino al termine del conteggio attualmente in corso
     */
    void timer2WaitUntilEnd ();

    /*
     * Imposta la funzione da richiamare al termine del conteggio di timer2
     *
     * input:
     *  - clbk: puntatore alla funzione da chiamare (NULL per nessuna funzione)
     */
    void setTimer2Callback (void (*clbk)());

    /*
     * Ritorna il tempo trascorso dall'avvio del conteggio (in us)
     *
     * output:
     *  - tempo trascorso dall'avvio del conteggio (us)
     */
    long int timer2ElaspedTime ();

    /*
     * Ritorna l'attuale frequenza interna del timer2
     *
     * output:
     *  - frequenza attuale a cui lavora il timer2
     */
    inline long int getTimer2Freq ();

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER2_H */

