/* 
 * File:   globalPinout.h
 * Author: Davide
 *
 * Created on 3 luglio 2013, 10.10
 */

#ifndef GLOBALPINOUT_H
#define	GLOBALPINOUT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

//#define PARALLEL_SERIAL_SELECTION_DISPLAY

    //Modulo di descrizione del pinout



    //Display BUS

        //A0 - Register select signal. 0: instruction; 1: data (RC4)
            #define A0_TRIS TRISCbits.TRISC4
            #define A0_PORT PORTCbits.RC4
            #define A0_LAT LATCbits.LATC4

        //!RES - Active LOW Reset signal (RC3)
            #define RES_TRIS TRISCbits.TRISC3
            #define RES_PORT PORTCbits.RC3
            #define RES_LAT LATCbits.LATC3

        //!CS1 - Active LOW chip select (RA9)
            #define CS1_TRIS TRISAbits.TRISA9
            #define CS1_PORT PORTAbits.RA9
            #define CS1_LAT LATAbits.LATA9

#ifdef PARALLEL_SERIAL_SELECTION_DISPLAY
        //PS - Parallel/Serial select. PS= H: Parallel; PS=L: Serial  (RB7)
            #define PS_TRIS TRISBbits.TRISB7
            #define PS_PORT PORTBbits.RB7
            #define PS_LAT LATBbits.LATB7
#endif


    //SPI BUS

        //SI - Serial data input (RP7)
            #define SI_RPOR RPOR3bits.RP7R
            #define SI_CNST 0x07

        //SCL - Serial clock (RP21)
            #define SCL_RPOR RPOR10bits.RP21R
            #define SCL_CNST 0x08


    //PWMs

        //PWM1 - Uscita per controllo PWM1 (comandata dal modulo OC) (RP15)
            #define PWM1_RPOR RPOR7bits.RP15R
            #define PWM1_CNST 0x12

        //PWM2 - Uscita per controllo PWM1 (comandata dal modulo OC) (RP8)
            #define PWM2_RPOR RPOR4bits.RP8R
            #define PWM2_CNST 0x13

        //PWM3 - Uscita per controllo PWM1 (comandata dal modulo OC) (RP6)
            #define PWM3_RPOR RPOR3bits.RP6R
            #define PWM3_CNST 0x14

        //PWM4 - Uscita per controllo PWM1 (comandata dal modulo OC) (RP5)
            #define PWM4_RPOR RPOR2bits.RP5R
            #define PWM4_CNST 0x15

    //Tasti
        
        //P1 - Input digitale per lettura stato tasti CENTRALE [PULL-UP] (RB9/CN21)
            #define P1_TRIS TRISBbits.TRISB9
            #define P1_PORT PORTBbits.RB9
            #define P1_LAT LATBbits.LATB9
            #define P1_CNPU CNPU2bits.CN21PUE
            #define P1_CNEN CNEN2bits.CN21IE

        //P2 - Input digitale per lettura stato tasti  DESTRA [PULL-UP] (RC8/CN20)
            #define P2_TRIS TRISCbits.TRISC8
            #define P2_PORT PORTCbits.RC8
            #define P2_LAT LATCbits.LATC8
            #define P2_CNPU CNPU2bits.CN20PUE
            #define P2_CNEN CNEN2bits.CN20IE

        //P3 - Input digitale per lettura stato tasti  SU [PULL-UP] (RB13/CN13)
            #define P3_TRIS TRISBbits.TRISB13
            #define P3_PORT PORTBbits.RB13
            #define P3_LAT LATBbits.LATB13
            #define P3_CNPU CNPU1bits.CN13PUE
            #define P3_CNEN CNEN1bits.CN13IE

        //P4 - Input digitale per lettura stato tasti SINISTRA [PULL-UP] (RB12/CN14)
            #define P4_TRIS TRISBbits.TRISB12
            #define P4_PORT PORTBbits.RB12
            #define P4_LAT LATBbits.LATB12
            #define P4_CNPU CNPU1bits.CN14PUE
            #define P4_CNEN CNEN1bits.CN14IE

        //P5 - Input digitale per lettura stato tasti GIU [PULL-UP] (RC9/CN19)
            #define P5_TRIS TRISCbits.TRISC9
            #define P5_PORT PORTCbits.RC9
            #define P5_LAT LATCbits.LATC9
            #define P5_CNPU CNPU2bits.CN19PUE
            #define P5_CNEN CNEN2bits.CN19IE

    //Controllo alimentazione

        //VCCON - Abilitazione alimentazione del sistema [OPEN-DRAIN] (RA10)
            #define VCCON_TRIS TRISAbits.TRISA10
            #define VCCON_PORT PORTAbits.RA10
            #define VCCON_LAT LATAbits.LATA10
            #define VCCON_ODC ODCAbits.ODCA10

    //Network

        //NETCON - Connessione alla rete elettrica (RB14)
            #define NETCON_TRIS TRISBbits.TRISB14
            #define NETCON_PORT PORTBbits.RB14
            #define NETCON_LAT  LATBbits.LATB14

    //Inverter

        //INVCON - Controllo accensione inverter [PULL-UP] (RB11/CN15)
        #define INVCON_TRIS TRISBbits.TRISB11
        #define INVCON_PORT PORTBbits.RB11
        #define INVCON_LAT LATBbits.LATB11
        #define INVCON_CNPU CNPU1bits.CN15PUE
        #define INVCON_CNEN CNEN1bits.CN15IE

    //Fan

        //FANCON - Controllo ventola (RB4)
            #define FANCON_TRIS TRISBbits.TRISB4
            #define FANCON_PORT PORTBbits.RB4
            #define FANCON_LAT  LATBbits.LATB4

    //Batteria

        //BATTERY - Input analogico batteria (AN4/RB2)
            #define BATTERY_TRIS TRISBbits.TRISB2
            #define BATTERY_AN_PIN_NO 4

    //Correnti

        //CURR1 - Input analogico corrente 1 (AN5/RB3)
            #define CURR1_TRIS TRISBbits.TRISB3
            #define CURR1_AN_PIN_NO 5

        //CURR2 - Input analogico corrente 1 (AN6/RC0)
            #define CURR2_TRIS TRISCbits.TRISC0
            #define CURR2_AN_PIN_NO 6

        //CURR3 - Input analogico corrente 1 (AN7/RC1)
            #define CURR3_TRIS TRISCbits.TRISC1
            #define CURR3_AN_PIN_NO 7

        //CURR4 - Input analogico corrente 1 (AN8/RC2)
            #define CURR4_TRIS TRISCbits.TRISC2
            #define CURR4_AN_PIN_NO 8

    //Funzioni di inizializzazione

        /*
         * Inizializza il modulo globalPinout. Mappa i pin alla funzione
         * corretta.
         */
        void initGlobalPinout ();



#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALPINOUT_H */

