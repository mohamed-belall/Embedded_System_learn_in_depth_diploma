/*
 * STM32F103C6_USART_Drivers.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Mohamed Belal
 */


#include "STM32F103C6_USART_Drivers.h"



/*
 * ===========================================================================================================
 *											 Generic variables
 * ===========================================================================================================
 * */


UART_ConFig* Global_UART_Config = NULL;
uint32_t pclk , BRR;



/*
 * ===========================================================================================================
 * 											 Generic Macros
 * ===========================================================================================================
 * */




/*
 * ===========================================================================================================
 * 											Generic Function
 * ===========================================================================================================
 * */












/*
 * ===========================================================================================================
 *											APIs function Definitions
 * ===========================================================================================================
 * */


/*
 * ===================================
 * @FN				- MCAL_UART_Init
 * @brief			- initialization UART (Supported feature asynchronous only
 * @param [in]		- USARTx: where x can be (1,2,3 depending on device used)
 * @param [in]		- USART_CFG: all UART configuration UART_ConFig
 * @retval			- none
 * @Note			- support for now asynchronous
 * ===================================
 * */
void MCAL_UART_Init(USART_TypeDef* USARTx , UART_ConFig* USART_CFG)
{
	Global_UART_Config = USART_CFG;

	// enable CLOCK for given UART peripheral
	if(USARTx == USART1)
		RCC_USART1_CLK_EN();
	else if(USARTx == USART2)
		RCC_USART2_CLK_EN();
	else if(USARTx == USART3)
		RCC_USART3_CLK_EN();



	// enable UART
	// Bit 13 UE: USART enable
	USARTx->CR1 |= (1<<13);



	// enable TX/RX engine according to the UART configuration item
	// USARTx->CR1 |=    Bit 10 PCE: Parity control enable      Bit 9 PS: Parity selection
	USARTx->CR1 |= USART_CFG->USART_Mode;


	// PAYLOAD width
	//  USARTx->CR1 |=   	Bit 12 M: Word length
	USARTx->CR1 |= USART_CFG->USART_PayLoad_Length;



	// configuration of parity control bit fields
	//  USARTx->CR1 |=   	Bit 10 PCE: Parity control enable         Bit 9 PS: Parity selection
	USARTx->CR1 |= USART_CFG->USART_Parity;



	// configuration of stop bits
	//   USARTx->CR2 |=   	Bits 13:12 STOP: STOP bits
	USARTx->CR2 |=  USART_CFG->USART_StopBits;



	// UART hardware flow control
	// USARTx->CR3 |=       Bit 9 CTSE: CTS enable                Bit 8 RTSE: RTS enable
	USARTx->CR3 |= USART_CFG->USART_HwFlowCtl;


	// confiuration of baud rate register (BBR)
	// PCLK1 => USART2 , 3
	// PCLK2 => USART1
	if(USARTx == USART1)
		pclk = MCAL_RCC_GetPCLK2Freq();
	else
		pclk = MCAL_RCC_GetPCLK1Freq();

	BRR  = UART_BRR_Register(pclk , USART_CFG->USART_BaudRate);
	USARTx->BRR = BRR;

	// enable / disable interrupt
	//USART_CR1
	if(USART_CFG->USART_IRQ_Enable != USART_IRQ_Enable_NONE)
	{
		// USART_CR1  =>     Bit 8 PEIE: PE interrupt enable
		USARTx->CR1 |= USART_CFG->USART_IRQ_Enable;

		//enable NVIC for USARTx IRQ
		if(USARTx == USART1)
			NVIC_IRQ37_USART1_Enable;

		else if(USARTx == USART2)
			NVIC_IRQ38_USART2_Enable;

		else if(USARTx == USART3)
			NVIC_IRQ39_USART3_Enable;
	}

}







/*
 * ===================================
 * @FN				- MCAL_UART_DeInit
 * @brief			- DEinitialization UART (Supported feature asynchronous only
 * @param [in]		- USARTx: where x can be (1,2,3 depending on device used)
 * @retval			- none
 * @Note			- reset the module by RCC
 * ===================================
 * */
void MCAL_UART_DeInit(USART_TypeDef* USARTx )
{
	if(USARTx == USART1)
	{
		RCC_USART1_Rest();
		NVIC_IRQ37_USART1_Disable;
	}


	else if(USARTx == USART2)
	{
		RCC_USART2_Rest();
		NVIC_IRQ38_USART2_Disable;
	}


	else if(USARTx == USART3)
	{
		RCC_USART3_Rest();
		NVIC_IRQ39_USART3_Disable;
	}

}







/*
 * ===================================
 * @FN				- MCAL_UART_DeInit
 * @brief			- initialization GPIO pins
 * @param [in]		- USARTx: where x can be (1,2,3 depending on device used)
 * @retval			- none
 * @Note			- should enable the corresponding ALT & GPIO in RCC clock also called after MCAL_GPIO_Init()
 * ===================================
 * */
