#include <xc.h>
#include "display.h"

#define DISP0_SELECT LATBbits.LATB12
#define DISP1_SELECT LATBbits.LATB13
#define DISP2_SELECT LATBbits.LATB15

#define SEG_A   LATBbits.LATB8
#define SEG_B   LATBbits.LATB7
#define SEG_C   LATBbits.LATB4
#define SEG_D   LATBbits.LATB3
#define SEG_E   LATBbits.LATB9
#define SEG_F   LATBbits.LATB5
#define SEG_G   LATBbits.LATB6
#define SEG_DP  LATBbits.LATB2

#define SEG_ON  0
#define SEG_OFF 1

#define DISPLAY_NUM 3

int aNum = 0;
int aBase = 10;

/*
 * Makes all the work necessary to make the display work.
 */
void initDisplay()
{
    AD1PCFGL = 0xFFFF;

    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0;
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB15 = 0;

    DISP0_SELECT = 0;
    DISP0_SELECT = 0;
    DISP0_SELECT = 0;

    SEG_A = SEG_OFF;
    SEG_B = SEG_OFF;
    SEG_C = SEG_OFF;
    SEG_D = SEG_OFF;
    SEG_E = SEG_OFF;
    SEG_F = SEG_OFF;
    SEG_G = SEG_OFF;
    SEG_DP = SEG_OFF;
}

/*
 * Enables all the displays and turn all the lamps on.
 */
void lampTest ()
{
    DISP0_SELECT = 1;
    DISP1_SELECT = 1;
    DISP2_SELECT = 1;

    SEG_A = SEG_ON;
    SEG_B = SEG_ON;
    SEG_C = SEG_ON;
    SEG_D = SEG_ON;
    SEG_E = SEG_ON;
    SEG_F = SEG_ON;
    SEG_G = SEG_ON;
    SEG_DP = SEG_ON;
}

/*
 * Rurn on one of the three display.
 * The input number is the id of the display (0-2).
 * If the input is out if the range 0-2 all displays are turned off.
 */
void selectDisplay (char dispNum)
{
    clearDisplay();
    
    switch (dispNum)
    {
        case 0:
            DISP0_SELECT = 1;
            DISP1_SELECT = 0;
            DISP2_SELECT = 0;
            break;
        case 1:
            DISP0_SELECT = 0;
            DISP1_SELECT = 1;
            DISP2_SELECT = 0;
            break;
        case 2:
            DISP0_SELECT = 0;
            DISP1_SELECT = 0;
            DISP2_SELECT = 1;
            break;
        default:
            DISP0_SELECT = 0;
            DISP1_SELECT = 0;
            DISP2_SELECT = 0;
            break;
    }
}
void setSegment (char segment)
{
    switch (segment)
    {
        case 'a':
            SEG_A = SEG_ON;
            break;
        case 'b':
            SEG_B = SEG_ON;
            break;
        case 'c':
            SEG_C = SEG_ON;
            break;
        case 'd':
            SEG_D = SEG_ON;
            break;
        case 'e':
            SEG_E = SEG_ON;
            break;
        case 'f':
            SEG_F = SEG_ON;
            break;
        case 'g':
            SEG_G = SEG_ON;
            break;
        case 'p':
            SEG_DP = SEG_ON;
            break;
    }
}

void clearSegment (char segment)
{
    switch (segment)
    {
        case 'a':
            SEG_A = SEG_OFF;
            break;
        case 'b':
            SEG_B = SEG_OFF;
            break;
        case 'c':
            SEG_C = SEG_OFF;
            break;
        case 'd':
            SEG_D = SEG_OFF;
            break;
        case 'e':
            SEG_E = SEG_OFF;
            break;
        case 'f':
            SEG_F = SEG_OFF;
            break;
        case 'g':
            SEG_G = SEG_OFF;
            break;
        case 'p':
            SEG_DP = SEG_OFF;
            break;
    }   
}

