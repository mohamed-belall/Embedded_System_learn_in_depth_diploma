/*
 * task_2.c
 *
 * Created: 8/26/2023 
 * Author : mohamed belal
 */ 

#define F_CPU 8000000UL
#include "bitwise.h"
#include "atmega32_register.h"
#include <util/delay.h>

int main(void)
{
	// make all pin of port A as output
	DDRA = 0b11111111;
	// PORTC PIN 0 as input
	CLEARBIT(DDRC,0);

	// create bit variable to iterate 8 bit 
	unsigned char bit =0 , flag=0;

	while (1) 
	{
		//we use external pull up resistance
		// we check if we cleck button
		if(READBIT(PINC,0)==0)
		{
			// if we reach pin 7 we make flag to 1 to decrement and turn off led 
			if (bit == 8)
				flag =1;
				
			// if we reach pin 0 we make flag to 0 to increment and turn on led 
			if(bit == 0)
				flag=0;

			if(flag == 0)
			{
				SETBIT(PARTA,bit);
				_delay_ms(200);
				bit++;
			}else
			{
				bit--;
				CLEARBIT(PARTA,bit);
				_delay_ms(200);

			}
		}



	}
}

