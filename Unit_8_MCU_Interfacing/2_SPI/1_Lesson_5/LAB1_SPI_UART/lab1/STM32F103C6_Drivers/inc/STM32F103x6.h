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


//-*-*-*-*-
//  NVIC
//-*-*-*-*-
#define NVIC_BASE								0xE000E100UL
#define NVIC_STIR								0xE000EF00UL

#define NVIC_ISER0								(*(volatile uint32_t*)(NVIC_BASE+0x0))
#define NVIC_ISER1								(*(volatile uint32_t*)(NVIC_BASE+0x4))
#define NVIC_ISER2								(*(volatile uint32_t*)(NVIC_BASE+0x8))

#define NVIC_ICER0								(*(volatile uint32_t*)(NVIC_BASE+0x80))
#define NVIC_ICER1								(*(volatile uint32_t*)(NVIC_BASE+0x84))
#define NVIC_ICER2								(*(volatile uint32_t*)(NVIC_BASE+0x88))



/*	============================================================	*/





//-------------------------------------
//Base addresses for AHB Peripherals
//-------------------------------------
#define RCC_BASE								0x40021000UL



//---------------------------------------------------------------------
//					Base addresses for APB2 Peripherals
//---------------------------------------------------------------------

//-*-*-*-*-
//  GPIO
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
//  EXTI
//-*-*-*-*-
#define EXTI_BASE								0x40010400UL


//-*-*-*-*-
//  AFIO
//-*-*-*-*-
#define AFIO_BASE								0x40010000UL


//-*-*-*-*-
//  USART
//-*-*-*-*-
#define USART1_BASE								0x40013800UL



//-*-*-*-*-
//  SPI1
//-*-*-*-*-
#define SPI1_BASE								0x40013000UL


//---------------------------------------------------------------------
//					Base addresses for APB1 Peripherals
//---------------------------------------------------------------------

//-*-*-*-*-
//  USART
//-*-*-*-*-
#define USART2_BASE								0x40004400UL
#define USART3_BASE								0x40004800UL


//-*-*-*-*-
//  SPI2
//-*-*-*-*-
#define SPI2_BASE								0x40003800UL


/*	============================================================	*/





//---------------------------------------------------------------------
//							Peripheral register:
//---------------------------------------------------------------------

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
	volatile uint32_t EXTICR[4];	//0x08 //0x0C //0x10 //0x14
	uint32_t RESERVED0;	//0x18
	volatile uint32_t MAPR2;		//0x1c
}AFIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: USART
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{

	volatile uint32_t SR;			//0x00
	volatile uint32_t DR;			//0x04
	volatile uint32_t BRR;	        //0x08
	volatile uint32_t CR1;	        //0x0C
	volatile uint32_t CR2;	        //0x10
	volatile uint32_t CR3;	        //0x14
	volatile uint32_t GTPR;			//0x18
}USART_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: SPI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t SPI_CR1;			//0x00
	volatile uint32_t SPI_CR2;			//0x04
	volatile uint32_t SPI_SR;	        //0x08
	volatile uint32_t SPI_DR;	        //0x0C
	volatile uint32_t SPI_CRCPR;	    //0x10
	volatile uint32_t SPI_RXCRCR;	    //0x14
	volatile uint32_t SPI_TXCRCR;		//0x18
	volatile uint32_t SPI_I2SCFGR;		//0x1C
	volatile uint32_t SPI_I2SPR;		//0x20
}SPI_TypeDef;

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

#define USART1			((USART_TypeDef *)USART1_BASE)
#define USART2			((USART_TypeDef *)USART2_BASE)
#define USART3			((USART_TypeDef *)USART3_BASE)

#define SPI1			((USART_TypeDef *)SPI1_BASE)
#define SPI2			((USART_TypeDef *)SPI2_BASE)

/*	============================================================	*/








//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-
//  GPIO
//-*-*-*-*-
#define RCC_GPIOA_CLK_EN()		((RCC->APB2ENR)|= 1<<2)
#define RCC_GPIOB_CLK_EN()		((RCC->APB2ENR)|= 1<<3)
#define RCC_GPIOC_CLK_EN()		((RCC->APB2ENR)|= 1<<4)
#define RCC_GPIOD_CLK_EN()		((RCC->APB2ENR)|= 1<<5)
#define RCC_GPIOE_CLK_EN()		((RCC->APB2ENR)|= 1<<6)


//-*-*-*-*-
//  AFIO
//-*-*-*-*-
#define RCC_AFIO_CLK_EN()		((RCC->APB2ENR)|= 1<<0)