void writeDigit (unsigned char digit)
{
int j;

    clearDisplay();

    switch (digit)
    {
       case 0x0:
            setSegment('a');
            setSegment('b');
            setSegment('c');
            setSegment('d');
            setSegment('e');
            setSegment('f');
            break;
       case 0x1:
            setSegment('b');
            setSegment('c');
            break;
       case 0x2:
            setSegment('a');
            setSegment('b');
            setSegment('g');
            setSegment('e');
            setSegment('d');
            break;
       case 0x3:
            setSegment('a');
            setSegment('b');
            setSegment('g');
            setSegment('c');
            setSegment('d');
            break;
       case 0x4:
            setSegment('f');
            setSegment('g');
            setSegment('b');
            setSegment('c');
            break;
       case 0x5:
            setSegment('a');
            setSegment('f');
            setSegment('g');
            setSegment('c');
            setSegment('d');
            break;
       case 0x6:
            setSegment('a');
            setSegment('f');
            setSegment('e');
            setSegment('d');
            setSegment('c');
            setSegment('g');
            break;
       case 0x7:
            setSegment('a');
            setSegment('b');
            setSegment('c');
            break;
       case 0x8:
            setSegment('a');
            setSegment('b');
            setSegment('c');
            setSegment('d');
            setSegment('e');
            setSegment('f');
            setSegment('g');
            break;
       case 0x9:
            setSegment('a');
            setSegment('b');
            setSegment('c');
            setSegment('d');
            setSegment('f');
            setSegment('g');
            break;
       case 0xA:
            setSegment('e');
            setSegment('f');
            setSegment('a');
            setSegment('b');
            setSegment('c');
            setSegment('g');
            break;
       case 0xB:
            setSegment('f');
            setSegment('e');
            setSegment('d');
            setSegment('c');
            setSegment('g');
            break;
       case 0xC:
            setSegment('a');
            setSegment('f');
            setSegment('e');
            setSegment('d');
            break;
       case 0xD:
            setSegment('b');
            setSegment('c');
            setSegment('d');
            setSegment('e');
            setSegment('g');
            break;
       case 0xE:
            setSegment('a');
            setSegment('f');
            setSegment('e');
            setSegment('d');
            setSegment('g');
            break;
       case 0xF:
            setSegment('a');
            setSegment('f');
            setSegment('e');
            setSegment('g');
            break;
       default:
            clearDisplay();
            break;
    }
}

void clearDisplay ()
{
    LATBbits.LATB0 = 1;
     SEG_A = SEG_OFF;
     SEG_B = SEG_OFF;
     SEG_C = SEG_OFF;
     SEG_D = SEG_OFF;
     SEG_E = SEG_OFF;
     SEG_F = SEG_OFF;
     SEG_G = SEG_OFF;
     SEG_DP = SEG_OFF;
}

void writeNumber (int num, int b)
{
int i;

    clearDisplay();
    selectDisplay(DISPLAY_NUM);

    for (i = 0; i < DISPLAY_NUM; i++)
    {
        
        selectDisplay(i);
        clearDisplay();
        writeDigit (num%b);
        num /= b;
        if (num == 0) break;
    }

    

    clearDisplay();
    selectDisplay(DISPLAY_NUM);
}

void writeFloatNumber (double num)
{
int i, dpPos, pow = 1, j, intNum = num, stop = 0, b = 10;
double dNum = num - intNum;

    for ( i = 0; i <= DISPLAY_NUM && !stop; i++)
    {
        if (num < pow) stop = 1;
        pow *= b;
    }

    i--;

    dpPos = i>0?i:1;

    dpPos = DISPLAY_NUM - dpPos;

    selectDisplay(dpPos);
    setSegment ('p');

    for (i = 0; i < 40; i++);

    for (i = dpPos; i < DISPLAY_NUM; i++)
    {
        selectDisplay(i);
        writeDigit (intNum%b);

        intNum /= b;

        if (intNum == 0) break;
    }

    for (i = dpPos - 1; i >= 0; i--)
    {
    int digit;

        selectDisplay(i);

        digit = (dNum *= b);
        writeDigit (digit);
        dNum -= digit;
        for (j = 0; j < 30; j++);
    }

    selectDisplay (DISPLAY_NUM);
}

/*
 * Makes it possible to asynchronously write a number on the display. It will be
 * really written only during the refresh routine.
 */
void asyncWriteNumber (int num, int b)
{
    aNum = num;
    aBase = b;
}

/*
 * Refreshes the display.
 */
void refreshDisplay ()
{
static int i = 0, num;

    if (num == 0 || i == DISPLAY_NUM)
    {
        num = aNum;
        i = 0;
    }

    selectDisplay(i);
    clearDisplay();
    writeDigit (num%aBase);
    num /= aBase;
    i++;
    
}