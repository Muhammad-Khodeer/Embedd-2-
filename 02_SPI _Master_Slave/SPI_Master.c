 
#include<avr/io.h>
#define F_CPU 1000000UL
#include<util/delay.h>
#define NUL ((void *) 0)
#define FALSE (0!=0)
typedef unsigned char u8;
typedef enum {
	Ok,
	BUSSY,
	NullPoint
}Stat;
void SPI_MasterInit(void);
Stat SPI_RX(u8 * SendData, volatile u8 * RecData);
int main()
{
	DDRD=0xff;
	PORTD=0x00;
	 u8 y, x=120;
	SPI_MasterInit();
	
	while(1)
	{
		_delay_ms(1000);
		SPI_RX(&x,&x); // send 120 to slave
			
	}
}


void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, CS output ,all others input */
	DDRB = (1<<DDB5)|(1<<DDB7);//|(1<<DDB4);
	//PORTB |= (1<<DDB4);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
//	SPDR = 0X03;
}
Stat SPI_RX(u8 * SendData, volatile u8 * RecData)
	{
		Stat retval;

	if((SPSR & (1<<SPIF)))
	{
	PORTD = SPDR;
	/* Start transmission */
	SPDR = 3;
	/* Wait for transmission complete */
	}else
	{
		retval = BUSSY;
	}
			return retval;
	}

		
