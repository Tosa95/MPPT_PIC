/* 
 * File:   pwms_graphic.h
 * Author: Davide
 *
 * Created on 30 luglio 2014, 15.26
 */

#ifndef PWMS_TIME_CONTROL_GRAPHIC_H
#define	PWMS_TIME_CONTROL_GRAPHIC_H

#ifdef	__cplusplus
extern "C" {
#endif

    /*
     * Inizializza il modulo che si occupa di visualizzare la carica
     * della batteria
     */
    void pwmsTimeControlMeasurementInit ();

    /*
     * Visualizza sul display la carica della batteria
     */
    void pwmsTimeControlMeasurementMainLoopBody ();

    /*
     * Stoppa il modulo che si occupa di visualizzare la carica
     * della batteria
     */
    void pwmsTimeControlMeasurementStop ();


#ifdef	__cplusplus
}
#endif

#endif	/* PWMS_GRAPHIC_H */

