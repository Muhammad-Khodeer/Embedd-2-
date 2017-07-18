/*
 * EEPROM.c
 *
 * Created: 22/07/2015 12:44:39 ص
 *  Author: Muhammad
 */ 

#include "MYMICRO.h"
#include "EEPROM.h"


/************** Function 1 **********************/
void init_EEPROM(void)
{	
	statusRegister_0;
	bitRate_47;
	I2C_Enable;
}
/************* function 2 **********************/
u8 EEPROM_Read(u8 Address)
{
	i2c_start();				// Start another data transfer
	i2c_write(0b10100000);		// Write mode // the add of the slave and 0 for write
	i2c_write(Address);		    // Write address // write the addressee that i want to read data from
	i2c_start();				// repeat Start //repeat bit
	i2c_write(0b10100001);		// Read mode // the addressee of the salve and 1 for read mode
	u8 x = i2c_read(1);			// Read the Data and write the Ackcnolagement by 1 >> last thing to read 0>>readmore
	i2c_stop();					// Stop the reading session
	
	return x; 
}

void EEPROM_Write(u8 Address ,u8 Data)
{
	i2c_start();			// Start session
	i2c_write(0b10100000);	// Write Mode //write the address // A000  EEPROM address + 0 for write
	i2c_write(0b00000000);	    // Write Address // write the first address in the EEPROM
	i2c_write(Data);		// Store Data 0x15 //Write the data at add 0
	i2c_stop(); 			// finish write Operation
}

