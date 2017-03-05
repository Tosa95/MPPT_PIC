/* 
 * File:   quantities.h
 * Author: Davide
 *
 * Created on 19 luglio 2013, 15.43
 */

#ifndef QUANTITIES_H
#define	QUANTITIES_H

#ifdef	__cplusplus
extern "C" {
#endif

#define Q_NAME_MAX_CHAR 5
#define Q_NUM 5

    typedef enum
    {
        BATTERY_QID = 0,
        PWMS_QID = 1,
        PWMS_TIME_CONTROL_QID = 2,
        PWMS_STABILITY_TEST_QID = 3,
        CONSOLE_QID = 4,
        NONE_QID = -1
    }qId_t;

    typedef void (*qMainMeasurementLoop_t)();
    typedef void (*qInit_t)();
    typedef void (*qStop_t)();
    typedef char qName_t[Q_NAME_MAX_CHAR + 1] ;
    
    typedef struct 
    {
        qId_t ID;
        qName_t name;
        qMainMeasurementLoop_t mainMeasurementLoop;
        qInit_t init;
        qStop_t stop;
    }quantity_t;

    /*
     * Inizializza il modulo per la misurazione semplificata di più grandezze
     */
    void initQuantities ();

    /*
     * Ritorna l'attuale grandezza misurata
     *
     * output:
     *  - puntatore alla grandezza attualmente desiderata
     */
    quantity_t *getActQuantity ();

    /*
     * Imposta l'attuale grandezza misurata
     *
     * input:
     *  - qId: id della grandezza da misurare
     */
    void setActQuantity (qId_t qId);

    /*
     * Inizializza la quantità attuale
     */
    void initActQuantity ();

    /*
     * Va alla prossima quantità
     */
    void goToNextQuantity ();

    /*
     * Va alla precedente quantità
     */
    void goToPreviousQuantity ();

#ifdef	__cplusplus
}
#endif

#endif	/* QUANTITIES_H */

