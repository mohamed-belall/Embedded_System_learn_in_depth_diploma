/*
 * timer0.c
 *
 * Created: 10/18/2023 7:15:09 AM
 *  Author: moham
 */ 

#include "./../../MCAL/DIO.h"
#include "./../../MCAL/Timer/Timer.h"

#include "timer0.h"



 uint32_t timerCounter = 0;


void Timer_OverFlow_Interrupt_Handler(void);


void timer_app(void)
{
	
	DIO_SetPortDirection(DIO_PORTC,DIO_PIN_OUTPUT);
	
	
	TIMER0_Config_t timer0CFG;
	timer0CFG.Timer_Mode = Timer0_Mode_CTC;
	timer0CFG.Timer_Clock_Source = Timer_Clock_Source_PRESCALING_8;
	timer0CFG.IRQ_Enable = IRQ_Enable_TOIE0;
	timer0CFG.P_IRQ_CallBack = Timer_OverFlow_Interrupt_Handler;
	
	MCAL_Timer0_SetCompareValue(100);
	MCAL_Timer0_Init(&timer0CFG);
	
	
	while (1);
	
}

void Timer_OverFlow_Interrupt_Handler(void)
{
	timerCounter++;
	if (timerCounter == 3921)
	{
		DIO_TogglePin(DIO_PORTC,DIO_PIN0);
		
		timerCounter =0;
	}
}