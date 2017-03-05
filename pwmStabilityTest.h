/* 
 * File:   pwmStabilityTest.h
 * Author: Davide
 *
 * Created on 29 agosto 2014, 11.42
 */

#ifndef PWMSTABILITYTEST_H
#define	PWMSTABILITYTEST_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdTypes.h"
#include "globalSettings.h"

#define PWM_STABILITY_TEST_SAMPLES 128

    typedef enum {STABILITY_TEST_RUNNING, STABILITY_TEST_STOPPED} stabilityTestState_t;

    /*
     * Ritorna lo stato di attivazione del test
     */
    stabilityTestState_t getStabilityTestState ();

    /*
     * Ritorna i dati per il grafico
     */
    int *getStabilityTestGraphData ();

    /*
     * Callback per il cambio di impostazioni
     */
    void settingChangeStabilityTest (settingID_t sid, void *v);

    /*
     * Aggiorna il grafico
     */
    void updateStabilityTest ();

    /*
     * ritorna l'indice attuale
     */
    int getStabilityTestActIndex ();

    /*
     * ritorna la media delle correnti
     */
    double getStabilityTestAverage ();

    /*
     * ritorna la varianza delle correnti
     */
    double getStabilityTestVariance ();

    /*
     * ritorna una corrente
     */
    double getStabilityTestVal (int index);

    /*
     * ritorna la corrente minima
     */
    double getStabilityTestMin ();

    /*
     * ritorna la corrente massima
     */
    double getStabilityTestMax ();




#ifdef	__cplusplus
}
#endif

#endif	/* PWMSTABILITYTEST_H */

