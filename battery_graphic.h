/* 
 * File:   battery.h
 * Author: Davide
 *
 * Created on 22 luglio 2014, 11.08
 */

#ifndef BATTERY_H
#define	BATTERY_H

#ifdef	__cplusplus
extern "C" {
#endif

    /*
     * Inizializza il modulo che si occupa di visualizzare la carica
     * della batteria
     */
    void batteryMeasurementInit ();

    /*
     * Visualizza sul display la carica della batteria
     */
    void batteryMeasurementMainLoopBody ();

    /*
     * Stoppa il modulo che si occupa di visualizzare la carica
     * della batteria
     */
    void batteryMeasurementStop ();

#ifdef	__cplusplus
}
#endif

#endif	/* BATTERY_H */

