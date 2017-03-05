/* 
 * File:   MyGraph.h
 * Author: Davide
 *
 * Created on 14 giugno 2013, 16.04
 */

#ifndef MYGRAPH_H
#define	MYGRAPH_H

#ifdef	__cplusplus
extern "C" {
#endif


    #include <Graphics/GOL.h>
    #include "GenericTypeDefs.h"

/*********************************************************************
* Object States Definition:
*********************************************************************/
    #define MYGR_FOCUSED     0x0001  // Bit for focus state.
    #define MYGR_DISABLED    0x0002  // Bit for disabled state.
    #define MYGR_PRESSED     0x0004  // Bit for press state.

    #define MYGR_DRAW 0xfc00
    #define MYGR_OPTIMIZED 0x01

    #define DATA_VALID 1
    #define DATA_INVALID 0
/*********************************************************************
* Overview: Defines the parameters required for a button Object.
* 			The following relationships of the parameters determines
*			the general shape of the button:
* 			1. Width is determined by right - left.
*			2. Height is determined by top - bottom.
*			3. Radius - specifies if the button will have a rounded
*						edge. If zero then the button will have
*						sharp (cornered) edge.
*			4. If 2*radius = height = width, the button is a circular button.
*
*********************************************************************/
typedef struct
{
    int left, top, right, bottom;
}rect;

typedef struct
{
    OBJ_HEADER  hdr;        // Generic header for all Objects (see OBJ_HEADER).
    int *dataSerie;
    int dataNum;
    int first;
    int last;
    int barPos;
    int maxValue;
    char *dataValid;
    rect doNotDrawArea;
} MYGRAPH;

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
        );

/*
 * Traduzione messaggi. Non implementata al momento.
 */
WORD    MygrTranslateMsg(void *pObj, GOL_MSG *pMsg);

/*
 * Comportamento di default ai messaggi. Non implementata al momento.
 */
void    MygrMsgDefault(WORD translatedMsg, void *pObj, GOL_MSG *pMsg);

/*
 * Disegna sullo schermo il grafico
 */
WORD MygrDraw(void *pObj);

/*
 * Setta la posizione del cursore
 */
void setBarPos (MYGRAPH *pMygr, int val);

/*
 * Ritorna la posizione del cursore
 */
int getBarPos (MYGRAPH *pMygr);

/*
 * Invalida l'intero grafico
 */
void invalidateMyGraph (MYGRAPH *pMygr);

/*
 * Invalida una colonna
 */
void invalidateColumn (MYGRAPH *pMygr, int index);
#endif	/* MYGRAPH_H */

