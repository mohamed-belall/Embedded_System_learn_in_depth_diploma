
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mohamed belal
 * @Created on     : 31/8/2023
 ******************************************************************************
 */


#include <stdint.h>
#include "STM32F103C6_GPIO_Drivers.h"
#include "STM32F103x6.h"







void GPIO_Init(void)
{

	GPIO_PinConfig_t PinCfg;

	// POARTA PIN1 (A1)
	//00: Input mode (reset state)
	//01: Floating input (reset state)
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(GPIOA, &PinCfg);



	// POARTB PIN1 (B1)
	//01: Output mode, max speed 10 MHz.
	//00: General purpose output push-pull

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);


	// ======================================================
	// POARTA PIN13 (A13)
	//00: Input mode (reset state)
	//01: Floating input (reset state)
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	// POARTB PIN1 (B13)
	//01: Output mode, max speed 10 MHz.
	//00: General purpose output push-pull
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}

void Clock_Init(void)
{

	//ENABLE CLOCK GPIOA
	//RCC_APB2ENR |= RCC_IOPAEN;
	RCC_GPIOA_CLK_EN();
	//ENABLE CLOCK GPIOB
	//RCC_APB2ENR |= RCC_IOPBEN;
	RCC_GPIOB_CLK_EN();

}

void delay_ms(uint32_t time)
{
	uint32_t i,j;
	for(i=0 ; i < time ; i++)
		for(j=0 ; j<255 ; j++);
}

int main(void)
{

	Clock_Init();

	GPIO_Init();




	while(1)
	{
		// A1 as input control B1 as output as single pressing
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0); // single pressing
		}

		// A13 as input control B13 as output as multi pressing
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		delay_ms(1);

	}
}


