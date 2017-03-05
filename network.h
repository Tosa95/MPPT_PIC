/* 
 * File:   network.h
 * Author: Davide
 *
 * Created on 20 agosto 2014, 10.15
 */

#ifndef NETWORK_H
#define	NETWORK_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdTypes.h"
#include "globalSettings.h"

extern voltageV_t NETWORK_SWITCH_LOWER_VOLTAGE;
extern voltageV_t NETWORK_SWITCH_UPPER_VOLTAGE;

typedef enum {NETWORK_CONNECTED, NETWORK_DISCONNECTED} networkState_t;

/*
 * Aggiorna lo stato di connessione al network, data la tensione di betteria
 */
void updateNetworkState (voltageV_t bV);

/*
 * Imposta lo stato di connessione al network
 */
void setNetworkState (networkState_t s);

/*
 * Ritorna lo stato di connessione al network
 */
networkState_t getNetworkState ();

/*
 * Callback per il cambio di impostazioni del network
 */
void networkSettingsChange (settingID_t sid, void *v);

/*
 * Dice se lo switching è bloccato o no
 */
bool_t networkLocked ();

/*
 * Ritorna il tempo di blocco allo switch rimanente
 */
discreteTimeS_t getNetworkLockRemainingTime ();

#ifdef	__cplusplus
}
#endif

#endif	/* NETWORK_H */

