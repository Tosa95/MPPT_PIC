#include "pwms.h"
#include "fan.h"
#include "stdlib.h"
#include "string.h"

#include "graphics/GOL.h"
#include "Graphics/Primitive.h"
#include "Graphics/StaticText.h"

#include "controls.h"
#include "rampControl.h"
#include "timer3.h"
#include "timer1.h"
#include "errorControl.h"

#include "globalPinout.h"

#include "pwmStabilityTest_graphic.h"

#include "MyGraph.h"
#include "pwmStabilityTest.h"

static STATICTEXT *head, *data;
static MYGRAPH *graph;

static int afterInit;

//Interfaccia di visualizzazione batteria

/*
 * Inizializza gli oggetti grafici
 */
void pwmStabilityTestInitGraphicObjects ();

/*
 * Inizializza il modulo che si occupa di visualizzare lo stato dei pwm
 */
void pwmStabilityTestMeasurementInit ()
{
    pwmStabilityTestInitGraphicObjects();
    afterInit = 1;
}

/*
 * Visualizza sul display lo stato dei pwm
 */
void pwmStabilityTestMeasurementMainLoopBody ()
{
keyID key;
char txt[50], dt[250], dtF[250];
int i;

        if (!afterInit)
        {
            key = getPressedKey();

            sprintf (txt, "MPPT - PWM STABILITY TEST");
            StSetText (head, txt);

            strcpy(dtF, "");

            sprintf (dt, "AVG:%5.2f SQM:%6.3f ACT:%5.2f\nMIN:%5.2f MAX:%5.2f", getStabilityTestAverage(), getStabilityTestVariance(), getStabilityTestVal(getStabilityTestActIndex()), getStabilityTestMin(), getStabilityTestMax());
            strcat(dtF, dt);

            StSetText (data, dtF);

            setBarPos(graph, getStabilityTestActIndex());
            invalidateMyGraph(graph);

            //head->hdr.state |= ST_DRAW;
            data->hdr.state |= ST_DRAW;
            //batt->hdr.state |= ST_DRAW;

            GOLDraw();
            refreshSPIDisplay();
        }
        else
        {
            eraseSPIDisplay();
            afterInit = 0;
            head->hdr.state |= ST_DRAW;
            data->hdr.state |= ST_DRAW;
        }

}

/*
 * Stoppa la visualizzazione dello stato dei pwm
 */
void pwmStabilityTestMeasurementStop ()
{
    GOLFree();
}

/*
 * Inizializza gli oggetti grafici
 */
void pwmStabilityTestInitGraphicObjects ()
{
GOL_SCHEME *pScheme;
WORD state;
int i;

    GOLNewList();

    pScheme = GOLCreateScheme();

    pScheme ->Color0 = 0x00;
    pScheme ->Color1 = 0x01;

    pScheme ->CommonBkColor = 0x01;

    pScheme ->EmbossDkColor = 0x00;
    pScheme ->EmbossLtColor = 0x01;

    pScheme ->TextColor0 = 0x00;
    pScheme ->TextColor1 = 0x00;

    state = ST_DRAW;
    head = StCreate (1, 0, 0, 128, 8, state, "MPPT - PWMs", pScheme);

    state = ST_DRAW;
    data = StCreate (2, 0, 46, 128, 64, state, "PWM_DATA_HERE", pScheme);

    state = MYGR_DRAW;
    graph = MygrCreate(3, 0, 9, 127, 45, state, getStabilityTestGraphData(), PWM_STABILITY_TEST_SAMPLES, 0, PWM_STABILITY_TEST_SAMPLES- 1, 0, 100, 0, 0, 0, 0, pScheme);

}

