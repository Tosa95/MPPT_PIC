#include "CNControl.h"
#include <xc.h>

#define MAX_CALLBACKS 5

static int numCb = 0;

static CNCallback_t cbs[MAX_CALLBACKS];

void addCNCallback(CNCallback_t cb)
{
    cbs[numCb++] = cb;
}

void __attribute__((__interrupt__, __auto_psv__)) _CNInterrupt ()
{
    int i;

    for (i = 0; i < numCb; i++)
        cbs[i]();

    IFS1bits.CNIF = 0;
}