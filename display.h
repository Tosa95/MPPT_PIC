/* 
 * File:   display.h
 * Author: Davide
 *
 * Created on 26 dicembre 2012, 13.49
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#ifdef	__cplusplus
extern "C" {
#endif

    void initDisplay();

    void lampTest ();

    void selectDisplay (char dispNum);

    void setSegment (char segment);

    void clearSegment (char segment);

    void clearDisplay ();

    void writeDigit (unsigned char digit);

    void writeNumber (int num, int b);

    void writeFloatNumber (double num);

    void asyncWriteNumber (int num, int b);

    void refreshDisplay ();

#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAY_H */

