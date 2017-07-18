/*
 * OStime.c              /////////////////////    non preemptive operating system     ///////////////////////////
 *
 * Created: 16/07/2015 01:30:16 ص
 *  Author: Muhammad
 */ 


#include <avr/interrupt.h>
#include "OStime.h"
#include "SSEG.h"
#include "MYMICRO.h"

void OStime_start(void)				/************ initialization OS ************/ 
{
	Enable_OverFlow_Timer0;          // Enable overflow interrupt    [timer/counter 0]
	Start_With_Speed_Type1;			 // Start timer at FCPU/64
	Enable_GlobalInterrupt;          // Enable the global interrupt
}


ISR(TIMER0_OVF_vect)               /****** interrupt service routine ***********/
{
	SSEG_cyclic10ms();     // this function will be called every 5ms by Timer0 interrupt
	Start_Count = 99;	/* load the timer register to fire each 10 ms (it will start 
					       with 99 until reaching 255 and then interrupt will take place)
						   To calculate the time (255 - 99) = 156 the counts remaining 
						   for the timer to overflow and since there is a prescaler FCPU/64 
						   then to calcualte the time:156*64 = 10000 microseconds = 10 milliseconds */
}
