
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





void Clock_Init(void)
{

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	//	RCC_GPIOC_CLK_EN();

}

unsigned char ch;

void USART_IRQ_CALLBACK(void)
{
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, enable);
}

int main(void)
{

	UART_ConFig UartCfg;
	Clock_Init();

	UartCfg.USART_BaudRate = USART_BaudRate_115200;
	UartCfg.USART_HwFlowCtl = USART_HwFlowCtl_NONE;

	UartCfg.USART_IRQ_Enable = USART_IRQ_Enable_RXNEIE;
	UartCfg.P_IRQ_CallBack = USART_IRQ_CALLBACK;

	UartCfg.USART_Parity = USART_Parity_NONE;
	UartCfg.USART_PayLoad_Length = USART_PayLoad_Length_8B;
	UartCfg.USART_StopBits = USART_StopBits_1;
	UartCfg.USART_Mode = USART_Mode_TX_RX;

	MCAL_UART_Init(USART1, &UartCfg);
	MCAL_UART_GPIO_Set_Pins(USART1);


	while(1)
	{

	}


}
