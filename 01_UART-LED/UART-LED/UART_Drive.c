////////// MCAL  ////////////////
//Microcontroller Abistraction layer
//////////////////////////////////////
#include <avr\io.h>
#include "UART_Drive.h"


//////////// Global Functions /////////////////////

void USART_Init( unsigned int baud )
{

/* Set baud rate */
UBRRH = (unsigned char)(baud>>8);
UBRRL = (unsigned char)baud;
/* Enable receiver and transmitter */
UCSRB = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 2stop bit */
UCSRC = (1<<URSEL)|(3<<UCSZ0);
//UCSRA |= (1<<U2X);
}

////////////////////////////////////////////////////

void USART_Transmit( unsigned char data )
{
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)) );
/* Put data into buffer, sends the data */
UDR = data;
}
//////////////////////////////////////////////////////
unsigned char USART_Receive( void )
{
/* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) );
/* Get and return received data from buffer */
return UDR;

}
