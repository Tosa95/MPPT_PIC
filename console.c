#include "console.h"
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
void consoleInitGraphicObjects ();

/*
 * Inizializza il modulo che si occupa di visualizzare lo stato dei pwm
 */
void consoleMeasurementInit ()
{
    consoleInitGraphicObjects();
    afterInit = 1;
}

/*
 * Visualizza sul display lo stato dei pwm
 */
void consoleMeasurementMainLoopBody ()
{
keyID key;
double f;
char txt[50], dt[50], dtF[50];
int i;
error_t e;
error_t *actError;

        if (getLastPressedKeys().UP_PRESSED == 1)
        {
            while ((actError = getError()) != NULL)
                deleteError();
        }

        if (!afterInit)
        {
            key = getPressedKey();

            sprintf (txt, "MPPT - CONSOLE");
            StSetText (head, txt);

            strcpy(dtF, "");

            i = 0;
                       
            while ((actError = getErrorByIndex(i)) != NULL)
            {
                sprintf (dt, "%s: ", actError->errorType== ERROR? "E" : "W");
                strcat (dt, actError->name);
                strcat (dt, "\n");
                strcat(dtF, dt);
                i++;
            }
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
void consoleMeasurementStop ()
{
    GOLFree();
}

/*
 * Inizializza gli oggetti grafici
 */
void consoleInitGraphicObjects ()
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
    head = StCreate (2, 0, 0, 128, 8, state, "MPPT - CONSOLE", pScheme);

    state = ST_DRAW;
    data = StCreate (2, 0, 9, 128, 64, state, "CONSOLE_DATA_HERE", pScheme);

}

