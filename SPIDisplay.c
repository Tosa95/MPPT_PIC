#include <xc.h>

#include "globalPinout.h"

#include "SPIDisplay.h"
#include "SPIControl.h"
#include "vincent.h"
#include "timer1.h"

#define SET_A0_COMMAND A0_LAT = 0
#define SET_A0_DATA A0_LAT = 1

#define INSTANTANEOUS_SEND_DEFAULT 0

#define MAXX 128
#define MAXY 64

#define PAGE_NUM 8

//---Variabili globali

//Invia subito un pixel appena modificato
int instantaneousSend;

//Buffer grafico: contiene lo stato attuale di tutti i pixel del display
static char displayMtrx [PAGE_NUM][MAXX];

//---Procedure private

//Attiva o disattiva il pin per selezionare il display
static void slaveSel (int active);

//Invia un comando al display
static inline void sendCommand (char command);

//Invia un dato alla memoria grafica del display
static inline void sendData (char data);

//Imposta la posizione del cursore grafico sul display
static inline void setPosition (char x, char y);

//Aspetta del tempo
static void delay(int cycles);

//Inizializza il buffer grafico
static void initMtrx();

//Disegna una linea verticale sul display
static void drawVLine (int x, int y1, int y2);

void initSPIDisplay ()
{
    initSPI(3, 7, 0, 1);
    setSlaveSelectSPI (slaveSel);

    #ifdef PARALLEL_SERIAL_SELECTION_DISPLAY
        PS_LAT = 0;
    #endif

    RES_LAT = 0;
    delay (20000);
    RES_LAT = 1;

    delay (20000);
    sendCommand (0xA2);
    delay (20000);
    sendCommand (0xA0);
    delay (20000);
    sendCommand (0xC8);
    delay (20000);
    sendCommand (0xA4);
    delay (20000);
    sendCommand (0x40);
    delay (20000);
    sendCommand (0x25);
    delay (20000);
    sendCommand (0x81);
    delay (20000);
    sendCommand (0x13);
    delay (20000);
    sendCommand (0x2F);
    delay (20000);
    sendCommand (0xAF);
    delay (20000);
    sendCommand(0xA3);
    delay (20000);
    //sendCommand (0xF8);
    //sendCommand (0x03);

    instantaneousSend = INSTANTANEOUS_SEND_DEFAULT;
    
    initMtrx();
    refreshSPIDisplay();
}

static void slaveSel (int active)
{
    if (active)
    {
        CS1_LAT = 0;
    }
    else
    {
        CS1_LAT = 1;
    }
}

static void delay(int cycles)
{
int i;

    for (i = 0; i < cycles; i++);
}

static inline void sendCommand (char command)
{
    SET_A0_COMMAND;

    sendSPI (command);
}

static inline void sendData (char data)
{
    SET_A0_DATA;

    sendSPI (data);
}

static inline void setPosition (char x, char y)
{
    char com1, com2, com3;

    com1 = (0x0B<<4) | (y & 0x0F);
    com2 = (0x00<<4) | (x & 0x0F);
    com3 = (0x01<<4) | ((x & 0xF0)>>4);

    sendCommand (com1);
    sendCommand (com2);
    sendCommand (com3);
}

static void initMtrx()
{
    int i, j;

    for (i = 0; i < PAGE_NUM; i++)
    {
        for (j = 0; j < MAXX; j++)
        {
            displayMtrx[i][j] = 0;
        }
    }
}

void inline refreshSPIDisplay ()
{
    int i, j;

    for (i = 0; i < PAGE_NUM; i++)
    {
        setPosition (0, i);
        for (j = 0; j < MAXX; j++)
        {
            sendData (displayMtrx[i][j]);
        }
    }
}

void inline setPixelSPIDisplay (int x, int y, char color)
{
    char page = (char)y>>3, data, bitNum = (char)y%8, mask;

    if (x < MAXX && y < MAXY && x >= 0 && y >= 0)
    {
        data = displayMtrx[page][x];

        mask = 0x01<<bitNum;

        if (color != 0)
        {
            data |= mask;
        }
        else
        {
            mask = ~mask;
            data &= mask;
        }

        displayMtrx[page][x] = data;

        if (instantaneousSend != 0)
        {
            setPosition (x, page);
            sendData(data);
        }
    }
}

void drawLineSPIDisplay (point p1, point p2)
{
point pMin, pMax, pAct, pPrec;
int x, y;
double m, q;

    pMin = p1.x<p2.x?p1:p2;
    pMax = p1.x>p2.x?p1:p2;

    if (p1.x != p2.x)
    {
        m = (pMax.y-pMin.y)/(double)(pMax.x-pMin.x);
        q = pMin.y - m*pMin.x;

        for (x = pMin.x, pPrec = pMin; x <= pMax.x; x++)
        {
        int yMax, yMin;

            pAct.x = x;
            pAct.y = m*x + q;

            yMax = pAct.y > pPrec.y?pAct.y:pPrec.y;
            yMin = pAct.y < pPrec.y?pAct.y:pPrec.y;

            yMin ++;
            yMax --;

            if (yMax >= yMin) drawVLine (pAct.x, yMin, yMax);

            setPixelSPIDisplay (pAct.x, pAct.y, 1);

            pPrec = pAct;
        }
    }
    else
    {
        drawVLine (p1.x, p1.y, p2.y);
    }
}

static void drawVLine (int x, int y1, int y2)
{
    int i, yMin, yMax;

    yMin = y1 < y2? y1 : y2;
    yMax = y1 > y2? y1 : y2;

    for (i = yMin; i <= yMax; i++)
    {
        setPixelSPIDisplay (x, i, 1);
    }
}

void eraseSPIDisplay()
{
    initMtrx();
}

point getPointSPIDisplay (int x, int y)
{
point ris;

    ris.x = x;
    ris.y = y;

    return ris;
}

int inline maxXSPIDisplay ()
{
    return MAXX;
}

int inline maxYSPIDisplay ()
{
    return MAXY;
}

void printCharSPIDisplay (char c, int x, int y)
{
vincentChar chr;
int i,j;

    chr = getCharVincent (c);

    for (i = 0; i < CHAR_HEIGHT; i++)
    {
        for (j = 0; j < CHAR_HEIGHT; j++)
        {
            setPixelSPIDisplay (x + j, y + i, chr.pixelMatrix[i][j]);
        }
    }
}

void setInstantaneousSendSPIDisplay (int value)
{
    instantaneousSend = value;
}

int getInstantaneousSendSPIDisplay ()
{
    return instantaneousSend;
}

char getPixelSPIDisplay (int x, int y)
{
    char page = (char)y>>3, data, bitNum = (char)y%8, mask, ris;

    if (x < MAXX && y < MAXY && x >= 0 && y >= 0)
    {
        data = displayMtrx[page][x];

        mask = 0x01<<bitNum;

        ris = data & mask;

        ris = ris >> bitNum;

        return ris;
    }

    return 0;
}

inline char getPageSPIDisplay (int x, int y)
{
    return displayMtrx[(char)(y>>3)][x];
}

inline void setPageSPIDisplay (int x, int y, char val)
{
    displayMtrx[(char)(y>>3)][x] = val;
    if (instantaneousSend != 0)
    {
       setPosition (x, y>>3);
       sendData(displayMtrx[(char)(y>>3)][x]);
    }
}