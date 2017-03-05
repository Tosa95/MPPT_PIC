#include "discreteSetting.h"
#include "Graphics/DisplayDriver.h"
#include "Graphics/Primitive.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stdTypes.h"
#include "myGraphicUtils.h"

#define DEFAULT_TXT_OFFSET 3

/*
 * Verifica che il punto specificato si trovi all'interno del tasto di decremento del valore
 * 
 * input:
 *  - pDS: puntatore all'oggetto
 *  - p: punto
 * 
 * output:
 *  - TRUE_B se il punto si trova sul tasto, FALSE_B altrimanti
 */
bool_t isInsideDecValue (DISCRETESETTING *pDS, iPoint_t p);

/*
 * Verifica che il punto specificato si trovi all'interno del tasto di incremento del valore
 *
 * input:
 *  - pDS: puntatore all'oggetto
 *  - p: punto
 *
 * output:
 *  - TRUE_B se il punto si trova sul tasto, FALSE_B altrimanti
 */
bool_t isInsideIncValue (DISCRETESETTING *pDS, iPoint_t p);

/*
 * Verifica che il punto specificato si trovi all'interno del controllo
 *
 * input:
 *  - pDS: puntatore all'oggetto
 *  - p: punto
 *
 * output:
 *  - TRUE_B se il punto si trova nel controllo, FALSE_B altrimanti
 */
bool_t isInsideControl (DISCRETESETTING *pDS, iPoint_t p);

void clearArea (DISCRETESETTING *pDS);

DISCRETESETTING  *discreteSettingCreate
        (
            WORD        ID,
            SHORT       left,
            SHORT       top,
            SHORT       right,
            SHORT       bottom,
            WORD        state,

            strValue_t name,        // Nome dell'impostazione

            int namePix,            // Spazio dedicato al nome (in pixel)

            int actIndex,           // Attuale indice all'interno della collezione di stringhe
            int strValuesNum,       // Numero di stringhe contenute nella collezione
            strValue_t *strVec,     // Collezione di stringhe

            double actValue,        // Attuale valore numerico
            double span,            // Span
            double minValue,        // Minimo valore numerico
            double maxValue,        // Massimo valore numerico

            strValue_t msUnit,      // Unità di misura

            GOL_SCHEME  *pScheme
        )
{
    DISCRETESETTING  *pDS = NULL;

    pDS = (DISCRETESETTING *)GFX_malloc(sizeof(DISCRETESETTING));

    if(pDS == NULL)
        return (NULL);

    pDS->hdr.ID = ID;                                       // unique id assigned for referencing
    pDS->hdr.pNxtObj = NULL;                                // initialize pointer to NULL
    pDS->hdr.type = OBJ_UNKNOWN;                            // set object type
    pDS->hdr.left = left;                                   // left position
    pDS->hdr.top = top;                                     // top position
    pDS->hdr.right = right;                                 // right position
    pDS->hdr.bottom = bottom;                               // bottom position
    pDS->hdr.state = state;                                 // state
    pDS->hdr.DrawObj = discreteSettingDraw;                 // draw function
    pDS->hdr.MsgObj = discreteSettingTranslateMsg;          // message function
    pDS->hdr.MsgDefaultObj = discreteSettingMsgDefault;     // default message function
    pDS->hdr.FreeObj = discreteSettingFreeObj;              // free function

    strcpy (pDS->name, name);
    pDS->namePix = namePix;

    pDS->actIndex = actIndex;
    pDS->strValuesNum = strValuesNum;
    pDS->strVec = (strValue_t *)malloc(sizeof(strValue_t) * strValuesNum);
    memcpy (pDS->strVec, strVec, sizeof(strValue_t) * strValuesNum);

    pDS->actValue = actValue;
    pDS->span = span;
    pDS->minValue =  minValue;
    pDS->maxValue = maxValue;

    strcpy (pDS->msUnit, msUnit);

    // Set the color scheme to be used
    if(pScheme == NULL)
        pDS->hdr.pGolScheme = _pDefaultGolScheme;
    else
        pDS->hdr.pGolScheme = (GOL_SCHEME *)pScheme;

    if((pDS->hdr.state & DISCRETESETTING_STRING) == 0 && (pDS->hdr.state & DISCRETESETTING_NUMERIC) == 0) pDS->hdr.state |= DISCRETESETTING_NUMERIC;

    GOLAddObject((OBJ_HEADER *)pDS);

    return (pDS);
}

