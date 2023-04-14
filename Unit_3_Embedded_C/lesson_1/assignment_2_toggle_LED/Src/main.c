/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mohamed belal
 * @brief          : Main program body
 ******************************************************************************
 */
#include <stdint.h>
#include "Platform_Types.h"

/* base address register */
#define RCC_BASE 		0x40021000
#define GPIOA_BASE 		0x40010800

/*	base address + offset	*/
#define RCC_APB2ENR 	*(vuint32 *)(RCC_BASE + 0x18)
#define GPIOA_CRH 		*(vuint32 *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR 		*(vuint32 *)(GPIOA_BASE + 0x0C)

typedef union
{
	vsint32 all_fields;
	struct
	{
		vsint32 reserved :13;
		vsint32 pin_13 	 :1;
	}Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);

int main(void)
{
	RCC_APB2ENR |= 1 << 2;
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;

	while (1)
	{
//		 GPIOA_ODR |= (1<<13);		//set bit
		R_ODR->Pin.pin_13 = 1;		//set bit
		for (int i = 0; i < 5000; i++);
//		 GPIOA_ODR &= ~(1<<13); 	//reset bit
		R_ODR->Pin.pin_13 = 0; 		//reset bit
		for (int i = 0; i < 5000; i++);
	}
	return 0;
}
