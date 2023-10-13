
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
#include "STM32F103C6_USART_Drivers.h"
#include "STM32F103C6_RCC_Drivers.h"
#include "STM32F103C6_SPI_Driver.h"
#include "STM32F103C6_I2C_Driver.h"
#include "EEPROM.h"


void Clock_Init(void)
{

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	//	RCC_GPIOC_CLK_EN();

}



int main(void)
{


	Clock_Init();
	

	// test case 1
	uint8_t ch1_send[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7};
	uint8_t ch2_receive[] = {0};
	EEPROM_Init();
	EEPROM_Write_Nbytes(0xAF, ch1_send, 7);
	EEPROM_Read_Nbytes(0xAF, ch2_receive, 7);



	// test case 2
	ch1_send[0] = 0xA ;
	ch1_send[1] = 0xB ;
	ch1_send[2] = 0xC ;
	ch1_send[3] = 0xD ;


	EEPROM_Write_Nbytes(0xFFF, ch1_send, 4);
	EEPROM_Read_Nbytes (0xFFF, ch2_receive, 4);



	while(1)
	{

	}


}


