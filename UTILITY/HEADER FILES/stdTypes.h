/*
 * stdTypes.h
 *
 * Created: 1/27/2020 11:20:49 AM
 *  Author: Eng_omar
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_

/*defining data types to use easily */
typedef unsigned char		uint8;
typedef signed char			sint8;
typedef unsigned short		uint16;
typedef signed short		sint16;
typedef unsigned long		uint32;
typedef signed long			sint32;
typedef unsigned long long	uint64;
typedef signed long long	sint64;
typedef float				float32;
typedef double				float64;

/*defining the same data types but with volatile keyword to stop compiller optmiazation*/
typedef volatile uint8   vuint8;
typedef volatile sint8   vsint8;
typedef volatile uint16  vuint16;
typedef volatile sint16  vsint16;
typedef volatile uint32  vuint32;
typedef volatile sint32  vsint32;
typedef volatile uint64  vuint64;
typedef volatile sint64  vsint64;

/*defining the user defined data types which will be used at the all the sources  */

typedef enum
{
	low=0,
	high=1,
}digitalState;

typedef enum
{
	PIN0=0,PIN1=1,PIN2=2,
	PIN3=3,PIN4=4,PIN5=5,
	PIN6=6,PIN7=7,
}pinNumber;

typedef enum 
{
	FALSE=0,
	TREUE=1,
}bool;
#endif /* STDTYPES_H_ */