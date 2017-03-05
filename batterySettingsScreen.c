#include "batterySettingsScreen.h"
#include "Graphics/GOL.h"
#include "discreteSetting.h"
#include "menuEntry.h"
#include "controls.h"
#include "Graphics/StaticText.h"
#include "myGraphicUtils.h"
#include "GOLCallbacks.h"
#include "SPIDisplay.h"
#include "ClockControl.h"
#include "Quantities.h"
#include "globalSettings.h"
#include "menuLayoutManager.h"
#include "battery.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define CONTROLS_NUM 7

#define BATT_CHARGED_LOW_ID     0
#define BATT_CHARGED_UPP_ID     1
#define NET_SWITCH_LOW_ID       2
#define NET_SWITCH_UPP_ID       3
#define ADC_BATT_UPP_ID         4
#define NET_LOCK_TIME_ID        5


#define EXIT_ID     6

static int exitF;

static menuLayoutManager_t *mlm;

/*
 * Callback del menu
 */
static void menuClbk (entryId_t id);

/*
 * Visualizza la schermata principale delle impostazioni
 */
void batterySInit ()
{
double  values [6] = {0, 0, 0, 0, 0, 0};
voltageV_t v;
timeS_t t;

    v = *(double *)getSetting(BATT_CHARGED_LOW_SID);
    values[0] = v;

    v = *(double *)getSetting(BATT_CHARGED_UPP_SID);
    values[1] = v;

    v = *(double *)getSetting(NET_SWITCH_LOW_SID);
    values[2] = v;

    v = *(double *)getSetting(NET_SWITCH_UPP_SID);
    values[3] = v;

    v = *(double *)getSetting(ADC_BATT_UPP_SID);
    values[4] = v;

    t = *(double *)getSetting(NET_SWITCH_TIME_SPAN_S_SID);
    values[5] = t;

    exitF = 0;

    mlm = getMenu("IMPOSTAZIONI BATTERIA", CONTROLS_NUM);

    addNumericEntry(mlm, BATT_CHARGED_LOW_ID, 0, 100, values[0], 0.5, "V", "B C LOW");
    addNumericEntry(mlm, BATT_CHARGED_UPP_ID, 0, 100, values[1], 0.5, "V", "B C UPP");
    addNumericEntry(mlm, NET_SWITCH_LOW_ID, 0, 100, values[2], 0.5, "V", "N S LOW");
    addNumericEntry(mlm, NET_SWITCH_UPP_ID, 0, 100, values[3], 0.5, "V", "N S UPP");
    addNumericEntry(mlm, ADC_BATT_UPP_ID, 0, 100, values[4], 0.01, "V", "ADC UPP");
    addNumericEntry(mlm, NET_LOCK_TIME_ID, 0, 120, values[5], 1, "S", "NET LOCK");

    addActionEntry(mlm, EXIT_ID, "ESCI", menuClbk);

    registerForCallback(mlm);

    createInterface (mlm);
}


/*
 * Loop che visualizza gli elementi sul display
 */
void batterySDisplayLoop ()
{
    drawMenu(mlm);
}

/*
 * Esegue tutte le operazioni necessarie prima di uscire dalla schermata
 */
void batterySLeavingScreen ()
{
    destroyMenu(mlm);
}

/*
 * Controlla lo stato della schermata
 */
int batterySState ()
{
    return exitF;
}

/*
 * Callback del menu
 */
static void menuClbk (entryId_t id)
{
    exitF = MAIN_SCREEN;

    voltageV_t v;
    timeS_t t;
    exitF = MAIN_SCREEN;

    v = getNumericEntry(mlm, BATT_CHARGED_LOW_ID);
    setSetting(BATT_CHARGED_LOW_SID, &v);

    v = getNumericEntry(mlm, BATT_CHARGED_UPP_ID);
    setSetting(BATT_CHARGED_UPP_SID, &v);

    v = getNumericEntry(mlm, NET_SWITCH_LOW_ID);
    setSetting(NET_SWITCH_LOW_SID, &v);

    v = getNumericEntry(mlm, NET_SWITCH_UPP_ID);
    setSetting(NET_SWITCH_UPP_SID, &v);

    v = getNumericEntry(mlm, ADC_BATT_UPP_ID);
    setSetting(ADC_BATT_UPP_SID, &v);

    t = getNumericEntry(mlm, NET_LOCK_TIME_ID);
    setSetting(NET_SWITCH_TIME_SPAN_S_SID, &t);

    saveSettingsToFlash();
}
