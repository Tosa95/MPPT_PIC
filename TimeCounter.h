/* 
 * File:   TimeCounter.h
 * Author: Davide
 *
 * Created on 8 aprile 2015, 15.06
 */

#ifndef TIMECOUNTER_H
#define	TIMECOUNTER_H

#include "basicTypes.h"

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * @file
 *
 * @addgroup TimeCounter TimeCounter
 *
 * @brief Mantiene un conteggio del tempo passato e calcola il tempo trascorso tra due momenti.
 *
 * @{
 */

    /**
     * Inizializza il conteggio
     */
    void initTimeCounter ();

    /**
     * @brief Ritorna il conteggio attuale
     *
     * @return Conteggio attuale in us
     */
    discreteTimeUS_t getTimeUS ();

    /**
     * @brief Ritorna il tempo trascorso tra due istanti
     * 
     * @param tBefore Primo istante (meno recente)
     * @param tAfter Secondo istante (più recente)
     * 
     * @return Differenza tra i due istanti in us.
     */
    discreteTimeUS_t getTimeDifferenceUS (discreteTimeUS_t tAfter, discreteTimeUS_t tBefore);

    /**
     * @brief Ritorna il tempo trascorso fino ad adesso da un certo istante
     *
     * @param t Istante iniziale
     * @return Tempo trascorso in us
     */
    discreteTimeUS_t getTimeDifferenceToNowUS (discreteTimeUS_t t);


///@}


#ifdef	__cplusplus
}
#endif

#endif	/* TIMECOUNTER_H */

