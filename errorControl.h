/* 
 * File:   errorControl.h
 * Author: Davide
 *
 * Created on 8 luglio 2013, 13.52
 */

#ifndef ERRORCONTROL_H
#define	ERRORCONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ERROR_NAME_MAX_CHAR 20
#define ERROR_DESCRIPTION_MAX_CHAR 100

    typedef enum
    {
        ERROR,
        WARNING
    }errorType_t;

    typedef struct
    {
        char name[ERROR_NAME_MAX_CHAR];
        char description[ERROR_DESCRIPTION_MAX_CHAR];
        errorType_t errorType;
    }error_t;

    /*
     * Inizializza il modulo di gestione e controllo degli errori
     */
    void initErrorControl();

    /*
     * Ritorna un nuovo errore date le caratteristiche che deve avere
     * 
     * input:
     *  - name: nome dell'errore
     *  - description: descrizione dell'errore
     *  - errorType: tipo dell'errore
     */
    error_t newError (const char *name, const char *description, errorType_t errorType);

    /*
     * Aggiunge un errore alla coda
     *
     * input:
     *  - error: l'errore da aggiungere
     */
    void addError (error_t *error);

    /*
     * Ritorna il primo errore della coda
     * 
     * output:
     *  - il primo errore della coda
     */
    error_t *getError ();

    /*
     * Elimina il primo errore della coda
     */
    void deleteError ();

     /*
     * Ritorna l'errore di indice index nella coda
     *
     * input:
     * - index: l'indice dell'errore
     *
     * output:
     *  - l'errore di indice index nella coda
     */
    error_t *getErrorByIndex (int index);

#ifdef	__cplusplus
}
#endif

#endif	/* ERRORCONTROL_H */

