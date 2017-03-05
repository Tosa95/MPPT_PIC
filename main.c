
#include "config.h"


#include "GeneralTimers.h"

#include "globalPinout.h"

#include "controls.h"

#include <xc.h>
#include <stdlib.h>
#include <math.h>

#include "rampControl.h"
#include "rosmeterControl.h"

#include "timeMeasurement.h"

#include "display.h"
#include "SPIDisplay.h"
#include "consoleLike.h"
#include <stdio.h>
#include "Graphics/GOL.h"
#include "Graphics/Primitive.h"
#include "Graphics/Button.h"
#include "MyGraph.h"
#include "ClockControl.h"
#include "timer1.h"
#include "Graphics/StaticText.h"
#include "ADC1Control.h"
#include "timers.h"
#include "addressableBits.h"
#include "OC1Control.h"
#include "OCControl.h"
#include "pwms.h"
#include "timer3.h"
#include "timer4.h"

#include "string.h"

#include "errorControl.h"

#include "quantities.h"

#include "mainSettingsScreen.h"
#include "splashScreen.h"

#include "globalSettings.h"
#include "settingsSaving.h"

#include "ControlLoop.h"

#include "pwmSettingScreen1.h"
#include "pwmSettingScreen.h"
#include "stabilityTestSettings.h"
#include "batterySettingsScreen.h"
#include "TimeCounter.h"
#include "flashWriting.h"
#include "inverter.h"

// TODO clean code

#define GP(x,y) getPointSPIDisplay(x,y)

#define ERROR_DELAY_CYCLES 1000000
#define MAX_ERROR_LEN 400

#define ERROR_ID 4

void drawGraph (int *num);

void updateScreen ();

void slaveSel (int active);

void lampeggia ();


void mainLoop ();
void initGOLObjects ();
void initHW ();

void tryTMR3 ();
void tryABITS();

static MYGRAPH *gr;
static STATICTEXT *time;
static STATICTEXT *errors;


static int dataSerie [128];

/*
 * Visualizza gli errori accaduti e svuota la coda
 */
static void errorDisplay ();

/*void __attribute__((__interrupt__, __auto_psv__))  _MathError (void)
{
    IFS0bits.T3IF = 0;
}

void __attribute__((__interrupt__, __auto_psv__))  _StackError (void)
{
    IFS0bits.T3IF = 0;
}

void __attribute__((__interrupt__, __auto_psv__))  _AddressError (void)
{
    IFS0bits.T3IF = 0;
}

void __attribute__((__interrupt__, __auto_psv__))  _OscillatorFail (void)
{
    IFS0bits.T3IF = 0;
}*/

int main()
{
    //tryABITS();

    //addSetting(0, 0, NULL);

    initSettings();

    initHW();
 
    initGOLObjects();

    //tryTMR3();

    initQuantities();

    initActQuantity();

    initTimeCounter();

    mainLoop();

    return 0;
}

void initHW ()
{
long int realFreq;

    inverterInit();

    CLKDIVbits.PLLPRE = 0;
    PLLFBDbits.PLLDIV = 20;
    CLKDIVbits.PLLPOST = 0;

    initGlobalPinout();

    realFreq = setClockFreq (32000000, PRIMARY, 32000000);

    //realFreq = setClockFreq (FRC_BASE_FREQ, PRIMARY, FRC_BASE_FREQ);

    IEC0bits.INT0IE = 0;
    IPC0bits.INT0IP = 0;

    initPWMs(25);
    
    initErrorControl();

    SRbits.IPL = 0;

    
}

void initGOLObjects ()
{
GOL_SCHEME *pScheme;
WORD state;
int i;


    GOLInit();

    pScheme = GOLCreateScheme();

    pScheme ->Color0 = 0x00;
    pScheme ->Color1 = 0x01;

    pScheme ->CommonBkColor = 0x01;

    pScheme ->EmbossDkColor = 0x00;
    pScheme ->EmbossLtColor = 0x01;

    pScheme ->TextColor0 = 0x00;
    pScheme ->TextColor1 = 0x00;




    for (i = 0; i < 128; i++)
    {
        dataSerie[i] = rand()%64;
    }

    

    state = MYGR_DRAW | MYGR_OPTIMIZED;
    gr = MygrCreate (3, 0, 0, 127, 63, state, dataSerie, sizeof(dataSerie)/sizeof(int), 0, 128, 0, 64, 0, 0, 128, 8,  pScheme);

    state = ST_DRAW;
    time = StCreate (2, 0, 0, 128, 8, state, "Dio Sauro", pScheme);

    state = ST_CENTER_ALIGN;
    errors = StCreate (ERROR_ID, 0, 16, 128, 48, state, "NESSUN ERRORE!", pScheme);

}

