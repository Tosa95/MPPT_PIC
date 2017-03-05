#include "pwmSettingScreen1.h"
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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define CONTROLS_NUM 6

#define PWM1_ID     0
#define PWM2_ID     1
#define PWM3_ID     2
#define PWM4_ID     3
#define STEP_ID     4

#define EXIT_ID     5



static STATICTEXT *title;
static OBJ_HEADER *hVec[CONTROLS_NUM];

static strValue_t pwmEnStrs [2] = {"ON", "OFF"};

static int exitF;

/*
 * Crea i controlli grafici
 */
static void GObjCreation ();

/*
 * Callback messaggi di GOL
 *
 * input:
 *  - objMsg: messagio tradotto dall'oggetto
 *  - pObj: puntatore all'oggetto
 *  - pMsg: puntatore al messaggio originale
 */
static WORD GMSGCB( WORD objMsg, OBJ_HEADER * pObj, GOL_MSG * pMsg);

/*
 * Loop che visualizza gli elementi sul display
 */
static void displayLoop ();

/*
 * Esegue tutte le operazioni necessarie prima di uscire dalla schermata
 */
static void leavingScreen ();

/*
 * Controlla se è necessario ridisegnare la chermata
 */
static bool_t redrawRequired ();

/*
 * Visualizza la schermata principale delle impostazioni
 */
void pwmS1Init ()
{
    clearDisplayU(0x01);
    GObjCreation ();
    exitF = 0;

    //displayLoop();

    //leavingScreen();
}

/*
 * Crea i controlli grafici
 */
static void GObjCreation ()
{
GOL_SCHEME *pScheme;
WORD state;
int pwmS [4] = {0, 0, 0, 0}, autoAdj;
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

    GOLFree();

    pScheme = GOLCreateScheme();

    pScheme ->Color0 = 0x00;
    pScheme ->Color1 = 0x01;

    pScheme ->CommonBkColor = 0x01;

    pScheme ->EmbossDkColor = 0x00;
    pScheme ->EmbossLtColor = 0x01;

    pScheme ->TextColor0 = 0x00;
    pScheme ->TextColor1 = 0x00;

    state = ST_DRAW | ST_CENTER_ALIGN;
    title = StCreate (100, 0, 0, 127, 10, state, "IMPOSTAZIONI PWM", pScheme);

    state = DISCRETESETTING_DRAW | DISCRETESETTING_STRING;
    hVec[0] = (OBJ_HEADER *)discreteSettingCreate(0, 0, 11, 127, 18, state, "PWM1", 70, pwmS[0], 2, pwmEnStrs, 0, 0, 0, 0, "",  pScheme);

    state = DISCRETESETTING_DRAW | DISCRETESETTING_STRING;
    hVec[1] = (OBJ_HEADER *)discreteSettingCreate(1, 0, 19, 127, 26, state, "PWM2", 70, pwmS[1], 2, pwmEnStrs, 0, 0, 0, 0, "",  pScheme);

    state = DISCRETESETTING_DRAW | DISCRETESETTING_STRING;
    hVec[2] = (OBJ_HEADER *)discreteSettingCreate(2, 0, 27, 127, 34, state, "PWM3", 70, pwmS[2], 2, pwmEnStrs, 0, 0, 0, 0, "",  pScheme);

    state = DISCRETESETTING_DRAW | DISCRETESETTING_STRING;
    hVec[3] = (OBJ_HEADER *)discreteSettingCreate(3, 0, 35, 127, 42, state, "PWM4", 70, pwmS[3], 2, pwmEnStrs, 0, 0, 0, 0, "",  pScheme);

    state = DISCRETESETTING_DRAW | DISCRETESETTING_STRING;
    hVec[4] = (OBJ_HEADER *)discreteSettingCreate(4, 0, 43, 127, 50, state, "AUTO ADJ", 70, autoAdj, 2, pwmEnStrs, 0, 0, 0, 0, "",  pScheme);
    
    state = MENUENTRY_DRAW;
    hVec[5] = (OBJ_HEADER *)menuEntryCreate(5, 0, 51, 127, 58, state, "ESCI",  pScheme);

    GOLSetFocus (hVec[0]);
    setGOLMsgCallback (GMSGCB);
}

/*
 * Callback messaggi di GOL
 *
 * input:
 *  - objMsg: messagio tradotto dall'oggetto
 *  - pObj: puntatore all'oggetto
 *  - pMsg: puntatore al messaggio originale
 */
static WORD GMSGCB( WORD objMsg, OBJ_HEADER * pObj, GOL_MSG * pMsg)
{
int i, nxt;

    for (i = 0; i < CONTROLS_NUM; i++)
    {
        if (pObj->ID == i)
        {
            if (objMsg == DISCRETESETTING_MSG_PRV_OBJ  || objMsg == MENUENTRY_MSG_PRV_OBJ)
                nxt = i - 1;
            else if (objMsg == DISCRETESETTING_MSG_NXT_OBJ || objMsg == MENUENTRY_MSG_NXT_OBJ)
                nxt = i + 1;
            else
                nxt = i;

            if (nxt < 0) nxt = CONTROLS_NUM - 1;
            if (nxt >= CONTROLS_NUM) nxt = 0;

            GOLSetFocus(hVec[nxt]);
        }
    }

    if (pObj -> ID == EXIT_ID && objMsg == MENUENTRY_MSG_PRESSED)
    {
        bool_t pwmS;
        percentage_t p;
        exitF = MAIN_SCREEN;
        
        pwmS = discreteSettingGetIndex(hVec[0])==0?TRUE_B:FALSE_B;
        setSetting(PWM1_ENABLED_SID, &pwmS);
        
        pwmS = discreteSettingGetIndex(hVec[1])==0?TRUE_B:FALSE_B;
        setSetting(PWM2_ENABLED_SID, &pwmS);
        
        pwmS = discreteSettingGetIndex(hVec[2])==0?TRUE_B:FALSE_B;
        setSetting(PWM3_ENABLED_SID, &pwmS);
        
        pwmS = discreteSettingGetIndex(hVec[3])==0?TRUE_B:FALSE_B;
        setSetting(PWM4_ENABLED_SID, &pwmS);

        pwmS = discreteSettingGetIndex(hVec[4])==0?TRUE_B:FALSE_B;
        setSetting(PWM_AUTO_STEP_ADJUST_SID, &pwmS);

    }


    return 1;
}

/*
 * Loop che visualizza gli elementi sul display
 */
void pwmS1DisplayLoop ()
{
    GOLDraw();
    refreshSPIDisplay();
    if (getPressedKey() == CONTROLS_ESC) exitF = MAIN_SCREEN;
    delayUS (100000);
    delayUS (100000);
    delayUS (100000);

    sendControlsToGOL();
    while (!(redrawRequired()))
        sendControlsToGOL();
}

/*
 * Esegue tutte le operazioni necessarie prima di uscire dalla schermata
 */
void pwmS1LeavingScreen ()
{
    GOLFree();
}

/*
 * Controlla se è necessario ridisegnare la chermata
 */
static bool_t redrawRequired ()
{
int i;

    for (i = 0; i < CONTROLS_NUM; i++)
    {
        if (!(GetState(hVec[i], 0xFC00)))
        {
            return TRUE_B;
        }
    }

    return FALSE_B;
}

/*
 * Controlla lo stato della schermata
 */
int pwmS1State ()
{
    return exitF;
}