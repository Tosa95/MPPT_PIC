/* 
 * File:   geometry.h
 * Author: Davide
 *
 * Created on 1 agosto 2013, 11.40
 */

#ifndef GEOMETRY_H
#define	GEOMETRY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "basicTypes.h"

    typedef struct
    {
       int x;
       int y;
    }iPoint_t;

    typedef struct
    {
        iPoint_t topLeft;
        iPoint_t bottomRight;
    }iRect_t;

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
    bool_t isInsideArea (iPoint_t p, iRect_t a);

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
    iPoint_t getIPoint (int x, int y);

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
    iRect_t getIRect (iPoint_t topLeft, iPoint_t bottomRight);

#ifdef	__cplusplus
}
#endif

#endif	/* GEOMETRY_H */

