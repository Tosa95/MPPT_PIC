#include "menuLayoutManager.h"
#include "discreteSetting.h"
#include "menuEntry.h"
#include "controls.h"
#include <stdlib.h>
#include <string.h>
#include "controls.h"

#define ENTRIES_LEFT_BOUND  0
#define ENTRIES_RIGHT_BOUND 127

#define ENTRIES_PER_SCREEN 5
#define ENTRIES_HEIGHT 9

#define ENTRIES_NAME_PIX 70

#define TITLE_HEIGHT    10

static menuLayoutManager_t *mlmCb;

/*
 * Aggiorna la lista di oggetti GOL
 */
void updateGOLList (menuLayoutManager_t *mlm);

/*
 * Imposta tutti gli oggetti nello stato di draw
 */
void setDrawStates (menuLayoutManager_t *mlm);

/*
 * Ritorna un nuovo menu
 */
menuLayoutManager_t *getMenu (strValue_t name, int objNum)
{
    menuLayoutManager_t *res;
    WORD state;
    int i;

    res = (menuLayoutManager_t *)malloc(sizeof(menuLayoutManager_t));

    strcpy(res->name, name);

    res->objNum = objNum;
    res->gObjs = (OBJ_HEADER **)malloc(sizeof(OBJ_HEADER*)*objNum);
    res->clbks = (menuClbk_t *)malloc(sizeof(menuClbk_t)*objNum);

    for (i = 0; i < res->objNum; i++)
    {
        res->clbks[i] = NULL;
    }


    res->lowerId = 0;
    res->upperId = ENTRIES_PER_SCREEN - 1;
    res->actId = 0;

    res->pScheme = GOLCreateScheme();

    res->pScheme ->Color0 = 0x00;
    res->pScheme ->Color1 = 0x01;

    res->pScheme ->CommonBkColor = 0x01;

    res->pScheme ->EmbossDkColor = 0x00;
    res->pScheme ->EmbossLtColor = 0x01;

    res->pScheme ->TextColor0 = 0x00;
    res->pScheme ->TextColor1 = 0x00;

    state = ST_DRAW | ST_CENTER_ALIGN;
    res->title = StCreate (1000, ENTRIES_LEFT_BOUND, 0, ENTRIES_RIGHT_BOUND, TITLE_HEIGHT, state, res->name, res->pScheme);

    return res;
}

/*
 * Distrugge un menu
 */
void destroyMenu (menuLayoutManager_t *mlm)
{
    int i;

    for (i = 0; i < mlm->objNum; i++)
    {
        if (mlm->gObjs[i]->FreeObj != NULL)
            mlm->gObjs[i]->FreeObj(mlm->gObjs[i]);
        free(mlm->gObjs[i]);
    }

    free(mlm->gObjs);
    free (mlm);
}

/*
 * Inserisce un controllo di tipo stringa
 */
void addStringEntry (menuLayoutManager_t *mlm, entryId_t eid, string_t *valuesSet, int valuesNum, int iValue, string_t name)
{
    WORD state;
    state = DISCRETESETTING_DRAW | DISCRETESETTING_STRING;
    mlm->gObjs[eid] = (OBJ_HEADER *)discreteSettingCreate(eid, ENTRIES_LEFT_BOUND, 0, ENTRIES_RIGHT_BOUND, 0, state, name, ENTRIES_NAME_PIX, iValue, valuesNum, valuesSet, 0, 0, 0, 0, "", mlm->pScheme);
}

/*
 * Inserisce un controllo di tipo numerico
 */
void addNumericEntry (menuLayoutManager_t *mlm, entryId_t eid, double minValue, double maxValue, double iValue, double step, string_t unit, string_t name)
{
    WORD state;
    state = DISCRETESETTING_DRAW | DISCRETESETTING_NUMERIC;
    mlm->gObjs[eid] = (OBJ_HEADER *)discreteSettingCreate(eid, ENTRIES_LEFT_BOUND, 0, ENTRIES_RIGHT_BOUND, 0, state, name, ENTRIES_NAME_PIX, 0, 0, 0, iValue, step, minValue, maxValue, unit, mlm->pScheme);
}

/*
 * Inserisce un controllo di tipo azione
 */
void addActionEntry (menuLayoutManager_t *mlm, entryId_t eid, string_t name, menuClbk_t clbk)
{
    WORD state;
    state = MENUENTRY_DRAW;
    mlm->gObjs[eid] = (OBJ_HEADER *)menuEntryCreate(eid, ENTRIES_LEFT_BOUND, 0, ENTRIES_RIGHT_BOUND, 0, state, name,  mlm->pScheme);
    mlm->clbks[eid] = clbk;
}

