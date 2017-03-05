#include <xc.h>
#include "settingsSaving.h"
#include "errorControl.h"
#include <string.h>
#include <stdio.h>

#define SETTINGS_BUFFER_SIZE    1000    //Lunghezza buffer dati
#define MAX_SETTINGS_NUM        100     //Massimo numero di impostazioni salvate

typedef unsigned int settingAddress_t;

typedef struct
{
    settingID_t ID;
    settingAddress_t addr;
    settingSize_t size;
}indexEntry_t;


__psv__ indexEntry_t sIndex[MAX_SETTINGS_NUM] __attribute__((space(prog)));
const unsigned int indexQueue /*__attribute__ ((space(prog)))*/ = 8;

__psv__ char buffer  [SETTINGS_BUFFER_SIZE] __attribute__((space(prog)));
__psv__ unsigned int bufferQueue __attribute__ ((space(prog))) = 0;


/*
 * Scrive sulla memoria flash una WORD
 */
void writeToFlash ();

/*
 * Cancella una pagina della memoria flash
 */
void eraseFlashPage ();

/*
 * Inserisce un impostazione nel modulo che si occupa della gestione delle stesse
 *
 * input:
 *  - sID: id dell'impostazione (unico, l'unicità deve essere garantita dall'utente)
 *  - sz: dimensione in byte dell'impostazione
 *  - setting: puntatore all'impostazione (sarà poi copiata nel sistema)
 *
 * output:
 *  - TRUE_B se l'inserimento è andato a buon fine, FALSE_B altrimenti
 */
bool_t addSetting (settingID_t sID, settingSize_t sz, const void *setting)
{
    unsigned int act;
    char descr[30];
        //sIndex[indexQueue].ID = sID;
        //sIndex[indexQueue].size = sz;
        TBLPAG = __builtin_tblpage (&indexQueue);
        unsigned int page = __builtin_tblpage (&indexQueue);
        unsigned int off = __builtin_tbloffset(&indexQueue);
        /*act = __builtin_tblrdl(off);
        __builtin_tblwtl (off, 11);
        __builtin_tblwth (++off, 27);
        NVMCON = 0x4003;
        SR = 0x00E0;
        __builtin_write_NVM();
        //NVMCONbits.WR = 1;*/

    eraseFlashPage (&indexQueue);

       act = __builtin_tblrdl(off);

       
       
       __builtin_tblwtl (off, 11);
       __builtin_tblwth (off, 1);
       NVMCON = 0x4003;
       __builtin_disi(30);
       __builtin_write_NVM();

       act = __builtin_tblrdl(off);

       sprintf(descr, "%d", 12);

       error_t e = newError("AA", descr, WARNING);
       addError(&e);
}

/*
 * Scrive sulla memoria flash una WORD
 */
void writeToFlash ()
{
     __builtin_disi(300);

     NVMCON  =  0x4003;

     __builtin_write_NVM();
}

/*
 * Cancella una pagina della memoria flash
 */
void eraseFlashPage (const void *addr)
{
     TBLPAG = __builtin_tblpage (&indexQueue);
     __builtin_disi(30);
     unsigned int off = __builtin_tbloffset(&indexQueue);
     __builtin_tblwtl (off, 0);
     NVMCON = 0x4042;
     __builtin_write_NVM();
}