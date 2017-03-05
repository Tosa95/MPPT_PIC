/* 
 * File:   inverter.h
 * Author: Davide
 *
 * Created on 21 dicembre 2014, 11.01
 */

#ifndef INVERTER_H
#define	INVERTER_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum {INVERTER_OFF = 1, INVERTER_ON = 0} inverterState_t;

    /*
     * Inizializza il controllo dell'inverter
     */
    void inverterInit();

    /*
     * Ritorna lo stato dell'inverter
     */
    inverterState_t getInverterState ();

#ifdef	__cplusplus
}
#endif

#endif	/* INVERTER_H */

