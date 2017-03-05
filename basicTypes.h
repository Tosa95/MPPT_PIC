/* 
 * File:   basicTypes.h
 * Author: Davide
 *
 * Created on 1 agosto 2013, 13.31
 */

#ifndef BASICTYPES_H
#define	BASICTYPES_H

#ifdef	__cplusplus
extern "C" {
#endif

#define STRVALUE_MAX_LEN 30
#define SECOND_US 1000000
#define SECOND_NS 1000000000

    typedef enum { FALSE_B = 0, TRUE_B = 1} bool_t;

    typedef double timeS_t;
    typedef double timeUS_t;
    typedef double timeNS_t;

    typedef unsigned long long int discreteTimeS_t;
    typedef unsigned long long int discreteTimeUS_t;
    typedef unsigned long long int discreteTimeNS_t;

    typedef enum
    {
        NONE_SCANCODE = 0,
        TAB_SCANCODE = 9,
        LF_SCANCODE = 10,
        CR_SCANCODE = 13,
        CLR_SCANCODE = 24,
        ESC_SCANCODE = 27,
        UP_SCANCODE = 38,
        DOWN_SCANCODE = 40,
        LEFT_SCANCODE = 37,
        RIGHT_SCANCODE = 39
    }stdKeyScan_t;

    typedef char *string_t;
    typedef const char *constString_t;
    typedef char strValue_t[STRVALUE_MAX_LEN];

    typedef struct
    {
        int num, den;
    }iFraction_t;

    typedef double percentage_t;

    /*
     * Ritorna una frazione dati numeratore e denominatore
     *
     * input:
     *  - num: numeratore
     *  - den: denominatore
     *
     * output:
     *  - frazione creata
     */
    iFraction_t getIFraction (int num, int den);

    /*
     * Riduce ai minimi termini una frazione
     *
     * input:
     *  - f: frazione da ridurre
     *
     * output:
     *  - frazione ridotta
     */
    iFraction_t reduceIFraction (iFraction_t f);

    /*
     * Crea una frazione dato un double
     *
     * input:
     *  - d: numero da cui trarre la frazione
     *
     * output:
     *  - frazione creata
     */
    iFraction_t getIFractionFromDouble (double d);

    /*
     * Calcola l'MCD tra due numeri
     *
     * input:
     *  - a: primo numero
     *  - b: secondo numero
     *
     * output:
     *  - risultato
     */
    int MCD(int a, int b);

    /*
     * Calcola la percentuale dato il valore e i due limiti
     *
     * input:
     *  - min: limite inferiore
     *  - max: limite superiore
     *  - val: valore
     *
     * output:
     *  - percentuale calcolata
     */
    percentage_t getPercentage (double min, double max, double val);

    /*
     * Calcola il valore data la percentuale e i due limiti
     *
     * input:
     *  - min: limite inferiore
     *  - max: limite superiore
     *  - perc: percentuale
     *
     * output:
     *  - valore calcolato
     */
    double getValueFromPercentage (double min, double max, double perc);

#ifdef	__cplusplus
}
#endif

#endif	/* BASICTYPES_H */

