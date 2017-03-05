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
     * Inizializza il modulo che si occupa di testare la stabilit�
     */
    void pwmStabilityTestMeasurementInit ();

    /*
     * Visualizza sul display la stabilit�
     */
    void pwmStabilityTestMeasurementMainLoopBody ();

    /*
     * Stoppa il modulo che si occupa di visualizzare la stabilit�
     */
    void pwmStabilityTestMeasurementStop ();


#ifdef	__cplusplus
}
#endif

#endif	/* PWMSTABILITYTEST_GRAPHIC_H */

