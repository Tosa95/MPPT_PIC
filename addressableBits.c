#include "addressableBits.h"

static unsigned int masks[MAX_BITS] = {0x1, 0x3, 0x7, 0xf, 0x1f, 0x3f, 0x7f, 0xff, 0x1ff, 0x3ff, 0x7ff, 0xfff, 0x1fff, 0x3fff, 0x7fff, 0xffff};

addressableBit getAddressableBit (specialFunctionRegister reg, int startingBitN, int endingBitN)
{
addressableBit ris;

    ris.reg = reg;

    ris.startingBitN = startingBitN;
    ris.endingBitN = endingBitN;

    return ris;
}

inline void setBit (addressableBit bt, unsigned int value)
{
    if (bt.endingBitN < MAX_BITS && bt.startingBitN <= bt.endingBitN)
    {
    unsigned int mask, diff, ris;

        diff = (bt.endingBitN - bt.startingBitN);

        mask = masks[diff];

        mask <<= bt.startingBitN;

        value <<= bt.startingBitN;
        value &= mask;

        ris = (*bt.reg);

        ris |= value;

        mask = ~mask;

        value |= mask;

        ris &= value;

        (*bt.reg) = ris;
    }

}

inline unsigned int getBit (addressableBit bt)
{

    if (bt.endingBitN < MAX_BITS && bt.startingBitN <= bt.endingBitN)
    {
    unsigned int mask, diff;

        diff = (bt.endingBitN - bt.startingBitN)/*+ 1*/;

        mask = masks[diff];

        mask <<= bt.startingBitN;

        return ((*bt.reg) & mask)>>bt.startingBitN;
    }

    return 0;
}