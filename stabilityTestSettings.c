#include "stabilityTestSettings.h"
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
#include "pwms.h"


#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define CONTROLS_NUM 4

#define PWMID_ID     0
#define DUTY_ID     1
#define STATE_ID     2

#define EXIT_ID     3

static strValue_t enStrs [2] = {"ON", "OFF"};
static strValue_t pwmStrs [4] = {"PWM1", "PWM2", "PWM3", "PWM4"};

static int exitF;

static menuLayoutManager_t *mlm;

/*
 * Callback del menu
 */
static void menuClbk (entryId_t id);

/*
 * Visualizza la schermata principale delle impostazioni
 */
void stabilityTestSInit ()
{
int pwmID;
percentage_t  duty;
int en;

bool_t act;

    act = *(int*)getSetting(STABILITY_TEST_STATE_SID);
    en = act == TRUE_B?0:1;

    pwmID = *(int*)getSetting(STABILITY_TEST_PWMID_SID);
    pwmID = pwmID == PWM1_ID?0:pwmID==PWM2_ID?1:pwmID==PWM3_ID?2:3;

    duty = *(double*)getSetting(STABILITY_TEST_DUTY_SID);


    exitF = 0;

    mlm = getMenu("IMPOSTAZIONI PWM SS", CONTROLS_NUM);

    addStringEntry(mlm, PWMID_ID, pwmStrs, 4, pwmID, "PWM USATO");
    addNumericEntry(mlm, DUTY_ID, 0, 100, duty, 1, "%", "DUTY");
    addStringEntry(mlm, STATE_ID, enStrs, 2, en, "TEST ATTIVO");


    addActionEntry(mlm, EXIT_ID, "ESCI", menuClbk);

    registerForCallback(mlm);

    createInterface (mlm);
}


/*
 * Loop che visualizza gli elementi sul display
 */
void stabilityTestSDisplayLoop ()
{
    drawMenu(mlm);
}

/*
 * Esegue tutte le operazioni necessarie prima di uscire dalla schermata
 */
void stabilityTestSLeavingScreen ()
{
    destroyMenu(mlm);
}

/*
 * Controlla lo stato della schermata
 */
int stabilityTestSState ()
{
    return exitF;
}

/*
 * Callback del menu
 */
static void menuClbk (entryId_t id)
{
    exitF = MAIN_SCREEN;

    bool_t pwmS;
    percentage_t p;
    exitF = MAIN_SCREEN;

    pwmS = getStringEntry(mlm, PWMID_ID);
    pwmS = pwmS == 0?PWM1_ID:pwmS == 1?PWM2_ID:pwmS == 2?PWM3_ID:PWM4_ID;
    setSetting(STABILITY_TEST_PWMID_SID, &pwmS);

    pwmS = getStringEntry(mlm, STATE_ID)==0?TRUE_B:FALSE_B;
    setSetting(STABILITY_TEST_STATE_SID, &pwmS);

    p = getNumericEntry(mlm, DUTY_ID);
    setSetting(STABILITY_TEST_DUTY_SID, &p);

    saveSettingsToFlash();
}
