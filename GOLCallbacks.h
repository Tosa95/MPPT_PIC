/* 
 * File:   GOLCallbacks.h
 * Author: Davide
 *
 * Created on 1 agosto 2013, 20.52
 */

#ifndef GOLCALLBACKS_H
#define	GOLCALLBACKS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Graphics/GOL.h"

    typedef WORD (*GOLMsgCallback_t)( WORD objMsg, OBJ_HEADER * pObj, GOL_MSG * pMsg);

    /*
     * Imposta la funzione da chiamare quando viene generato l'evento GOLMsg
     *
     * input:
     *  - pGOLMsgCallback: puntatore alla funzione da chiamare
     */
    void setGOLMsgCallback (GOLMsgCallback_t pGOLMsgCallback);


#ifdef	__cplusplus
}
#endif

#endif	/* GOLCALLBACKS_H */

