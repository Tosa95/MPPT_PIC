/* 
 * File:   timer45.h
 * Author: Davide
 *
 * Created on 26 giugno 2013, 16.56
 */

#ifndef TIMER45_H
#define	TIMER45_H

#ifdef	__cplusplus
extern "C" {
#endif

#define TIMER45_INSTANT_START __asm__("BSET (T4CON), #0x0F")
#define TIMER45_INSTANT_STOP __asm__("BCLR T4CON, #0x0F")
#define TIMER45_INSTANT_RESET __asm__("CLR TMR4\nCLR TMR5")
#define TIMER45_INSTANT_WAIT __asm__("AAB:\n\tMOV IFS1, w0\n\tAND #b0001000000000000, w0\n\tBRA Z, AAB\nBCLR IFS1, #0x0C")

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
    void setTimer45Prescaler (char prsc);

    /*
     * Inizializza il timer3.
     */
    void timer45Init ();

    /*
     * Fa partire il timer3
     */
    inline void timer45Start ();

    /*
     * Ferma il timer3
     */
    inline void timer45Stop ();

    /*
     * Resetta il conteggio del timer3
     */
    inline void timer45Reset ();

    /*
     * ritorna il conteggio attuale del timer3
     *
     * output:
     *  - conteggio attuale del timer3
     */
    inline unsigned long int getTimer45Count ();

    /*
     * Blocca l'esecuzione fino al termine del conteggio attualmente in corso
     */
    void timer45WaitUntilEnd ();

    /*
     * Imposta la funzione da richiamare al termine del conteggio di timer3
     *
     * input:
     *  - clbk: puntatore alla funzione da chiamare (NULL per nessuna funzione)
     */
    void setTimer45Callback (void (*clbk)());

    /*
     * Ritorna l'attuale prescaler del timer45
     * 
     * output:
     *  - attuale prescaler
     */
    int getTimer45Prescaler ();

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER45_H */

