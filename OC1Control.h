/* 
 * File:   OC1Control.h
 * Author: Davide
 *
 * Created on 24 giugno 2013, 14.30
 */

#ifndef OC1CONTROL_H
#define	OC1CONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "timers.h"

    typedef enum
    {
        OC1_PWM_FAULT = 0x7,
        OC1_PWM = 0x6,
        OC1_INIT_L_CONTINUOUS_PULSES = 0x5,
        OC1_INIT_L_SINGLE_PULSES = 0x4,
        OC1_COMPARE_EVENT = 0x3,
        OC1_INIT_H_CMP_L = 0x2,
        OC1_INIT_L_CMP_H = 0x1,
        OC1_DISABLED = 0x0
    }OC1Mode;

    /*
     * Inizializza il modulo Output Compare 1
     *
     * input:
     *  - tmr: seleziona il timer utilizzato per il modulo Output Compare 1
     *  - mode: seleziona la modalità di funzionamento del modulo Output Compare 1
     *
     */
    void OC1init (timerID tmr, OC1Mode mode);

    /*
     * Setta l'intervallo del timer associato al modulo Output Compare 1
     *
     * input:
     *  - uS: l'intervallo desiderato (in uS)
     */
    void setOC1Interval (int uS);

    /*
     * Imposta il registro OC1R
     *
     * input:
     *  - val: valore da assegnare al registro
     */
    void setOC1R (int val);

    /*
     * Imposta il registro OC1RS
     *
     * input:
     *  - val: valore da assegnare al registro
     */
    void setOC1RS (int val);

    /*
     * Fa partire il modulo Output Compare 1
     */
    void OC1Start ();

    /*
     * Fa fermare il modulo Output Compare 1
     */
    void OC1Stop ();

    /*
     * Imposta il modulo per realizzare l'onda quadra desiderata.
     * Il modulo verrà impostato automaticamente su PWM.
     *
     * input:
     *  - interval: la durata (in uS) del periodo dell'onda
     *  - dutyCycle: il dutyCycle in percentuale
     */
    void setOC1PWM (long int freq, long int dutyCycle);
#ifdef	__cplusplus
}
#endif

#endif	/* OC1CONTROL_H */

