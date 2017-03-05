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

static STATICTEXT *head, *data;

static int val = 50;

static int afterInit;

//Interfaccia di visualizzazione batteria

/*
 * Inizializza gli oggetti grafici
 */
void pwmsInitGraphicObjects ();

/*
 * Inizializza il modulo che si occupa di visualizzare lo stato dei pwm
 */
void pwmsMeasurementInit ()
{
    pwmsInitGraphicObjects();
    afterInit = 1;
}

/*
 * Visualizza sul display lo stato dei pwm
 */
void pwmsMeasurementMainLoopBody ()
{
keyID key;
double f;
char txt[50], dt[50], dtF[150];
int i;
error_t e;

        if (!afterInit)
        {
            key = getPressedKey();

            sprintf (txt, "MPPT - PWM");
            StSetText (head, txt);

            strcpy(dtF, "");

            for (i = PWM1_ID; i <= PWM4_ID; i++)
            {
                if (getPWMEnabled(i) == TRUE_B)
                {
                    sprintf (dt, "PWM%d: %5.2f%%  %5.2fV  %c S:%4.1f\n", i+1, getPWMDutyCycle(i), getPWMCurrent(i), getPWMVerso(i)==PWM_INCR?'+':'-', getPWMStep (i));
                    strcat(dtF, dt);
                }
                else
                {
                    sprintf (dt, "PWM%d: DISATTIVATO\n", i+1);
                    strcat(dtF, dt);
                }
            }

            sprintf (dt, "CORRENTE MEDIA: %8.3fV\n", getPWMsAvgCurrent());
            strcat(dtF, dt);

            sprintf (dt, "VENTOLA: %s\n", getFanState()==FAN_ON?"ACCESA":"SPENTA");
            strcat(dtF, dt);

            StSetText (data, dtF);


            //head->hdr.state |= ST_DRAW;
            data->hdr.state |= ST_DRAW;
            //batt->hdr.state |= ST_DRAW;

            GOLDraw();
            refreshSPIDisplay();



            val+=3;
            val %= 101;
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
void pwmsMeasurementStop ()
{
    GOLFree();
}

/*
 * Inizializza gli oggetti grafici
 */
void pwmsInitGraphicObjects ()
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
    head = StCreate (2, 0, 0, 128, 8, state, "MPPT - PWMs", pScheme);

    state = ST_DRAW;
    data = StCreate (2, 0, 9, 128, 64, state, "PWM_DATA_HERE", pScheme);

}
