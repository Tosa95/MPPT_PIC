/* 
 * File:   console.h
 * Author: Davide
 *
 * Created on 30 luglio 2014, 23.05
 */

#ifndef CONSOLE_H
#define	CONSOLE_H

#ifdef	__cplusplus
extern "C" {
#endif

    /*
     * Inizializza il modulo che si occupa di visualizzare la carica
     * della batteria
     */
    void consoleMeasurementInit ();

    /*
     * Visualizza sul display la carica della batteria
     */
    void consoleMeasurementMainLoopBody ();

    /*
     * Stoppa il modulo che si occupa di visualizzare la carica
     * della batteria
     */
    void consoleMeasurementStop ();

#ifdef	__cplusplus
}
#endif

#endif	/* CONSOLE_H */

