/* 
 * File:   basicTimersControl.h
 * Author: Davide
 *
 * Created on 27 giugno 2013, 17.17
 */

#ifndef BASICTIMERSCONTROL_H
#define	BASICTIMERSCONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "timersCommonTypes.h"

    /*
     * Aggiunge tutti i timer di base disponibili alla libreria
     */
    void addBasicTimers ();

    //Inizializzazione

    /*
     * Inizializza il timer
     *
     * input:
     *  - tmr: il timer utilizzato
     */
    void initBasicTimer (timer tmr);

    //Metodi di impostazione

    /*
     * Accende/Spegne il timer
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - stt: lo stato voluo (acceso/spento)
     */
    void setBasicTimerState (timer tmr, timerState stt);

    /*
     * Decide se utilizzare o meno il gate
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - gt: stato del gate (usato o no)
     */
    void setBasicTimerGate (timer tmr, timerGate gt);

    /*
     * Decide la modalità del timer (timer/contatore)
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - md: modalità da utilizzare (timer/contatore)
     */
    void setBasicTimerMode (timer tmr, timerMode md);

    /*
     * Decide se attivare o meno l'interrupt per il timer
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - is: stato dell'interrupt (attivato/disattivato)
     */
    void setBasicTimerInterruptState (timer tmr, timerInterruptState is, int interruptPriority);

    /*
     * Imposta l'intervallo per il timer selezionato (nS)
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - interval: intervallo desiderato (nS)
     *
     * output:
     *  - l'intervallo realmente ottenuto (nS)
     */
    timerNS setBasicTimerIntervalNS (timer tmr, timerNS interval);

    /*
     * Imposta l'intervallo per il timer selezionato (uS)
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - interval: intervallo desiderato (uS)
     *
     * output:
     *  - l'intervallo realmente ottenuto (uS)
     */
    timerUS setBasicTimerIntervalUS (timer tmr, timerUS interval);

     /*
     * Imposta il limite al conteggio del timer. Quando esso raggiungerà tale valore
     * verrà scatenato un interrupt (se abilitato) e il timer verrà resettato
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - lim: il limite al conteggio
     */
    void setBasicTimerLimit (timer tmr, timerLimit lim);

    /*
     * Imposta il prescaler del timer
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - prsc: il prescaler desiderato
     */
    void setBasicTimerPrescaler (timer tmr, timerPrescaler prsc);

    //Metodi di osservazione

    /*
     * Ritorna il tempo trascorso dall'avvio del timer  (nS)
     *
     * input:
     *  - tmr: il timer utilizzato
     *
     * output:
     *  - tempo trascorso dall'avvio del timer (nS)
     */
    timerNS getBasicTimerElaspedTimeNS (timer tmr);

    /*
     * Ritorna il tempo trascorso dall'avvio del timer  (uS)
     *
     * input:
     *  - tmr: il timer utilizzato
     *
     * output:
     *  - tempo trascorso dall'avvio del timer (uS)
     */
    timerUS getBasicTimerElaspedTimeUS (timer tmr);

    /*
     * Ritorna l'attuale frequenza di lavoro del timer
     *
     * input:
     *  - tmr: il timer utilizzato
     *
     * output:
     *  - la frequenza attuale del timer (Hz)
     */
    timerHZ getBasicTimerFreq (timer tmr);

    /*
     * Ritorna l'attuale conteggio del timer
     *
     * input:
     *  - tmr: il timer utilizzato
     *
     * output:
     *  - conteggio attuale del timer
     */
    timerCount getBasicTimerCount (timer tmr);

    //Metodi di utilità

    /*
     * Attende il termine del conteggio
     *
     * input:
     *  - tmr: il timer utilizzato
     */
    void basicTimerWaitForEnd (timer tmr);

    /*
     * Blocca il conteggio per il numero di nS desiderato
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - interval: il tempo da aspettare (nS)
     */
    void basicTimerDelayNS (timer tmr, timerNS interval);

    /*
     * Blocca il conteggio per il numero di uS desiderato
     *
     * input:
     *  - tmr: il timer utilizzato
     *  - interval: il tempo da aspettare (uS)
     */
    void basicTimerDelayUS (timer tmr, timerUS interval);

    /*
     * Pone a 0 il conteggio del timer
     *
     * input:
     *  - tmr: il timer utilizzato
     */
    void resetBasicTimer (timer tmr);

#ifdef	__cplusplus
}
#endif

#endif	/* BASICTIMERSCONTROL_H */

