/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mohamed belal
 * @Created on     : 18/8/2023
 ******************************************************************************
 */


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef volatile unsigned int vuint32_t ;
// register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH  *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR  *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
/* ========= clock ==========*/
#define RCC_BASE   0x40021000
#define RCC_IOPAEN *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR   *(volatile vuint32_t *)(RCC_BASE + 0x04)


int main(void)
{
	/*===== INIT CLOCK ======*/
	// Bit 2 IOPAEN: IO port A clock enable
	//			0: IO port A clock disabled
	//			1: IO port A clock enabled
	RCC_IOPAEN |= (1<<2);


	//	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	//	Set and cleared by software to control the division factor of the APB low-speed clock
	//	(PCLK1).
	//	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16
	RCC_CFGR |= (0b100<<8);

	//	Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	//	Set and cleared by software to control the division factor of the APB high-speed clock
	//	(PCLK2).
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16
	RCC_CFGR |= (0b101<<11);


	//Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}
