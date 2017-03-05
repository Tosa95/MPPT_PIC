/* 
 * File:   menuEntry.h
 * Author: Davide
 *
 * Created on 1 agosto 2013, 20.09
 */

#ifndef MENUENTRY_H
#define	MENUENTRY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <Graphics/GOL.h>
#include "GenericTypeDefs.h"
#include "stdTypes.h"

/*********************************************************************
* Object States Definition:
*********************************************************************/
#define MENUENTRY_FOCUSED               0x0001  // Bit for focus state.
#define MENUENTRY_DISABLED              0x0002  // Bit for disabled state.

#define MENUENTRY_PRESSED               0x0004  // Bit for next-pressed state.

#define MENUENTRY_CENTER                0x0040  // Bit for centred name.

#define MENUENTRY_DRAW                  0xfc00  // Bit for draw state.

#define STRVALUE_MAX_LEN                20      // Max string size.

#define MENUENTRY_MSG_PRESSED           200     // Menuentry value increment
#define MENUENTRY_MSG_NXT_OBJ           202     // Menuentry switch to next object
#define MENUENTRY_MSG_PRV_OBJ           203     // Menuentry switch to previous object
#define MENUENTRY_MSG_FOCUS_REQ         204     // Menuentry focus requested
#define MENUENTRY_MSG_RESET             205     // Menuentry reset to normal

typedef struct
{
    OBJ_HEADER  hdr;        // Generic header for all Objects (see OBJ_HEADER).

    strValue_t name;        // Nome dell'impostazione

} MENUENTRY;


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
        );

/*
 * Traduzione messaggi
 */
WORD    menuEntryTranslateMsg(void *pObj, GOL_MSG *pMsg);

/*
 * Comportamento di default ai messaggi
 */
void    menuEntryMsgDefault(WORD translatedMsg, void *pObj, GOL_MSG *pMsg);

/*
 * Disegna sullo schermo il controllo
 */
WORD    menuEntryDraw(void *pObj);


#ifdef	__cplusplus
}
#endif

#endif	/* MENUENTRY_H */

