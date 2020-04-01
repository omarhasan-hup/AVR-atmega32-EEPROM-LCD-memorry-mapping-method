/*
 * ATMega32A.c
 *
 * Created: 1/27/2020 4:44:01 PM
 *  Author: Eng_omar
 */ 
#include "DIO_ATmega32A.h"
/*include your own file to get the user defined data types and the functions prototypes */

/******************************Fuctions defnitions**************************************/\
void DIO_pinConfigure(DIO_Struct* dio,pinNumber pin,pinMode mode)
{
	switch(mode)
	{
		case INPUT_FLOAT:
		CLEARBIT(dio->ddr.allRegister,pin);
		CLEARBIT(dio->port.allRegister,pin);
		break;
		case INPUT_PULLUP:
		CLEARBIT(dio->ddr.allRegister,pin);
		SETBIT(dio->port.allRegister,pin);
		break;
		case OUTPUT:
		SETBIT(dio->ddr.allRegister,pin);
		CLEARBIT(dio->port.allRegister,pin);
		break;
		default:
		/*error message*/
		break;
	}
}

void DIO_pinWrite(DIO_Struct* dio,pinNumber pin,digitalState State)
{
	switch (State)
	{
		case low:
		CLEARBIT(dio->port.allRegister,pin);
		break;
		case high:
		SETBIT(dio->port.allRegister,pin);
		break;
		default:
		/*error message*/
		break;
	}
}
digitalState DIO_pinRead(DIO_Struct* dio,pinNumber pin)
{
	digitalState return_var=0;
	switch (READBIT(dio->pin.allRegister,pin))
	{
		case low:
		return_var=low;
		break;
		case high:
		return_var=high;
		break;
		default:
		/*error message*/
		break;
	}
	return return_var;
}

void DIO_portConfigure(DIO_Struct* dio,vuint8 configbyte)
{
	dio->ddr.allRegister=configbyte;
}

void DIO_portWrite(DIO_Struct* dio,vuint8 configbyte)
{
	dio->port.allRegister=configbyte;
}
vuint8 DIO_portRead(DIO_Struct* dio)
{
	return (dio->pin.allRegister);
}