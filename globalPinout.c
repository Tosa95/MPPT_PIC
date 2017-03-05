#include <xc.h>
#include <math.h>

#include "globalPinout.h"



/*
 * Mappa i pin rimappabili
 */
void mapRPPins ();

/*
 * Imposta i pin digitali per essere ingressi o uscite
 */
void digitalPinsIOSelection ();

/*
 * Imposta i pin analogici per funzionare correttamente
 */
void analogPinsConfig ();

/*
 * Inizializza il modulo globalPinout. Mappa i pin alla funzione
 * corretta.
 */
void initGlobalPinout ()
{
    mapRPPins();
    digitalPinsIOSelection();

    P1TCONbits.PTEN = 0;
    P2TCONbits.PTEN = 0;
}

/*
 * Mappa i pin rimappabili
 */
void mapRPPins ()
{
    asm volatile (                             // Unlock Registers (Per DS39881B-page 102)
                "MOV #OSCCON, w1 \n"
                "MOV #0x46, w2 \n"
                "MOV #0x57, w3 \n"
                "MOV.b w2, [w1] \n"
                "MOV.b w3, [w1] \n"
                "BCLR OSCCON,#6"
                );

    SI_RPOR = SI_CNST;
    SCL_RPOR = SCL_CNST;

    PWM1_RPOR = PWM1_CNST;
    PWM2_RPOR = PWM2_CNST;
    PWM3_RPOR = PWM3_CNST;
    PWM4_RPOR = PWM4_CNST;

    asm volatile (                             // Lock Registers
                "MOV #OSCCON, w1 \n"
                "MOV #0x46, w2 \n"
                "MOV #0x57, w3 \n"
                "MOV.b w2, [w1] \n"
                "MOV.b w3, [w1] \n"
                "BSET OSCCON, #6"
                );
}

/*
 * Imposta i pin digitali per essere ingressi o uscite
 */
void digitalPinsIOSelection ()
{
    A0_TRIS = 0;
    RES_TRIS = 0;
    CS1_TRIS = 0;
    
#ifdef PARALLEL_SERIAL_SELECTION_DISPLAY
    PS_TRIS = 0;
#endif

    VCCON_TRIS = 0;
    //VCCON_ODC = 1;
    VCCON_LAT = 0;

    P1_TRIS = 1;
    P1_CNPU = 1;
    P1_CNEN = 1;

    P2_TRIS = 1;
    P2_CNPU = 1;
    P2_CNEN = 1;
    
    P3_TRIS = 1;
    P3_CNPU = 1;
    P3_CNEN = 1;

    P4_TRIS = 1;
    P4_CNPU = 1;
    P4_CNEN = 1;

    P5_TRIS = 1;
    P5_CNPU = 1;
    P5_CNEN = 1;

    INVCON_TRIS = 1;
    INVCON_CNPU = 1;
    INVCON_CNEN = 1;

    NETCON_TRIS = 0;
    NETCON_LAT = 0;

    FANCON_TRIS = 0;
    FANCON_LAT = 1;
}

/*
 * Imposta i pin analogici per funzionare correttamente
 */
void analogPinsConfig ()
{
    BATTERY_TRIS = 1;
    AD1PCFGL &= ~((int)pow(2, BATTERY_AN_PIN_NO));

    CURR1_TRIS = 1;
    AD1PCFGL &= ~((int)pow(2, CURR1_AN_PIN_NO));

    CURR2_TRIS = 1;
    AD1PCFGL &= ~((int)pow(2, CURR2_AN_PIN_NO));

    CURR3_TRIS = 1;
    AD1PCFGL &= ~((int)pow(2, CURR3_AN_PIN_NO));

    CURR4_TRIS = 1;
    AD1PCFGL &= ~((int)pow(2, CURR4_AN_PIN_NO));
}