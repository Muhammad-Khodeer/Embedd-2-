/*
 * EEPROM.h
 *
 * Created: 22/07/2015 12:45:21 ص
 *  Author: Muhammad
 */ 

typedef unsigned char u8;

#ifndef EEPROM_H_
#define EEPROM_H_

void init_EEPROM(void);
u8 EEPROM_Read(u8 Address);
void EEPROM_Write(u8 Address ,u8 Data);



#endif /* EEPROM_H_ */