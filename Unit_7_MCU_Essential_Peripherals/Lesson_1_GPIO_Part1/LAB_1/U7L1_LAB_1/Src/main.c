/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mohamed belal
 * @Created on     : 25/8/2023
 ******************************************************************************
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// GPIO Register
#define GPIOA_BASE   0x40010800
#define GPIOA_CRH    *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL    *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR    *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_IDR    *(volatile uint32_t *)(GPIOA_BASE + 0x08)
#define GPIOA13      (1UL<<13)

#define GPIOB_BASE   0x40010C00
#define GPIOB_CRH    *(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_CRL    *(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_ODR    *(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR    *(volatile uint32_t *)(GPIOB_BASE + 0x08)


// clock Register RCC
#define RCC_BASE 	 0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_IOPAEN   (1<<2)
#define RCC_IOPBEN   (1<<3)





void GPIO_Init(void)
{

	GPIOA_CRL = 0x0;
	GPIOB_CRL = 0x0;
//	GPIOA_ODR = 0;

	// POARTA PIN1 (A1)
	//00: Input mode (reset state)
	GPIOA_CRL &= ~(0b11 << 4);
	//01: Floating input (reset state)
	GPIOA_CRL |= (0b01 << 6);

	// POARTB PIN1 (B1)
	//01: Output mode, max speed 10 MHz.
	GPIOB_CRL |= (0b01 << 4);
	//00: General purpose output push-pull
	GPIOB_CRL &= ~(0b11 << 6);


	// ======================================================
	// POARTA PIN13 (A13)
	//00: Input mode (reset state)
	GPIOA_CRH &= ~(0b11 << 20);
	//01: Floating input (reset state)
	GPIOA_CRH |= (0b01 << 22);

	// POARTB PIN13 (B13)
	//01: Output mode, max speed 10 MHz.
	GPIOB_CRH |= (0b01 << 20);
	//00: General purpose output push-pull
	GPIOB_CRH &= ~(0b11 << 22);

}

void Clock_Init(void)
{
	//ENABLE CLOCK GPIOA
	RCC_APB2ENR |= RCC_IOPAEN;

	//ENABLE CLOCK GPIOB
	RCC_APB2ENR |= RCC_IOPBEN;

}

void delay_ms(int time)
{
	unsigned int i,j;
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
		if(((GPIOA_IDR & (1<<1))>>1) == 0)
		{
			GPIOB_ODR ^= (1<<1);
			while((((GPIOA_IDR & (1<<1)) >> 1) == 0)); // single pressing
		}

		// A13 as input control B13 as output as multi pressing
		if(((GPIOA_IDR & (1<<13)) >> 13 ) == 1)
		{
			GPIOB_ODR ^= (1<<13);
		}
		delay_ms(10);

	}
}


