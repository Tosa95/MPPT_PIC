/* 
 * File:   fan.h
 * Author: Davide
 *
 * Created on 20 agosto 2014, 12.09
 */

#ifndef FAN_H
#define	FAN_H

#ifdef	__cplusplus
extern "C" {
#endif

#define FAN_SWITCH_LOWER_VOLTAGE    0.4
#define FAN_SWITCH_UPPER_VOLTAGE    0.5

#include "stdTypes.h"

    typedef enum {FAN_ON, FAN_OFF} fanState_t;

    /*
     * Aggiorna lo stato della ventola in base alla corrente media
     */
    void updateFanState (voltageV_t aC);
    
    /*
     * Imposta lo stato della ventola
     */
    void setFanState (fanState_t fS);
    
    /*
     * Ritorna lo stato della ventola
     */
    fanState_t getFanState ();

#ifdef	__cplusplus
}
#endif

#endif	/* FAN_H */