/*
 * Traduzione messaggi
 */
WORD discreteSettingTranslateMsg(void *pObj, GOL_MSG *pMsg)
{
iPoint_t tP;
DISCRETESETTING *pDS;
    
    pDS = (DISCRETESETTING *) pObj;

    if ((pDS->hdr.state & DISCRETESETTING_DISABLED) != 0)
        return OBJ_MSG_INVALID;

    switch (pMsg->type)
    {
        case TYPE_KEYBOARD:
            
            if ((pDS->hdr.state & DISCRETESETTING_FOCUSED) != 0 && pMsg->uiEvent == EVENT_KEYSCAN && pMsg->param1 == pDS->hdr.ID)
            {
                switch (pMsg->param2)
                {
                    case UP_SCANCODE:

                        return DISCRETESETTING_MSG_PRV_OBJ;

                        break;

                    case DOWN_SCANCODE:

                        return DISCRETESETTING_MSG_NXT_OBJ;

                        break;

                    case LEFT_SCANCODE:

                        return DISCRETESETTING_MSG_VALUE_DEC;

                        break;

                    case RIGHT_SCANCODE:

                        return DISCRETESETTING_MSG_VALUE_INC;

                        break;

                    case NONE_SCANCODE:

                        return DISCRETESETTING_MSG_RESET;

                    default:

                        return OBJ_MSG_INVALID;

                        break;
                }
            }
            else
            {
                return OBJ_MSG_INVALID;
            }
            
            break;

        case TYPE_TOUCHSCREEN:

            if (pMsg->uiEvent == EVENT_MOVE || pMsg->uiEvent == EVENT_PRESS || pMsg->uiEvent == EVENT_STILLPRESS)
            {
                tP.x = pMsg->param1;
                tP.y = pMsg->param2;

                if (!((pDS->hdr.state & DISCRETESETTING_FOCUSED) != 0))
                {
                    if (isInsideControl(pDS, tP))
                        return DISCRETESETTING_MSG_FOCUS_REQ;
                    else
                        return OBJ_MSG_INVALID;
                }

                if (isInsideIncValue(pDS, tP))
                    return DISCRETESETTING_MSG_VALUE_INC;
                else if (isInsideDecValue(pDS, tP))
                    return DISCRETESETTING_MSG_VALUE_DEC;
                else
                    return DISCRETESETTING_MSG_RESET;
            }
            else if (pMsg->uiEvent == EVENT_RELEASE)
            {
                return DISCRETESETTING_MSG_RESET;
            }
            else
            {
                return OBJ_MSG_INVALID;
            }
            break;
    }

    return OBJ_MSG_INVALID;
}

/*
 * Comportamento di default ai messaggi
 */
void    discreteSettingMsgDefault(WORD translatedMsg, void *pObj, GOL_MSG *pMsg)
{
DISCRETESETTING *pDS;

    pDS = (DISCRETESETTING *)pObj;

    switch (translatedMsg)
    {
        case DISCRETESETTING_MSG_VALUE_INC:

            SetState(pDS, DISCRETESETTING_NEXT_PRESSED);
            discreteSettingIncValue(pDS);

            break;

        case DISCRETESETTING_MSG_VALUE_DEC:

            SetState(pDS, DISCRETESETTING_PREV_PRESSED);
            discreteSettingDecValue(pDS);

            break;

        case DISCRETESETTING_MSG_FOCUS_REQ:

            GOLSetFocus (&(pDS->hdr));

            break;

        case DISCRETESETTING_MSG_RESET:

            if (GetState (pDS, DISCRETESETTING_NEXT_PRESSED) || GetState (pDS, DISCRETESETTING_PREV_PRESSED))
            {
                ClrState (pDS, DISCRETESETTING_NEXT_PRESSED);
                ClrState (pDS, DISCRETESETTING_PREV_PRESSED);
                SetState (pDS, DISCRETESETTING_DRAW);
            }

            break;
    }
}

/*
 * Disegna sullo schermo il controllo
 */
