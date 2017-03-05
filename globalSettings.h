/* 
 * File:   globalSettings.h
 * Author: Davide
 *
 * Created on 20 agosto 2014, 16.21
 */

#ifndef GLOBALSETTINGS_H
#define	GLOBALSETTINGS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdTypes.h"

#define MAX_SETTING_NAME_LEN 30
    
    typedef char  settingName_t [MAX_SETTING_NAME_LEN];

    typedef enum {DOUBLE_T, INT_T, LONG_INT_T, STRING_T, BOOL_T} settingType_t;

    typedef int settingID_t;

    typedef void (*settingChangeClbk_t)(settingID_t sid, void *v);
    
    extern const settingID_t PWM1_ENABLED_SID;
    extern const settingID_t PWM2_ENABLED_SID;
    extern const settingID_t PWM3_ENABLED_SID;
    extern const settingID_t PWM4_ENABLED_SID;
    extern const settingID_t PWM_PERIOD_SID;
    extern const settingID_t PWM1_STEP_SID;
    extern const settingID_t PWM2_STEP_SID;
    extern const settingID_t PWM3_STEP_SID;
    extern const settingID_t PWM4_STEP_SID;
    extern const settingID_t PWM_AUTO_STEP_ADJUST_SID;
    extern const settingID_t STABILITY_TEST_PWMID_SID;
    extern const settingID_t STABILITY_TEST_DUTY_SID;
    extern const settingID_t STABILITY_TEST_STATE_SID;
    extern const settingID_t BATT_CHARGED_UPP_SID;
    extern const settingID_t BATT_CHARGED_LOW_SID;
    extern const settingID_t NET_SWITCH_UPP_SID;
    extern const settingID_t NET_SWITCH_LOW_SID;
    extern const settingID_t ADC_BATT_UPP_SID;
    extern const settingID_t NET_SWITCH_TIME_SPAN_S_SID;


    /*
     * Inizializza le impostazioni
     */
    void initSettings ();

    /*
     * Modifica il valore di un'impostazione
     */
    void setSetting (settingID_t sid, const void *v);

    /*
     * Ritorna il valore di un'impostazione
     */
    void *getSetting (settingID_t sid);

    /*
     * Salva le impostazioni sulla memoria flash
     */
    void saveSettingsToFlash ();

    /*
     * Carica le impostazioni dalla memoria flash
     */
    void loadSettingsFromFlash ();

#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALSETTINGS_H */

