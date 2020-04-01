/*
 * interruptuse.h
 *
 * Created: 1/29/2020 6:04:23 PM
 *  Author: Eng_omar
 */ 


#ifndef INTERRUPTUSE_H_
#define INTERRUPTUSE_H_
#include "U_CONFIG.h"
#include "ExternalinterruptAtmega32.h"
#include "DIO_ATmega32A.h"
void int0(void);
void int1(void);
void int2(void);
void threeinterrupt(void);
void end_check(void);



#endif /* INTERRUPTUSE_H_ */