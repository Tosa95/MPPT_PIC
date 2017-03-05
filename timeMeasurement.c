#include "timer4.h"

#include "timeMeasurement.h"


#define MEASUREMENT_MAX_NUM 20

#define STOP_COUNTING TIMER4_INSTANT_STOP
#define RESTART_COUNTING TIMER4_INSTANT_RESET; TIMER4_INSTANT_START
#define INIT_COUNTER setTimer4Interval(50000); /*setTimer4Callback(tmrClbk);*/ TIMER4_INSTANT_START
#define GET_COUNTER_TIME timer4ElaspedTime()
#define COUNTER_MAX_SIZE getTimer4MaxTime ()

typedef enum {FREE, BUSY} measurementState_t;

typedef timeUS_t timeMeasurement_t;

timeUS_t measurements [MEASUREMENT_MAX_NUM];
measurementState_t measurementsState [MEASUREMENT_MAX_NUM];

/*
 * Aggiorna le misurazioni
 */
void updateMeasurements ();

/*
 * Ritorna l'indice di una misurazione libera
 *
 * output:
 *  - indice della prima misurazione libera o MEASUREMENT_NO_SPACE_ERR
 */
timeMeasurementID_t getFreeMeasurement ();

/*
 * Inizializza una misurazione
 *
 * input:
 *  - id: id della misurazione da inizializzare
 */
void initMeasurement (timeMeasurementID_t id);

/*
 * Richiamata in caso di overconteggio
 */
void tmrClbk ();


/*
 * Inizializza il modulo che effettua le misurazioni temporali
 */
void initTimeMeasurement ()
{
timeMeasurementID_t i;

    for (i = 0; i < MEASUREMENT_MAX_NUM; i++)
    {
        measurementsState[i] = FREE;
    }

    INIT_COUNTER;
}

/*
 * Inizia una nuova misurazione
 *
 * output:
 *  - id della misurazione (MEASUREMENT_NO_SPACE_ERR se non c'è
 *    spazio per la misurazione)
 */
timeMeasurementID_t startTimeMeasurement ()
{
timeMeasurementID_t ris;

    STOP_COUNTING;
    
    updateMeasurements();

    ris = getFreeMeasurement();
    
    initMeasurement (ris);
    
    RESTART_COUNTING;
    
    return ris;
}

/*
 * Ritorna il tempo trascorso dall'attivazione della misurazione
 * 
 * input:
 *  - id: l'id della misurazione
 * 
 * output:
 *  - tempo trascorso dall'attivazione della misurazione (uS)
 */
timeUS_t getElaspedTime (timeMeasurementID_t id)
{
    STOP_COUNTING;
    
    updateMeasurements();
    
    return measurements[id];
    
    RESTART_COUNTING;
}

/*
 * Fa ripartire da 0 una misurazione
 * 
 * input:
 *  - id: l'id della misurazione
 */
void restartMeasurement (timeMeasurementID_t id)
{
    STOP_COUNTING;
    
    updateMeasurements();
    
    RESTART_COUNTING;
    
    measurements[id] = 0;
}

/*
 * Libera una misurazione
 * 
 * input:
 *  - id: l'id della misurazione
 */
void freeMeasurement (timeMeasurementID_t id)
{
    STOP_COUNTING;
    
    updateMeasurements();

    measurementsState[id] = FREE;

    RESTART_COUNTING;
}





/*
 * Ritorna l'indice di una misurazione libera
 *
 * output:
 *  - indice della prima misurazione libera o MEASUREMENT_NO_SPACE_ERR
 */
timeMeasurementID_t getFreeMeasurement ()
{
timeMeasurementID_t i;

    for (i = 0; i < MEASUREMENT_MAX_NUM; i++)
    {
        if (measurementsState[i] == FREE) return i;
    }

    return MEASUREMENT_NO_SPACE_ERR;
}

/*
 * Inizializza una misurazione
 *
 * input:
 *  - id: id della misurazione da inizializzare
 */
void initMeasurement (timeMeasurementID_t id)
{
    if (measurementsState[id] == FREE && id != MEASUREMENT_NO_SPACE_ERR)
    {
        measurementsState[id] = BUSY;
        measurements[id] = 0;
    }
}

/*
 * Aggiorna le misurazioni
 */
void updateMeasurements ()
{
timeMeasurementID_t i;
timeMeasurement_t count;

    count = GET_COUNTER_TIME;

    for (i = 0; i < MEASUREMENT_MAX_NUM; i++)
    {
        if (measurementsState[i] == BUSY)
            measurements[i] += count;
    }
}

/*
 * Richiamata in caso di overconteggio
 */
void tmrClbk ()
{
timeMeasurementID_t i;

    STOP_COUNTING;
    for (i = 0; i < MEASUREMENT_MAX_NUM; i++)
    {
        if (measurementsState[i] == BUSY)
            measurements[i] += COUNTER_MAX_SIZE;
    }
    RESTART_COUNTING;
}