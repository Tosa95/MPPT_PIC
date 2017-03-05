#include <xc.h>

#include "OC1Control.h"
#include "timer2.h"

#define OC1_RP 0x12

#define OC1_TIMER2 0
#define OC1_TIMER3 1

timer usedTmr;

void OC1init (timerID tmr, OC1Mode mode)
{
int oc1Timer;

    //OC1CONbits.OCM = OC1_DISABLED;

    if (tmr == TIMER3)
    {
        oc1Timer = OC1_TIMER3;
    }
    else
    {
        oc1Timer = OC1_TIMER2;
        tmr = TIMER2;
    }

    getTimer (tmr, &usedTmr);

    //OC1CONbits.OCTSEL = oc1Timer;
    //OC1CONbits.OCM = mode;

    PR3;
}

void setOC1Interval (int uS)
{
    usedTmr.setInterval (uS);
}

void setOC1R (int val)
{
    if (OC1R != val)
        OC1R = val;
}

void setOC1RS (int val)
{
    if (OC1RS != val)
        OC1RS = val;
}

void OC1Start ()
{
    usedTmr.reset();
    usedTmr.start();
}

void OC1Stop ()
{
    usedTmr.stop();
}

void setOC1PWM (long int freq, long int dutyCycle)
{
long int tOn, step, interval;
int r;
    

   /* if (OC1CONbits.OCM != OC1_PWM && OC1CONbits.OCM != OC1_PWM_FAULT)
    {
        OC1CONbits.OCM = OC1_PWM;
    }*/

    interval = 1000000L/freq;

    tOn = (dutyCycle * interval)/100;

    step = 1000000L / usedTmr.getFreq();

    r = tOn / step;

    //OC1Stop();

    setOC1Interval (interval);
    setOC1R (r);
    setOC1RS (r);

    //usedTmr.reset();
    //OC1Start();
}
