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

static int afterInit;

//Interfaccia di visualizzazione batteria

/*
 * Inizializza gli oggetti grafici
 */
void pwmsTimeControlInitGraphicObjects ();

/*
 * Inizializza il modulo che si occupa di visualizzare lo stato dei pwm
 */
void pwmsTimeControlMeasurementInit ()
{
    pwmsTimeControlInitGraphicObjects();
    afterInit = 1;
}

/*
 * Visualizza sul display lo stato dei pwm
 */
void pwmsTimeControlMeasurementMainLoopBody ()
{
keyID key;
char txt[50], dt[50], dtF[150], errs[4];
int i;

        if (!afterInit)
        {
            key = getPressedKey();

            sprintf (txt, "MPPT - PWM TIME CONTROL");
            StSetText (head, txt);

            strcpy(dtF, "");

            for (i = PWM1_ID; i <= PWM4_ID; i++)
            {
                if (getPWMEnabled(i) == TRUE_B)
                {
                    sprintf (dt, "PWM%d: [%4.1f%%; %4.1f%%] R:%4.1f%%\n", i+1, getPWMMin(i), getPWMMax(i), getPWMRange(i));
                    strcat(dtF, dt);
                    if (getPWMRangeState(i) == RANGE_STATE_KO)
                        errs[i] = 'e';
                    else
                        errs[i] = 'k';
                }
                else
                {
                    sprintf (dt, "PWM%d: DISATTIVATO\n", i+1);
                    strcat(dtF, dt);
                    errs[i] = 'k';
                }
            }

            sprintf (dt, "ERRORI: %s%s%s%s\n", errs[0]=='e'?"P1 ":"", errs[1]=='e'?"P2 ":"", errs[2]=='e'?"P3 ":"", errs[3]=='e'?"P4 ":"" );
            strcat(dtF, dt);

            StSetText (data, dtF);


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
void pwmsTimeControlMeasurementStop ()
{
    GOLFree();
}

/*
 * Inizializza gli oggetti grafici
 */
void pwmsTimeControlInitGraphicObjects ()
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
