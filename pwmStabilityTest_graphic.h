/* 
 * File:   pwmStabilityTest_graphic.h
 * Author: Davide
 *
 * Created on 29 agosto 2014, 12.23
 */

#ifndef PWMSTABILITYTEST_GRAPHIC_H
#define	PWMSTABILITYTEST_GRAPHIC_H

#ifdef	__cplusplus
extern "C" {
#endif

    /*
     * Inizializza il modulo che si occupa di testare la stabilità
     */
    void pwmStabilityTestMeasurementInit ();

    /*
     * Visualizza sul display la stabilità
     */
    void pwmStabilityTestMeasurementMainLoopBody ();

    /*
     * Stoppa il modulo che si occupa di visualizzare la stabilità
     */
    void pwmStabilityTestMeasurementStop ();


#ifdef	__cplusplus
}
#endif

#endif	/* PWMSTABILITYTEST_GRAPHIC_H */

