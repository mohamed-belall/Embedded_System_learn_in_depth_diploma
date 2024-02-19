
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

int cpu_control_register=0;
int cpu_IPSR_register=0;


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
	__asm("nop \t\n nop \t\n nop");
	// cpu in handler mode
	__asm("MRS  %[out0], IPSR "
		  :[out0] "=r" (cpu_IPSR_register) // first  : output parameter
		  ); // second : input  parameter

	__asm("nop \t\n nop \t\n nop");

}

int main(void)
{

	Clock_Init();


	EXTI_PinConfig_t EXTI_cfg;
	EXTI_cfg.EXTI_PINS = EXTI9PB9;
	EXTI_cfg.Trigger_Case = EXTI_Trigger_Rising;
	EXTI_cfg.P_IRQ_CallBack = EXTI9_Callback;
	EXTI_cfg.IRQ_EN = EXTI_IRQ_Enable;
	MCAL_EXTI_GPIO_Init(&EXTI_cfg);
	IRQ_Flag = 1;


	__asm("nop \t\n nop \t\n nop");
	// cpu in thread mode
	__asm("MRS  %[out0], CONTROL "
		  :[out0] "=r" (cpu_control_register) // first  : output parameter
		  ); // second : input  parameter

	__asm("nop \t\n nop \t\n nop");


	while(1)
	{
		if(IRQ_Flag)
		{

			IRQ_Flag = 0;
		}
	}

}
