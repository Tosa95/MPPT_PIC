#include "stdlib.h"
#include "string.h"

#include "graphics/GOL.h"
#include "Graphics/Primitive.h"
#include "Graphics/StaticText.h"
#include "BatteryDisplayer.h"

#include "battery.h"
#include "network.h"

#include "controls.h"
#include "rampControl.h"
#include "timer3.h"
#include "timer1.h"
#include "errorControl.h"

#include "globalPinout.h"

#include "flashWriting.h"
#include "inverter.h"

static STATICTEXT *head, *data;
static BATTERYDISPLAYER *batt;

static int val = 50;

static int afterInit;

//Interfaccia di visualizzazione batteria

/*
 * Inizializza gli oggetti grafici
 */
void batteryInitGraphicObjects ();

/*
 * Inizializza il modulo che si occupa di misurare e visualizzare la quantità
 * dell'errore effettuato sulla rampa di frequenza
 */
void batteryMeasurementInit ()
{
    batteryInitGraphicObjects();
    afterInit = 1;
}

/*
 * Misura e visualizza sul display la quantità dell'errore effettuato sulla
 * rampa di frequenza
 */
void batteryMeasurementMainLoopBody ()
{
keyID key;
double f;
char txt[50], dt[50], swlck[50] = "";
int i;
error_t e;

        if (!afterInit)
        {
            key = getPressedKey();

            if (networkLocked())
                sprintf (swlck, "LCK:%3d SEC", (int)getNetworkLockRemainingTime());

            sprintf (txt, "MPPT - BATTERIA");
            StSetText (head, txt);

            sprintf (dt, "%3.2fV\n%3.2f%%\n%s\nNET:%s\nINV:%s\n%s", getBatteryVoltage(),
                     getBatteryPercentage(), getBatteryState()==BATTERY_CHARGED?"CARICA":"SCARICA",
                     getNetworkState()==NETWORK_CONNECTED?"C":"D", getInverterState()==INVERTER_ON?"ON":"OFF",
                     swlck);
            StSetText (data, dt);
            
            BatteryDisplayer_setBatteryValue (batt, getBatteryPercentage());

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
            batt->hdr.state |= ST_DRAW;
        }

}

/*
 * Stoppa il modulo che si occupa di misurare e visualizzare la quantità
 * dell'errore effettuato sulla rampa di frequenza     
 */
void batteryMeasurementStop ()
{
    GOLFree();
}

/*
 * Inizializza gli oggetti grafici
 */
void batteryInitGraphicObjects ()
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
    head = StCreate (2, 0, 0, 128, 8, state, "MPPT - BATTERIA", pScheme);

    state = ST_DRAW;
    data = StCreate (2, 80, 15, 128, 64, state, "30V\n40%", pScheme);

    state = BD_DRAW;
    batt = BatteryDisplayerCreate(3, 0, 10, 70, 50, state, 50.0, pScheme);
}
