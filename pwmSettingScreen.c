#include "pwmSettingScreen.h"
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


#define CONTROLS_NUM 10

#define PWM1_ID     0
#define PWM2_ID     1
#define PWM3_ID     2
#define PWM4_ID     3
#define AUTO_ADJ_ID     4
#define PWM1_STEP_ID     5
#define PWM2_STEP_ID     6
#define PWM3_STEP_ID     7
#define PWM4_STEP_ID     8

#define EXIT_ID     9

static strValue_t pwmEnStrs [2] = {"ON", "OFF"};

static int exitF;

static menuLayoutManager_t *mlm;

/*
 * Callback del menu
 */
static void menuClbk (entryId_t id);

/*
 * Visualizza la schermata principale delle impostazioni
 */
void pwmSInit ()
{
int pwmS [4] = {0, 0, 0, 0}, autoAdj;
double  pwmSteps [4] = {0, 0, 0, 0};
percentage_t p;

bool_t act;

    act = *(int*)getSetting(PWM1_ENABLED_SID);
    pwmS[0] = act == TRUE_B?0:1;

    act = *(int*)getSetting(PWM2_ENABLED_SID);
    pwmS[1] = act == TRUE_B?0:1;

    act = *(int*)getSetting(PWM3_ENABLED_SID);
    pwmS[2] = act == TRUE_B?0:1;

    act = *(int*)getSetting(PWM4_ENABLED_SID);
    pwmS[3] = act == TRUE_B?0:1;

    act = *(int*)getSetting(PWM_AUTO_STEP_ADJUST_SID);
    autoAdj = act == TRUE_B?0:1;

    p = *(double *)getSetting(PWM1_STEP_SID);
    pwmSteps[0] = p;

    p = *(double *)getSetting(PWM2_STEP_SID);
    pwmSteps[1] = p;

    p = *(double *)getSetting(PWM3_STEP_SID);
    pwmSteps[2] = p;

    p = *(double *)getSetting(PWM4_STEP_SID);
    pwmSteps[3] = p;


    exitF = 0;

    mlm = getMenu("IMPOSTAZIONI PWM", CONTROLS_NUM);

    addStringEntry(mlm, PWM1_ID, pwmEnStrs, 2, pwmS[0], "PWM1 ENABLED");
    addStringEntry(mlm, PWM2_ID, pwmEnStrs, 2, pwmS[1], "PWM2 ENABLED");
    addStringEntry(mlm, PWM3_ID, pwmEnStrs, 2, pwmS[2], "PWM3 ENABLED");
    addStringEntry(mlm, PWM4_ID, pwmEnStrs, 2, pwmS[3], "PWM4 ENABLED");
    addStringEntry(mlm, AUTO_ADJ_ID, pwmEnStrs, 2, autoAdj, "AUTO ADJUST");
    addNumericEntry(mlm, PWM1_STEP_ID, MIN_STEP, MAX_STEP, pwmSteps[0], STEP_CHANGE, "%", "PWM1 STEP");
    addNumericEntry(mlm, PWM2_STEP_ID, MIN_STEP, MAX_STEP, pwmSteps[1], STEP_CHANGE, "%", "PWM2 STEP");
    addNumericEntry(mlm, PWM3_STEP_ID, MIN_STEP, MAX_STEP, pwmSteps[2], STEP_CHANGE, "%", "PWM3 STEP");
    addNumericEntry(mlm, PWM4_STEP_ID, MIN_STEP, MAX_STEP, pwmSteps[3], STEP_CHANGE, "%", "PWM4 STEP");

    addActionEntry(mlm, EXIT_ID, "ESCI", menuClbk);

    registerForCallback(mlm);

    createInterface (mlm);
}


/*
 * Loop che visualizza gli elementi sul display
 */
void pwmSDisplayLoop ()
{
    drawMenu(mlm);
}

/*
 * Esegue tutte le operazioni necessarie prima di uscire dalla schermata
 */
void pwmSLeavingScreen ()
{
    destroyMenu(mlm);
}

/*
 * Controlla lo stato della schermata
 */
int pwmSState ()
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

    pwmS = getStringEntry(mlm, PWM1_ID)==0?TRUE_B:FALSE_B;
    setSetting(PWM1_ENABLED_SID, &pwmS);

    pwmS = getStringEntry(mlm, PWM2_ID)==0?TRUE_B:FALSE_B;
    setSetting(PWM2_ENABLED_SID, &pwmS);

    pwmS = getStringEntry(mlm, PWM3_ID)==0?TRUE_B:FALSE_B;
    setSetting(PWM3_ENABLED_SID, &pwmS);

    pwmS = getStringEntry(mlm, PWM4_ID)==0?TRUE_B:FALSE_B;
    setSetting(PWM4_ENABLED_SID, &pwmS);

    pwmS = getStringEntry(mlm, AUTO_ADJ_ID)==0?TRUE_B:FALSE_B;
    setSetting(PWM_AUTO_STEP_ADJUST_SID, &pwmS);

    p = getNumericEntry(mlm, PWM1_STEP_ID);
    setSetting(PWM1_STEP_SID, &p);

    p = getNumericEntry(mlm, PWM2_STEP_ID);
    setSetting(PWM2_STEP_SID, &p);

    p = getNumericEntry(mlm, PWM3_STEP_ID);
    setSetting(PWM3_STEP_SID, &p);

    p = getNumericEntry(mlm, PWM4_STEP_ID);
    setSetting(PWM4_STEP_SID, &p);

    saveSettingsToFlash();

}