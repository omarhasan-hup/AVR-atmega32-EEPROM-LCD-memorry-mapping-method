/*
 * DIO_ATmega32A.h
 *
 * Created: 1/27/2020 3:19:05 PM
 *  Author: Eng_omar
 */ 


#ifndef DIO_ATMEGA32A_H_
#define DIO_ATMEGA32A_H_
/**************************INCLUDE THE NEEDED HEADER FILES*******************************/
#include "U_CONFIG.h"
#include "macroes.h"
#include "stdTypes.h"

/**************************DEFNITIONS FOR PORT ADDRESSES TO BE ACCESSES******************/

#define DIOA ((DIO_Struct*)(IO_OFFSET+0x19))
#define DIOB ((DIO_Struct*)(IO_OFFSET+0x16))
#define DIOC ((DIO_Struct*)(IO_OFFSET+0x13))
#define DIOD ((DIO_Struct*)(IO_OFFSET+0x10))

/*use the DIO_struct pointer to talk with the 3 registers PIN,DDR,PORT with accurate addresses*/

/*****************private data types used in this header file only************************/
typedef enum
{
	INPUT_FLOAT,
	INPUT_PULLUP,
	OUTPUT,
}pinMode;
/*this enum is used in this header file to determine the pin mode*/

/*******************************functions prototypes**************************************/
void DIO_pinConfigure(
                       DIO_Struct* dio,
                       pinNumber pin,
					  pinMode mode
					  );

void DIO_pinWrite(
                       DIO_Struct* dio,
					   pinNumber pin,
					   digitalState State
					   );

digitalState DIO_pinRead(DIO_Struct* dio,pinNumber pin);

void DIO_portConfigure(DIO_Struct* dio,vuint8 configbyte);
void DIO_portWrite(DIO_Struct* dio,vuint8 configbyte);
vuint8 DIO_portRead(DIO_Struct* dio);
#endif /* DIO_ATMEGA32A_H_ */