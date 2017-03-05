/* 
 * File:   settingsSaving.h
 * Author: Davide
 *
 * Created on 13 agosto 2013, 17.13
 */

#ifndef SETTINGSSAVING_H
#define	SETTINGSSAVING_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdTypes.h"
#include "globalSettings.h"

    typedef unsigned int settingSize_t;

    /*
     * Inserisce un impostazione nel modulo che si occupa della gestione delle stesse
     *
     * input:
     *  - sID: id dell'impostazione (unico, l'unicità deve essere garantita dall'utente)
     *  - sz: dimensione in byte dell'impostazione
     *  - setting: puntatore all'impostazione (sarà poi copiata nel sistema)
     *
     * output:
     *  - TRUE_B se l'inserimento è andato a buon fine, FALSE_B altrimenti
     */
    bool_t addSetting (settingID_t sID, settingSize_t sz, const void *setting);


#ifdef	__cplusplus
}
#endif

#endif	/* SETTINGSSAVING_H */

