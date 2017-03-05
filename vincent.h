#ifndef VINCENT_H
#define VINCENT_H 1

#define CHAR_WIDTH 8
#define CHAR_HEIGHT 8

typedef struct
{
    char pixelMatrix [CHAR_WIDTH][CHAR_HEIGHT];
}vincentChar;

vincentChar getCharVincent (char code);

#endif
 