/*
 * ExternalInterruptsAtmega32A.c
 *
 * Created: 1/28/2020 2:49:43 PM
 *  Author: Eng_omar
 */ 
#include "ExternalinterruptAtmega32.h"
#include "U_CONFIG.h"
/*include our own file to get the data types and the functions prototypes*/
/*include the "U_CONFIG" header file to get the GPRS AND SREG REGISTERS
  Also the "U_CONFIG.h" file is included to import the attribute orders written in it*/

/*defining the interrupts names*/
#define INT0VECTOR	_VECTOR(1)
#define INT1VECTOR	_VECTOR(2)
#define INT2VECTOR	_VECTOR(3)
/*****making the 3 pointers to functions to be replaced inside the ISR*****************/
void(*EXTINT0_Functionp)(void)=NULL;
void(*EXTINT1_Functionp)(void)=NULL;
void(*EXTINT2_Functionp)(void)=NULL;
/****************************************************************************************/

ISR(INT0VECTOR)
{
	if (EXTINT0_Functionp !=NULL)
	{
		EXTINT0_Functionp();
	}
	
}
ISR(INT1VECTOR)
{
	if (EXTINT1_Functionp!=NULL)
	{
		EXTINT1_Functionp();
	}
	
}
ISR(INT2VECTOR)
{
	if (EXTINT2_Functionp!=NULL)
	{
		EXTINT2_Functionp();
	}
	
}

















void ExternalInterrupt_Configure(ExtInt_Number int_number,ExtInt_Mode int_mode)
{
	switch (int_number)
	{
		case EXTINT0:
		/*disable the INT0 MODULE bit to close the interrupts during configuring the interrupts*/
		ATMEGA32_GICR->bits.bit6=0;
		/*then we will start configuring the interrupt according to it's mode */
		switch (int_mode)
		{
			case EXTINT_LOWLVL:
			ATMEGA32A_MCUCR->bits.bit2=0;
			ATMEGA32A_MCUCR->bits.bit3=0;
			break;
			case EXTINT_FALLING:
			ATMEGA32A_MCUCR->bits.bit2=0;
			ATMEGA32A_MCUCR->bits.bit3=1;
			break;
			case EXTINT_RISING:
			ATMEGA32A_MCUCR->bits.bit2=1;
			ATMEGA32A_MCUCR->bits.bit3=1;
			break;
			case EXTINT_BOTHEDGE:
			ATMEGA32A_MCUCR->bits.bit2=1;
			ATMEGA32A_MCUCR->bits.bit3=0;
			break;
			default:
			break;
		}		
		GIFR->bits.bit6=1;
		/*clear the flag to erase any interrupt during config*/
		ATMEGA32_GICR->bits.bit6=1;
		/*at the end enable the INT0 MODULE TO ENABLE EINTERRUPTS*/
		break;
		case EXTINT1:
				/*disable the I bit to close the interrupts during configuring the interrupts*/
				ATMEGA32_GICR->bits.bit7=0;
				/*then we will start configuring the interrupt according to it's mode */
				switch (int_mode)
				{
					case EXTINT_LOWLVL:
					ATMEGA32A_MCUCR->bits.bit0=0;
					ATMEGA32A_MCUCR->bits.bit1=0;
					break;
					case EXTINT_FALLING:
					ATMEGA32A_MCUCR->bits.bit0=0;
					ATMEGA32A_MCUCR->bits.bit1=1;
					break;
					case EXTINT_RISING:
					ATMEGA32A_MCUCR->bits.bit0=1;
					ATMEGA32A_MCUCR->bits.bit1=1;
					break;
					case EXTINT_BOTHEDGE:
					ATMEGA32A_MCUCR->bits.bit0=1;
					ATMEGA32A_MCUCR->bits.bit1=0;
					break;
					default:
					break;
				}
				GIFR->bits.bit7=1;
				/*clear the interrupt flag to ensure to erease any interrupt during config */
				ATMEGA32_GICR->bits.bit7=1;
				/*at the end enable the INT1 MODULE to enable the interrupt */
		break;
		case EXTINT2:
		/*disable the I bit to close the interrupts during configuring the interrupts*/
		ATMEGA32_GICR->bits.bit5=0;
		/*then we will start configuring the interrupt acorrdig to it's mode */
		switch (int_mode)
		{
			case EXTINT_FALLING:
			ATMEGA32_MCUCSR->bits.bit6=0;
			break;
			case EXTINT_RISING:
			ATMEGA32_MCUCSR->bits.bit6=1;
			break;
			default:
			break;
		}
		GIFR->bits.bit5=1;
		/*clear the interrupt2 flag to ensure ereasing any interrupt during config*/
		ATMEGA32_GICR->bits.bit5=1;
		/*enable the interrupt2 module to enable the interrupts from it*/
		break;
		default:
		break;
	}
}
void ExternalInterrupt_Disable(ExtInt_Number int_num)
{
	switch (int_num)
	{
		case EXTINT0:
		ATMEGA32_GICR->bits.bit6=0;
		/*Disable the INT0 MODULE by clearing bit6 in GICR*/
		break;
		case EXTINT1:
		ATMEGA32_GICR->bits.bit7=0;
		/*Disable the INT1 MODULE by clearing bit7 in GICR*/
		break;
		case EXTINT2:
		ATMEGA32_GICR->bits.bit5=0;
		/*Disable the INT2 MODULE by clearing bit5 in GICR*/
		break;
		default:
		break;
	}
}