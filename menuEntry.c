#include "menuEntry.h"
#include "Graphics/DisplayDriver.h"
#include "Graphics/Primitive.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stdTypes.h"
#include "myGraphicUtils.h"

/*
 * Controlla che il punto specificato si trovi sul pulsante freccia
 * 
 * input:
 *  - pME: puntatore al controllo
 *  - p: il punto
 */
bool_t isInsideButton (MENUENTRY *pME, iPoint_t p);

MENUENTRY  *menuEntryCreate
        (
            WORD        ID,
            SHORT       left,
            SHORT       top,
            SHORT       right,
            SHORT       bottom,
            WORD        state,

            strValue_t name,        // Nome dell'impostazione

            GOL_SCHEME  *pScheme
        )
{
    MENUENTRY  *pME = NULL;

    pME = (MENUENTRY *)GFX_malloc(sizeof(MENUENTRY));

    if(pME == NULL)
        return (NULL);

    pME->hdr.ID = ID;                                       // unique id assigned for referencing
    pME->hdr.pNxtObj = NULL;                                // initialize pointer to NULL
    pME->hdr.type = OBJ_UNKNOWN;                            // set object type
    pME->hdr.left = left;                                   // left position
    pME->hdr.top = top;                                     // top position
    pME->hdr.right = right;                                 // right position
    pME->hdr.bottom = bottom;                               // bottom position
    pME->hdr.state = state;                                 // state
    pME->hdr.DrawObj = menuEntryDraw;                 // draw function
    pME->hdr.MsgObj = menuEntryTranslateMsg;          // message function
    pME->hdr.MsgDefaultObj = menuEntryMsgDefault;     // default message function
    pME->hdr.FreeObj = NULL;              // free function

    strcpy (pME->name, name);

    // Set the color scheme to be used
    if(pScheme == NULL)
        pME->hdr.pGolScheme = _pDefaultGolScheme;
    else
        pME->hdr.pGolScheme = (GOL_SCHEME *)pScheme;

    GOLAddObject((OBJ_HEADER *)pME);

    return (pME);
}

/*
 * Traduzione messaggi
 */
WORD    menuEntryTranslateMsg(void *pObj, GOL_MSG *pMsg)
{
iPoint_t tP;
MENUENTRY *pME;

    pME = (MENUENTRY *) pObj;

    if ((pME->hdr.state & MENUENTRY_DISABLED) != 0)
        return OBJ_MSG_INVALID;

    switch (pMsg->type)
    {
        case TYPE_KEYBOARD:

            if ((pME->hdr.state & MENUENTRY_FOCUSED) != 0 && pMsg->uiEvent == EVENT_KEYSCAN && pMsg->param1 == pME->hdr.ID)
            {
                switch (pMsg->param2)
                {
                    case UP_SCANCODE:

                        return MENUENTRY_MSG_PRV_OBJ;

                        break;

                    case DOWN_SCANCODE:

                        return MENUENTRY_MSG_NXT_OBJ;

                        break;

                    case RIGHT_SCANCODE:

                        return MENUENTRY_MSG_PRESSED;

                        break;

                    case NONE_SCANCODE:

                        return MENUENTRY_MSG_RESET;

                        break;

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

                if (!((pME->hdr.state & MENUENTRY_FOCUSED) != 0))
                {
                    if (isInsideControl(pME, tP))
                        return MENUENTRY_MSG_FOCUS_REQ;
                    else
                        return OBJ_MSG_INVALID;
                }

                if (isInsideButton(pME, tP))
                    return MENUENTRY_MSG_PRESSED;
                else
                    return MENUENTRY_MSG_RESET;
            }
            else if (pMsg->uiEvent == EVENT_RELEASE)
            {
                return MENUENTRY_MSG_RESET;
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
void    menuEntryMsgDefault(WORD translatedMsg, void *pObj, GOL_MSG *pMsg)
{
MENUENTRY *pME;

    pME = (MENUENTRY *)pObj;

    switch (translatedMsg)
    {
        case MENUENTRY_MSG_PRESSED:

            pME->hdr.state |= MENUENTRY_PRESSED;

            break;

        case MENUENTRY_MSG_FOCUS_REQ:

            GOLSetFocus (&(pME->hdr));

            break;

        case MENUENTRY_MSG_RESET:

            if (GetState (pME, MENUENTRY_PRESSED))
            {
                ClrState (pME, MENUENTRY_PRESSED);
                SetState (pME, MENUENTRY_DRAW);
            }

            break;
    }
}

/*
 * Disegna sullo schermo il controllo
 */
WORD    menuEntryDraw(void *pObj)
{
MENUENTRY *pME;
SHORT height;
iPoint_t tP;
iRect_t area;

    pME = (MENUENTRY *)pObj;

    if ((pME->hdr.state & MENUENTRY_DRAW) != 0)
    {
        area = getIRect (getIPoint (pME->hdr.left, pME->hdr.top), getIPoint (pME->hdr.right, pME->hdr.bottom));
        fillRectArea (area, pME->hdr.pGolScheme->CommonBkColor);

        height = pME->hdr.bottom - pME->hdr.top;

        SetLineThickness (NORMAL_LINE);

        // Draws the external rectangle
        SetColor (pME->hdr.pGolScheme->Color0);
        if ((pME->hdr.state & MENUENTRY_FOCUSED) != 0)
        {
            area = getIRect (getIPoint(pME->hdr.left, pME->hdr.top), getIPoint(pME->hdr.left + height, pME->hdr.bottom));
            drawArrowButton (area, FALSE_B, FALSE_B, ARROW_RIGHT);
        }

        // Draws the arrow-button
        area = getIRect (getIPoint(pME->hdr.right - height, pME->hdr.top), getIPoint(pME->hdr.right, pME->hdr.bottom));
        drawArrowButton (area, FALSE_B, (pME->hdr.state & MENUENTRY_PRESSED) != 0, ARROW_RIGHT);

        // Draws the name
        SetColor (pME->hdr.pGolScheme->TextColor0);
        SetFont (pME->hdr.pGolScheme->pFont);
        if ((pME->hdr.state & MENUENTRY_FOCUSED) != 0)
            area = getIRect (getIPoint(pME->hdr.left + height, pME->hdr.top), getIPoint(pME->hdr.right - height, pME->hdr.bottom));
        else
            area = getIRect (getIPoint(pME->hdr.left, pME->hdr.top), getIPoint(pME->hdr.right - height, pME->hdr.bottom));
        tP = getTextPoint (area, pME->name, pME->hdr.pGolScheme->pFont, (pME->hdr.state & MENUENTRY_CENTER) != 0?TEXT_CENTRED:TEXT_LEFT);
        OutTextXY (tP.x, tP.y, pME->name);

        //Resets statep
        pME->hdr.state &= ~MENUENTRY_DRAW;
        //pME->hdr.state &= ~MENUENTRY_PRESSED;
        
    }

    return 1;
}

/*
 * Controlla che il punto specificato si trovi sul pulsante freccia
 *
 * input:
 *  - pME: puntatore al controllo
 *  - p: il punto
 */
bool_t isInsideButton (MENUENTRY *pME, iPoint_t p)
{
iRect_t r;

    r.topLeft.x = pME->hdr.right - (pME->hdr.bottom - pME->hdr.top);
    r.topLeft.y = pME->hdr.top;

    r.bottomRight.x = pME->hdr.right;
    r.bottomRight.y = pME->hdr.bottom;

    return isInsideArea(p, r);
}