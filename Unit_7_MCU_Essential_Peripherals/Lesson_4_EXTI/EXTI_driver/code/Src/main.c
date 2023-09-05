
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mohamed belal
 * @Created on     : 31/8/2023
 ******************************************************************************
 */

#include "STM32F103x6.h"
#include "STM32F103C6_GPIO_Drivers.h"
#include "STM32F103C6_EXTI_Driver.h"
#include "keypad_Driver.h"
#include "lcd_driver.h"



uint8_t IRQ_Flag = 0;
void Clock_Init(void)
{

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
//	RCC_GPIOC_CLK_EN();

}

void EXTI9_Callback(void)
{
	IRQ_Flag = 1;
	LCD_Send_String("IRQ EXTI9 is happened _|- ");
	delay_ms(1000);
	LCD_Clear_Screen();
}

int main(void)
{

	Clock_Init();
	LCD_Init();
	LCD_Clear_Screen();

	EXTI_PinConfig_t EXTI_cfg;
	EXTI_cfg.EXTI_PINS = EXTI9PB9;
	EXTI_cfg.Trigger_Case = EXTI_Trigger_Rising;
	EXTI_cfg.P_IRQ_CallBack = EXTI9_Callback;
	EXTI_cfg.IRQ_EN = EXTI_IRQ_Enable;
	MCAL_EXTI_GPIO_Init(&EXTI_cfg);
	IRQ_Flag = 1;
	while(1)
	{
		if(IRQ_Flag)
		{
			LCD_Clear_Screen();
			IRQ_Flag = 0;
		}
	}

}


