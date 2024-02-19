
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



uint8_t IRQ_Flag = 0;
enum CPUaccessLevel{
	privileged ,
	unprivileged
};




void Switch_CPU_AccessLevel(enum CPUaccessLevel level)
{
	switch(level)
	{
	case privileged:
		//clear Bit 0 : in CONTROL register
		__asm(" MRS R3,CONTROL \n\t"
			  " LSR R3,R3,#0x1 \n\t"
			  " LSL R3,R3,#0x1 \n\t"
			  " MSR CONTROL,R3");
		break;
	case unprivileged:
		//Set Bit 0 : in CONTROL register
		__asm(" MRS R3,CONTROL \n\t"
			  " ORR R3,R3,#0x1 \n\t"
			  " MSR CONTROL,R3");
		break;
	}

}

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
	Switch_CPU_AccessLevel(privileged);

}

void HardFault_Handler()
{

}
void BusFault_Handler()
{

}
void MemManage_Handler()
{

}
void UsageFault_Handler()
{

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
	Switch_CPU_AccessLevel(unprivileged);




	while(1)
	{
		if(IRQ_Flag)
		{

			IRQ_Flag = 0;
		}
	}

}