void mainLoop ()
{
timeMeasurementID_t cycleLenID;
timeUS_t cycleLen;
void (*dLoop)(), (*sEsc)();
int (*sState) ();
int isSetting = 0;

    SRbits.IPL = 0;
    CORCONbits.IPL3 = 0;
    IEC1bits.CNIE = 1;

    splashScreenShow();

    setActQuantity(BATTERY_QID);
    getActQuantity() ->init();

    initControls();

    initTimer(TIMER4_ID, TIMER_TIMER, TIMER_IDLE_CONTINUE);
    setTimerInterval (TIMER4_ID, CONTROL_LOOP_LAUNCH_DELAY);
    setTimerEnabled (TIMER4_ID, TIMER_ON);

    dLoop = getActQuantity() -> mainMeasurementLoop;

    while (1)
    {

        dLoop();

        controlLoop();

        //errorDisplay(); // TODO lasciare!

        if (!isSetting)
        {
            if (getLastPressedKeys().RIGHT_PRESSED == 1)
            {
                getActQuantity()->stop();
                goToNextQuantity();
                getActQuantity() ->init();
                dLoop = getActQuantity() -> mainMeasurementLoop;
            }
            else if (getLastPressedKeys().LEFT_PRESSED == 1)
            {
                getActQuantity()->stop();
                goToPreviousQuantity();
                getActQuantity() ->init();
                dLoop = getActQuantity() -> mainMeasurementLoop;
            }
            else if (getLastPressedKeys().ESC_PRESSED == 1)
            {
                if (getActQuantity()->ID == PWMS_QID)
                {
                    getActQuantity()->stop();

                    pwmSInit();

                    dLoop = pwmSDisplayLoop;

                    isSetting = 1;
                    sState = pwmSState;
                    sEsc = pwmSLeavingScreen;
                }
                else if (getActQuantity()->ID == PWMS_STABILITY_TEST_QID)
                {
                    getActQuantity()->stop();

                    stabilityTestSInit();

                    dLoop = stabilityTestSDisplayLoop;

                    isSetting = 1;
                    sState = stabilityTestSState;
                    sEsc = stabilityTestSLeavingScreen;
                }
                else if (getActQuantity()->ID == BATTERY_QID)
                {
                    getActQuantity()->stop();

                    batterySInit();

                    dLoop = batterySDisplayLoop;

                    isSetting = 1;
                    sState = batterySState;
                    sEsc = batterySLeavingScreen;
                }
            }
            flushLastKeys();
        }

        if (isSetting && sState() == MAIN_SCREEN)
        {
                dLoop();
                sEsc();
                getActQuantity() ->init();
                dLoop = getActQuantity() -> mainMeasurementLoop;
                isSetting = 0;
        }

        if (timerCompleted(TIMER4_ID) &&  getActQuantity()->ID != CONSOLE_QID)
        {
            error_t err;

            err = newError("HIGH CYCLE TIME", "", ERROR);

            addError(&err);
        }

        waitForTimerCompletion(TIMER4_ID);
    }

    
}

static void errorDisplay ()
{
error_t *actError;
char errorStr [MAX_ERROR_LEN], err[] = "ERRORE", warn[] = "WARNING";
long int i;
GOL_SCHEME *pScheme;
WORD state;

    if (getError() != NULL)
    {
        pScheme = GOLCreateScheme();

        pScheme ->Color0 = 0x00;
        pScheme ->Color1 = 0x01;

        pScheme ->CommonBkColor = 0x01;

        pScheme ->EmbossDkColor = 0x00;
        pScheme ->EmbossLtColor = 0x01;

        pScheme ->TextColor0 = 0x00;
        pScheme ->TextColor1 = 0x00;

        GOLDeleteObjectByID (ERROR_ID);

        state = ST_CENTER_ALIGN;
        errors = StCreate (ERROR_ID, 0, 16, 128, 48, state, "NESSUN ERRORE!", pScheme);

        while ((actError = getError()) != NULL)
        {
            sprintf (errorStr, "%s: ", actError->errorType == ERROR?err:warn);

            strcat (errorStr, actError->name);
            strcat (errorStr, "\n");
            strcat (errorStr, actError->description);

            StSetText (errors, errorStr);

            errors->hdr.state = ST_DRAW | ST_CENTER_ALIGN;
            GOLDraw();
            refreshSPIDisplay();

            for (i = 0; i < ERROR_DELAY_CYCLES; i++);

            deleteError();
        }

        GOLDeleteObjectByID (ERROR_ID);
    }
}