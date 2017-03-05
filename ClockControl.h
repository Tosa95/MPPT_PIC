/* 
 * File:   ClockControl.h
 * Author: Davide
 *
 * Created on 17 giugno 2013, 15.17
 */

#ifndef CLOCKCONTROL_H
#define	CLOCKCONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdTypes.h"

    #define FRC_BASE_FREQ 7370000 //Frequenza nominale dell'oscillatore interno FRC

    typedef enum
    {
        FRC,
        PRIMARY
    } clockSource;


    /*
     * Ritorna l'attuale frequenza di clock
     */
    long int getClockFreq();

    /*
     * Setta il clock in modo da avere una frequenza che si avvicina il più possibile a quella richiesta.
     *
     * Input:
     *  - targetFreq: frequenza alla quale si richiede che sia impostato il clock.
     *  - clkSrc: sorgente del clock (XT, HS, FRC)
     *  - baseFreq: la frequenza base del clock (ossia quella fornita dall'oscillatore selezionato).
     *
     * Output:
     *  - Frequenza di clock realmente raggiunta.
     *
     * Nel caso in cui sia utilizzato l'oscillatore interno (FRC), si assume una frequenza base di 7.37MHz.
     * Se vengono impostate frequenza base e frequenza richiesta allo stesso valore, il modulo PLL non viene utilizzato.
     *
     */
    long int setClockFreq(long int targetFreq, clockSource clkSrc, long int baseFreq);

    /*
     * Blocca l'esecuzione per l'ammontare di uS specificato
     *
     * input:
     *  - time: i uS da attendere
     */
    void delayUS (timeUS_t time);

#ifdef	__cplusplus
}
#endif

#endif	/* CLOCKCONTROL_H */

