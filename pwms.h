/* 
 * File:   pwms.h
 * Author: Davide
 *
 * Created on 30 luglio 2014, 15.25
 */

#ifndef PWMS_H
#define	PWMS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "pwms_graphic.h"
#include "stdTypes.h"
#include "globalSettings.h"

#define PWM_MIN_DC  5
#define PWM_MAX_DC 95

#define PWM_INCR +1
#define PWM_DECR -1

extern percentage_t MAX_STEP;
extern percentage_t MIN_STEP;
extern percentage_t STEP_CHANGE;

    typedef enum
    {
        PWM1_ID = 0,
        PWM2_ID,
        PWM3_ID,
        PWM4_ID
    }PWMID_t;

    typedef enum {RANGE_STATE_OK, RANGE_STATE_KO} rangeState_t;

/*
 * Imposta il periodo di tutti i PWM
 */
void setPWMPeriod (timeUS_t t);

/*
 * Ritorna il periodo di tutti i PWM
 */
timeUS_t getPWMPeriod ();

/*
 * Inizializza i PWM
 */
void initPWMs (timeUS_t p);

/*
 * Imposta il duty cycle di un pwm
 */
void setPWMDutyCycle (PWMID_t id, percentage_t dc);

/*
 * Ritorna il duty cycle di un pwm
 */
percentage_t getPWMDutyCycle (PWMID_t id);

/*
 * Ritorna la corrente attuale di un pwm
 */
voltageV_t getPWMCurrent (PWMID_t id);

/*
 * Ritorna l'attuale verso di variazione del pwm
 */
int getPWMVerso (PWMID_t id);

/*
 * Ritorna l'attuale tensione dei pannelli associati al PWM
 */
voltageV_t getPWMPhotoV (PWMID_t id);

/*
 * Aggiorna la corrente attuale del pwm, cambiando verso se necessario
 */
void setPWMCurrent (PWMID_t id, voltageV_t c);

/*
 * Imposta il verso di variazione del PWM
 */
void setPWMVerso (PWMID_t id, int v);

/*
 * Aggiorna i PWM (incrementa/decrementa)
 */
void updatePWMs ();

/*
 * Attiva/disattiva un PWM
 */
void setPWMEnabled (PWMID_t id, bool_t en);

/*
 * Ritorna lo stato di attivazione del pwm
 */
bool_t getPWMEnabled (PWMID_t id);

/*
 * Ritorna la media delle correnti dei pwm attivi
 */
voltageV_t getPWMsAvgCurrent ();

/*
 * Callback per il cambio di impostazioni dei pwm
 */
void pwmSettingsChange (settingID_t sid, void *v);

/*
 * Ritorna il minimo valore assunto dal pwm
 */
percentage_t getPWMMin (PWMID_t id);

/*
 * Ritorna il massimo valore assunto dal pwm
 */
percentage_t getPWMMax (PWMID_t id);

/*
 * Resetta il conteggio max/min dei pwm
 */
void resetPWMsMinMax ();

/*
 * Ritorna lo stato del range di variazione (normale/anormale)
 */
rangeState_t getPWMRangeState (PWMID_t id);

/*
 * Ritorna il range di variazione del pwm
 */
percentage_t getPWMRange (PWMID_t id);

/*
 * Aggiorna lo step di variazione di tutti i pwm
 */
void updatePWMsSteps ();

/*
 * Imposta lo step di un pwm
 */
void setPWMStep (PWMID_t id, percentage_t s);

/*
 * Ritorna lo step di un pwm
 */
percentage_t getPWMStep (PWMID_t id);

/*
 * Incrementa/decrementa lo step di un pwm
 */
void updatePWMStep (PWMID_t id, int verso);

/*
 * Attiva/disattiva la correzione automatica dello step
 */
void setPWMsAutoStepAdjust (bool_t s);

/*
 * Ritorna lo stato di attivazione della correzone automatica dello step
 */
bool_t getPWMsAutoStepAdjust ();

/*
 * Blocca/sblocca un pwm
 */
void setPWMLocked (PWMID_t id, bool_t s);

/*
 * Ritorna lo stato di bloccaggio del PWM
 */
bool_t getPWMLocked (PWMID_t id);


#ifdef	__cplusplus
}
#endif

#endif	/* PWMS_H */

