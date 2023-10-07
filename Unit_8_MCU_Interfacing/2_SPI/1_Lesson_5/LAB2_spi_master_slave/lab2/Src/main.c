
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


//#define MCU_Act_As_Master
#define MCU_Act_As_Slave


void Clock_Init(void)
{

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	//	RCC_GPIOC_CLK_EN();

}

unsigned char ch;

void SPI_IRQ_CALLBACK(struct S_IRQ_SRC irqSrc)
{
#ifdef MCU_Act_As_Slave
	if(irqSrc.RXNE)
	{
		ch = 0xf;
		MCAL_SPI_TX_RX(SPI1, &ch, PollingDisable);
		MCAL_UART_SendData(USART1, &ch, enable);
	}
#endif
}

void USART_IRQ_CALLBACK(void)
{
#ifdef MCU_Act_As_Master
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, enable);
	// send spi
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	MCAL_SPI_TX_RX(SPI1, &ch, PollingEnable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
#endif
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


	/* ====================== SPI Init ====================== */
	/*
	 * PA4  ====> SPI1_NSS
	 * PA5  ====> SPI1_SCK
	 * PA6  ====> SPI1_MISO
	 * PA7  ====> SPI1_MOSI
	 */
	SPI_Config_t SPI1_cfg;
	/* --------------- common configuration --------------- */
	SPI1_cfg.CLKPhase = SPI_CLKPhase_2ndEdge_First_Data_Capture_Edge;
	SPI1_cfg.CLKPolarity = SPI_CLKPolarity_1_when_idle;
	SPI1_cfg.Communication_Mode = SPI_Direction_2LINE;
	SPI1_cfg.DataSize = SPI_DataSize_8BIT;

	SPI1_cfg.Frame_Format = SPI_Frame_Format_MSB_Transmitted_First;

	// assume by default pclk2 = 8MHz
	SPI1_cfg.SPI_BaudRate = SPI_BaudRatePrescaler_8;


#ifdef MCU_Act_As_Master

	SPI1_cfg.Device_Mode = Device_Mode_Master;
	SPI1_cfg.IRQ_Enable = SPI_IRQ_Enable_NONE;
	SPI1_cfg.NSS = SPI_NSS_SW_NSSInternalSoft_Set;
	SPI1_cfg.P_IRQ_CallBack = 	NULL;



	// config ss on PA4 as gpio
	GPIO_PinConfig_t pinCFG;
	pinCFG.GPIO_PinNumber = GPIO_PIN_4;
	pinCFG.GPIO_MODE =GPIO_MODE_OUTPUT_PP;
	pinCFG.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &pinCFG);

	// force slave select (high) idle mode
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
#endif



#ifdef MCU_Act_As_Slave
SPI1_cfg.Device_Mode = Device_Mode_Slave;
SPI1_cfg.Communication_Mode = SPI_NSS_HW_Slave;
SPI1_cfg.IRQ_Enable = SPI_IRQ_Enable_RXNEIE;
SPI1_cfg.P_IRQ_CallBack = SPI_IRQ_CALLBACK;
#endif

	MCAL_SPI_Init(SPI1, &SPI1_cfg);
	MCAL_SPI_GPIO_Set_Pins(SPI1);


	while(1)
	{

	}


}


