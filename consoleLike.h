/* 
 * File:   consoleLike.h
 * Author: Davide
 *
 * Created on 30 aprile 2013, 18.11
 */

#ifndef CONSOLELIKE_H
#define	CONSOLELIKE_H

#ifdef	__cplusplus
extern "C" {
#endif

    void moveCurConsoleLike (int x, int y);
    void resetConsoleLike ();

    void putch (char c);


#ifdef	__cplusplus
}
#endif

#endif	/* CONSOLELIKE_H */

