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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mainSettingsScreen.h"

#define CONTROLS_NUM 3

#define GENERAL_ID  0
#define TOOLS_ID    1
#define EXIT_ID     2

#define EXIT_TO_GENERAL 1
#define EXIT_TO_TOOLS   2
#define EXIT_TO_GRAPH   3

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
void mainSettingsScreenShow ()
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
    title = StCreate (100, 0, 0, 127, 10, state, "IMPOSTAZIONI", pScheme);

    state = MENUENTRY_DRAW;
    hVec[0] = (OBJ_HEADER *)menuEntryCreate(0, 0, 11, 127, 20, state, "GENERALI", pScheme);
    
    state = MENUENTRY_DRAW;
    hVec[1] = (OBJ_HEADER *)menuEntryCreate(1, 0, 21, 127, 30, state, "STRUMENTI", pScheme);
    
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
        exitF = EXIT_TO_GRAPH;

    if (pObj -> ID == TOOLS_ID && objMsg == MENUENTRY_MSG_PRESSED)
        exitF = EXIT_TO_TOOLS;

    if (pObj -> ID == GENERAL_ID && objMsg == MENUENTRY_MSG_PRESSED)
        exitF = EXIT_TO_GENERAL;

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
        if (getPressedKey() == CONTROLS_ESC) exitF = EXIT_TO_GRAPH;
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
    if (exitF == EXIT_TO_GRAPH)
        initActQuantity();
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