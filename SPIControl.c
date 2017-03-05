#include <xc.h>

#include "globalPinout.h"

#include "SPIControl.h"
#include "display.h"

#include "timer1.h"

static void (*slaveSel) (int active);

//Aspetta del tempo
static void delay(int cycles);

void initSPI (int prescale1, int prescale2, int clockEdge, int clockPolarity)
{

    SPI1STATbits.SPIEN = 0;

    delay (20000);

    SPI1CON1bits.DISSCK = 0;
    SPI1CON1bits.DISSDO = 0;
    
    SPI1CON1bits.MODE16 = 0;
    
    SPI1CON1bits.CKE = clockEdge;
    SPI1CON1bits.CKP = clockPolarity;
    
    SPI1CON1bits.SSEN = 0;
    
    SPI1CON1bits.MSTEN = 1;

    SPI1CON1bits.SMP = 1;

    SPI1CON1bits.SPRE = prescale2;
    SPI1CON1bits.PPRE = prescale1;

    prescale2 = SPI1CON1bits.SPRE;
    prescale1 = SPI1CON1bits.PPRE;

    SPI1STATbits.SPIEN = 1;
}

void inline setSlaveSelectSPI (void (*ss) (int active))
{
    slaveSel = ss;
}

void inline sendSPI (char byte)
{
    slaveSel (1);

    SPI1BUF = byte;

    while (!IFS0bits.SPI1IF);

    byte = SPI1BUF;

    slaveSel (0);
}

static void delay(int cycles)
{
int i;

    for (i = 0; i < cycles; i++);
}