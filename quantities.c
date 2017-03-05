#include <stdlib.h>
#include <string.h>

#include "quantities.h"

#include "battery_graphic.h"
#include "pwms_graphic.h"
#include "pwmsTimeControl_graphic.h"
#include "pwmStabilityTest_graphic.h"
#include "console.h"

//TODO: reconfigure
quantity_t qs[Q_NUM];

typedef struct
{
    qId_t actQ;
}qState_t;

qState_t st;

/*
 * Inizializza il modulo per la misurazione semplificata di più grandezze
 */
void initQuantities ()
{
    st.actQ = BATTERY_QID;

    qs[0].ID = BATTERY_QID;
    strcpy (qs[0].name, "BATT");
    qs[0].init = batteryMeasurementInit;
    qs[0].mainMeasurementLoop = batteryMeasurementMainLoopBody;
    qs[0].stop = batteryMeasurementStop;

    qs[1].ID = PWMS_QID;
    strcpy (qs[1].name, "PWMs");
    qs[1].init = pwmsMeasurementInit;
    qs[1].mainMeasurementLoop = pwmsMeasurementMainLoopBody;
    qs[1].stop = pwmsMeasurementStop;

    qs[2].ID = PWMS_TIME_CONTROL_QID;
    strcpy (qs[2].name, "PWMs_TC");
    qs[2].init = pwmsTimeControlMeasurementInit;
    qs[2].mainMeasurementLoop = pwmsTimeControlMeasurementMainLoopBody;
    qs[2].stop = pwmsTimeControlMeasurementStop;

    qs[3].ID = PWMS_STABILITY_TEST_QID;
    strcpy (qs[3].name, "PWMs_ST");
    qs[3].init = pwmStabilityTestMeasurementInit;
    qs[3].mainMeasurementLoop = pwmStabilityTestMeasurementMainLoopBody;
    qs[3].stop = pwmStabilityTestMeasurementStop;

    qs[4].ID = CONSOLE_QID;
    strcpy (qs[4].name, "CONS");
    qs[4].init = consoleMeasurementInit;
    qs[4].mainMeasurementLoop = consoleMeasurementMainLoopBody;
    qs[4].stop = consoleMeasurementStop;
}

/*
 * Ritorna l'attuale grandezza misurata
 * 
 * output:
 *  - puntatore alla grandezza attualmente desiderata
 */
quantity_t *getActQuantity ()
{
    return &qs[st.actQ];
}

/*
 * Imposta l'attuale grandezza misurata
 *
 * input:
 *  - qId: id della grandezza da misurare
 */
void setActQuantity (qId_t qId)
{
    if (qId >= Q_NUM) qId = 0;
    if (qId < 0) qId = Q_NUM - 1;
    getActQuantity() -> stop();
    st.actQ = qId;
}

/*
 * Inizializza la quantità attuale
 */
void initActQuantity ()
{
    getActQuantity() -> init();
}

/*
 * Va alla prossima quantità
 */
void goToNextQuantity ()
{
    setActQuantity(getActQuantity()->ID + 1);
}

/*
 * Va alla precedente quantità
 */
void goToPreviousQuantity ()
{
    setActQuantity(getActQuantity()->ID - 1);
}