#include "Graphics/Graphics.h"
#include "MyGraph.h"
#include "Graphics/Primitive.h"
#include "SPIDisplay.h"
#include "Graphics/DisplayDriver.h"

inline int isInsideDNDR (int x, int y, rect dndr);
inline void drawBar (int x, int y, int height, int top, GFX_COLOR cBk, GFX_COLOR c0);
inline void drawBarSpeedDNDR (int x, int y, int height, int top, GFX_COLOR cBk, GFX_COLOR c0, rect dndr);
/*
 * Crea un nuovo grafico (istogramma con colonne larghe 1 px)
 */

MYGRAPH  *MygrCreate
        (
            WORD        ID,
            SHORT       left,
            SHORT       top,
            SHORT       right,
            SHORT       bottom,
            WORD        state,
            int *dataSerie,
            int dataNum,
            int first,
            int last,
            int barPos,
            int maxValue,
            int leftDNDR,
            int topDNDR,
            int rightDNDR,
            int bottomDNDR,
            GOL_SCHEME  *pScheme
        )
{
    int i = 0;
    MYGRAPH  *pB = NULL;
    pB = (MYGRAPH *)GFX_malloc(sizeof(MYGRAPH));
    if(pB == NULL)
        return (NULL);

    pB -> dataValid = (char *)GFX_malloc(sizeof(char)*dataNum);
    
    pB->hdr.ID = ID;                        // unique id assigned for referencing
    pB->hdr.pNxtObj = NULL;                 // initialize pointer to NULL
    pB->hdr.type = OBJ_UNKNOWN;              // set object type
    pB->hdr.left = left;                    // left position
    pB->hdr.top = top;                      // top position
    pB->hdr.right = right;                  // right position
    pB->hdr.bottom = bottom;                // bottom position
    pB->hdr.state = state;                  // state
    pB->hdr.DrawObj = MygrDraw;              // draw function
    pB->hdr.MsgObj = MygrTranslateMsg;       // message function
    pB->hdr.MsgDefaultObj = MygrMsgDefault;  // default message function
    pB->hdr.FreeObj = NULL;  				// free function

    pB->dataSerie = dataSerie;
    pB->dataNum = dataNum;
    pB->first = first;
    pB->last = last;
    pB->barPos = barPos;
    pB->maxValue = maxValue;

    pB->doNotDrawArea.left = leftDNDR;
    pB->doNotDrawArea.top = topDNDR;
    pB->doNotDrawArea.right = rightDNDR;
    pB->doNotDrawArea.bottom = bottomDNDR;

    // Set the color scheme to be used
    if(pScheme == NULL)
        pB->hdr.pGolScheme = _pDefaultGolScheme;
    else
        pB->hdr.pGolScheme = (GOL_SCHEME *)pScheme;

    GOLAddObject((OBJ_HEADER *)pB);

    invalidateMyGraph (pB);

    return (pB);
}

/*
 * Traduzione messaggi. Non implementata al momento.
 */
WORD    MygrTranslateMsg(void *pObj, GOL_MSG *pMsg)
{
    return 0;
}

/*
 * Comportamento di default ai messaggi. Non implementata al momento.
 */
void    MygrMsgDefault(WORD translatedMsg, void *pObj, GOL_MSG *pMsg)
{

}

/*
 * Disegna sullo schermo il grafico
 */
WORD MygrDraw(void *pObj)
{
int i, prop, height, first, last, *dataSerie, x, y, max, propEn;
MYGRAPH *pMygr = (MYGRAPH*)pObj;

    height = (pMygr->hdr.bottom - pMygr->hdr.top) + 1;

    first = pMygr->first;
    last = pMygr->last;

    max = pMygr->maxValue;

    dataSerie = pMygr->dataSerie;

    y = pMygr->hdr.bottom;

    propEn = !(max == height);

    for (i = first, x = pMygr->hdr.left; i <= last && x <= pMygr->hdr.right; i++, x++)
    {
        if (pMygr->dataValid[i] == DATA_INVALID)
        {
            prop = propEn?(dataSerie[i]*height)/max:dataSerie[i];

            if (i != pMygr->barPos)
            {
                #if defined (GFX_USE_DISPLAY_CONTROLLER_ST7565R)
                    if (pMygr->hdr.state & MYGR_OPTIMIZED)
                        drawBarSpeedDNDR (x, y, prop, pMygr->hdr.top, pMygr->hdr.pGolScheme->CommonBkColor, pMygr->hdr.pGolScheme->Color0, pMygr->doNotDrawArea);
                    else
                        drawBarDNDR (x, y, prop, pMygr->hdr.top, pMygr->hdr.pGolScheme->CommonBkColor, pMygr->hdr.pGolScheme->Color0, pMygr->doNotDrawArea);
                #else
                    drawBarDNDR (x, y, prop, pMygr->hdr.top, pMygr->hdr.pGolScheme->CommonBkColor, pMygr->hdr.pGolScheme->Color0, pMygr->doNotDrawArea);
                #endif
            }
            else
            {
                drawBarDNDR (x, y, prop, pMygr->hdr.top, pMygr->hdr.pGolScheme->Color0, pMygr->hdr.pGolScheme->CommonBkColor, pMygr->doNotDrawArea);
                //drawBar (x, y, prop, pMygr->hdr.top, pMygr->hdr.pGolScheme->Color0, pMygr->hdr.pGolScheme->CommonBkColor);
            }
            pMygr->dataValid[i] = DATA_VALID;
        }
        
    }

    pMygr->hdr.state &= ~(MYGR_DRAW);

    return 1;
}

