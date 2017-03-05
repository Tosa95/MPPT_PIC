#include "pwms.h"
#include "OCControl.h"
#include "GeneralTimers.h"
#include <math.h>



static timeUS_t PWM_PERIOD;
static const timerID_t PWM_TIMER = TIMER2_ID;
static percentage_t PWM_RANGE_KO_MUL = 3;
static bool_t autoAdjustStep = FALSE_B;

percentage_t MAX_STEP = 10.0;
percentage_t MIN_STEP = 0.10;
percentage_t STEP_CHANGE = 0.10;


typedef struct
{
    OCID_t ocid;

    int verso;
    percentage_t dc;
    voltageV_t current;
    voltageV_t photoV;
    bool_t enabled;
    bool_t locked;

    percentage_t step;

    percentage_t min;
    percentage_t max;
    percentage_t minInCalc;
    percentage_t maxInCalc;
}pwmData_t;

pwmData_t pwmData[4] = {{OC1_ID, PWM_INCR, 50, 0, 0, TRUE_B, FALSE_B, 5.0, 100, 0, 100, 0}, {OC2_ID, PWM_INCR,50, 0, 0, TRUE_B, FALSE_B, 5.0, 100, 0, 100, 0}, {OC3_ID, PWM_INCR,50, 0, 0, TRUE_B, FALSE_B, 5.0, 100, 0, 100, 0}, {OC4_ID, PWM_INCR, 50, 0, 0, TRUE_B, FALSE_B, 5.0, 100, 0, 100, 0}};

/*
 * Commuta il verso di variazione del pwm
 */
void togglePWMVerso (PWMID_t id);

/*
 * Imposta il periodo di tutti i PWM
 */
void setPWMPeriod (timeUS_t t)
{
    PWM_PERIOD = t;
    setTimerInterval(PWM_TIMER, PWM_PERIOD);
    setTimerEnabled (PWM_TIMER, TIMER_ON);
}

/*
 * Ritorna il periodo di tutti i PWM
 */
timeUS_t getPWMPeriod ()
{
    return PWM_PERIOD;
}

/*
 * Inizializza i PWM
 */
void initPWMs (timeUS_t p)
{
int i;

    setPWMPeriod(p);
    initTimer(PWM_TIMER, TIMER_TIMER, TIMER_IDLE_CONTINUE);

    for (i = PWM1_ID; i <= PWM4_ID; i++)
    {
        initOC(pwmData[i].ocid, OC_CONTINUOUS_PULSE, PWM_TIMER, OC_IDLE_CONTINUE);
        setPWMDutyCycle(i, pwmData[i].dc);
    }

    setTimerEnabled(PWM_TIMER, TIMER_ON);
}

/*
 * Imposta il duty cycle di un pwm
 */
void setPWMDutyCycle (PWMID_t id, percentage_t dc)
{
    if (dc <= PWM_MIN_DC)
    {
        dc = PWM_MIN_DC;
        setPWMVerso(id, PWM_INCR);
    }
    else if (dc > PWM_MAX_DC)
    {
        dc = PWM_MAX_DC;
        setPWMVerso(id, PWM_DECR);
    }

    if (getPWMEnabled(id) == FALSE_B)
        dc = 0;

    pwmData[id].dc = dc;
    
    if (id == PWM1_ID || id == PWM2_ID)
    {
        setOCDutyCycle(pwmData[id].ocid, pwmData[id].dc);
    }
    else if (id == PWM3_ID || id == PWM4_ID)
    {
        setOCDutyCycleReverse(pwmData[id].ocid, pwmData[id].dc);
    }
    
    if (dc < pwmData[id].minInCalc)
        pwmData[id].minInCalc = dc;
    
    if (dc > pwmData[id].maxInCalc)
        pwmData[id].maxInCalc = dc;
}

/*
 * Ritorna il duty cycle di un pwm
 */
percentage_t getPWMDutyCycle (PWMID_t id)
{
    return pwmData[id].dc;
}

/*
 * Ritorna la corrente attuale di un pwm
 */
voltageV_t getPWMCurrent (PWMID_t id)
{
    return pwmData[id].current;
}

/*
 * Ritorna l'attuale verso di variazione del pwm
 */
int getPWMVerso (PWMID_t id)
{
    return pwmData[id].verso;
}

/*
 * Ritorna l'attuale tensione dei pannelli associati al PWM
 */
voltageV_t getPWMPhotoV (PWMID_t id)
{
    return pwmData[id].photoV;
}

/*
 * Aggiorna la corrente attuale del pwm, cambiando verso se necessario
 */
void setPWMCurrent (PWMID_t id, voltageV_t c)
{
voltageV_t old = pwmData[id].current;

    pwmData[id].current = c;

    if (c < old)
        togglePWMVerso (id);

}

/*
 * Imposta il verso di variazione del PWM
 */
void setPWMVerso (PWMID_t id, int v)
{
    pwmData[id].verso = v;
}

/*
 * Commuta il verso di variazione del pwm
 */
void togglePWMVerso (PWMID_t id)
{
    int verso = pwmData[id].verso;

    verso = verso==PWM_INCR?PWM_DECR:PWM_INCR;

    pwmData[id].verso = verso;
}


/*
 * Aggiorna i PWM (incrementa/decrementa)
 */
