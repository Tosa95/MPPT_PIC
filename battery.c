#include "battery.h"
#include "stdTypes.h"
#include "network.h"
#include "globalSettings.h"
#include <stdlib.h>

batteryState_t state;
voltageV_t voltage;
percentage_t perc;

voltageV_t BATTERY_UPPER_CHARGING_THRESHOLD;
voltageV_t BATTERY_LOWER_CHARGING_THRESHOLD;

/*
 * Ritorna il voltaggio minimo della batteria
 */
voltageV_t getMinVoltage ()
{
    voltageV_t val;

    val = *(double *)getSetting(NET_SWITCH_LOW_SID);

    return val;
}

/*
 * Ritorna il voltaggio massimo della batteria
 */
voltageV_t getMaxVoltage ()
{
    voltageV_t val;

    val = *(double *)getSetting(BATT_CHARGED_UPP_SID);

    return val;
}

/*
 * Imposta lo stato della batteria (carica/scarica)
 */
void setBatteryState (batteryState_t bState)
{
    state = bState;
}

/*
 * Restituisce lo stato della batteria (carica/scarica)
 */
batteryState_t getBatteryState ()
{
    return state;
}

/*
 * Imposta la tensione attuale della batteria (calcola automaticamete la
 * percentuale)
 */
void setBatteryVoltage (voltageV_t v)
{
    voltage = v;

    if (voltage >= BATTERY_UPPER_CHARGING_THRESHOLD)
        setBatteryState(BATTERY_CHARGED);
    else if (voltage <= BATTERY_LOWER_CHARGING_THRESHOLD)
        setBatteryState(BATTERY_NON_CHARGED);
    
    perc = getPercentage(getMinVoltage(),getMaxVoltage(), voltage);
}

/*
 * Restituisce la tensione della batteria
 */
voltageV_t getBatteryVoltage ()
{
    return voltage;
}

/*
 * Imposta la percentuale attuale della batteria (calcola automaticamente la
 * tensione)
 */
void setBatteryPercentage (percentage_t p)
{
    perc = p;
    setBatteryVoltage(getValueFromPercentage(getMinVoltage(),getMaxVoltage(), perc));
}

/*
 * Restituisce la percentuale attuale della batteria
 */
percentage_t getBatteryPercentage ()
{
    return perc;
}

/*
 * Callback per il cambio di impostazioni della batteria
 */
void batterySettingsChange (settingID_t sid, void *v)
{
    if (sid == BATT_CHARGED_UPP_SID)
        BATTERY_UPPER_CHARGING_THRESHOLD = *((double *)v);
    else if (sid == BATT_CHARGED_LOW_SID)
        BATTERY_LOWER_CHARGING_THRESHOLD = *((double *)v);
}