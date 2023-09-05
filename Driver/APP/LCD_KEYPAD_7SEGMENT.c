
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




uint8_t segments_hex[] = {
		0x3F,  // 0
		0x06,  // 1
		0x5B,  // 2
		0x4F,  // 3
		0x66,  // 4
		0x6D,  // 5
		0x7D,  // 6
		0x07,  // 7
		0x7F,  // 8
		0x6F   // 9
};




void GPIO_SevenSegment_Init(void)
{

	GPIO_PinConfig_t PinCfg;


	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);


	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	MCAL_GPIO_Init(GPIOB, &PinCfg);


	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_8;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_9;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}

uint8_t IRQ_Flag = 0;
void Clock_Init(void)
{

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
//	RCC_GPIOC_CLK_EN();

}


int main(void)
{


	volatile uint8_t key_pressed;
	uint8_t i;

	Clock_Init();
	GPIO_SevenSegment_Init();
	LCD_Init();

	LCD_Send_String("hey");
	delay_ms(500);
	LCD_Clear_Screen();

	for(i=0;i<11;i++)
	{
		MCAL_GPIO_WritePort(GPIOB, segments_hex[i] << 3);
		LCD_Display_Number(i);
		delay_ms(500);
	}
	LCD_Clear_Screen();

	keypad_Init();

	LCD_Send_String("keypad is Ready");
	delay_ms(500);
	LCD_Clear_Screen();

	while(1)
	{
		key_pressed = keypad_GetKey();
		switch (key_pressed) {
		case 'A':
			break;
		case '?':
			LCD_Clear_Screen();
			break;
		default:
			LCD_Send_Character(key_pressed);
			break;
		}


	}
}


