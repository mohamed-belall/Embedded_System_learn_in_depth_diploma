/*
 * task_3.c
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
	//DDRA = 0b11111111;
	SETBIT(DDRD,4);
	SETBIT(DDRD,5);
	SETBIT(DDRD,6);
	SETBIT(DDRD,7);
	
	DDRC = 0xFF;
	
	// PORTC PIN 0 as input
	CLEARBIT(DDRC,0);

	// create bit variable to iterate 8 bit 
	volatile unsigned char bit =0 ,i,j;

	while (1) 
	{
		for(bit=7;bit>=5;bit--)
		{
				SETBIT(PORTD,bit);
				_delay_ms(500);
				CLEARBIT(PORTD,bit);
		}
		SETBIT(PORTD,4);
		_delay_ms(500);
		CLEARBIT(PORTD,4);
		
		for(i=0;i<4;i++)
		{
			
			for(j=0;j<10;j++)
			{
				
				PORTC = 0b0111 | (j<<4);
				_delay_ms(200);
			}
			PORTC = 0b1011 | (i<<4);
			_delay_ms(200);
		}
	
	
	}
}

