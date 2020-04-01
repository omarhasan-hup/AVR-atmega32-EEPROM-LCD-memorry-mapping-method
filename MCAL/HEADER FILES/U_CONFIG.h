/*
 * U_CONFIG.h
 *
 * Created: 1/27/2020 9:12:29 AM
 *  Author: Omar Hasan 
 */ 


#ifndef U_CONFIG_H_
#define U_CONFIG_H_
#define _AVR_ATMEGA32A_H_INCLUDED
/*this is defined to prevent the avr/io.h to be defined here. when it enters the 
  guard file and see this definition it will think the avr/io.h is included */

/*Including the needed header files to be used always with all source files */
#include "macroes.h"
#include "stdTypes.h"

/****************************CPU FREQUANCY DETERMINATION***************************/
#define F_CPU (8000000U)

/**************************CPU Internal Registers <SFRs & GPRs>*************************/

/*The registers SFR AND GPR are defined here in the u_config header file, because there
  many files using them. Also they contain many bits for several registers*/
#define IO_OFFSET	(0x20)
/*This is the beginning of the IO_prefiral at the memory 
  Page (17) at the data sheet */
#define SRAM_OFFSET	(0x60)
/*The same goes for the beginning of the SRAM addresses page(17) at he data sheet */
#define CPU_REG		((vuint8 *)0x00)
/*NEEDED COMMENT HERE */
#define NULL	((void *) 0x0FFF)
/*NEEDED COMMENT HERE */
/*see the register summary at the data sheet page(331)
  each one of them is set using the reg8 data type defined below */
#define ATMEGA32_SREG		((reg8*)(0x3F+IO_OFFSET))
#define ATMEGA32A_MCUCR		((reg8*)(0x35+IO_OFFSET))
#define ATMEGA32_MCUCSR		((reg8*)(0x34+IO_OFFSET))
#define ATMEGA32_GICR		((reg8*)(0x3B+IO_OFFSET))
#define GIFR				((reg8*)(0x3A+IO_OFFSET))

/**************************Global Interrupt Related Macros***********************************/
#define GLOBAL_INTERRUPT_ENABLE  (ATMEGA32_SREG->bits.bit7=1)
#define GLOBAL_INTERRUPT_DISABLE (ATMEGA32_SREG->bits.bit7=0)

/********************Attribute Defines FOR AVR Interrupt Handling****************************/
#define ISR_NONBLOCK 	__attribute__((interrupt))
/*this attribute is used to enable the nested interrupts as it set I_BIT at the begging 
  of the ISR*/
#define ISR_BLOCK
/*THIS ATTRIBUTE clears the I_BIT at the begging of the ISR which will block the nested interrupts*/
#define ISR_NAKED      	__attribute__((naked))
/*this attribute does not save the current cpu registers before the interrupt.the user is 
responsible for using this interrupt method.  */
#define ISR_ALIASOF(v) 	__attribute__((alias(__STRINGIFY(v))))
/*this attribute is used to put an interrupt vector insted of another*/
#define _VECTOR(N) 		__vector_ ## N
/**/

#define ISR(V,...)	void V (void) __attribute__ ((signal)) __VA_ARGS__;\
void V (void)

/***********USER DEFINDED DATA TYPE FOR AVR MICRO FOR MAPPING THE MEMORY*******************/

/*this below union is used to access the memory addresses
  so you have two options:
                          1_use the (allRegister) variable to store a binary in all the register 
						  2_use the (bits) struct to access the each bit alone
						  */
typedef union
{
	vuint8 allRegister;
	struct  
	{
		vuint8 bit0:1;
		vuint8 bit1:1;
		vuint8 bit2:1;
		vuint8 bit3:1;
		vuint8 bit4:1;
		vuint8 bit5:1;
		vuint8 bit6:1;
		vuint8 bit7:1;
	}bits;
}reg8;

/*the below structure use three of all (reg8) data types.
  the three (reg8) data types are put in this order, because the lowest address is the
  PIN addresses so when this structure is called it adjusts itself at the correct addresses*/
typedef struct  
{
	reg8 pin;
	reg8 ddr;
	reg8 port;
}DIO_Struct;
#endif /* U_CONFIG_H_ */