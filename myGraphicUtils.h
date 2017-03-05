/* 
 * File:   myGraphicUtils.h
 * Author: Davide
 *
 * Created on 1 agosto 2013, 16.46
 */

#ifndef MYGRAPHICUTILS_H
#define	MYGRAPHICUTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdTypes.h"
#include "geometry.h"
#include "Graphics/GOL.h"
#include "Graphics/Primitive.h"

    typedef enum
    {
        TEXT_CENTRED,
        TEXT_RIGHT,
        TEXT_LEFT
    }txtAlignement_t;

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
    iPoint_t getTextPoint (iRect_t area, constString_t txt, void *pFont, txtAlignement_t txtAlign);

    typedef enum
    {
        ARROW_UP,
        ARROW_DOWN,
        ARROW_LEFT,
        ARROW_RIGHT
    }arrowOrientation_t;

    /*
     * Disegna un pulsante con freccia
     *
     * input:
     *  - area: area del pulsante
     *  - drawEdge: TRUE_B se si vuole disegnare il contorno, FALSE_B altrimenti
     *  - aO: orientamento della freccia
     */
    void drawArrowButton (iRect_t area, bool_t drawEdge, bool_t fillArrow, arrowOrientation_t aO);

    /*
     * Riempie l'area specificata con il colore specificato
     *
     * input:
     *  - area: l'area da riempire
     *  - cl: colore con cui riempire l'area
     */
    void fillRectArea (iRect_t area, GFX_COLOR cl);

    /*
     * Riempie tutto il display con il colore desiserato
     *
     * input:
     *  - cl: colore con cui riempire il display
     */
    void clearDisplayU (GFX_COLOR cl);

    /*
     * Riempie un area dello schermo del colore specificato. I contorni dell'area devono essere già stati disegnati a schermo.
     *
     * input:
     *  - p: un qualsiasi punto interno all'area da colorare
     *  - cl: colore
     */
    void fillArea (iPoint_t p, GFX_COLOR cl);

#ifdef	__cplusplus
}
#endif

#endif	/* MYGRAPHICUTILS_H */

