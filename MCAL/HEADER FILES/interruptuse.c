/*
 * interruptuse.c
 *
 * Created: 1/29/2020 6:13:37 PM
 *  Author: Eng_omar
 */ 
#include "interruptuse.h"
#include <util/delay.h>
vsint8 led0=-1;
vsint8 led1=-1; 
uint8 looper=0;
void int0(void)
{
	led0++;
	led1--;
	SETBIT(DIOA->port.allRegister,led0);
	SETBIT(DIOC->port.allRegister,led1);
}
void int1(void)
{
	led1++;
	led0--;
	SETBIT(DIOC->port.allRegister,led1);
	SETBIT(DIOA->port.allRegister,led0);
}
void int2(void)
{
	TOGGLEBIT(DIOC->port.allRegister,PIN2);
	
}
void threeinterrupt(void)
{
	/*configure the buttons*/
	DIO_pinConfigure(DIOD,PIN2,INPUT_FLOAT);
	/*this one is for the interrupt 0*/
	DIO_pinConfigure(DIOD,PIN3,INPUT_FLOAT);
	/*this one is for the interrupt 1*/
	//DIO_pinConfigure(DIOB,PIN2,INPUT_FLOAT);
	/*this one is for the interrupt 2*/
	/*configure the interrupts on this buttons*/	
	ExternalInterrupt_Configure(EXTINT0,EXTINT_RISING);
	ExternalInterrupt_Configure(EXTINT1,EXTINT_RISING);
	/*configure the interrupt 0 and 1 to be at the rising edge*/
    //ExternalInterrupt_Configure(EXTINT2,EXTINT_RISING);
	/*configure the leds*/
	/*
	DIO_pinConfigure(DIOC,PIN0,OUTPUT);
	DIO_pinConfigure(DIOC,PIN1,OUTPUT);
	DIO_pinConfigure(DIOC,PIN2,OUTPUT);
	DIO_pinConfigure(DIOC,PIN3,OUTPUT);
	DIO_pinConfigure(DIOC,PIN4,OUTPUT);
	DIO_pinConfigure(DIOC,PIN5,OUTPUT);
	DIO_pinConfigure(DIOC,PIN6,OUTPUT);
	DIO_pinConfigure(DIOC,PIN7,OUTPUT);
	DIO_pinConfigure(DIOA,PIN0,OUTPUT);
	DIO_pinConfigure(DIOA,PIN1,OUTPUT);
	DIO_pinConfigure(DIOA,PIN2,OUTPUT);
	DIO_pinConfigure(DIOA,PIN3,OUTPUT);
	DIO_pinConfigure(DIOA,PIN4,OUTPUT);
	DIO_pinConfigure(DIOA,PIN5,OUTPUT);
	DIO_pinConfigure(DIOA,PIN6,OUTPUT);
	DIO_pinConfigure(DIOA,PIN7,OUTPUT);
	*/
	DIO_portConfigure(DIOA,0xFF);
	DIO_portConfigure(DIOC,0xFF);
	
	EXTINT0_Functionp =int0;
	EXTINT1_Functionp =int1;
	EXTINT2_Functionp =int2;
	GLOBAL_INTERRUPT_ENABLE;
}
void end_check(void)
{
			if(led0>=8)
			{
				for (looper=0;looper<=8;looper++)
				{
					
					DIO_portWrite(DIOA,0xFF);
					_delay_ms(100);
					DIO_portWrite(DIOA,0x00);
					_delay_ms(100);
				}
				DIO_portWrite(DIOA,0x00);
				DIO_portWrite(DIOC,0x00);
				led0=-1;
				led1=-1;
			}
			if(led1>=8)
			{
				for (looper=0;looper<=8;looper++)
				{
					
					DIO_portWrite(DIOC,0xFF);
					_delay_ms(100);
					DIO_portWrite(DIOC,0x00);
					_delay_ms(100);
				}
				DIO_portWrite(DIOA,0x00);
				DIO_portWrite(DIOC,0x00);
				led1=-1;
				led0=-1;
			}
}







