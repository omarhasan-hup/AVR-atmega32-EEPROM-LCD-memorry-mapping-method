/*
 * LCD.h
 *
 * Created: 3/11/2020 3:35:24 PM
 *  Author: Eng_omar
 */ 
/*This driver will work on the lcd to interface with data at portC and control the lcd
  using portB as follow 
                       bit7 as rs
					   bit6 as rw
					   bit5 as en
*/  

#ifndef LCD_H_
#define LCD_H_
#include "U_CONFIG.h"
#include "macroes.h"
#include "stdTypes.h"
#include "DIO_ATmega32A.h"
#define LCD_DATA DIOC
#define ctrl DIOB
#define rs 7
#define rw 6
#define en 5
void LCD_cmd(uint8);
void LCD4_cmd(uint8);
void LCD_init();
void LCD4_init();
void LCD_clear();
void LCD4_clear();
void LCD_write(uint8 data);
void LCD4_write(uint8 data);
void LCD4_write_string(uint8* data);
void LCD_write_string(uint8* data);



#endif /* LCD_H_ */