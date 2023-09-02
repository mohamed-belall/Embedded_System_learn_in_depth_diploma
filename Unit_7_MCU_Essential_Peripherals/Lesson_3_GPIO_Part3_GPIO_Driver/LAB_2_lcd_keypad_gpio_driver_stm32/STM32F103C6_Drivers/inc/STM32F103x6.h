/*
 * STM32F103x6.h
 *
 *  Created on: Aug 30, 2023
 *  Author: Mohamed Belal
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_


//-------------------------------------
//Includes
//-------------------------------------
#include <stdlib.h>
#include <stdint.h>


//-------------------------------------
//Base addresses for Memories
//-------------------------------------
#define FLASH_MEMORY_BASE 						0x08000000UL
#define SYSTEM_MEMORY_BASE 						0x1FFFF000UL
#define SREAM_BASE		 						0x20000000UL
#define PREIPHERALS_BASE 						0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE 	0xE0000000UL
/*	============================================================	*/





//-------------------------------------
//Base addresses for AHB Peripherals
//-------------------------------------
#define RCC_BASE								0x40021000UL

//-------------------------------------
//Base addresses for APB2 Peripherals
//-------------------------------------

//-*-*-*-*-
//GPIO
//-*-*-*-*-
// GPIO A,B fully included in LQFP48 package
#define GPIOA_BASE								0x40010800UL
#define GPIOB_BASE								0x40010C00UL

// GPIO C,D partial included in LQFP48 package
#define GPIOC_BASE								0x40011000UL
#define GPIOD_BASE								0x40011400UL
// GPIO E not included in LQFP48 package
#define GPIOE_BASE								0x40011800UL


//-*-*-*-*-
//EXTI
//-*-*-*-*-
#define EXTI_BASE								0x40010400UL


//-*-*-*-*-
//AFIO
//-*-*-*-*-
#define AFIO_BASE								0x40010000UL



//-------------------------------------
//Base addresses for APB1 Peripherals
//-------------------------------------

/*	============================================================	*/






//-------------------------------------
//Peripheral register:
//-------------------------------------
// IN TRM section register map at the end of any peripheral section

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t CR;		//0x000
	volatile uint32_t CFGR;		//0x004
	volatile uint32_t CIR;		//0x008
	volatile uint32_t APB2RSTR;	//0x00C
	volatile uint32_t APB1RSTR;	//0x010
	volatile uint32_t AHBENR;	//0x014
	volatile uint32_t APB2ENR;	//0x018
	volatile uint32_t APB1ENR;	//0x01C
	volatile uint32_t BDCR;		//0x020
	volatile uint32_t CSR;		//0x024
	volatile uint32_t AHBSTR;	//0x028
	volatile uint32_t CFGR2;	//0x02C

}RCC_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: GPIOx
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{

	volatile uint32_t CRL;		//0x00
	volatile uint32_t CRH;		//0x04
	volatile uint32_t IDR;		//0x08
	volatile uint32_t ODR;		//0x0C
	volatile uint32_t BSRR;		//0x10
	volatile uint32_t BRR;		//0x14
	volatile uint32_t LCKR;		//0x18
}GPIO_TypeDef;



//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{

	volatile uint32_t IMR;		//0x00
	volatile uint32_t EMR;		//0x04
	volatile uint32_t RTSR;		//0x08
	volatile uint32_t FTSR;		//0x0C
	volatile uint32_t SWIER;	//0x10
	volatile uint32_t PR;		//0x14
}EXTI_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{

	volatile uint32_t EVCR;			//0x00
	volatile uint32_t MAPR;			//0x04
	volatile uint32_t EXTICR1;		//0x08
	volatile uint32_t EXTICR2;		//0x0C
	volatile uint32_t EXTICR3;		//0x10
	volatile uint32_t EXTICR4;		//0x14
	uint32_t RESERVED0;	//0x18
	volatile uint32_t MAPR2;		//0x1c
}AFIO_TypeDef;

/*	============================================================	*/





//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA  			((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB  			((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC  			((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD  			((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE  			((GPIO_TypeDef *)GPIOE_BASE)

#define RCC  			((RCC_TypeDef *)RCC_BASE)

#define EXTI  			((EXTI_TypeDef *)EXTI_BASE)

#define AFIO  			((AFIO_TypeDef *)AFIO_BASE)

/*	============================================================	*/








//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN()		((RCC->APB2ENR)|= 1<<2)
#define RCC_GPIOB_CLK_EN()		((RCC->APB2ENR)|= 1<<3)
#define RCC_GPIOC_CLK_EN()		((RCC->APB2ENR)|= 1<<4)
#define RCC_GPIOD_CLK_EN()		((RCC->APB2ENR)|= 1<<5)
#define RCC_GPIOE_CLK_EN()		((RCC->APB2ENR)|= 1<<6)

#define RCC_AFIO_CLK_EN()		((RCC->APB2ENR)|= 1<<0)







//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*






#endif /* INC_STM32F103X6_H_ */
