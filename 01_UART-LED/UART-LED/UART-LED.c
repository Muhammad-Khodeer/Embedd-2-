#include <avr/io.h>
#include "UART_Drive.h"
#include "LED.h"
#include "common.h"
//void PrintStr(const char * sent);
int main(void)
{
///////////// Local Declaration //////////////
uint8 receivedByte;

//////////// init seq ////////////

USART_Init(207);
LED_init;
//////////  app seq /////////////
while(1)
{
	receivedByte = USART_Receive();
	switch(receivedByte)
	{
		case 'a':
			LED_ON;
			break;
		case 'b':
			LED_OFF;
			break;
		default:
			USART_Transmit('E');
		//	PrintStr("Error\r\n");
	}
}
return 0;
}
/*void PrintStr(const char * sent)
{
	// USART_Transmit(*(sent+2))
	while(*(sent) != 0)
	{
		USART_Transmit(*sent++);
	}

}*/
