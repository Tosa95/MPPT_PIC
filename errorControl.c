#include "errorControl.h"

#include <string.h>
#include <stdlib.h>

#define MAX_ERRORS 5

typedef struct _errorQueueNode_t
{
    error_t error;
    struct _errorQueueNode_t *next;
}errorQueueNode_t;

typedef errorQueueNode_t *errorQueueIterator_t;

typedef struct
{
    errorQueueIterator_t head;
    errorQueueIterator_t tail;
}errorQueue_t;

errorQueue_t eq;
int errorNum = 0;

/*
 * Inizializza il modulo di gestione e controllo degli errori
 */
void initErrorControl()
{
    eq.head = NULL;
    eq.tail = NULL;
}

/*
 * Ritorna un nuovo errore date le caratteristiche che deve avere
 *
 * input:
 *  - name: nome dell'errore
 *  - description: descrizione dell'errore
 *  - errorType: tipo dell'errore
 */
error_t newError (const char *name, const char *description, errorType_t errorType)
{
error_t ris;

    strcpy (ris.name, name);
    strcpy (ris.description, description);
    ris.errorType = errorType;

    return ris;
}

/*
 * Aggiunge un errore alla coda
 *
 * input:
 *  - error: l'errore da aggiungere
 */
void addError (error_t *error)
{
errorQueueIterator_t newNode;

    if (errorNum > MAX_ERRORS)
    {
        deleteError();
    }

    newNode = (errorQueueIterator_t) malloc (sizeof(errorQueueNode_t));

    newNode -> next = NULL;

    newNode -> error = *error;

    if (eq.tail != NULL)
    {
        eq.tail -> next = newNode;
    }
    else
    {
        eq.head = newNode;
    }

    eq.tail = newNode;

    errorNum++;
}

/*
 * Ritorna il primo errore della coda
 *
 * output:
 *  - il primo errore della coda
 */
error_t *getError ()
{
    if (eq.head != NULL)
        return &(eq.head -> error);
    else
        return NULL;
}

/*
 * Elimina il primo errore della coda
 */
void deleteError ()
{
    if (eq.head != NULL)
    {
    errorQueueIterator_t tmp;

        tmp = eq.head;

        eq.head = tmp->next;

        if (eq.head == NULL) eq.tail = NULL;

        free (tmp);

        errorNum--;
    }
}

 /*
 * Ritorna l'errore di indice index nella coda
 *
 * input:
 * - index: l'indice dell'errore
 *
 * output:
 *  - l'errore di indice index nella coda
 */
error_t *getErrorByIndex (int index)
{
int i = 0;
errorQueueNode_t *act = eq.head;

    while (act!=NULL)
    {
        if (i == index)
            return &(act->error);

        act = act->next;

        i++;
    }

    return NULL;
}
