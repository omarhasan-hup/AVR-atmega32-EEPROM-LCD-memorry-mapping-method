#include "lcd.h"
#include <util/delay.h>
void LCD_cmd(uint8 cmd)
{
	DIO_portWrite(LCD_DATA,cmd);
	_delay_ms(1);
	ctrl->port.allRegister = (0<<rs)|(0<<rw)|(1<<en);
	_delay_ms(1);
	ctrl->port.allRegister = (0<<rs)|(0<<rw)|(0<<en);
	_delay_ms(10);
}
void LCD4_cmd(uint8 cmd)
{
	uint8 value=0;
	value = (cmd & 0xf0);
	LCD_cmd(value);
	_delay_ms(1);
	value = ((cmd<<4) & 0xf0);
	LCD_cmd(value);
	_delay_ms(1);
}
void LCD_init()
{
	LCD_cmd(0x38);
	_delay_ms(1);
	LCD_cmd(0x01);
	_delay_ms(1);
	LCD_cmd(0x0E);
	_delay_ms(1);
	LCD_cmd(0x80);
	_delay_ms(1);
}

void LCD4_init()
{
	LCD4_cmd(0x02);
	_delay_ms(1);
	LCD4_cmd(0x28);
	_delay_ms(1);
	LCD4_cmd(0x0c);
	_delay_ms(1);
	LCD4_cmd(0x06);
	_delay_ms(1);
	LCD4_cmd(0x80);
	_delay_ms(1);
}
void LCD_clear()
{
	LCD_cmd(0x01);
}

void LCD4_clear()
{
	LCD4_cmd(0x01);
}
void LCD_write(uint8 data)
{
	LCD_DATA->port.allRegister = data;
	ctrl->port.allRegister = (1<<rs)|(0<<rw)|(1<<en);
	_delay_ms(1);
	ctrl->port.allRegister = (1<<rs)|(0<<rw)|(0<<en);
	_delay_ms(10);
}
void LCD4_write(uint8 data)
{
	uint8 value;
	value = (data & 0xf0);
	LCD_write(value);
	_delay_ms(1);
	value = ((data<<4) & 0xf0);
	LCD_write(value);
	_delay_ms(1);
}

void LCD_write_string(uint8* data)
{
	uint8 n=0;
	while(data[n])
	{
		LCD_write(data[n]);
		n++;
		if (n==16)
		{
			LCD_cmd(0xC0);
		}
	}
}
void LCD4_write_string(uint8* data)
{
	uint8 n=0;
	while(data[n])
	{
		LCD4_write(data[n]);
		n++;
		if (n==16)
		{
			LCD4_cmd(0xC0);
		}
	}
}