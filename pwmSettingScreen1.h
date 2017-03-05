/* 
 * File:   pwmSettingScreen1.h
 * Author: Davide
 *
 * Created on 22 agosto 2014, 9.55
 */

#ifndef PWMSETTINGSCREEN1_H
#define	PWMSETTINGSCREEN1_H

#ifdef	__cplusplus
extern "C" {
#endif

    #include "settingsExitCodes.h"

    /*
     * Visualizza la schermata delle impostazioni dei pwm
     */
    void pwmS1Init ();

    /*
     * Loop di visualizzazione della schermata
     */
    void pwmS1DisplayLoop ();

    /*
     * Controlla lo stato della schermata
     */
    int pwmS1State ();

    /*
     * Esegue tutte le operazioni necessarie prima di uscire dalla schermata
     */
    void pwmS1LeavingScreen ();

#ifdef	__cplusplus
}
#endif

#endif	/* PWMSETTINGSCREEN1_H */

