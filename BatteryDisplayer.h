/* 
 * File:   BatteryDisplayer.h
 * Author: Davide
 *
 * Created on 22 luglio 2014, 13.39
 */

#ifndef BATTERYDISPLAYER_H
#define	BATTERYDISPLAYER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <Graphics/GOL.h>
    #include "GenericTypeDefs.h"
#include "stdTypes.h"

/*********************************************************************
* Object States Definition:
*********************************************************************/
    #define BD_FOCUSED     0x0001  // Bit for focus state.
    #define BD_DISABLED    0x0002  // Bit for disabled state.
    #define BD_PRESSED     0x0004  // Bit for press state.

    #define BD_DRAW 0xfc00
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
    percentage_t batteryVal;
    rect doNotDrawArea;
} BATTERYDISPLAYER;

/*
 * Crea un nuovo visualizzatore di stato batteria
 */



BATTERYDISPLAYER  *BatteryDisplayerCreate
        (
            WORD        ID,
            SHORT       left,
            SHORT       top,
            SHORT       right,
            SHORT       bottom,
            WORD        state,
            percentage_t batteryVal,
            GOL_SCHEME  *pScheme
        );

/*
 * Traduzione messaggi. Non implementata al momento.
 */
WORD    BatteryDisplayerTranslateMsg(void *pObj, GOL_MSG *pMsg);

/*
 * Comportamento di default ai messaggi. Non implementata al momento.
 */
void    BatteryDisplayerMsgDefault(WORD translatedMsg, void *pObj, GOL_MSG *pMsg);

/*
 * Disegna sullo schermo la batteria
 */
WORD BatteryDisplayerDraw(void *pObj);

/*
 * Imposta la percentuale
 */
void BatteryDisplayer_setBatteryValue (BATTERYDISPLAYER *pBD, percentage_t perc);

/*
 * Restituisce la percentuale
 */
percentage_t BatteryDisplayer_getBatteryBatteryValue (BATTERYDISPLAYER *pBD);

#ifdef	__cplusplus
}
#endif

#endif	/* BATTERYDISPLAYER_H */

