#include "basicTypes.h"

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
iFraction_t getIFraction (int num, int den)
{
    iFraction_t res = {num, den};
    
    return res;
}

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
int MCD(int a, int b)
{
    int r;
    r = a % b;             // operazione modulo //
    while(r != 0)          // ciclo di iterazione //
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

/*
 * Riduce ai minimi termini una frazione
 *
 * input:
 *  - f: frazione da ridurre
 *
 * output:
 *  - frazione ridotta
 */
iFraction_t reduceIFraction (iFraction_t f)
{
    int mcd;

    mcd = MCD(f.num, f.den);

    f.num /= mcd;
    f.den /= mcd;

    return f;
}

/*
 * Crea una frazione dato un double
 *
 * input:
 *  - d: numero da cui trarre la frazione
 *
 * output:
 *  - frazione creata
 */
iFraction_t getIFractionFromDouble (double d)
{
iFraction_t res;
int mul = 1;
double act = d;

    while (act != (int)act)
    {
        mul *= 10;
        act *= 10;
    }

    res = getIFraction((int)act, mul);
    return reduceIFraction (res);
}

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
    percentage_t getPercentage (double min, double max, double val)
    {
        percentage_t res;

        res = (percentage_t) (((val-min)*100.0)/(max-min));

        if (res>100) res = 100;
        if (res<0) res = 0;

        return res;
    }

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
    double getValueFromPercentage (double min, double max, double perc)
    {
        return (double) ((((max-min)/100)*perc)+min);
    }