/*
 * EEPROM.h
 *
 * Created: 3/11/2020 1:50:19 PM
 *  Author: Eng_omar
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "U_CONFIG.h"
#include "stdTypes.h"
#include "macroes.h"
/*The register definitions*/
#define EEDR ((reg8*)(0x1D + IO_OFFSET))
#define EECR ((reg8*)(0x1C + IO_OFFSET))
#define EEARL ((reg8*)(0x1E + IO_OFFSET))
#define EEARH ((reg8*)(0x1F + IO_OFFSET))

/*The function prototypes*/
/*This function to write the data in a specific address in the memory */
void write_eeprom(uint16 address,sint8 data);
/*This function to read the data in a specific address in the memory */
sint8 read_eeprom(uint16 address);
/*This function is to store a 16 bit variable in a TWO 8 bit register 
                                                                     EEARL register
																	 EEARH register
 */
void eeprom_address(uint16);


#endif /* EEPROM_H_ */