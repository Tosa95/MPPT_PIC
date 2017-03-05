#include "Graphics/GOL.h"
#include "GOLCallbacks.h"
#include <stdlib.h>
#include "SPIDisplay.h"

GOLMsgCallback_t mcb = NULL;

WORD GOLDrawCallback ()
{

    return 1;
}

WORD GOLMsgCallback( WORD objMsg, OBJ_HEADER * pObj, GOL_MSG * pMsg)
{
    if (mcb != NULL)
        return (mcb (objMsg, pObj, pMsg));

    return 1;
}

/*
 * Imposta la funzione da chiamare quando viene generato l'evento GOLMsg
 *
 * input:
 *  - pGOLMsgCallback: puntatore alla funzione da chiamare
 */
void setGOLMsgCallback (GOLMsgCallback_t pGOLMsgCallback)
{
    mcb = pGOLMsgCallback;
}