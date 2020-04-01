#include "U_CONFIG.h"
#include "DIO_ATmega32A.h"
#include <util/delay.h>
#include "interruptplay.h" 
#include "EEPROM.h" 
//extern vsint8 led0;
//extern vsint8 led1;  
#include "LCD.h"
uint8 out='c';
uint8 out_string[16]={"mum_Amira"};
sint8 data='D';
sint8 data2='s';
int main(void)
{ 
/*threeinterrupt();*/
DIO_portConfigure(DIOC,0x00);
DIO_pinConfigure(DIOB,PIN7,OUTPUT);
DIO_pinConfigure(DIOB,PIN6,OUTPUT);
DIO_pinConfigure(DIOB,PIN5,OUTPUT);
LCD_init();
	while(1)
	{
		//end_check();
		write_eeprom(500,data);
		LCD_write(data);
		_delay_ms(1000);
		LCD_clear();
		_delay_ms(1000);
		data2=read_eeprom(500);
		LCD_write(data2);
		_delay_ms(1000);
		LCD_clear();
	}
	
	
	return 0;
}