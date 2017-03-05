#include <limits.h>
#include "ClockControl.h"
#include <xc.h>

#define PLLPRE_RANGE 32
#define PLLDIV_RANGE 512
#define PLLPOST_RANGE 4

#define MIN_FREF 800000
#define MAX_FREF 8000000

#define MIN_FVCO 100000000
#define MAX_FVCO 200000000

#define MAX_FOSC 80000000

#define PLLPRE_STARTING_DIV 2
#define PLLDIV_STARTING_DIV 2

#define ASM_WAIT_MACRO(it)   asm ("AWM:\nNOP\nDEC %0, %0\nBRA NZ, AWM\n" : "+r"( it ));
#define ASM_WAIT_MACRO_IPC  3

static long int actClkFreq;

inline static long int labs (long int num);
inline static void clkSwitch (char newClkSrc);

const int PLLPOST_DIVS [4] = {2, 4, 32000, 8};

long int getClockFreq()
{
    return actClkFreq;
}

long int setClockFreq(long int targetFreq, clockSource clkSrc, long int baseFreq)
{
long int dMin = LONG_MAX, bestFreq = LONG_MAX, actFreq, dAct, actFref, actFvco;
int div1, div2, mul, rightPLLPRE = 0, rightPLLDIV = 0, rightPLLPOST = 0, actPLLPRE, actPLLDIV, actPLLPOST;
char rightNOSC;

    if (clkSrc == FRC)
        baseFreq = FRC_BASE_FREQ;

    __builtin_disi(0x3FFF);

    if (targetFreq != baseFreq)
    {
        for (actPLLPRE = 0; actPLLPRE < PLLPRE_RANGE; actPLLPRE++)
        {
            for (actPLLDIV = 0; actPLLDIV < PLLDIV_RANGE; actPLLDIV++)
            {
                for (actPLLPOST = 0; actPLLPOST < PLLPOST_RANGE; actPLLPOST++)
                {
                    div1 = PLLPRE_STARTING_DIV + actPLLPRE;
                    mul = PLLDIV_STARTING_DIV + actPLLDIV;
                    div2 = PLLPOST_DIVS [actPLLPOST];

                    actFref = baseFreq / div1;
                    actFvco = actFref * mul;

                    actFreq = actFvco / div2;

                    dAct = labs (targetFreq - actFreq);

                    if (dAct < dMin && actFref > MIN_FREF && actFref < MAX_FREF && actFvco > MIN_FVCO && actFvco < MAX_FVCO && actFreq < MAX_FOSC)
                    {
                        dMin = dAct;

                        bestFreq = actFreq;

                        rightPLLPRE = actPLLPRE;
                        rightPLLDIV = actPLLDIV;
                        rightPLLPOST = actPLLPOST;
                    }
                }
            }

        }

        actPLLPRE = 0;

        switch (clkSrc)
        {
            case FRC:
                rightNOSC = 0x01;
                break;

            case PRIMARY:
                rightNOSC = 0x03;
                break;
        }

    }
    else
    {
        bestFreq = baseFreq;
        
        switch (clkSrc)
        {
            case FRC:
                rightNOSC = 0x00;
                break;

            case PRIMARY:
                rightNOSC = 0x02;
                break;
        }
    }

    int f = OSCCONbits.OSWEN;

    
    if (rightNOSC != OSCCONbits.COSC)
        clkSwitch (rightNOSC);

    //f = OSCCONbits.OSWEN;

    //TODO Problem !!!
    while ((f = OSCCONbits.OSWEN) != 0);

    __builtin_disi(0x0000);

    /*CLKDIVbits.PLLPRE = rightPLLPRE;
    CLKDIVbits.PLLPOST = rightPLLPOST;
    PLLFBDbits.PLLDIV = rightPLLDIV;*/

    actClkFreq = bestFreq;

    return bestFreq;
}

inline static long int labs (long int num)
{
    if (num < 0)
        return -num;
    else
        return num;
}

inline static void clkSwitch (char newClkSrc)
{   
     __asm__ ("MOV.B %0, w0" : "+r"(newClkSrc));
     __asm__ (                             // Unlock OSCCONH for clock switching
                "MOV     #OSCCONH, w1\n"
                "MOV     #0x78, w2\n"
                "MOV     #0x9A, w3\n"
                "MOV.B   w2, [w1]\n"
                "MOV.B   w3, [w1]\n"
                "MOV.B   WREG,OSCCONH\n"
                "MOV     #0x01, w0\n"
                "MOV     #OSCCONL, w1\n"
                "MOV     #0x46, w2\n"
                "MOV     #0x57, w3\n"
                "MOV.B   w2, [w1]\n"
                "MOV.B   w3, [w1]\n"
                "MOV.B   w0,[w1]"
                /*"wait:
                "btsc OSCCONL, #OSWEN"
                "bra wait"*/
                );
}

/*
 * Blocca l'esecuzione per l'ammontare di uS specificato
 *
 * input:
 *  - time: i uS da attendere
 */
void delayUS (timeUS_t time)
{
timeNS_t time1Ins, time1Cyc;
long int fD2 = getClockFreq()/2;
int cycles;


    time1Ins = 1000000000L/fD2;
    time1Cyc = ASM_WAIT_MACRO_IPC * time1Ins;

    cycles = time*1000 / time1Cyc;

    ASM_WAIT_MACRO (cycles);
}