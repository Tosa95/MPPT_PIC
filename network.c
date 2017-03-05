#include "network.h"
#include "globalPinout.h"
#include "inverter.h"
#include "TimeCounter.h"

#define NETON 0
#define NETOFF 1

#define US_PER_SECOND 1000000

networkState_t nS;

voltageV_t NETWORK_SWITCH_LOWER_VOLTAGE = 41.0;
voltageV_t NETWORK_SWITCH_UPPER_VOLTAGE = 47.0;

discreteTimeUS_t NETWORK_SWITCH_LOCK_DURATION = 20*US_PER_SECOND;

bool_t _locked = FALSE_B;
discreteTimeUS_t lockBeginTime = 0;

void lockSwitch ();

/* TODO: change here. New requirement: in addition to hysteresis cycle a time
 * span between two cycles has to be considered.
 *
 * In particular we need:
 *
 *  - A new setting containing the amount of time (seconds?) to wait between two switches
 *    with the corresponding update in the setting callback
 *
 *  - A way to mesure time. The method doesn't have to be precise, but has to be simple
 *    it's better to avoid the reservation of a timer for this job.
 *
 *  - The time has to be waited only in the switch from network back to battery.
 *    No time waited in the inverse way.
 *
*/
/*
 * Aggiorna lo stato di connessione al network, data la tensione di betteria
 */
void updateNetworkState (voltageV_t bV)
{
    if (bV < NETWORK_SWITCH_LOWER_VOLTAGE)
    {
        if (getNetworkState()==NETWORK_DISCONNECTED)
            lockSwitch();
        setNetworkState (NETWORK_CONNECTED);
        
    }
    else if ((bV > NETWORK_SWITCH_UPPER_VOLTAGE) && !networkLocked())
    {
        setNetworkState (NETWORK_DISCONNECTED);
    }
}

/*
 * Blocca lo switching da rete a batteria
 */
void lockSwitch ()
{
    if (!networkLocked())
    {
        _locked = TRUE_B;
        lockBeginTime = getTimeUS();
    }
}

/*
 * Ritorna vero se bloccato, falso altrimenti
 * Scaduto il tempo sblocca automaticamente
 */
bool_t networkLocked ()
{
    if (!_locked)
        return FALSE_B;

    discreteTimeUS_t timeSpent = getTimeDifferenceToNowUS(lockBeginTime);

    if (timeSpent > NETWORK_SWITCH_LOCK_DURATION)
        _locked = FALSE_B;

    return _locked;
}

/*
 * Ritorna il tempo di blocco allo switch rimanente
 */
discreteTimeS_t getNetworkLockRemainingTime ()
{
    return (NETWORK_SWITCH_LOCK_DURATION - getTimeDifferenceToNowUS(lockBeginTime))/US_PER_SECOND;
}

/*
 * Imposta lo stato di connessione al network
 */
void setNetworkState (networkState_t s)
{
    nS = s;

    if (getInverterState() == INVERTER_ON)
    {
        if (s == NETWORK_CONNECTED)
            NETCON_LAT = NETON;
        else
            NETCON_LAT = NETOFF;
    }
    else
    {
        NETCON_LAT = NETON;
        nS = NETWORK_CONNECTED;
    }
}

/*
 * Ritorna lo stato di connessione al network
 */
networkState_t getNetworkState ()
{
    return nS;
}

/*
 * Callback per il cambio di impostazioni del network
 */
void networkSettingsChange (settingID_t sid, void *v)
{
    if (sid == NET_SWITCH_UPP_SID)
        NETWORK_SWITCH_UPPER_VOLTAGE = *((double *)v);
    else if (sid == NET_SWITCH_LOW_SID)
        NETWORK_SWITCH_LOWER_VOLTAGE = *((double *)v);
    else if (sid == NET_SWITCH_TIME_SPAN_S_SID)
        NETWORK_SWITCH_LOCK_DURATION = ((int)(*((double *)v)))*US_PER_SECOND;
}