WORD discreteSettingDraw(void *pObj)
{
DISCRETESETTING *pDS;
SHORT height;
strValue_t val;
iPoint_t tP;
iRect_t area;

    pDS = (DISCRETESETTING *)pObj;
    
    if ((pDS->hdr.state & DISCRETESETTING_DRAW) != 0)
    {
        area = getIRect (getIPoint (pDS->hdr.left, pDS->hdr.top), getIPoint (pDS->hdr.right, pDS->hdr.bottom));
        fillRectArea (area, pDS->hdr.pGolScheme->CommonBkColor);

        height = pDS->hdr.bottom - pDS->hdr.top;
        
        SetLineThickness (NORMAL_LINE);
        
        // Draws the external rectangle
        SetColor (pDS->hdr.pGolScheme->Color0);
        if ((pDS->hdr.state & DISCRETESETTING_FOCUSED) != 0)
        {
            area = getIRect (getIPoint(pDS->hdr.left, pDS->hdr.top), getIPoint(pDS->hdr.left + height, pDS->hdr.bottom));
            drawArrowButton (area, FALSE_B, FALSE_B, ARROW_RIGHT);
        }
        
        // Draws the first arrow-button
        area = getIRect (getIPoint(pDS->hdr.left + pDS->namePix, pDS->hdr.top), getIPoint(pDS->hdr.left + pDS->namePix + height, pDS->hdr.bottom));
        drawArrowButton (area, FALSE_B, (pDS->hdr.state & DISCRETESETTING_PREV_PRESSED) != 0, ARROW_LEFT);
        
        // Draws the second arrow-button
        area = getIRect (getIPoint(pDS->hdr.right - height, pDS->hdr.top), getIPoint(pDS->hdr.right, pDS->hdr.bottom));
        drawArrowButton (area, FALSE_B, (pDS->hdr.state & DISCRETESETTING_NEXT_PRESSED) != 0, ARROW_RIGHT);

        // Draws the name
        SetColor (pDS->hdr.pGolScheme->TextColor0);
        SetFont (pDS->hdr.pGolScheme->pFont);
        if ((pDS->hdr.state & DISCRETESETTING_FOCUSED) != 0)
            area = getIRect (getIPoint(pDS->hdr.left + height, pDS->hdr.top), getIPoint(pDS->hdr.left + pDS->namePix, pDS->hdr.bottom));
        else
            area = getIRect (getIPoint(pDS->hdr.left, pDS->hdr.top), getIPoint(pDS->hdr.left + pDS->namePix, pDS->hdr.bottom));
        tP = getTextPoint (area, pDS->name, pDS->hdr.pGolScheme->pFont, (pDS->hdr.state & DISCRETESETTING_NAME_CENTER) != 0?TEXT_CENTRED:TEXT_LEFT);
        OutTextXY (tP.x, tP.y, pDS->name);

        // Draws the value
        if ((pDS->hdr.state & DISCRETESETTING_STRING) != 0)
            strcpy(val, pDS->strVec[pDS->actIndex]);
        else
        {
            sprintf (val, "%.2f ", pDS->actValue);
            strcat (val, pDS->msUnit);
        }
        area = getIRect (getIPoint(pDS->hdr.left + pDS->namePix + height, pDS->hdr.top), getIPoint(pDS->hdr.right - height, pDS->hdr.bottom));
        tP = getTextPoint (area, val, pDS->hdr.pGolScheme->pFont, (pDS->hdr.state & DISCRETESETTING_VALUE_CENTER) != 0?TEXT_CENTRED:TEXT_LEFT);
        OutTextXY (tP.x, tP.y, val);
        
        //Resets state
        pDS->hdr.state &= ~DISCRETESETTING_DRAW;
        //pDS->hdr.state &= ~DISCRETESETTING_NEXT_PRESSED;
        //pDS->hdr.state &= ~DISCRETESETTING_PREV_PRESSED;

    }
    
    return 1;
}

/*
 * Libera la memoria occupata dall'oggetto
 */
void discreteSettingFreeObj (void *pObj)
{
DISCRETESETTING *pDS;

    pDS = (DISCRETESETTING *)pObj;

    free (pDS->strVec);
}

/*
 * Incrementa il valore del controllo
 *
 * input:
 *  - pDS: puntatore al controllo
 */
void discreteSettingIncValue (DISCRETESETTING *pDS)
{
    if ((pDS->hdr.state & DISCRETESETTING_STRING) != 0)
    {
        discreteSettingSetIndex (pDS, pDS->actIndex + 1);
    }
    else
    {
        discreteSettingSetValue (pDS, pDS->actValue + pDS->span);
    }
}

/*
 * Decrementa il valore del controllo
 *
 * input:
 *  - pDS: puntatore al controllo
 */
void discreteSettingDecValue (DISCRETESETTING *pDS)
{
    if ((pDS->hdr.state & DISCRETESETTING_STRING) != 0)
    {
        discreteSettingSetIndex (pDS, pDS->actIndex - 1);
    }
    else
    {
        discreteSettingSetValue (pDS, pDS->actValue - pDS->span);
    }
}