//-*-*-*-*-
//  USART
//-*-*-*-*-
#define RCC_USART1_CLK_EN()		((RCC->APB2ENR) |= 1<< 14)
#define RCC_USART2_CLK_EN()		((RCC->APB1ENR) |= 1<< 17)
#define RCC_USART3_CLK_EN()		((RCC->APB1ENR) |= 1<< 18)

#define RCC_USART1_Rest()		((RCC->APB2RSTR) |= 1<< 14)
#define RCC_USART2_Rest()		((RCC->APB1RSTR) |= 1<< 17)
#define RCC_USART3_Rest()		((RCC->APB1RSTR) |= 1<< 18)


//-*-*-*-*-
//  SPI
//-*-*-*-*-
#define RCC_SPI1_CLK_EN()		((RCC->APB2ENR) |= 1<< 12)
#define RCC_SPI2_CLK_EN()		((RCC->APB1ENR) |= 1<< 14)


#define RCC_SPI1_Rest()		((RCC->APB2RSTR) |= 1<< 12)
#define RCC_SPI2_Rest()		((RCC->APB1RSTR) |= 1<< 14)




//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*
//	IVT:
//-*-*-*-*-*
//EXTI
#define EXTI0					0
#define EXTI1					1
#define EXTI2					2
#define EXTI3					3
#define EXTI4					4
#define EXTI5					5
#define EXTI6					6
#define EXTI7					7
#define EXTI8					8
#define EXTI9					9
#define EXTI10					10
#define EXTI11					11
#define EXTI12					12
#define EXTI13					13
#define EXTI14					14
#define EXTI15					15

//EXTI_IRQ
#define EXTI0_IRQ				6
#define EXTI1_IRQ				7
#define EXTI2_IRQ				8
#define EXTI3_IRQ				9
#define EXTI4_IRQ				10
#define EXTI5_IRQ				23
#define EXTI6_IRQ				23
#define EXTI7_IRQ				23
#define EXTI8_IRQ				23
#define EXTI9_IRQ				23
#define EXTI10_IRQ				40
#define EXTI11_IRQ				40
#define EXTI12_IRQ				40
#define EXTI13_IRQ				40
#define EXTI14_IRQ				40
#define EXTI15_IRQ				40


//USART_IRQ
#define USART1_IRQ				37
#define USART2_IRQ				38
#define USART3_IRQ				39

//SPI_IRQ
#define SPI1_IRQ				35
#define SPI2_IRQ				36



//-*-*-*-*-*
//	NVIC:
//-*-*-*-*-*

#define NVIC_IRQ6_EXTI0_Enable			(NVIC_ISER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Enable			(NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Enable			(NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Enable			(NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Enable			(NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Enable		(NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Enable		(NVIC_ISER1 |= (1<<8)) // 40-32 = 8

#define NVIC_IRQ6_EXTI0_Disable			(NVIC_ICER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Disable			(NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Disable			(NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Disable			(NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Disable		(NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Disable		(NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Disable	(NVIC_ICER1 |= (1<<8)) // 40-32 = 8


//USART
#define NVIC_IRQ37_USART1_Enable		(NVIC_ISER1 |= (1<<5)) // 37-32 = 5
#define NVIC_IRQ38_USART2_Enable		(NVIC_ISER1 |= (1<<6)) // 38-32 = 6
#define NVIC_IRQ39_USART3_Enable		(NVIC_ISER1 |= (1<<7)) // 39-32 = 7

#define NVIC_IRQ37_USART1_Disable		(NVIC_ICER1 |= (1<<5)) // 37-32 = 5
#define NVIC_IRQ38_USART2_Disable		(NVIC_ICER1 |= (1<<6)) // 38-32 = 6
#define NVIC_IRQ39_USART3_Disable		(NVIC_ICER1 |= (1<<7)) // 39-32 = 7


//SPI
#define NVIC_IRQ35_SPI1_Enable			(NVIC_ISER1 |= ( 1 << (SPI1_IRQ -32) )) // SPI1_IRQ-32
#define NVIC_IRQ36_SPI2_Enable			(NVIC_ISER1 |= ( 1 << (SPI2_IRQ -32) )) // SPI2_IRQ-32

#define NVIC_IRQ35_SPI1_Disable			(NVIC_ICER1 |= ( 1 << (SPI1_IRQ -32) )) // SPI1_IRQ-32
#define NVIC_IRQ36_SPI2_Disable			(NVIC_ICER1 |= ( 1 << (SPI2_IRQ -32) )) // SPI2_IRQ-32


#endif /* INC_STM32F103X6_H_ */
