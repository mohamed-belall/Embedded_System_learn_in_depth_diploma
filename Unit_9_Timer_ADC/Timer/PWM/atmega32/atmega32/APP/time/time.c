/*
 * time.c
 *
 * Created: 10/18/2023 7:16:36 AM
 *  Author: Mohamed
 */ 
#include "time.h"
#include "./../../MCAL/Timer/Timer.h"
#include "./../../MCAL/DIO.h"

void timeApp()
{
	
   uint8_t hours =20  , minutes = 43 ,seconds = 23  , counter =0;

	
	DIO_SetPortDirection(DIO_PORTD,DIO_PIN_OUTPUT);
	DIO_SetPortDirection(DIO_PORTC,0x0F);

    while (1) 
    {
	
		for(counter=0;counter<=50;counter++)
		{
			DIO_SetPortValue(DIO_PORTD, 0xFE );
			DIO_SetPortValue(DIO_PORTC,((uint8_t)(hours/10)));
			_delay_us(3333);
			
			DIO_SetPortValue(DIO_PORTD, 0xFD );
			DIO_SetPortValue(DIO_PORTC,((uint8_t)(hours%10)));
			_delay_us(3333);
			
			
			DIO_SetPortValue(DIO_PORTD, 0xF7 );
			DIO_SetPortValue(DIO_PORTC,((uint8_t)(minutes/10)));
			_delay_us(3333);
			
			DIO_SetPortValue(DIO_PORTD, 0xEF );
			DIO_SetPortValue(DIO_PORTC,((uint8_t)(minutes%10)));
			_delay_us(3333);
			
			
			DIO_SetPortValue(DIO_PORTD, 0xBF );
			DIO_SetPortValue(DIO_PORTC,((uint8_t)(seconds/10)));
			_delay_us(3333);
			
			DIO_SetPortValue(DIO_PORTD, 0x7F );
			DIO_SetPortValue(DIO_PORTC,((uint8_t)(seconds%10)));
			_delay_us(3333);
			seconds++;
			if (seconds==60)
			{
				seconds=0;
				minutes++;
			}
			if (minutes==60)
			{
				minutes=0;
				hours++;
			}
			if (hours==24)
			{
				hours=0;
				
			}
			
		}	
		
    }
}