void setBarPos (MYGRAPH *pMygr, int val)
{
    invalidateColumn (pMygr, pMygr->barPos);
    pMygr->barPos = val;
    invalidateColumn (pMygr, val);
}

int getBarPos (MYGRAPH *pMygr)
{
    return pMygr->barPos;
}

inline void drawBarDNDR (int x, int y, int height, int top, GFX_COLOR cBk, GFX_COLOR c0, rect dndr)
{
    int actY = y, actX = x, i;

    SetColor (c0);

    for (i = 0; i < height; i++)
    {
        actY = y - i;

        if (!isInsideDNDR(actX, actY, dndr))
        {
            PutPixel (actX, actY);
        }
    }

    actY = y - i;

    SetColor (cBk);

    for (; actY >= top; actY--)
    {
        if (!isInsideDNDR(actX, actY, dndr))
        {
            PutPixel (actX, actY);
        }
    }
}

inline void drawBar (int x, int y, int height, int top, GFX_COLOR cBk, GFX_COLOR c0)
{
    if (height > 0)
    {
        SetColor (c0);
        Line (x, y, x, y - (height - 1));

        if ((y - (height - 2)) > top)
        {
            SetColor (cBk);
            Line (x, y - (height), x, top);
        }
    }
    else
    {
        SetColor (cBk);
        Line (x, y, x, top);
    }
}

inline void drawBarSpeed (int x, int y, int height, int top, GFX_COLOR cBk, GFX_COLOR c0)
{
char act, iPix = (y - ((y>>3)<<3)) + 1, i, numBlack, little = 0;

    //prima pagina
        act = 0;

        if (height < iPix)
        {
            iPix = height;
            little = 1;
        }

        for ( i = 0; i < iPix; i++)
        {
            act = (act<<1) + 1;
        }
        act <<= 8 - iPix;
        

        setPageSPIDisplay (x, y, act);

        if (little)
            y -= 8;
        else
            y -= iPix + 1;

        //pagine solo nere

        height -= iPix;

        numBlack = height >> 3;

        for (i = 0; i < numBlack; i++)
        {
            act = 0xFF;

            setPageSPIDisplay (x, y, act);

            y -= 8;

            height -= 8;
        }


        // ultima pagina nera
        act = 0;

        for ( i = 0; i < height; i++)
        {
            act = (act<<1) + 1;
        }

        act <<= 8 - height;

        setPageSPIDisplay (x, y, act);

        y -= 8;

        for (;y >= 0; y -= 8)
        {
            setPageSPIDisplay (x, y, 0x00);
        }

}

inline void drawBarSpeedDNDR (int x, int y, int height, int top, GFX_COLOR cBk, GFX_COLOR c0, rect dndr)
{
char act, iPix = (y - ((y>>3)<<3)) + 1, i, numBlack, little = 0;

    //prima pagina
        act = 0;

        if (height < iPix)
        {
            iPix = height;
            little = 1;
        }

        for ( i = 0; i < iPix; i++)
        {
            act = (act<<1) + 1;
        }
        act <<= 8 - iPix;

        if (!isInsideDNDR(x, y, dndr))
            setPageSPIDisplay (x, y, act);

        if (little)
            y -= 8;
        else
            y -= iPix + 1;

        //pagine solo nere

        height -= iPix;

        numBlack = height >> 3;

        for (i = 0; i < numBlack; i++)
        {
            act = 0xFF;

            if (!isInsideDNDR(x, y, dndr))
                setPageSPIDisplay (x, y, act);

            y -= 8;

            height -= 8;
        }


        // ultima pagina nera
        act = 0;

        for ( i = 0; i < height; i++)
        {
            act = (act<<1) + 1;
        }

        act <<= 8 - height;

        if (!isInsideDNDR(x, y, dndr))
            setPageSPIDisplay (x, y, act);

        y -= 8;

        for (;y >= 0; y -= 8)
        {
            if (!isInsideDNDR(x, y, dndr))
                setPageSPIDisplay (x, y, 0x00);
        }

}

void invalidateMyGraph (MYGRAPH *pMygr)
{
int i = 0;
    
    pMygr->hdr.state |= MYGR_DRAW;
    
    for (i = 0; i < pMygr->dataNum; i++)
    {
        pMygr -> dataValid[i] = DATA_INVALID;
    }
}

void invalidateColumn (MYGRAPH *pMygr, int index)
{
    if (index >= 0 && index < pMygr->dataNum)
    {
        pMygr->hdr.state |= MYGR_DRAW;
        pMygr->dataValid[index] = DATA_INVALID;
    }
}

inline int isInsideDNDR (int x, int y, rect dndr)
{
    if (x >= dndr.left && x <= dndr.right && y >= dndr.top && y <= dndr.bottom)
        return 1;
    else
        return 0;
}