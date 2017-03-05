#include "inverter.h"
#include "CNControl.h"
#include "globalPinout.h"
#include "network.h"

static void callback();

/*
 * Inizializza il controllo dell'inverter
 */
void inverterInit()
{
    addCNCallback(callback);
}

static void callback()
{
     if (getInverterState () == INVERTER_OFF)
     {
         setNetworkState(NETWORK_CONNECTED);
     }
}

/*
 * Ritorna lo stato dell'inverter
 */
inverterState_t getInverterState ()
{
    int a = INVCON_PORT;
    
    if (INVCON_PORT == INVERTER_OFF)
        return INVERTER_OFF;
    else
        return INVERTER_ON;
}