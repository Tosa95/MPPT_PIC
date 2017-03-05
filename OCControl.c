#include <xc.h>
#include "OCControl.h"
#include "GeneralTimers.h"

typedef volatile unsigned int OCR_t;
typedef volatile unsigned int OCRS_t;

static OCCONBITS *cons[4] = {(OCCONBITS*)&OC1CONbits, (OCCONBITS*)&OC2CONbits, (OCCONBITS*)&OC3CONbits, (OCCONBITS*)&OC4CONbits};
static OCR_t *OCRs[4] = {(OCR_t*)&OC1R, (OCR_t*)&OC2R, (OCR_t*)&OC3R, (OCR_t*)&OC4R};
static OCRS_t *OCRSs[4] = {(OCR_t*)&OC1RS, (OCR_t*)&OC2RS, (OCR_t*)&OC3RS, (OCR_t*)&OC4RS};

/*
 * Ritorna il timer utilizzato dal modulo OC
 */
timerID_t getTimerUsed (OCID_t id);

/*
 * Inizializza il modulo OC
 */
void initOC (OCID_t id, OCMode_t m, timerID_t tid, OCIdleBehaviour_t idl)
{
    cons[id]->OCM = m;

    cons[id]->OCTSEL = tid==TIMER3_ID?1:0;

    cons[id]->OCSIDL = idl;
}

/*
 * Ritorna il timer utilizzato dal modulo OC
 */
timerID_t getTimerUsed (OCID_t id)
{
    return cons[id]->OCTSEL == 1?TIMER3_ID:TIMER2_ID;
}

/*
 * Imposta il registro OCR del modulo al tempo desiderato
 */
void setOCR (OCID_t id, timeUS_t t)
{
timerID_t tid = getTimerUsed (id);

    *OCRs[id] = getRequestedSteps(tid, t);
}

/*
 * Imposta il registro OCRS del modulo al tempo desiderato
 */
void setOCRS (OCID_t id, timeUS_t t)
{
timerID_t tid = getTimerUsed (id);

    *OCRSs[id] = getRequestedSteps(tid, t);
}

/*
 * Imposta il modulo OC per fornire un'onda quadra con il Duty Cycle desiderato,
 * parte dallo stato alto
 */
void setOCDutyCycle (OCID_t id, percentage_t p)
{
timerID_t tid = getTimerUsed (id);
timeUS_t period = getTimerInterval(tid);

    setOCR(id, 0);

    setOCRS(id, getValueFromPercentage(0, period, p));
}

/*
 * Imposta il modulo OC per fornire un'onda quadra con il Duty Cycle desiderato,
 * parte dallo stato basso
 */
void setOCDutyCycleReverse (OCID_t id, percentage_t p)
{
timerID_t tid = getTimerUsed (id);
timeUS_t period = getTimerInterval(tid);

    setOCR(id, getValueFromPercentage(0, period, 100-p));

    setOCRS(id, period);
}