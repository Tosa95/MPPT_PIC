#include "ControlLoop.h"
#include "stdTypes.h"
#include "battery.h"
#include "ADC1Control.h"
#include "ClockControl.h"
#include "pwms.h"
#include "globalPinout.h"
#include "fan.h"
#include "network.h"
#include "pwmStabilityTest.h"

#include <stdlib.h>

#define CURR_NUM 4
#define PWM_MIN_MAX_RESET_CYCLES 10
#define PWM_STEP_UPDATE_CYCLES 20

int resetCount = 0, stepUpdateCount = 0;

int anPinsCurr[CURR_NUM] = {CURR1_AN_PIN_NO, CURR2_AN_PIN_NO, CURR3_AN_PIN_NO, CURR4_AN_PIN_NO};

 /*
  * Legge la tensione della batteria
  */
voltageV_t readBatteryVoltage ();

/*
 * Legge la corrente richiesta
 */
voltageV_t readCurrent (int currNum);

/*
 * Esegue un iterazione del loop che si occupa di controllare il dispositivo
 */
void controlLoop ()
{
    voltageV_t v;
    int i;

    if (resetCount >= PWM_MIN_MAX_RESET_CYCLES)
    {
        resetPWMsMinMax();
        resetCount = 0;
    }

    if (stepUpdateCount >= PWM_STEP_UPDATE_CYCLES)
    {
        updatePWMsSteps();
        stepUpdateCount = 0;
    }

    v = readBatteryVoltage();

    setBatteryVoltage(v);

    if (getBatteryState()==BATTERY_NON_CHARGED)
    {
        for (i = PWM1_ID; i <= PWM4_ID; i++)
        {
            v = readCurrent(i);
            setPWMCurrent(i, v);
        }

        updatePWMs();
    }
    else
    {
        for (i = PWM1_ID; i <= PWM4_ID; i++)
        {
            v = readCurrent(i);
            setPWMCurrent(i, v);
            setPWMDutyCycle(i, PWM_MIN_DC);
            setPWMVerso(i, PWM_INCR);
        }
    }

    updateFanState(getPWMsAvgCurrent());
    updateNetworkState(getBatteryVoltage());
    updateStabilityTest();

    resetCount++;
    stepUpdateCount++;
}

 /*
  * Legge la tensione della batteria
  */
voltageV_t readBatteryVoltage ()
{
    //TODO: Implement
    //return rand()%57;

    double upp = *(double *)getSetting(ADC_BATT_UPP_SID);

    initADC1 (BATTERY_AN_PIN_NO, ADC1_AVDD_AVSS, 0, 10, ADC1_INTEGER, 0, NULL, 0, upp);

    beginSamplingADC1();

    while (!doneADC1());

    return getActVoltageADC1 ();
}

/*
 * Legge la corrente richiesta
 */
voltageV_t readCurrent (int currNum)
{
    initADC1 (anPinsCurr[currNum], ADC1_AVDD_AVSS, 0, 10, ADC1_INTEGER, 0, NULL, 0, 3.0);

    beginSamplingADC1();

    while (!doneADC1());

    return getActVoltageADC1 ();
}