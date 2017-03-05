/* 
 * File:   addressableBits.h
 * Author: Davide
 *
 * Created on 27 giugno 2013, 18.01
 */

#ifndef ADDRESSABLEBITS_H
#define	ADDRESSABLEBITS_H

#ifdef	__cplusplus
extern "C" {
#endif

    #define MAX_BITS 16

    typedef volatile unsigned int *specialFunctionRegister;

    typedef struct
    {
        specialFunctionRegister reg;
        int startingBitN, endingBitN;
    }addressableBit;

    addressableBit getAddressableBit (specialFunctionRegister reg, int startingBitN, int endingBitN);

    inline void setBit (addressableBit bt,unsigned int value);

    inline unsigned int getBit (addressableBit bt);

    #define GET_BIT(adBit) ((*(adBit.reg)) & (1 << adBit.bitN)) != 0

    #define SET_BIT(adBit, value) value==0? (*(adBit.reg)) &= (~(1 << adBit.bitN)) : (*(adBit.reg)) |= (1 << adBit.bitN)

#ifdef	__cplusplus
}
#endif

#endif	/* ADDRESSABLEBITS_H */