/*
 * Disegna a schermo il menu
 */
void drawMenu (menuLayoutManager_t *mlm)
{
    //clearDisplayU(0x01);
    
    //setDrawStates(mlm);

    GOLDraw();

    refreshSPIDisplay();

    sendControlsToGOL();
    
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

    for (i = 0; i < mlmCb->objNum; i++)
    {
        if (pObj->ID == i)
        {
            if (objMsg == DISCRETESETTING_MSG_PRV_OBJ  || objMsg == MENUENTRY_MSG_PRV_OBJ)
                nxt = i - 1;
            else if (objMsg == DISCRETESETTING_MSG_NXT_OBJ || objMsg == MENUENTRY_MSG_NXT_OBJ)
                nxt = i + 1;
            
            if (objMsg == DISCRETESETTING_MSG_PRV_OBJ  || objMsg == MENUENTRY_MSG_PRV_OBJ || objMsg == DISCRETESETTING_MSG_NXT_OBJ || objMsg == MENUENTRY_MSG_NXT_OBJ)
            {
                if (nxt < 0)
                {
                    nxt = mlmCb->objNum-1;
                    
                    mlmCb->upperId = nxt;
                    mlmCb->lowerId = nxt - ENTRIES_PER_SCREEN + 1;
                }
                if (nxt >= mlmCb->objNum) 
                {
                    nxt = 0;
                    
                    mlmCb->upperId = nxt + ENTRIES_PER_SCREEN - 1;
                    mlmCb->lowerId = nxt;
                }

                if (nxt > mlmCb->upperId)
                {
                    mlmCb->upperId++;
                    mlmCb->lowerId++;
                }

                if (nxt < mlmCb->lowerId)
                {
                    mlmCb->upperId--;
                    mlmCb->lowerId--;
                }

                ClrState(mlmCb->gObjs[mlmCb->actId], FOCUSED);
                SetState(mlmCb->gObjs[mlmCb->actId], DRAW_FOCUS);

                mlmCb->actId = nxt;

                updateGOLList(mlmCb);
            }

            else if (mlmCb->clbks[i] != NULL && objMsg == MENUENTRY_MSG_PRESSED)
            {
                mlmCb->clbks[i](i);
            }

            

        }
    }


    return 1;
}

/*
 * Iscrive il menu al callback di GOL (un menu alla volta)
 */
void registerForCallback (menuLayoutManager_t *mlm)
{
    mlmCb = mlm;

    setGOLMsgCallback (GMSGCB);

    clearDisplayU(0x01);
}

/*
 * Aggiorna la lista di oggetti GOL
 */
void updateGOLList (menuLayoutManager_t *mlm)
{
    int i, top = TITLE_HEIGHT + 1;
    GOLNewList();
    clearDisplayU(0x01);

    GOLAddObject(mlm->title);

    if (mlm->lowerId < 0)
        mlm->lowerId = 0;
    if (mlm->upperId >= mlm->objNum)
        mlm->upperId = mlm->objNum-1;

    for (i = mlm->lowerId; i <= mlm->upperId; i++)
    {
        mlm->gObjs[i]->top = top;
        mlm->gObjs[i]->bottom = top + ENTRIES_HEIGHT - 1;

        mlm->gObjs[i]->state |= ST_DRAW;

        top += ENTRIES_HEIGHT;

        GOLAddObject(mlm->gObjs[i]);
    }

    mlm->title->hdr.state |= ST_DRAW;

    GOLSetFocus(mlm->gObjs[mlm->actId]);
}

/*
 * Imposta tutti gli oggetti nello stato di draw
 */
void setDrawStates (menuLayoutManager_t *mlm)
{
    int i;

    for (i = mlm->lowerId; i <= mlm->upperId; i++)
    {

        mlm->gObjs[i]->state |= ST_DRAW;

    }

    mlm->title->hdr.state |= ST_DRAW;


}

/*
 * Una volta inseriti i controlli, crea l'interfaccia
 */
void createInterface (menuLayoutManager_t *mlm)
{
    updateGOLList(mlm);
}

/*
 * Ritorna il valore di un controllo numerico
 */
double getNumericEntry (menuLayoutManager_t *mlm, entryId_t eid)
{
    DISCRETESETTING *ds;

    ds = (DISCRETESETTING *)mlm->gObjs[eid];

    return discreteSettingGetValue(ds);
}

/*
 * Ritorna il valore di un controllo dtringa
 */
int getStringEntry (menuLayoutManager_t *mlm, entryId_t eid)
{
    DISCRETESETTING *ds;

    ds = (DISCRETESETTING *)mlm->gObjs[eid];

    return discreteSettingGetIndex(ds);
}