void updatePWMs ()
{
int i;

    for (i = PWM1_ID; i <= PWM4_ID; i++)
    {
        if (pwmData[i].enabled == TRUE_B)
        {
            if (pwmData[i].locked == FALSE_B)
                pwmData[i].dc += pwmData[i].step * pwmData[i].verso;
            setPWMDutyCycle(i, pwmData[i].dc);
        }
        else if (pwmData[i].enabled == FALSE_B)
        {
            setPWMDutyCycle(i, 0);
        }
    }

}

/*
 * Attiva/disattiva un PWM
 */
void setPWMEnabled (PWMID_t id, bool_t en)
{
    pwmData[id].enabled = en;
}

/*
 * Ritorna lo stato di attivazione del pwm
 */
bool_t getPWMEnabled (PWMID_t id)
{
    return pwmData[id].enabled;
}

/*
 * Ritorna la media delle correnti dei pwm attivi
 */
voltageV_t getPWMsAvgCurrent ()
{
    int i;
    voltageV_t res = 0;
    double en = 0;

    for (i = PWM1_ID; i <= PWM4_ID; i++)
    {
        if (pwmData[i].enabled == TRUE_B)
        {
            en++;
            res += pwmData[i].current;
        }
    }

    res /= en;

    return res;
}

/*
 * Callback per il cambio di impostazioni dei pwm
 */
void pwmSettingsChange (settingID_t sid, void *v)
{
    if (sid == PWM1_ENABLED_SID)
            setPWMEnabled(PWM1_ID, *((bool_t *)v));
    else if (sid == PWM2_ENABLED_SID)
            setPWMEnabled(PWM2_ID, *((bool_t *)v));
    else if (sid == PWM3_ENABLED_SID)
            setPWMEnabled(PWM3_ID, *((bool_t *)v));
    else if (sid == PWM4_ENABLED_SID)
            setPWMEnabled(PWM4_ID, *((bool_t *)v));
    else if (sid == PWM_PERIOD_SID)
        setPWMPeriod(*(double *)v);
    else if (sid == PWM1_STEP_SID)
        setPWMStep(PWM1_ID, *(double *)v);
    else if (sid == PWM2_STEP_SID)
        setPWMStep(PWM2_ID, *(double *)v);
    else if (sid == PWM3_STEP_SID)
        setPWMStep(PWM3_ID, *(double *)v);
    else if (sid == PWM4_STEP_SID)
        setPWMStep(PWM4_ID, *(double *)v);
    else if (sid == PWM_AUTO_STEP_ADJUST_SID)
        setPWMsAutoStepAdjust(*(bool_t *)v);
}

/*
 * Ritorna il minimo valore assunto dal pwm
 */
percentage_t getPWMMin (PWMID_t id)
{
    return pwmData[id].min;
}

/*
 * Ritorna il massimo valore assunto dal pwm
 */
percentage_t getPWMMax (PWMID_t id)
{
    return pwmData[id].max;
}

/*
 * Resetta il conteggio max/min dei pwm
 */
void resetPWMsMinMax ()
{
    int i;
    
    for (i = PWM1_ID; i <= PWM4_ID; i++)
    {
        pwmData[i].min = pwmData[i].minInCalc;
        pwmData[i].max = pwmData[i].maxInCalc;
        pwmData[i].minInCalc = 100;
        pwmData[i].maxInCalc = 0;
    }
}

/*
 * Ritorna lo stato del range di variazione (normale/anormale)
 */
rangeState_t getPWMRangeState (PWMID_t id)
{
    percentage_t range;

    range = getPWMRange(id);

    if (range>=PWM_RANGE_KO_MUL*pwmData[id].step)
        return RANGE_STATE_KO;
    else
        return RANGE_STATE_OK;
}

/*
 * Ritorna il range di variazione del pwm
 */
percentage_t getPWMRange (PWMID_t id)
{
    return fabs(getPWMMax(id)-getPWMMin(id));
}

/*
 * Aggiorna lo step di variazione di tutti i pwm
 */
void updatePWMsSteps ()
{
    int i;

    if (autoAdjustStep == TRUE_B)
        for (i = PWM1_ID; i <= PWM4_ID; i++)
        {
            if (getPWMRangeState(i) == RANGE_STATE_KO)
                updatePWMStep(i, +1);
            else
                updatePWMStep(i, -1);
        }
}

/*
 * Imposta lo step di un pwm
 */
void setPWMStep (PWMID_t id, percentage_t s)
{
    if (s < MIN_STEP)
        s = MIN_STEP;

    if (s > MAX_STEP)
        s = MAX_STEP;

    pwmData[id].step = s;
}

/*
 * Ritorna lo step di un pwm
 */
percentage_t getPWMStep (PWMID_t id)
{
    return pwmData[id].step;
}

/*
 * Incrementa/decrementa lo step di un pwm
 */
void updatePWMStep (PWMID_t id, int verso)
{
    percentage_t actS;

    actS = getPWMStep(id);

    actS += STEP_CHANGE*verso;

    setPWMStep(id, actS);
}

/*
 * Attiva/disattiva la correzione automatica dello step
 */
void setPWMsAutoStepAdjust (bool_t s)
{
    autoAdjustStep = s;
}

/*
 * Ritorna lo stato di attivazione della correzone automatica dello step
 */
bool_t getPWMsAutoStepAdjust ()
{
    return autoAdjustStep;
}

/*
 * Blocca/sblocca un pwm
 */
void setPWMLocked (PWMID_t id, bool_t s)
{
    pwmData[id].locked = s;
}

/*
 * Ritorna lo stato di bloccaggio del PWM
 */
bool_t getPWMLocked (PWMID_t id)
{
    return pwmData[id].locked;
}
