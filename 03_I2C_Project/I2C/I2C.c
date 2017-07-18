/*
 * I2C.c
 * Created: 09/07/2015 06:49:41 م
 *  Author: Muhammad
 */ 
/*
	led is on
	read first value from the EEPROM
	if the value is equal to (0xFF)|| > 99 then value = 00
	show that value on the seven segment
	if the value is less than 99 >> increase the value by one
	write the new value to the first place in the EEPROM
	stop here and never ever move
*/
#define F_CPU 1000000ul
#include <util/delay.h>
#include "SSEG.h"
#include "OStime.h"
#include "EEPROM.h"


int main(void)
{	
	///////////////// Local variables ///////////////////////
	unsigned char MyValue=0 ;
//	unsigned short int i;
	
	///////////////// initialization ///////////////////////
	OStime_start();
	init_SSEG();
	//init_LED4();
	init_EEPROM();
	//////////////// main sequence   ////////////////////////
	
	/*for (i=0;i<3;i++)					// the LED on off three times.
	{
		//LED4_ON();
		_delay_ms(500);
		//LED4_OFF();
		_delay_ms(500);
	}*/
	
	SSEG_Print99(91);					// Printing 91 using one function
	_delay_ms(2000);					// normal delay
	SSEG_Print99(34);					// Printing 34
	_delay_ms(2000);
	//LED_ON();
	
	MyValue = EEPROM_Read(0);			//read value at address zero.
	if (MyValue > 99)					// note: because at the first time the addressee 0 will have the value FF
	{	
		MyValue=0;
	}
	
	SSEG_Print99(MyValue);
	
	if (MyValue < 99)					//note : the value can't be bigger than 99.
	{ 
		MyValue++;						//increase the value by one that means the APP is opened Again.
		EEPROM_Write(0,MyValue);		//save the new value at EEPROM.		
	}

    while(1);							//stop here forever.
}