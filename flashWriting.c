#include "flashWriting.h"
#include "buffer.h"

#include <xc.h>

void toShadow ();

void erase ()
{
     unsigned int old = TBLPAG;

     unsigned int addr = __builtin_tbladdress(flashBuffer);
     unsigned int page = __builtin_tblpage (flashBuffer);
     
     TBLPAG = __builtin_tblpage (flashBuffer);
     __builtin_disi(20);
     unsigned int off = __builtin_tbloffset(flashBuffer);
     __builtin_tblwtl (off, 0);
     NVMCON = 0x4042;
     __builtin_write_NVM();

     TBLPAG = old;
}

void toShadow ()
{
    int i;

    unsigned int old = TBLPAG;

    TBLPAG = __builtin_tblpage (&flashBuffer);
    unsigned off = __builtin_tbloffset(&flashBuffer);

    i = 0;
    
    while (i < BUFFER_SIZE)
    {
        unsigned int act = __builtin_tblrdl(off);

        shadowBuffer[i] = (act&0xFF);
        i++;

        shadowBuffer[i] = (act&0xFF00)>>8;
        i++;

        off += 2;
    }

    TBLPAG = old;
}

void toBuffer ()
{
    int i;

    erase();

    unsigned int old = TBLPAG;

    TBLPAG = __builtin_tblpage (&flashBuffer);
    unsigned off = __builtin_tbloffset(&flashBuffer);

    i = 0;

    while (i < BUFFER_SIZE)
    {
       unsigned int act;
       unsigned int nxt;

       act = shadowBuffer[i];
       i++;
       nxt = shadowBuffer[i];
       i++;
       act = (nxt<<8) + (act);

       __builtin_tblwtl (off, act);
       NVMCON = 0x4003;
       __builtin_disi(30);
       __builtin_write_NVM();

       off += 2;
    }

    TBLPAG = old;

    unsigned act = __builtin_tblrdl(__builtin_tbloffset(&flashBuffer));
}

void setShadow (int index, unsigned char val)
{
    shadowBuffer[index] = val;
}

unsigned char getShadow (int index)
{
    return shadowBuffer[index];
}

void saveToFlash()
{
    toBuffer();
}

void setData (unsigned int offset, unsigned int size, const void *data)
{
    char *dataBuf = (char *)data;
    int i;
    
    for (i = 0; i < size; i++)
    {
        shadowBuffer[offset+i] = dataBuf[i];
    }
}

void getData (unsigned int offset, unsigned int size, void *data)
{
    char *dataBuf = (char *)data;
    int i;
    
    for (i = 0; i < size; i++)
    {
        dataBuf[i] = shadowBuffer[offset+i];
    }
}

void loadFromFlash()
{
    toShadow();
}