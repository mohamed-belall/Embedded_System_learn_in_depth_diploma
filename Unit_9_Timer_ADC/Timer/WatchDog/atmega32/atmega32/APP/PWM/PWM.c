/*
 * PWM.c
 *
 * Created: 10/18/2023 7:14:57 AM
 *  Author: moham
 */ 
#include "PWM.h"


void PWM_App(void)
{
	DIO_SetPinDirection(DIO_PORTB , DIO_PIN3,DIO_PIN_OUTPUT);
	
		TIMER0_Config_t timer0CFG;
		timer0CFG.Timer_Mode = Timer0_Mode_PWM_INVERTING;
		timer0CFG.Timer_Clock_Source = Timer_Clock_Source_PRESCALING_8;
		timer0CFG.IRQ_Enable = IRQ_Enable_NON;
		timer0CFG.P_IRQ_CallBack = 0;
		
		
		MCAL_Timer0_Init(&timer0CFG);
		MCAL_Timer0_PWM_DutyCycle(1000);
		while(1)
		{
			
		}
}