void MCAL_UART_GPIO_Set_Pins(USART_TypeDef* USARTx )
{
	GPIO_PinConfig_t PinCfg;

	if(USARTx == USART1)
	{
		/*
		 * USART1_TX    ====>  PA9
		 * USART1_RX    ====>  PA10
		 * USART1_CTS   ====>  PA11
		 * USART1_RTS   ====>  PA12
		 * */

		// USART1_TX    ====>  PA9
		PinCfg.GPIO_PinNumber = GPIO_PIN_9;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		// USART1_RX    ====>  PA10
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_INPUT_AF;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		if(Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_CTS ||Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_CTS_RTS)
		{
			// USART1_CTS   ====>  PA11
			PinCfg.GPIO_PinNumber = GPIO_PIN_11;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		}else if(Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_RTS ||Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_CTS_RTS)
		{
			// USART1_RTS   ====>  PA12
			PinCfg.GPIO_PinNumber = GPIO_PIN_12;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		}

	}else if (USARTx == USART2)
	{
		/*
		 * USART2_CTS   ====>  PA0
		 * USART2_RTS   ====>  PA1
		 * USART2_TX    ====>  PA2
		 * USART2_RX    ====>  PA3
		 * */

		// USART2_TX    ====>  PA2
		PinCfg.GPIO_PinNumber = GPIO_PIN_2;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		// USART2_RX    ====>  PA3
		PinCfg.GPIO_PinNumber = GPIO_PIN_3;
		PinCfg.GPIO_MODE = GPIO_MODE_INPUT_AF;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		if(Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_CTS ||Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_CTS_RTS)
		{
			// USART2_CTS   ====>  PA0
			PinCfg.GPIO_PinNumber = GPIO_PIN_0;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		}else if(Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_RTS ||Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_CTS_RTS)
		{
			// USART2_RTS   ====>  PA1
			PinCfg.GPIO_PinNumber = GPIO_PIN_1;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		}


	}else if (USARTx == USART3)
	{
		/*
		 * USART3_TX    ====>  PB10
		 * USART3_RX    ====>  PB11
		 * USART3_CTS   ====>  PB13
		 * USART3_RTS   ====>  PB14
		 * */


		// USART3_TX    ====>  PB10
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		// USART3_RX    ====>  PB11
		PinCfg.GPIO_PinNumber = GPIO_PIN_11;
		PinCfg.GPIO_MODE = GPIO_MODE_INPUT_AF;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		if(Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_CTS ||Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_CTS_RTS)
		{
			// USART3_CTS   ====>  PB13
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

		}else if(Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_RTS ||Global_UART_Config->USART_HwFlowCtl == USART_HwFlowCtl_CTS_RTS)
		{
			// USART3_RTS   ====>  PB14
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

		}

	}

}

















/*
 * ===================================
 * @FN				- MCAL_UART_SendData
 * @brief			- DEinitialization UART (Supported feature asynchronous only
 * @param [in]		- USARTx: where x can be (1,2,3 depending on device used)
 * @param [in]		- pTxBuffer:
 * @param [in]		- PollingEN: enable polling or disable it
 * @retval			- none
 * @Note			- should initialize usart first
 * 						When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
						the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
						because it is replaced by the parity.
						When receiving with the parity enabled, the value read in the MSB bit is the received parity
						bit.
 * ===================================
 * */
void MCAL_UART_SendData(USART_TypeDef* USARTx , uint16_t* pTxBuffer , enum Polling_Mechism PollingEN)
{
	//Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
	// for each data to be transmitted in case of single buffer.
	// wait until TXE flag is  set in SR => send data from transmit data register (TDR) === TO ===> transmit shift register
	if(PollingEN == enable)
	{
		while(!(USARTx->SR & 1<<7));
	}


	// check the USART word length item for 8B , 9B in a frame
	if(Global_UART_Config->USART_PayLoad_Length == USART_PayLoad_Length_9B)
	{
		USARTx->DR = (*pTxBuffer & (uint16_t)0x01FF);
	}else

	{
		// this is 8bit data transfer
		USARTx->DR = (*pTxBuffer & (uint8_t)0xFF);

	}



}




/*
 * ===================================
 * @FN				- MCAL_UART_ReceiveData
 * @brief			- DEinitialization UART (Supported feature asynchronous only
 * @param [in]		- USARTx: where x can be (1,2,3 depending on device used)
 * @retval			- none
 * @Note			- reset the module by RCC
 * ===================================
 * */
void MCAL_UART_ReceiveData(USART_TypeDef* USARTx , uint16_t* pRxBuffer , enum Polling_Mechism PollingEN)
{
	if(PollingEN == enable)
	{
		while(!(USARTx->SR & 1<<5));
	}

	// check USART word length 8B , 9B
	if(Global_UART_Config->USART_PayLoad_Length == USART_PayLoad_Length_9B)
	{
		// check parity
		if(Global_UART_Config->USART_Parity == USART_Parity_NONE)
		{
			// no parity so select all 9bit are considered data
			*((uint16_t *)pRxBuffer) = USARTx->DR;
		}else
		{
			// parity is used , so 8bit only are considered as data and 1bit is parity
			*((uint16_t *)pRxBuffer) = (USARTx->DR & (uint8_t)0xFF);
		}

	}else
	{
		// this is 8bit data
		// check parity
		if(Global_UART_Config->USART_Parity == USART_Parity_NONE)
		{
			// no parity so select all 8bit are considered data
			*((uint16_t *)pRxBuffer) = (USARTx->DR & (uint8_t)0xFF);
		}else
		{
			// parity is used , so 7bit only are considered as data and 1bit is parity
			*((uint16_t *)pRxBuffer) = (USARTx->DR & (uint8_t)0x7F);
		}

	}

}






void MCAL_UART_Wait_TC(USART_TypeDef* USARTx )
{
	// wait until TC flag is set in the SR
	while(!(USARTx->SR & 1<<6));
}












/*
 * ===========================================================================================================
 *											ISR
 * ===========================================================================================================
 * */


void USART1_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CallBack ();
}

void USART2_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CallBack ();
}

void USART3_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CallBack ();
}












