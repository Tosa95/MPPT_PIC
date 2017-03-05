/* 
 * File:   timeMeasurement.h
 * Author: Davide
 *
 * Created on 6 luglio 2013, 17.24
 */

#ifndef TIMEMEASUREMENT_H
#define	TIMEMEASUREMENT_H

#ifdef	__cplusplus
extern "C" {
#endif

#define MEASUREMENT_NO_SPACE_ERR -1

    #include "stdTypes.h"

    typedef int timeMeasurementID_t;

    /*
     * Inizializza il modulo che effettua le misurazioni temporali
     */
    void initTimeMeasurement ();

    /*
     * Inizia una nuova misurazione
     *
     * output:
     *  - id della misurazione (MEASUREMENT_NO_SPACE_ERR se non c'è
     *    spazio per la misurazione)
     */
    timeMeasurementID_t startTimeMeasurement ();

    /*
     * Ritorna il tempo trascorso dall'attivazione della misurazione
     *
     * input:
     *  - id: l'id della misurazione
     *
     * output:
     *  - tempo trascorso dall'attivazione della misurazione (uS)
     */
    timeUS_t getElaspedTime (timeMeasurementID_t id);

    /*
     * Fa ripartire da 0 una misurazione
     *
     * input:
     *  - id: l'id della misurazione
     */
    void restartMeasurement (timeMeasurementID_t id);

    /*
     * Libera una misurazione
     *
     * input:
     *  - id: l'id della misurazione
     */
    void freeMeasurement (timeMeasurementID_t id);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMEMEASUREMENT_H */

