#include <stdlib.h>
#include <xc.h>
#include <math.h>
#include "ADC1Control.h"

#define CHANNEL 0
#define INTERNAL_COUNTER 7

static void (*clbk) ();
static double minVoltage;
static double maxVoltage;

static const int MAX_ADC1BUF0 =  1023;

void __attribute__ ((__interrupt__, __auto_psv__)) _ADC1Interrupt()
{
    if (clbk != NULL)
        clbk();

    IFS0bits.AD1IF = 0;
}

void initADC1
    (int pin,
    ADC1RefSelect voltageReference,
    int conversionClockMul,
    int autoSampleTime,
    ADC1ResultForm resultForm,
    int interruptEnable,
    void (*interruptClbk)(),
    double minV,
    double maxV)
{
    AD1CON1bits.ADON = 0;

    AD1PCFGL = ~((int)pow(2, pin));

    AD1CHS0bits.CH0SB = pin;
    AD1CHS0bits.CH0SA = pin;

    AD1CSSL = pow(2, pin);

    AD1CON2bits.VCFG = voltageReference;
    AD1CON3bits.ADCS = conversionClockMul - 1;
    //AD1CON2bits.CHPS = CHANNEL;
    AD1CON1bits.SSRC = INTERNAL_COUNTER;
    AD1CON3bits.SAMC = autoSampleTime;
    AD1CON1bits.FORM = resultForm;

    IFS0bits.AD1IF = 0;
    IEC0bits.AD1IE = interruptEnable;
    IPC3bits.AD1IP = 7;

    clbk = interruptClbk;

    minVoltage = minV;
    maxVoltage = maxV;

    AD1CON1bits.ADON = 1;
}

inline double getActVoltageADC1 ()
{
double ris, d;

    d = maxVoltage - minVoltage;

    ris = (d * ADC1BUF0)/MAX_ADC1BUF0;

    return ris;
}

inline voltage10bits_t getActBUFADC1 ()
{
    return ADC1BUF0;
}

void beginSamplingADC1 ()
{
    AD1CON1bits.DONE = 0;
    AD1CON1bits.SAMP = 1;

    while (AD1CON1bits.SAMP == 1);
}

int doneADC1 ()
{
    return AD1CON1bits.DONE;
}

long int power (int num, int exponent)
{
    long int ris = 1, i;

    for (i = 0; i < exponent; i++)
        ris *= num;

    return ris;
}

void setInputPinADC1 (int pin)
{
    if (AD1PCFGL != ~(power(2, pin)))
    {
        AD1CON1bits.ADON = 0;

        AD1PCFGL = ~(power(2, pin));

        AD1CHS0bits.CH0SB = pin;
        AD1CHS0bits.CH0SA = pin;

        AD1CSSL = power(2, pin);

        AD1CON1bits.ADON = 1;
    }
}