/* 
 * File:   controls.h
 * Author: Davide
 *
 * Created on 4 luglio 2013, 17.34
 */

#ifndef CONTROLS_H
#define	CONTROLS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdTypes.h"

    typedef struct
    {
        char ESC_PRESSED;
        char UP_PRESSED;
        char DOWN_PRESSED;
        char RIGHT_PRESSED;
        char LEFT_PRESSED;
    }keyMap_t;

    typedef enum
    {
        CONTROLS_NONE = 0,
        CONTROLS_ESC,
        CONTROLS_UP,
        CONTROLS_DOWN,
        CONTROLS_RIGHT,
        CONTROLS_LEFT
    }keyID;

    /*
     * Ritorna il tasto attualmente premuto
     *
     * output:
     *  - codice del tasto attualmente premuto
     */
    keyID getPressedKey ();

    /*
     * Ritorna i tasti attualmente premuti
     *
     * output:
     *  - struttura contenente la situazione attuale
     */
    keyMap_t getPressedKeys ();

    /*
     * Invia i controlli attualmente premuti a GOL
     */
    void sendControlsToGOL();

    /*
     * Ritorna gli ultimi tasti premuti
     *
     * output:
     *  - struttura contenente la situazione attuale
     */
    keyMap_t getLastPressedKeys ();


    /*
     * Ritorna l'ultimo tasto premuto
     *
     * output:
     *  - ultimo tasto premuto
     */
    keyID getLastPressedKey ();

    /*
     * Resetta i tasti premuti
     */
    void flushLastKeys();

    /*
     * Trasforma il codice di un tasto in un carattere GOL
     */
    char translate (keyID k);

    /*
     * Inizializza il gestore dei controlli
     */
    void initControls ();
#ifdef	__cplusplus
}
#endif

#endif	/* CONTROLS_H */

