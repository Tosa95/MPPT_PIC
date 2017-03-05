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
#include "stdTypes.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mainSettingsScreen.h"
#include "toolsSettingsScreen.h"

#define CONTROLS_NUM    3

#define TOOL_ID         0
#define BUZZER_ID       1
#define EXIT_ID         2

#define EXIT_TO_MAIN    1
#define EXIT_TO_BUZZER  2

static STATICTEXT *title;
static OBJ_HEADER *hVec[CONTROLS_NUM];

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
void generalSettingsScreenShow ()
{
    clearDisplayU(0x01);
    GObjCreation ();
    exitF = 0;

    displayLoop();

    leavingScreen();
}

/*
 * Crea i controlli grafici
 */
static void GObjCreation ()
{
GOL_SCHEME *pScheme;
WORD state;
strValue_t tools [2] = {"ROS", "DF"};

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
    title = StCreate (100, 0, 0, 127, 10, state, "IMPOSTAZIONI - GENERALI", pScheme);

    state = DISCRETESETTING_DRAW | DISCRETESETTING_STRING | DISCRETESETTING_VALUE_CENTER;
    hVec[0] = discreteSettingCreate(0, 0, 11, 127, 20, state, "STRUMENTO", 60, 0, 2, tools, 0, 0, 0, 0, "", pScheme);

    state = MENUENTRY_DRAW;
    hVec[1] = (OBJ_HEADER *)menuEntryCreate(1, 0, 21, 127, 30, state, "BUZZER", pScheme);

    state = MENUENTRY_DRAW;
    hVec[2] = (OBJ_HEADER *)menuEntryCreate(2, 0, 31, 127, 40, state, "ESCI", pScheme);

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
        exitF = EXIT_TO_MAIN;

    if (pObj -> ID == BUZZER_ID && objMsg == MENUENTRY_MSG_PRESSED)
        exitF = EXIT_TO_BUZZER;

    return 1;
}

/*
 * Loop che visualizza gli elementi sul display
 */
static void displayLoop ()
{
    sendControlsToGOL();
    while (!exitF)
    {
        GOLDraw();
        refreshSPIDisplay();
        if (getPressedKey() == CONTROLS_T5) exitF = EXIT_TO_MAIN;
        delayUS (100000);
        delayUS (100000);
        delayUS (100000);

        sendControlsToGOL();
        while (!(redrawRequired()))
            sendControlsToGOL();
    }
    GOLDraw();
    refreshSPIDisplay();
}

/*
 * Esegue tutte le operazioni necessarie prima di uscire dalla schermata
 */
static void leavingScreen ()
{
    int i;

    i = discreteSettingGetIndex((DISCRETESETTING *)hVec[0]);

    //TODO: adjust

    switch (i)
    {
        case 0:

            setActQuantity (BATTERY_QID);

            break;

        case 1:

            setActQuantity (BATTERY_QID);

            break;
    }

    setActQuantity(getActQuantity()->ID);

    if (exitF == EXIT_TO_MAIN)
        mainSettingsScreenShow();
    if (exitF == EXIT_TO_BUZZER)
        toolsSettingsScreenShow();
}

/*
 * Controlla se è necessario ridisegnare la chermata
 */
static bool_t redrawRequired ()
{
int i;

    for (i = 0; i < CONTROLS_NUM; i++)
    {
        if (!IsObjUpdated(hVec[i])) return TRUE_B;
    }

    return FALSE_B;
}