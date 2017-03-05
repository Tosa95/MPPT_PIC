/* 
 * File:   menuLayoutManager.h
 * Author: Davide
 *
 * Created on 28 agosto 2014, 18.16
 */

#ifndef MENULAYOUTMANAGER_H
#define	MENULAYOUTMANAGER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdTypes.h"
#include "Graphics/GOL.h"
#include "Graphics/StaticText.h"

    /*
     * ATTENZIONE: In questo modulo le stringhe non vengono copiate, percui
     * passare solo stringhe che restano definite durante l'intero utilizzo
     * del menu
     */

    typedef int entryId_t;

    typedef void (*menuClbk_t)(entryId_t eid);

    typedef struct
    {
        strValue_t name;

        STATICTEXT *title;

        OBJ_HEADER **gObjs;
        menuClbk_t *clbks;
        int objNum;

        int upperId;
        int actId;
        int lowerId;

        GOL_SCHEME *pScheme;
    }menuLayoutManager_t;

    /*
     * Ritorna un nuovo menu
     */
    menuLayoutManager_t *getMenu (strValue_t name, int objNum);

    /*
     * Distrugge un menu
     */
    void destroyMenu (menuLayoutManager_t *mlm);

    /*
     * Inserisce un controllo di tipo stringa
     */
    void addStringEntry (menuLayoutManager_t *mlm, entryId_t eid, string_t *valuesSet, int valuesNum, int iValue, string_t name);

    /*
     * Inserisce un controllo di tipo numerico
     */
    void addNumericEntry (menuLayoutManager_t *mlm, entryId_t eid, double minValue, double maxValue, double iValue, double step, string_t unit, string_t name);

    /*
     * Inserisce un controllo di tipo azione
     */
    void addActionEntry (menuLayoutManager_t *mlm, entryId_t eid, string_t name, menuClbk_t clbk);

    /*
     * Disegna a schermo il menu
     */
    void drawMenu (menuLayoutManager_t *mlm);

    /*
     * Iscrive il menu al callback di GOL (un menu alla volta)
     */
    void registerForCallback (menuLayoutManager_t *mlm);

    /*
     * Una volta inseriti i controlli, crea l'interfaccia
     */
    void createInterface (menuLayoutManager_t *mlm);

    /*
     * Ritorna il valore di un controllo numerico
     */
    double getNumericEntry (menuLayoutManager_t *mlm, entryId_t eid);

    /*
     * Ritorna il valore di un controllo dtringa
     */
    int getStringEntry (menuLayoutManager_t *mlm, entryId_t eid);

#ifdef	__cplusplus
}
#endif

#endif	/* MENULAYOUTMANAGER_H */

