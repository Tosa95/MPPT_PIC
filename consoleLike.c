#include "consoleLike.h"
#include "SPIDisplay.h"
#include "vincent.h"

#define STDIN   0
#define STDOUT  1
#define STDERR  2
#define LF   '\n'
#define CR   '\r'

int iX = 0, iY = 0, actX = 0, actY = 0;

void drawGraph (int *num);

void moveCurConsoleLike (int x, int y)
{
    iX = x;
    iY = y;
    resetConsoleLike();
}

void resetConsoleLike ()
{
    actX = iX;
    actY = iY;
}

void putch (char c)
{
    if (c != '\n')
    {
        printCharSPIDisplay ((char)c, actX, actY);

        actX += CHAR_WIDTH;

        if (actX+CHAR_WIDTH - 1 >= maxXSPIDisplay())
        {
            actX = iX;
            actY += CHAR_HEIGHT;
        }
    }
    else
    {
        actX = iX;
        actY += CHAR_HEIGHT;
    }
}


void    mon_putc(char ch);

int __attribute__((__weak__, __section__(".libc")))
write(int handle, void * buffer, unsigned int len)
{
    int i = 0;
    switch (handle)
    {
        case STDOUT:
        case STDERR:    while (i < len)
                            putch(((char*)buffer)[i++]);
                        break;
    }
    return (len);  // number of characters written
}

