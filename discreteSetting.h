/* 
 * File:   discreteSetting.h
 * Author: Davide
 *
 * Created on 31 luglio 2013, 16.02
 */

#ifndef DISCRETESETTING_H
#define	DISCRETESETTING_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <Graphics/GOL.h>
#include "GenericTypeDefs.h"
#include "stdTypes.h"

/*********************************************************************
* Object States Definition:
*********************************************************************/
#define DISCRETESETTING_FOCUSED             0x0001  // Bit for focus state.
#define DISCRETESETTING_DISABLED            0x0002  // Bit for disabled state.

#define DISCRETESETTING_NEXT_PRESSED        0x0004  // Bit for next-pressed state.
#define DISCRETESETTING_PREV_PRESSED        0x0008  // Bit for prev-pressed state.

#define DISCRETESETTING_STRING              0x0010  // Bit for string type setting.
#define DISCRETESETTING_NUMERIC             0x0020  // Bit for numeric type setting.

#define DISCRETESETTING_NAME_CENTER         0x0040  // Bit for centred name.
#define DISCRETESETTING_VALUE_CENTER        0x0080  // Bit for centred value.

#define DISCRETESETTING_DRAW                0xfc00  // Bit for draw state.

#define STRVALUE_MAX_LEN                    30      // Max string size.

#define DISCRETESETTING_MSG_VALUE_INC       100     // Discretesetting value increment
#define DISCRETESETTING_MSG_VALUE_DEC       101     // Discretesetting value decrement
#define DISCRETESETTING_MSG_NXT_OBJ         102     // Discretesetting switch to next object
#define DISCRETESETTING_MSG_PRV_OBJ         103     // Discretesetting switch to previous object
#define DISCRETESETTING_MSG_FOCUS_REQ       104     // Discretesetting focus requested
#define DISCRETESETTING_MSG_RESET           105     // Discretesetting reset to normal

typedef struct
{
    OBJ_HEADER  hdr;        // Generic header for all Objects (see OBJ_HEADER).

    strValue_t name;        // Nome dell'impostazione

    int namePix;            // Spazio dedicato al nome (in pixel)

    int actIndex;           // Attuale indice all'interno della collezione di stringhe
    int strValuesNum;       // Numero di stringhe contenute nella collezione
    strValue_t *strVec;     // Collezione di stringhe

    double actValue;        // Attuale valore numerico
    double span;            // Span
    double minValue;        // Minimo valore numerico
    double maxValue;        // Massimo valore numerico

    strValue_t msUnit;      // Unità di misura
} DISCRETESETTING;


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
        );

/*
 * Traduzione messaggi
 */
WORD    discreteSettingTranslateMsg(void *pObj, GOL_MSG *pMsg);

/*
 * Comportamento di default ai messaggi
 */
void    discreteSettingMsgDefault(WORD translatedMsg, void *pObj, GOL_MSG *pMsg);

/*
 * Disegna sullo schermo il controllo
 */
WORD discreteSettingDraw(void *pObj);

/*
 * Libera la memoria occupata dall'oggetto
 */
void discreteSettingFreeObj (void *pObj);

/*
 * Incrementa il valore del controllo
 *
 * input:
 *  - pDS: puntatore al controllo
 */
void discreteSettingIncValue (DISCRETESETTING *pDS);

/*
 * Decrementa il valore del controllo
 * 
 * input:
 *  - pDS: puntatore al controllo
 */
void discreteSettingDecValue (DISCRETESETTING *pDS);

/*
 * Setta il valore alla nuova quantità passata.
 * I valori verranno adattati automaticamente ai limiti.
 * 
 * input:
 *  - pDS: puntatore all'oggetto
 *  - newVal: nuovo valore
 */
void discreteSettingSetValue (DISCRETESETTING *pDS, double newVal);

/*
 * Setta l'indice alla nuova quantità passata.
 * I valori verranno adattati automaticamente ai limiti.
 *
 * input:
 *  - pDS: puntatore all'oggetto
 *  - newInd: nuovo valore
 */
void discreteSettingSetIndex (DISCRETESETTING *pDS, int newInd);

/*
 * Ritorna l'attuale valore memorizzato nel controllo
 * 
 * input:
 *  - pDS: puntatore al controllo
 * 
 * output:
 *  - l'attuale valore memorizzato nel controllo
 */
double discreteSettingGetValue (DISCRETESETTING *pDS);

/*
 * Ritorna l'attuale indice memorizzato nel controllo
 *
 * input:
 *  - pDS: puntatore al controllo
 *
 * output:
 *  - l'attuale indice memorizzato nel controllo
 */
int discreteSettingGetIndex (DISCRETESETTING *pDS);

#ifdef	__cplusplus
}
#endif

#endif	/* DISCRETESETTING_H */

