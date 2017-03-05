#include "myGraphicUtils.h"
#include "Graphics/GOL.h"
#include "Graphics/DisplayDriver.h"
#include "stdlib.h"
#include "SPIDisplay.h"

#define DEFAULT_TXT_BORDER 3

typedef struct _iPointStackNode_t
{
   iPoint_t p;
   struct _iPointStackNode_t *next;
}iPointStackNode_t;

typedef iPointStackNode_t *iPointStack_t;

/*
 * Ritorna un nuovo stack
 */
static iPointStack_t getNew_iPointStack ();

/*
 * Inserisce un punto nello stack
 * 
 * input:
 *  - st: stack
 *  - p: punto da inserire
 */
static void push_iPointStack (iPointStack_t *st, iPoint_t p);

/*
 * Ritorna il punto in cima allo stack
 * 
 * input:
 *  - st: stack
 * 
 * output:
 *  - il puto in cima allo stack
 */
static iPoint_t pop_iPointStack (iPointStack_t *st);

/*
 * Verifica che lo stack sia vuoto
 *
 * input:
 *  - st: stack
 *
 * output:
 *  - TRUE_B se lo stack è vuoto, FALSE_B altrimenti
 */
static bool_t empty_iPointStack (iPointStack_t st);

/*
 * Ritorna il punto dal quale iniziare a scrivere il testo.
 *
 * input:
 *  - area: area nella quale deve comparire il testo
 *  - txt: il testo da scrivere
 *  - pFont: il font da utilizzare
 *  - txtAlign: l'allineamento del testo
 *
 * output:
 *  - punto da cui iniziare a scrivere
 */
iPoint_t getTextPoint (iRect_t area, constString_t  txt, void *pFont, txtAlignement_t txtAlign)
{
iPoint_t ris;
SHORT tW, tH, aH, aW;

    tH = GetTextHeight (pFont);
    tW = GetTextWidth  (txt, pFont);
    
    aH = area.bottomRight.y - area.topLeft.y;
    aW = area.bottomRight.x - area.topLeft.x;
    
    switch (txtAlign)
    {
        case TEXT_CENTRED:
            
            ris.x = area.topLeft.x + ((aW/2) - tW/2);
            ris.y = area.topLeft.y + ((aH/2) - tH/2);
            
            break;

        case TEXT_LEFT:

            ris.x = area.topLeft.x + DEFAULT_TXT_BORDER;
            ris.y = area.topLeft.y + ((aH/2) - tH/2);

            break;

        case TEXT_RIGHT:

            ris.x = area.bottomRight.x - (DEFAULT_TXT_BORDER + tW);
            ris.y = area.topLeft.y + ((aH/2) - tH/2);

            break;
    }

    return ris;
        
}

/*
 * Disegna un pulsante con freccia
 *
 * input:
 *  - area: area del pulsante
 *  - drawEdge: TRUE_B se si vuole disegnare il contorno, FALSE_B altrimenti
 *  - aO: orientamento della freccia
 */
void drawArrowButton (iRect_t area, bool_t drawEdge, bool_t fillArrow, arrowOrientation_t aO)
{
SHORT arrowPoints[8];
SHORT w, h;

    w = area.bottomRight.x - area.topLeft.x;
    h = area.bottomRight.y - area.topLeft.y;

    switch (aO)
    {
        case ARROW_UP:

            arrowPoints[0] = area.topLeft.x + w/4;
            arrowPoints[1] = area.topLeft.y + (h*3)/4;
            arrowPoints[2] = area.topLeft.x + (w*3)/4;
            arrowPoints[3] = area.topLeft.y + (h*3)/4;
            arrowPoints[4] = area.topLeft.x + w/2;
            arrowPoints[5] = area.topLeft.y + h/4;
            arrowPoints[6] = arrowPoints[0];
            arrowPoints[7] = arrowPoints[1];

            break;

        case ARROW_DOWN:

            arrowPoints[0] = area.topLeft.x + (w*3)/4;
            arrowPoints[1] = area.topLeft.y + h/4;
            arrowPoints[2] = area.topLeft.x + w/2;
            arrowPoints[3] = area.topLeft.y + (h*3)/4;
            arrowPoints[4] = area.topLeft.x + w/4;
            arrowPoints[5] = area.topLeft.y + h/4;
            arrowPoints[6] = arrowPoints[0];
            arrowPoints[7] = arrowPoints[1];

            break;

        case ARROW_LEFT:

            arrowPoints[0] = area.topLeft.x + (w*3)/4;
            arrowPoints[1] = area.topLeft.y + (h*3)/4;
            arrowPoints[2] = area.topLeft.x + w/4;
            arrowPoints[3] = area.topLeft.y + h/2;
            arrowPoints[4] = area.topLeft.x + (w*3)/4;
            arrowPoints[5] = area.topLeft.y + h/4;
            arrowPoints[6] = arrowPoints[0];
            arrowPoints[7] = arrowPoints[1];

            break;

        case ARROW_RIGHT:

            arrowPoints[0] = area.topLeft.x + w/4;
            arrowPoints[1] = area.topLeft.y + h/4;
            arrowPoints[2] = area.topLeft.x + (w*3)/4;
            arrowPoints[3] = area.topLeft.y + h/2;
            arrowPoints[4] = area.topLeft.x + w/4;
            arrowPoints[5] = area.topLeft.y + (h*3)/4;
            arrowPoints[6] = arrowPoints[0];
            arrowPoints[7] = arrowPoints[1];

            break;
    }

    DrawPoly (4, arrowPoints);

    if (drawEdge)
        Rectangle(area.topLeft.x, area.topLeft.y, area.bottomRight.x, area.bottomRight.y);

    if (fillArrow)
        fillArea(getIPoint(area.topLeft.x + w/2, area.topLeft.y + h/2), 0x00);

}

