/*
 * watchDog.c
 *
 * Created: 10/18/2023 7:14:29 AM
 *  Author: Mohamed Belal
 */ 
#include "./../../MCAL/Timer/Timer.h"
#include "./../../MCAL/DIO.h"
#include "watchDog.h"

void WDT_OFF()
{
	WDTCR |= WDTOE;
	WDTCR |= WDE;

}

void WDT_ON()
{
	WDTCR |= WDE;
	WDTCR &= ~(WDP0);
	WDTCR |= WDP1;
	WDTCR |= WDP2;
}



void watchDog()
{
	
		DIO_SetPinDirection(DIO_PORTA,DIO_PIN0 , DIO_PIN_OUTPUT);
		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		
		_delay_ms(100);
		while (1)
		{
			WDT_ON();
			TOGGLEBIT(PORTA,DIO_PIN0);
			_delay_ms(2000);
			WDT_OFF();
		}
}