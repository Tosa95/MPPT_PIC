/* 
 * File:   SPIControl.h
 * Author: Davide
 *
 * Created on 22 aprile 2013, 16.38
 */

#ifndef SPICONTROL_H
#define	SPICONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

    void initSPI (int prescale1, int prescale2, int clockEdge, int clockPolarity);
    void inline setSlaveSelectSPI (void (*ss) (int active));
    void inline sendSPI (char byte);

#ifdef	__cplusplus
}
#endif

#endif	/* SPICONTROL_H */