/*
 * Riempie l'area specificata con il colore specificato
 *
 * input:
 *  - area: l'area da riempire
 *  - cl: colore con cui riempire l'area
 */
void fillRectArea (iRect_t area, GFX_COLOR cl)
{
    SHORT i, j;

    SetColor (cl);

    for (i = area.topLeft.y; i <= area.bottomRight.y; i++)
    {
        for (j = area.topLeft.x; j <= area.bottomRight.x; j++)
        {
            PutPixel(j, i);
        }
    }
}

/*
 * Riempie tutto il display con il colore desiserato
 *
 * input:
 *  - cl: colore con cui riempire il display
 */
void clearDisplayU (GFX_COLOR cl)
{
iRect_t r;

    r = getIRect (getIPoint(0, 0), getIPoint(GetMaxX(), GetMaxY()));

    fillRectArea (r, cl);
}

/*
 * Riempie un area dello schermo del colore specificato. I contorni dell'area devono essere già stati disegnati a schermo.
 * 
 * input:
 *  - p: un qualsiasi punto interno all'area da colorare
 *  - cl: colore
 */
void fillArea (iPoint_t p, GFX_COLOR cl);

/*
 * Riempie un area dello schermo del colore specificato. I contorni dell'area devono essere già stati disegnati a schermo.
 *
 * input:
 *  - p: un qualsiasi punto interno all'area da colorare
 *  - cl: colore
 */
void fillArea (iPoint_t p, GFX_COLOR cl)
{
iPointStack_t st;
GFX_COLOR clTS;
iPoint_t actP;

    st = getNew_iPointStack();

    clTS = GetPixel((SHORT)p.x, (SHORT)p.y);

    push_iPointStack (&st, p);

    while (!empty_iPointStack (st))
    {
        actP = pop_iPointStack(&st);

        if (GetPixel(actP.x, actP.y) == clTS && actP.x >= 0 && actP.x <= GetMaxX() && actP.y >= 0 && actP.y <= GetMaxY())
        {
            SetColor (cl);
            PutPixel(actP.x, actP.y);

            push_iPointStack (&st, getIPoint(actP.x-1, actP.y));
            push_iPointStack (&st, getIPoint(actP.x+1, actP.y));
            push_iPointStack (&st, getIPoint(actP.x, actP.y-1));
            push_iPointStack (&st, getIPoint(actP.x, actP.y+1));
        }
    }
}

/*
 * Inserisce un punto nello stack
 * 
 * input:
 *  - st: stack
 *  - p: punto da inserire
 */
static void push_iPointStack (iPointStack_t *st, iPoint_t p)
{
    iPointStackNode_t *newNode;
    
    newNode = (iPointStackNode_t *)malloc(sizeof(iPointStackNode_t));

    newNode->p = p;
    newNode->next = (*st);
    (*st) = newNode;
}

/*
 * Ritorna un nuovo stack
 */
static iPointStack_t getNew_iPointStack ()
{
    return 0;
}

/*
 * Ritorna il punto in cima allo stack
 *
 * input:
 *  - st: stack
 *
 * output:
 *  - il puto in cima allo stack
 */
static iPoint_t pop_iPointStack (iPointStack_t *st)
{
iPoint_t ris;
iPointStackNode_t *tmp;

    if ((*st) != NULL)
    {
        ris = (*st)->p;
        tmp = (*st);
        (*st) = tmp->next;
        free(tmp);
    }

    return ris;
}

/*
 * Verifica che lo stack sia vuoto
 *
 * input:
 *  - st: stack
 *
 * output:
 *  - TRUE_B se lo stack è vuoto, FALSE_B altrimenti
 */
static bool_t empty_iPointStack (iPointStack_t st)
{
    if (st == NULL)
        return TRUE_B;
    else
        return FALSE_B;
}