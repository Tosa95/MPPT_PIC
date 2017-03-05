/* 
 * File:   stabilityTestSettings.h
 * Author: Davide
 *
 * Created on 29 agosto 2014, 12.07
 */

#ifndef STABILITYTESTSETTINGS_H
#define	STABILITYTESTSETTINGS_H

#ifdef	__cplusplus
extern "C" {
#endif

    #include "settingsExitCodes.h"

    /*
     * Visualizza la schermata delle impostazioni dei pwm
     */
    void stabilityTestSInit ();

    /*
     * Loop di visualizzazione della schermata
     */
    void stabilityTestSDisplayLoop ();

    /*
     * Controlla lo stato della schermata
     */
    int stabilityTestSState ();

    /*
     * Esegue tutte le operazioni necessarie prima di uscire dalla schermata
     */
    void stabilityTestSLeavingScreen ();


#ifdef	__cplusplus
}
#endif

#endif	/* STABILITYTESTSETTINGS_H */

