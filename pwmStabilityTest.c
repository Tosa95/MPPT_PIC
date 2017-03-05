#include "pwmStabilityTest.h"
#include "pwms.h"
#include "MyGraph.h"
#include <math.h>
#include <xc.h>

static double data[PWM_STABILITY_TEST_SAMPLES];
static int graphData[PWM_STABILITY_TEST_SAMPLES];

static stabilityTestState_t state = STABILITY_TEST_STOPPED;

static PWMID_t pID;
static percentage_t duty;

static int actI = 0;

/*
 * Ritorna lo stato di attivazione del test
 */
stabilityTestState_t getStabilityTestState ()
{
    return state;
}

/*
 * Ritorna i dati per il grafico
 */
int *getStabilityTestGraphData ()
{
    return graphData;
}

/*
 * Callback per il cambio di impostazioni
 */
void settingChangeStabilityTest (settingID_t sid, void *v)
{
    if (sid == STABILITY_TEST_DUTY_SID)
    {
        duty = *(double *)v;
        setPWMDutyCycle(pID, duty);
    }
    else if (sid == STABILITY_TEST_PWMID_SID)
    {
        setPWMLocked(pID, FALSE_B);

        pID = *(int *)v;
    }
    else if (sid == STABILITY_TEST_STATE_SID)
    {
        state = (*(bool_t *)v) == TRUE_B?STABILITY_TEST_RUNNING:STABILITY_TEST_STOPPED;

        if (state == STABILITY_TEST_RUNNING)
            setPWMLocked(pID, TRUE_B);
        else
            setPWMLocked(pID, FALSE_B);
    }

    int i;

    for (i = 0; i < PWM_STABILITY_TEST_SAMPLES; i++)
    {
        data[i] = 0;
        graphData[i] = 0;
    }

    actI = 0;
}

/*
 * Aggiorna il grafico
 */
void updateStabilityTest ()
{
    int i;

    if (actI >= PWM_STABILITY_TEST_SAMPLES)
    {
        for (i = 0; i < PWM_STABILITY_TEST_SAMPLES - 1; i++)
        {
            data[i] = data[i+1];
            graphData[i] = graphData[i+1];
        }

        actI--;
    }

    if (state == STABILITY_TEST_RUNNING)
        setPWMDutyCycle(pID, duty);

    data[actI] = getPWMCurrent(pID);
    graphData[actI] = getPercentage(0, 3.0, data[actI]);

    actI++;
}

/*
 * ritorna l'indice attuale
 */
int getStabilityTestActIndex ()
{
    return actI - 1;
}

/*
 * ritorna la media delle correnti
 */
double getStabilityTestAverage ()
{
    int i;
    double sum = 0;

    for (i = 0; i < actI; i++)
    {
        sum += data[i];
    }

    if (actI != 0)
        sum /= actI;

    return sum;
}

/*
 * ritorna la varianza delle correnti
 */
double getStabilityTestVariance ()
{
    long int i;
    double s = 0, avg = getStabilityTestAverage(), act;

    for (i = 0; i < actI; i++)
    {
        act = data[i]-avg;
        s += act*act;
    }

    if (actI != 0)
    {
        s /= actI;
        s = sqrt(s);
    }

    return s;
}

/*
 * ritorna una corrente
 */
double getStabilityTestVal (int index)
{
    if (index < 0)
        index = 0;

    if (index >= actI)
        index = actI - 1;

    return data[index];
}

    /*
     * ritorna la corrente minima
     */
    double getStabilityTestMin ()
    {
        double min = 10000;

        int i;

        for (i = 0; i < actI; i++)
        {
            if (data[i] < min)
                min = data[i];
        }

        return min;

    }

    /*
     * ritorna la corrente massima
     */
    double getStabilityTestMax ()
    {
        double max = 0;

        int i;

        for (i = 0; i < actI; i++)
        {
            if (data[i] > max)
                max = data[i];
        }

        return max;
    }