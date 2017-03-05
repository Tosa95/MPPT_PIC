#include "globalPinout.h"
#include "CNControl.h"
#include "controls.h"
#include "Graphics/GOL.h"
#include "GeneralTimers.h"

#define KEY_NUM 6
#define KEYBOARD_BITS 3

#define PEAK_VALIDATION_TIME_US 10000
#define TIMER_USED_FOR_VALIDATION TIMER3_ID

#define T_ON 0
#define T_OFF 1

int waitingForValidation = 0;
keyMap_t lastPressed = {0, 0, 0, 0, 0};
keyMap_t lastPressedValidated = {0, 0, 0, 0, 0};
/*
 * Funzione di trasformazione da controllo ad ASCII
 */
char ctrlToASCII [KEY_NUM] = {NONE_SCANCODE, ESC_SCANCODE, UP_SCANCODE, DOWN_SCANCODE, RIGHT_SCANCODE, LEFT_SCANCODE};

/*
 * Azzera i tasti non validati
 */
void flushUnvalidated ();

/*
 * Ritorna il tasto attualmente premuto
 *
 * output:
 *  - codice del tasto attualmente premuto
 */
keyID getPressedKey ()
{
    if (P1_PORT == T_ON)
        return CONTROLS_ESC;
    else if (P2_PORT == T_ON)
        return CONTROLS_RIGHT;
    else if (P3_PORT == T_ON)
        return CONTROLS_UP;
    else if (P4_PORT == T_ON)
        return CONTROLS_LEFT;
    else if (P5_PORT == T_ON)
        return CONTROLS_DOWN;
    else
        return CONTROLS_NONE;
}

/*
 * Ritorna i tasti attualmente premuti
 *
 * output:
 *  - struttura contenente la situazione attuale
 */
keyMap_t getPressedKeys ()
{
keyMap_t res;

    res.UP_PRESSED = 0;
    res.DOWN_PRESSED = 0;
    res.LEFT_PRESSED = 0;
    res.RIGHT_PRESSED = 0;
    res.ESC_PRESSED = 0;

    if (P1_PORT == T_ON)
        res.ESC_PRESSED = 1;

    if (P2_PORT == T_ON)
        res.RIGHT_PRESSED = 1;
    if (P3_PORT == T_ON)
        res.UP_PRESSED = 1;
    if (P4_PORT == T_ON)
        res.LEFT_PRESSED = 1;
    if (P5_PORT == T_ON)
        res.DOWN_PRESSED = 1;

    return res;
}

void updateLastPressedKeys ()
{
    if (waitingForValidation)
    {
        waitingForValidation = 0;

        if (getTimerActTime(TIMER_USED_FOR_VALIDATION) >= PEAK_VALIDATION_TIME_US)
        {
            memcpy (&lastPressedValidated, &lastPressed, sizeof(lastPressed));
        }

        flushUnvalidated();
    }

    if (P1_PORT == T_ON)
    {
        lastPressed.ESC_PRESSED = 1;
        waitingForValidation = 1;
    }
    if (P2_PORT == T_ON)
    {
        lastPressed.RIGHT_PRESSED = 1;
        waitingForValidation = 1;
    }
    if (P3_PORT == T_ON)
    {
        lastPressed.UP_PRESSED = 1;
        waitingForValidation = 1;
    }
    if (P4_PORT == T_ON)
    {
        lastPressed.LEFT_PRESSED = 1;
        waitingForValidation = 1;
    }
    if (P5_PORT == T_ON)
    {
        lastPressed.DOWN_PRESSED = 1;
        waitingForValidation = 1;
    }

    if (waitingForValidation)
    {
        resetTimer(TIMER_USED_FOR_VALIDATION);
    }
}

/*
 * Invia i controlli attualmente premuti a GOL
 */
void sendControlsToGOL()
{
    GOL_MSG msg;



    msg.type = TYPE_KEYBOARD;
    msg.uiEvent = EVENT_KEYSCAN;
    msg.param1 = GOLGetFocus()->ID;
    msg.param2 = translate(getLastPressedKey());

    flushLastKeys();

    GOLMsg (&msg);
}

/*
 * Ritorna gli ultimi tasti premuti
 *
 * output:
 *  - struttura contenente la situazione attuale
 */
keyMap_t getLastPressedKeys ()
{
    return lastPressedValidated;
}

/*
 * Ritorna l'ultimo tasto premuto
 *
 * output:
 *  - ultimo tasto premuto
 */
keyID getLastPressedKey ()
{
    keyID key;

    keyMap_t l = getLastPressedKeys();

    if (l.ESC_PRESSED)
        key = CONTROLS_ESC;
    else  if (l.UP_PRESSED)
        key = CONTROLS_UP;
    else  if (l.DOWN_PRESSED)
        key = CONTROLS_DOWN;
    else  if (l.LEFT_PRESSED)
        key = CONTROLS_LEFT;
    else  if (l.RIGHT_PRESSED)
        key = CONTROLS_RIGHT;
    else
        key = CONTROLS_NONE;
}

/*
 * Resetta i tasti premuti
 */
void flushLastKeys()
{
    lastPressedValidated.DOWN_PRESSED = 0;
    lastPressedValidated.ESC_PRESSED = 0;
    lastPressedValidated.UP_PRESSED = 0;
    lastPressedValidated.LEFT_PRESSED = 0;
    lastPressedValidated.RIGHT_PRESSED = 0;

}

/*
 * Interrupt attivato se un tasto viene cliccato
 */
static void callback ()
{
    updateLastPressedKeys();
}

/*
 * Trasforma il codice di un tasto in un carattere GOL
 */
char translate (keyID k)
{
    if (k == CONTROLS_NONE)
        return NONE_SCANCODE;
    else if (k == CONTROLS_ESC)
        return ESC_SCANCODE;
    else if (k == CONTROLS_UP)
        return UP_SCANCODE;
    else if (k == CONTROLS_DOWN)
        return DOWN_SCANCODE;
    else if (k == CONTROLS_LEFT)
        return LEFT_SCANCODE;
    else if (k == CONTROLS_RIGHT)
        return RIGHT_SCANCODE;
}

/*
 * Azzera i tasti non validati
 */
void flushUnvalidated ()
{

    lastPressed.DOWN_PRESSED = 0;
    lastPressed.ESC_PRESSED = 0;
    lastPressed.UP_PRESSED = 0;
    lastPressed.LEFT_PRESSED = 0;
    lastPressed.RIGHT_PRESSED = 0;

    waitingForValidation = 0;
}

/*
 * Inizializza il gestore dei controlli
 */
void initControls ()
{
    initTimer(TIMER_USED_FOR_VALIDATION, TIMER_TIMER, TIMER_IDLE_CONTINUE);
    setTimerInterval (TIMER_USED_FOR_VALIDATION, 1000000);
    setTimerEnabled (TIMER_USED_FOR_VALIDATION, TIMER_ON);
    addCNCallback(callback);
}