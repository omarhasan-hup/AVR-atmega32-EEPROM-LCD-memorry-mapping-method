#include "EEPROM.H" 

/*This function is to store a 16 bit variable in a TWO 8 bit register 
                                                                     EEARL register
																	 EEARH register
 */
void eeprom_address(uint16 address)
{
	EEARL->allRegister=(address & 0xFF);
	EEARH->allRegister=(address >> 8);
}
 void write_eeprom(uint16 address,sint8 data)
 {
	 while((READBIT(EECR->allRegister,1))==1);
	 
	 eeprom_address(address);
	 EEDR->allRegister=data;
	 EECR->bits.bit2=1;
	 EECR->bits.bit1=1;
 }
 
 sint8 read_eeprom(uint16 address)
 {
	 sint8 data_out=0;
	 while((READBIT(EECR->allRegister,1))==1);
	 
	 eeprom_address(address);
	 EECR->bits.bit0=1;
	 data_out=EEDR->allRegister;
	 return data_out;
 }