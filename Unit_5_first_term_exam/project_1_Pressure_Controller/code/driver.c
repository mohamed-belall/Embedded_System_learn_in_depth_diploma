#include "driver.h"
#include <stdint.h>
#include <stdio.h>
void Delay(int nCount)
{
	for (; nCount != 0; nCount--);
}

int getPressureVal()
{
	// Delay(40000);
	// TOGGLE_BIT(GPIOA_ODR, 13);
	// Delay(40000);
	return (GPIOA_IDR & 0xFF);
	// return 10;
}

void Set_Alarm_actuator(int i)
{
	if (i == 1)
	{
		SET_BIT(GPIOA_ODR, 13);
	}
	else if (i == 0)
	{
		RESET_BIT(GPIOA_ODR, 13);
	}
}

void GPIO_INITIALIZATION()
{
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}
