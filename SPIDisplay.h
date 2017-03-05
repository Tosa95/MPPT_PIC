/* 
 * File:   SPIDisplay.h
 * Author: Davide
 *
 * Created on 22 aprile 2013, 17.18
 */

#ifndef SPIDISPLAY_H
#define	SPIDISPLAY_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct
    {
        int x, y;
    }point;

    //Inizializza il display (chiamarla prima di usare la SDA)
    void initSPIDisplay ();

    //Invia al display l'intero buffer grafico
    void refreshSPIDisplay ();

    //Imposta un pixel del display
    void inline setPixelSPIDisplay (int x, int y, char color);

    //Riceve un pixel dal display
    char inline getPixelSPIDisplay (int x, int y);

    //Traccia una linea sul display
    void drawLineSPIDisplay (point p1, point p2);

    //Cancella l'intero display
    void eraseSPIDisplay();

    //Ritorna un punto date due coordinate
    point getPointSPIDisplay (int x, int y);

    //Ritorna il numero di colonne del display
    int inline maxXSPIDisplay ();

    //Ritorna il numero di righe del display
    int inline maxYSPIDisplay ();

    //Imposta se inviare o meno un pixel appena dopo averlo settato (0 = no, 1 = si)
    void setInstantaneousSendSPIDisplay (int value);

    //Ritorna il flag che decide se inviare o meno un pixel appena dopo averlo settato (0 = no, 1 = si)
    int getInstantaneousSendSPIDisplay ();

    //Stampa un carattere di testo alle coordinate specificate
    void printCharSPIDisplay (char c, int x, int y);

    inline char getPageSPIDisplay (int x, int y);

    inline void setPageSPIDisplay (int x, int y, char val);

#ifdef	__cplusplus
}
#endif

#endif	/* SPIDISPLAY_H */