void clearArea (DISCRETESETTING *pDS)
{
SHORT i, j;

    SetColor (pDS->hdr.pGolScheme->Color1);

    for (i = pDS->hdr.top; i <= pDS->hdr.bottom; i++)
    {
        for (j = pDS->hdr.left; j < pDS->hdr.right; j++)
        {
            PutPixel(j, i);
        }
    }
}

/*
 * Verifica che il punto specificato si trovi all'interno del tasto di decremento del valore
 *
 * input:
 *  - pDS: puntatore all'oggetto
 *  - p: punto
 *
 * output:
 *  - TRUE_B se il punto si trova sul tasto, FALSE_B altrimanti
 */
bool_t isInsideDecValue (DISCRETESETTING *pDS, iPoint_t p)
{
iRect_t r;

    r.topLeft.x = pDS->hdr.left + pDS->namePix;
    r.topLeft.y = pDS->hdr.top;

    r.bottomRight.x = r.topLeft.x + (pDS->hdr.bottom - pDS->hdr.top);
    r.bottomRight.y = pDS->hdr.bottom;

    return isInsideArea(p, r);
}

/*
 * Verifica che il punto specificato si trovi all'interno del tasto di incremento del valore
 *
 * input:
 *  - pDS: puntatore all'oggetto
 *  - p: punto
 *
 * output:
 *  - TRUE_B se il punto si trova sul tasto, FALSE_B altrimanti
 */
bool_t isInsideIncValue (DISCRETESETTING *pDS, iPoint_t p)
{
iRect_t r;

    r.topLeft.x = pDS->hdr.right - (pDS->hdr.bottom - pDS->hdr.top);
    r.topLeft.y = pDS->hdr.top;

    r.bottomRight.x = pDS->hdr.right;
    r.bottomRight.y = pDS->hdr.bottom;

    return isInsideArea(p, r);
}

/*
 * Verifica che il punto specificato si trovi all'interno del controllo
 *
 * input:
 *  - pDS: puntatore all'oggetto
 *  - p: punto
 *
 * output:
 *  - TRUE_B se il punto si trova nel controllo, FALSE_B altrimanti
 */
bool_t isInsideControl (DISCRETESETTING *pDS, iPoint_t p)
{
iRect_t r;

    r.topLeft.x = pDS->hdr.left;
    r.topLeft.y = pDS->hdr.top;

    r.bottomRight.x = pDS->hdr.right;
    r.bottomRight.y = pDS->hdr.bottom;

    return isInsideArea(p, r);
}

/*
 * Setta il valore alla nuova quantità passata
 * I valori verranno adattati automaticamente ai limiti
 *
 * input:
 *  - pDS: puntatore all'oggetto
 *  - newVal: nuovo valore
 */
void discreteSettingSetValue (DISCRETESETTING *pDS, double newVal)
{
    if (newVal > pDS->maxValue) newVal = pDS->minValue;
    if (newVal < pDS->minValue) newVal = pDS->maxValue;

    pDS->actValue = newVal;

    pDS->hdr.state |= DISCRETESETTING_DRAW;
}

/*
 * Setta l'indice alla nuova quantità passata.
 * I valori verranno adattati automaticamente ai limiti.
 *
 * input:
 *  - pDS: puntatore all'oggetto
 *  - newInd: nuovo valore
 */
void discreteSettingSetIndex (DISCRETESETTING *pDS, int newInd)
{
    if (newInd >= pDS->strValuesNum) newInd = 0;
    if (newInd < 0) newInd = pDS->strValuesNum - 1;

    pDS->actIndex = newInd;

    pDS->hdr.state |= DISCRETESETTING_DRAW;
}

/*
 * Ritorna l'attuale valore memorizzato nel controllo
 *
 * input:
 *  - pDS: puntatore al controllo
 *
 * output:
 *  - l'attuale valore memorizzato nel controllo
 */
double discreteSettingGetValue (DISCRETESETTING *pDS)
{
    return pDS->actValue;
}

/*
 * Ritorna l'attuale indice memorizzato nel controllo
 *
 * input:
 *  - pDS: puntatore al controllo
 *
 * output:
 *  - l'attuale indice memorizzato nel controllo
 */
int discreteSettingGetIndex (DISCRETESETTING *pDS)
{
    return pDS->actIndex;
}