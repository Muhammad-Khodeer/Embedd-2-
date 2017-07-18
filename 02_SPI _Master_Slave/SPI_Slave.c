
#include<avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>

#define DD_MISO PB6
#define DDR_SPI DDRB
void SPI_SlaveInit();
unsigned char SPI_RX(void);
unsigned char rotleft(unsigned char num);
void SPI_MasterTransmit(char cData);
unsigned char glob;
int main()
{
	unsigned char shift = 0x01;
	DDRD=0xFF;
	PORTD=0xFF;
	
	SPI_SlaveInit();
	SPDR = shift;  //This is initialized because when I want it to be sent when the master start the transmission of the first byte
	while(1)
	{
		//shift = rotleft(shift);
		if(SPI_RX()==120) // if received 120 from master toggle portD
		{
			//PORTD=~PORTD;	
			SPDR= 0x44; // put "5" into spdr to be shifted by master and sent by slave to master
			
		}		
	}
	
}
unsigned char rotleft(unsigned char num)
{
    return (num << 1) | (num >> 7);
}

void SPI_SlaveInit(void)
{
/* Set MISO output, all others input */
DDR_SPI = (1<<DD_MISO);
/* Enable SPI */
SPCR |= (1<<SPE);
}


unsigned char SPI_RX()
{
	while(!(SPSR &(1<<SPIF)));	//wait until SPIF get high 
	glob = SPDR;				// return SPDR value
	return glob;
}
