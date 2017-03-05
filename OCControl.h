/* 
 * File:   OCControl.h
 * Author: Davide
 *
 * Created on 25 luglio 2014, 10.01
 */

#ifndef OCCONTROL_H
#define	OCCONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdTypes.h"
#include "GeneralTimers.h"


    typedef enum
    {
        OC_PWM_FAULT = 0x7,
        OC_PWM = 0x6,
        OC_CONTINUOUS_PULSE = 0x5,
        OC_DELAYED_ONE_SHOT = 0x4,
        OC_TOGGLE = 0x3,
        OC_ONE_SHOT_L = 0x2,
        OC_ONE_SHOT_H = 0x1,
        OC_DISABLED = 0x0
    }OCMode_t;

    typedef struct tagOCCONBITS {
      union {
        struct {
          unsigned OCM:3;
          unsigned OCTSEL:1;
          unsigned OCFLT:1;
          unsigned :8;
          unsigned OCSIDL:1;
        };
        struct {
          unsigned OCM0:1;
          unsigned OCM1:1;
          unsigned OCM2:1;
        };
      };
    } OCCONBITS;

    typedef enum
    {
        OC1_ID = 0,
        OC2_ID,
        OC3_ID,
        OC4_ID
    }OCID_t;

    typedef enum
{
    OC_IDLE_CONTINUE = 0,
    OC_IDLE_STOP = 1
}OCIdleBehaviour_t;



/*
 * Inizializza il modulo OC
 */
void initOC (OCID_t id, OCMode_t m, timerID_t tid, OCIdleBehaviour_t idl);

/*
 * Imposta il registro OCR del modulo al tempo desiderato
 */
void setOCR (OCID_t id, timeUS_t t);

/*
 * Imposta il registro OCRS del modulo al tempo desiderato
 */
void setOCRS (OCID_t id, timeUS_t t);

/*
 * Imposta il modulo OC per fornire un'onda quadra con il Duty Cycle desiderato,
 * parte dallo stato alto
 */
void setOCDutyCycle (OCID_t id, percentage_t p);

/*
 * Imposta il modulo OC per fornire un'onda quadra con il Duty Cycle desiderato,
 * parte dallo stato basso
 */
void setOCDutyCycleReverse (OCID_t id, percentage_t p);

#ifdef	__cplusplus
}
#endif

#endif	/* OCCONTROL_H */

