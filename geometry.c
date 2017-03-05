#include "geometry.h"

/*
 * Verifica che un punto si trovi all'interno dell'area specificata
 *
 * input:
 *  - p: il punto di cui verificare l'appartenenza all'area
 *  - a: l'area
 *
 * output:
 *  - TRUE_B se il punto è all'interno del'area, FALSE_B altrimenti
 */
bool_t isInsideArea (iPoint_t p, iRect_t a)
{
    if (p.x >= a.topLeft.x && p.x <= a.bottomRight.x && p.y >= a.topLeft.y && p.y <= a.bottomRight.y)
        return TRUE_B;
    else
        return FALSE_B;
}

/*
 * Ritorna un punto con le coordinate specificate
 *
 * input:
 *  - x: l'ascissa
 *  - y: l'ordinata
 *
 * output:
 *  - il punto creato
 */
iPoint_t getIPoint (int x, int y)
{
iPoint_t ris;

    ris.x = x;
    ris.y = y;

    return ris;
}

/*
 * Ritorna un rettangolo dati i punti superiore sx ed inferiore dx
 *
 * input:
 *  - topLeft: punto superiore sx
 *  - bottomRight: punto inferiore dx
 *
 * output:
 *  - il rettangolo creato
 */
iRect_t getIRect (iPoint_t topLeft, iPoint_t bottomRight)
{
iRect_t ris;

    ris.topLeft = topLeft;
    ris.bottomRight = bottomRight;

    return ris;
}