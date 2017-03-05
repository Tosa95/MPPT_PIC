/* 
 * File:   stdTypes.h
 * Author: Davide
 *
 * Created on 2 luglio 2013, 16.11
 */

#ifndef STDTYPES_H
#define	STDTYPES_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "geometry.h"
#include "basicTypes.h"

    typedef long int freqHZ_t;
    typedef long int freqKHZ_t;
    typedef int freq100KHZ_t;
    typedef double voltageV_t;

    typedef unsigned int voltage10bits_t;

    typedef struct
    {
        voltage10bits_t voltage;
        voltageV_t upperLimit;
    }voltage10bitswl_t;



#ifdef	__cplusplus
}
#endif

#endif	/* STDTYPES_H */

