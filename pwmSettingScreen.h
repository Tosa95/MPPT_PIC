/* 
 * File:   pwmSettingScreen1.h
 * Author: Davide
 *
 * Created on 22 agosto 2014, 9.55
 */

#ifndef PWMSETTINGSCREEN_H
#define	PWMSETTINGSCREEN_H

#ifdef	__cplusplus
extern "C" {
#endif

    #include "settingsExitCodes.h"

    /*
     * Visualizza la schermata delle impostazioni dei pwm
     */
    void pwmSInit ();

    /*
     * Loop di visualizzazione della schermata
     */
    void pwmSDisplayLoop ();

    /*
     * Controlla lo stato della schermata
     */
    int pwmSState ();

    /*
     * Esegue tutte le operazioni necessarie prima di uscire dalla schermata
     */
    void pwmSLeavingScreen ();

#ifdef	__cplusplus
}
#endif

#endif	/* PWMSETTINGSCREEN_H */

