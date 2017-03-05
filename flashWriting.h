/* 
 * File:   flashWriting.h
 * Author: Davide
 *
 * Created on 20 dicembre 2014, 14.41
 */

#ifndef FLASHWRITING_H
#define	FLASHWRITING_H

#ifdef	__cplusplus
extern "C" {
#endif

    void erase();
    void toShadow ();
    void toBuffer ();
    void setShadow (int index, unsigned char val);
    unsigned char getShadow (int index);
    void saveToFlash();
    void loadFromFlash();
    void setData (unsigned int offset, unsigned int size, const void *data);
    void getData (unsigned int offset, unsigned int size, void *data);

#ifdef	__cplusplus
}
#endif

#endif	/* FLASHWRITING_H */

