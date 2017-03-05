/* 
 * File:   batterySettingsScreen.h
 * Author: Davide
 *
 * Created on 12 ottobre 2014, 18.57
 */

#ifndef BATTERYSETTINGSSCREEN_H
#define	BATTERYSETTINGSSCREEN_H

#ifdef	__cplusplus
extern "C" {
#endif

 #include "settingsExitCodes.h"

    /*
     * Visualizza la schermata delle impostazioni dei pwm
     */
    void batterySInit ();

    /*
     * Loop di visualizzazione della schermata
     */
    void batterySDisplayLoop ();

    /*
     * Controlla lo stato della schermata
     */
    int batterySState ();

    /*
     * Esegue tutte le operazioni necessarie prima di uscire dalla schermata
     */
    void batterySLeavingScreen ();


#ifdef	__cplusplus
}
#endif

#endif	/* BATTERYSETTINGSSCREEN_H */

