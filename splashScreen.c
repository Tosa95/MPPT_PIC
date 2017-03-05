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
#include "toolsSettingsScreen.h"

#include "Graphics/Picture.h"
#include "tosaSoftwareLogo_1bpp.h"
#include "MPPTLogo.h"
#include "version.h"
#include "GeneralTimers.h"

#define CONTROLS_NUM 0

#define EXIT_TO_GRAPH   3

static PICTURE *logo, *dmLogo;
static STATICTEXT *info;
static OBJ_HEADER *hVec[CONTROLS_NUM];

static char str[100];

static int exitF;

/*
 * Crea i controlli grafici
 */
static void GObjCreation_TSLogo ();

/*
 * Crea i controlli grafici
 */
static void GObjCreation_DMLogo ();

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
void splashScreenShow ()
{
    clearDisplayU(0x01);
    GObjCreation_TSLogo ();
    exitF = 0;

    displayLoop();

    leavingScreen();
}

/*
 * Crea i controlli grafici
 */
static void GObjCreation_TSLogo ()
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

    state = PICT_DRAW;
    logo = PictCreate (100, 14, 0, 114, 56, state, 1, &Tosa_Software_Logo_100x56_1bpp, pScheme);
    
    setGOLMsgCallback (GMSGCB);
}

/*
 * Crea i controlli grafici
 */
static void GObjCreation_DMLogo ()
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

    state = PICT_DRAW;
    dmLogo = PictCreate (101, 4, 8, 37, 56, state, 1, &MPPT_1bpp, pScheme);

    sprintf (str, "S/W:\n TOSATTO DAVIDE\nH/W:\n TOSATTO LUCIANO\nV:\n %d.%d.%d", VERSION, SUBVERSION, SUBSUBVERSION);
    state = ST_DRAW;
    info = StCreate (102, 44, 7, 127, 63, state, str, pScheme);

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

    return 1;
}

/*
 * Loop che visualizza gli elementi sul display
 */
static void displayLoop ()
{
int i;

    i = 0;
    sendControlsToGOL();

    initTimer(TIMER3_ID, TIMER_TIMER, TIMER_IDLE_STOP);
    setTimerInterval (TIMER3_ID, 1500000);
    setTimerEnabled (TIMER3_ID, TIMER_ON);

    SetState(logo, PICT_DRAW);
    GOLDraw();
    refreshSPIDisplay();
    waitForTimerCompletion(TIMER3_ID);

    clearDisplayU(0x01);
    GObjCreation_DMLogo();
    SetState(dmLogo, PICT_DRAW);
    SetState(info, ST_DRAW);
    GOLDraw();
    refreshSPIDisplay();
    waitForTimerCompletion(TIMER3_ID);


    setTimerEnabled (TIMER3_ID, TIMER_OFF);

    exitF = EXIT_TO_GRAPH;
}

/*
 * Esegue tutte le operazioni necessarie prima di uscire dalla schermata
 */
static void leavingScreen ()
{
    if (exitF == EXIT_TO_GRAPH);
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
