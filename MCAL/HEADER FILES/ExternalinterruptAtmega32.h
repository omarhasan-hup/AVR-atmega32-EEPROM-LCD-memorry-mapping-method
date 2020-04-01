/*
 * ExternalinterruptAtmega32.h
 *
 * Created: 1/28/2020 2:28:37 PM
 *  Author: Eng_omar
 */ 


#ifndef EXTERNALINTERRUPTATMEGA32_H_
#define EXTERNALINTERRUPTATMEGA32_H_
/*include the files needed to start this header file*/
#include "U_CONFIG.h"
#include "stdTypes.h"

/****************create the user defined data types needed in this file***********************/
typedef enum
{
	EXTINT0,
	EXTINT1,
	EXTINT2,
}ExtInt_Number;
/*this enum is used to choose the correct external interrupt*/
typedef enum
{
	EXTINT_LOWLVL,
	EXTINT_RISING,
	EXTINT_FALLING,
	EXTINT_BOTHEDGE,
}ExtInt_Mode; 
/*this data type is used to specify the external interrupt mode
  NOTE: EXTINT2 works only with the rising or the falling edge not like the other interrupts*/

/*************************making 3 pointer to functions to be replaced inside the ISR********/
extern void(*EXTINT0_Functionp)(void);
extern void(*EXTINT1_Functionp)(void);
extern void(*EXTINT2_Functionp)(void);
/*THOSE 3 POINTER TO FUCTION IS EXTERNED HERE FROM THE C FILE, SO THAT ANYONE INCLUDE 
  THIS HEADER FILE CAN USE THEM*/











/**************************************Functions prototypes**********************************/
void ExternalInterrupt_Configure(ExtInt_Number intnum,ExtInt_Mode intmode);
void ExternalInterrupt_Disable(ExtInt_Number intnum);


#endif /* EXTERNALINTERRUPTATMEGA32_H_ */