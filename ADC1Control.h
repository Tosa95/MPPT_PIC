/* 
 * File:   ADC1Control.h
 * Author: Davide
 *
 * Created on 21 giugno 2013, 11.15
 */

#ifndef ADC1CONTROL_H
#define	ADC1CONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdTypes.h"

    typedef enum
    {
        ADC1PIN0 = 1,
        ADC1PIN1 = 2,
        ADC1PIN2 = 4,
        ADC1PIN3 = 8,
        ADC1PIN4 = 16,
        ADC1PIN5 = 32,
        ADC1PIN6 = 64,
        ADC1PIN7 = 128,
        ADC1PIN8 = 256
    } ADC1PinSelect;

    typedef enum
    {
        ADC1_AVDD_AVSS = 0,
        ADC1_EVREFP_AVSS = 1,
        ADC1_AVDD_EVREFN = 2,
        ADC1_EVREFP_EVREFN = 3
    }ADC1RefSelect;

    typedef enum
    {
        ADC1_SIGNED_FRACTIONAL = 3,
        ADC1_FRACTIONAL = 2,
        ADC1_SIGNED_INTEGER = 1,
        ADC1_INTEGER = 0
    }ADC1ResultForm;

    void initADC1 (int pin, ADC1RefSelect voltageReference, int conversionClockMul, int autoSampleTime, ADC1ResultForm resultForm, int interruptEnable, void (*interruptClbk)(), double minV, double maxV);

    inline double getActVoltageADC1 ();

    inline voltage10bits_t getActBUFADC1 ();

    void beginSamplingADC1 ();

    int doneADC1 ();

    void setInputPinADC1 (int pin);
#ifdef	__cplusplus
}
#endif

#endif	/* ADC1CONTROL_H */

