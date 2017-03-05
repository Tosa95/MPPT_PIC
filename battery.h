/* 
 * File:   battery.h
 * Author: Davide
 *
 * Created on 22 luglio 2014, 11.20
 */

#ifndef BATTERY_H
#define	BATTERY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "battery_graphic.h"
#include "stdTypes.h"
#include "globalSettings.h"

    extern voltageV_t BATTERY_UPPER_CHARGING_THRESHOLD;
    extern voltageV_t BATTERY_LOWER_CHARGING_THRESHOLD;

    //#define BATTERY_MAX_VOLTAGE                             56.0
    //#define BATTERY_MIN_VOLTAGE                             40.0

    typedef enum {BATTERY_CHARGED, BATTERY_NON_CHARGED} batteryState_t;

    /*
     * Imposta lo stato della batteria (carica/scarica)
     */
    void setBatteryState (batteryState_t bState);

    /*
     * Restituisce lo stato della batteria (carica/scarica)
     */
    batteryState_t getBatteryState ();

    /*
     * Imposta la tensione attuale della batteria (calcola automaticamete la
     * percentuale)
     */
    void setBatteryVoltage (voltageV_t v);

    /*
     * Restituisce la tensione della batteria
     */
    voltageV_t getBatteryVoltage ();

    /*
     * Imposta la percentuale attuale della batteria (calcola automaticamente la
     * tensione)
     */
    void setBatteryPercentage (percentage_t p);

    /*
     * Restituisce la percentuale attuale della batteria
     */
    percentage_t getBatteryPercentage ();

    /*
     * Callback per il cambio di impostazioni della batteria
     */
    void batterySettingsChange (settingID_t sid, void *v);

    /*
     * Ritorna il voltaggio minimo della batteria
     */
    voltageV_t getMinVoltage ();

    /*
     * Ritorna il voltaggio massimo della batteria
     */
    voltageV_t getMaxVoltage ();

#ifdef	__cplusplus
}
#endif

#endif	/* BATTERY_H */

