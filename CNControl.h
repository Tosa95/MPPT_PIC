/* 
 * File:   CNControl.h
 * Author: Davide
 *
 * Created on 21 dicembre 2014, 10.34
 */

#ifndef CNCONTROL_H
#define	CNCONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef void (*CNCallback_t)();

    void addCNCallback(CNCallback_t cb);


#ifdef	__cplusplus
}
#endif

#endif	/* CNCONTROL_H */

