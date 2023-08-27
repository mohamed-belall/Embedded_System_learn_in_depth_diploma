/*
 * task_1.c
 *
 * Created: 8/26/2023 12:54:49 PM
 * Author : mohamed belal
 */ 

#define F_CPU 8000000UL
#include "bitwise.h"
#include "atmega32_register.h"
#include <util/delay.h>

int main(void)
{
	DDRA = 0b11111111;
	
	volatile  char bit =0 , flag=0;
    /* Replace with your application code */
    while (1) 
    {
		if (bit == 8)
			flag =1;
		
		if(bit == 0)
			flag=0;
		
		if(flag == 0)
		{
			SETBIT(PARTA,bit);
			_delay_ms(500);
			bit++;
		}else
		{
			bit--;	
			CLEARBIT(PARTA,bit);
			_delay_ms(500);
			
		}
		
			
    }
}

