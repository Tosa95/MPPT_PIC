/* 
 * File:   ControlLoop.h
 * Author: Davide
 *
 * Created on 23 luglio 2014, 13.11
 */

#ifndef CONTROLLOOP_H
#define	CONTROLLOOP_H

#ifdef	__cplusplus
extern "C" {
#endif

#define CONTROL_LOOP_LAUNCH_DELAY 150000

    /*
     * Esegue un iterazione del loop che si occupa di controllare il dispositivo
     */
    void controlLoop ();

#ifdef	__cplusplus
}
#endif

#endif	/* CONTROLLOOP_H */

