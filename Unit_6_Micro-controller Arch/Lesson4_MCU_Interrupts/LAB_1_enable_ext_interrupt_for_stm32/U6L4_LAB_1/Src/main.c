/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mohamed belal
 * @Created on     : 21/8/2023
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
#define GPIOA13      (1UL<<13)

// AFIO Register
#define AFIO_BASE    0x40010000
#define AFIO_EXTICR1 *(volatile uint32_t *)(AFIO_BASE + 0x08)

// clock Register RCC
#define RCC_BASE 	 0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_IOPAEN   (1<<2)
#define RCC_AFIOEN   (1<<0)

//interrupt register EXTI0
#define EXTI_BASE    0x40010400
#define EXTI_IMR     *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR    *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR      *(volatile uint32_t *)(EXTI_BASE + 0x14)

// from cotrex m3 data sheet
#define NVIC_EXTI0   *(volatile uint32_t *)(0xE000E100)

void GPIO_Init(void)
{
	// PIN 13 PORT A OUTPUT
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	// 01: Floating input (reset state) PORTA PIN0
	GPIOA_CRL |= (0x01<<2);

}

void Clock_Init(void)
{
	//ENABLE CLOCK GPIOA
	RCC_APB2ENR |= RCC_IOPAEN;

	//ENABLE CLOCK AFIO
	RCC_APB2ENR |= RCC_AFIOEN;
}
void Interrupt_Init(void)
{
	// interrupt mask register enable write 1
	EXTI_IMR |= (1<<0);
	// Rising trigger selection register 1: Rising trigger enabled (for Event and Interrupt) for input line.
	EXTI_RTSR |= (1<<0);
}

int main(void)
{

	Clock_Init();
	Interrupt_Init();
	GPIO_Init();
	// AFIO External interrupt configuration register 1
	AFIO_EXTICR1 = 0;

	// enable IRQ6 => NVIC
	NVIC_EXTI0 |= (1<<6);

	while(1);
}


void EXTI0_IRQHandler(void)
{
	//IRQ is happened EXTI0 >>> PORTA PIN 0  _|- RISING EDGE
	// toggle led pin a 13
	GPIOA_ODR ^= GPIOA13;

	// write 1 to clear pending request for line 0
	EXTI_PR |= (1<<0);
}
