/*
 * STM32F103C6_SPI_Driver.c
 *
 *  Created on: Oct 5, 2023
 *      Author: Mohamed Belal
 */


#include "STM32F103C6_SPI_Driver.h"

/*
 * ===========================================================================================================
 *											 Generic variables
 * ===========================================================================================================
 * */
SPI_Config_t*	Global_SPI_Config[2] = {NULL , NULL};


/*
 * ===========================================================================================================
 * 											 Generic Macros
 * ===========================================================================================================
 * */
#define SPI1_Index 			0
#define SPI2_Index 			1



#define SPI_SR_TXE			((uint8_t)0x02)			/* transmit buffer Empty    */
#define SPI_SR_RXNE			((uint8_t)0x01)			/* receive buffer not Empty */

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
 * @FN				- MCAL_SPI_Init
 * @brief			- initialization SPI according to specific parameter
 * @param [in]		- SPIx: where x can be (1,2 depending on device used)
 * @param [in]		- SPI_config: all SPI configuration SPI_Config_t
 * @retval			- none
 * @Note			- support for SPI full Duplex master/slave only & NSS HW/SW
 * 					- in case of master you have to configure pin and drive it
 * ===================================
 * */
void MCAL_SPI_Init(SPI_TypeDef * SPIx , SPI_Config_t * SPI_config )
{
	/* ------------- safety for register ------------- */
	uint16_t tempRegister_CR1 = 0;
	uint16_t tempRegister_CR2 = 0;


	if(SPIx == SPI1)
	{
		Global_SPI_Config[SPI1_Index] = SPI_config;
		RCC_SPI1_CLK_EN();
	}else if(SPIx == SPI2)
	{
		Global_SPI_Config[SPI2_Index] = SPI_config;
		RCC_SPI2_CLK_EN();
	}

	/* ------------- enable SPI CR1.SPE BIT6 W1 to enable ------------- */
	tempRegister_CR1 = (0x1U<<6);


	/* --------------------- master | slave --------------------------- */
	tempRegister_CR1 |= SPI_config->Device_Mode;


	/* -------------------- SPI_Communication_Mode -------------------- */
	tempRegister_CR1 |= SPI_config->Communication_Mode;


	/* -------------------- SPI_Frame_Format ------------------------- */
	tempRegister_CR1 |= SPI_config->Frame_Format;


	/* -------------------- SPI_DataSize ----------------------------- */
	tempRegister_CR1 |= SPI_config->DataSize;


	/* -------------------- SPI_CLKPolarity ------------------------- */
	tempRegister_CR1 |= SPI_config->CLKPolarity;


	/* -------------------- SPI_CLKPhase ---------------------------- */
	tempRegister_CR1 |= SPI_config->CLKPhase;


	/* --------------------- SPI_NSS ------------------------------- */
	if(SPI_config->NSS == SPI_NSS_HW_Master_SS_Output_Enable)
	{
		tempRegister_CR2 |= SPI_config->NSS;
	}else if(SPI_config->NSS == SPI_NSS_HW_Master_SS_Output_Disable)
	{
		tempRegister_CR2 &= SPI_config->NSS;
	}else
	{
		tempRegister_CR1 |= SPI_config->NSS;
	}


	/* --------------------- SPI_SPI_BaudRate --------------------- */
	tempRegister_CR1 |= SPI_config->SPI_BaudRate;


	/* --------------------- SPI_IRQ_Enable ----------------------- */
	if(SPI_config->IRQ_Enable != SPI_IRQ_Enable_NONE)
	{
		tempRegister_CR2 |= SPI_config->IRQ_Enable;
		if(SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_Enable;
		}else if(SPIx == SPI2)
		{
			NVIC_IRQ36_SPI2_Enable;
		}
	}



	SPIx->SPI_CR1 = tempRegister_CR1;
	SPIx->SPI_CR2 = tempRegister_CR2;
}








/*
 * ===================================
 * @FN				- MCAL_SPI_DeInit
 * @brief			- De initialization SPI according to specific parameter
 * @param [in]		- SPIx: where x can be (1,2 depending on device used)
 * @retval			- none
 * @Note			- none
 * ===================================
 * */
void MCAL_SPI_DeInit(SPI_TypeDef * SPIx )
{
	if(SPIx == SPI1)
	{
		NVIC_IRQ35_SPI1_Disable;
		RCC_SPI1_Rest();
	}else if(SPIx == SPI2)
	{
		NVIC_IRQ36_SPI2_Disable;
		RCC_SPI2_Rest();
	}
}




/*
 * ===================================
 * @FN				- MCAL_SPI_GPIO_Set_Pins
 * @brief			- initialization SPI according to specific parameter
 * @param [in]		- SPIx: where x can be (1,2 depending on device used)
 * @param [in]		- SPI_config: all SPI configuration SPI_Config_t
 * @retval			- none
 * @Note			- support for SPI full Duplex master/slave only & NSS HW/SW
 * 					- in case of master you have to configure pin and drive it
 * ===================================
 * */
void MCAL_SPI_GPIO_Set_Pins(SPI_TypeDef * SPIx )
{
	GPIO_PinConfig_t pinCfg ;
	if(SPIx == SPI1)
	{
		/*
		 * PA4  ====> SPI1_NSS
		 * PA5  ====> SPI1_SCK
		 * PA6  ====> SPI1_MISO
		 * PA7  ====> SPI1_MOSI
		 */
		// 9.1.11 GPIO configurations for device peripherals
		// Table 25. SPI
		if(Global_SPI_Config[SPI1_Index]->Device_Mode == Device_Mode_Master)
		{
			// PA4  ====> SPI1_NSS
			switch(Global_SPI_Config[SPI1_Index]->NSS)
			{
			case SPI_NSS_HW_Master_SS_Output_Disable:
				//	Hardware master /slave Input floating/
				pinCfg.GPIO_PinNumber = GPIO_PIN_4;
				pinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLOATING;
				MCAL_GPIO_Init(GPIOA, &pinCfg);
				break;
			case SPI_NSS_HW_Master_SS_Output_Enable:
				//Hardware master/ NSS output enabled Alternate function push-pull
				pinCfg.GPIO_PinNumber = GPIO_PIN_4;
				pinCfg.GPIO_MODE =GPIO_MODE_OUTPUT_AF_PP;
				pinCfg.GPIO_output_speed = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOA, &pinCfg);
				break;
			}


			// PA5  ====> SPI1_SCK
			// Master Alternate function push-pull
			pinCfg.GPIO_PinNumber = GPIO_PIN_5;
			pinCfg.GPIO_MODE =GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_output_speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &pinCfg);


			//PA6  ====> SPI1_MISO
			// Full duplex / master Input floating / Input pull-up
			pinCfg.GPIO_PinNumber = GPIO_PIN_6;
			pinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &pinCfg);


			// PA7  ====> SPI1_MOSI
			// Full duplex / master Alternate function push-pull
			pinCfg.GPIO_PinNumber = GPIO_PIN_7;
			pinCfg.GPIO_MODE =GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_output_speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &pinCfg);

		}else /* ======================== slave ======================== */
		{

			// PA4  ====> SPI1_NSS
			if(Global_SPI_Config[SPI1_Index]->NSS == SPI_NSS_HW_Slave)
			{
				//	Hardware master /slave Input floating/
				pinCfg.GPIO_PinNumber = GPIO_PIN_4;
				pinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLOATING;
				MCAL_GPIO_Init(GPIOA, &pinCfg);
			}


			// PA5  ====> SPI1_SCK
			// Slave Input floating
			pinCfg.GPIO_PinNumber = GPIO_PIN_5;
			pinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &pinCfg);


			//PA6  ====> SPI1_MISO
			// Full duplex / slave (point to point) Alternate function push-pull
			//TODO: Full duplex / slave (multi-slave) Alternate function open drain
			pinCfg.GPIO_PinNumber = GPIO_PIN_6;
			pinCfg.GPIO_MODE =GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_output_speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &pinCfg);


			// PA7  ====> SPI1_MOSI
			// Full duplex / slave Input floating / Input pull-up
			pinCfg.GPIO_PinNumber = GPIO_PIN_7;
			pinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &pinCfg);


		}


	}else if(SPIx == SPI2)
	{
		/*
		 * PA12  ====> SPI2_NSS
		 * PA13  ====> SPI2_SCK
		 * PA14  ====> SPI2_MISO
		 * PA15  ====> SPI2_MOSI
		 */
		if(Global_SPI_Config[SPI2_Index]->Device_Mode == Device_Mode_Master)
		{
			// PA12  ====> SPI2_NSS
			switch(Global_SPI_Config[SPI2_Index]->NSS)
			{
			case SPI_NSS_HW_Master_SS_Output_Disable:
				//	Hardware master /slave Input floating/
				pinCfg.GPIO_PinNumber = GPIO_PIN_12;
				pinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLOATING;
				MCAL_GPIO_Init(GPIOA, &pinCfg);
				break;
			case SPI_NSS_HW_Master_SS_Output_Enable:
				//Hardware master/ NSS output enabled Alternate function push-pull
				pinCfg.GPIO_PinNumber = GPIO_PIN_12;
				pinCfg.GPIO_MODE =GPIO_MODE_OUTPUT_AF_PP;
				pinCfg.GPIO_output_speed = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOA, &pinCfg);
				break;
			}


			// PA13  ====> SPI2_SCK
			// Master Alternate function push-pull
			pinCfg.GPIO_PinNumber = GPIO_PIN_13;
			pinCfg.GPIO_MODE =GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_output_speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &pinCfg);


			//PA14  ====> SPI2_MISO
			// Full duplex / master Input floating / Input pull-up
			pinCfg.GPIO_PinNumber = GPIO_PIN_14;
			pinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &pinCfg);


			// PA15  ====> SPI2_MOSI
			// Full duplex / master Alternate function push-pull
			pinCfg.GPIO_PinNumber = GPIO_PIN_15;
			pinCfg.GPIO_MODE =GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_output_speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &pinCfg);

		}else /* ======================== slave ======================== */
		{

			// PA12  ====> SPI2_NSS
			if(Global_SPI_Config[SPI2_Index]->NSS == SPI_NSS_HW_Slave)
			{
				//	Hardware master /slave Input floating/
				pinCfg.GPIO_PinNumber = GPIO_PIN_12;
				pinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLOATING;
				MCAL_GPIO_Init(GPIOA, &pinCfg);
			}


			// PA13  ====> SPI2_SCK
			// Slave Input floating
			pinCfg.GPIO_PinNumber = GPIO_PIN_13;
			pinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &pinCfg);


			//PA14  ====> SPI2_MISO
			// Full duplex / slave (point to point) Alternate function push-pull
			//TODO: Full duplex / slave (multi-slave) Alternate function open drain
			pinCfg.GPIO_PinNumber = GPIO_PIN_14;
			pinCfg.GPIO_MODE =GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_output_speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &pinCfg);


			// PA15  ====> SPI2_MOSI
			// Full duplex / slave Input floating / Input pull-up
			pinCfg.GPIO_PinNumber = GPIO_PIN_15;
			pinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &pinCfg);
		}
	}

}






/*
 * ===================================
 * @FN				- MCAL_SPI_SendData
 * @brief			- SPI transmit data
 * @param [in]		- SPIx: where x can be (1,2 depending on device used)
 * @param [in]		- pTxBuffer: buffer contain data that i want to transmit
 * @param [in]		- PollingEN: check polling mechanism
 * @retval			- none
 * @Note			- none
 * ===================================
 * */
void MCAL_SPI_SendData(SPI_TypeDef * SPIx , uint16_t *pTxBuffer ,  enum PollingMechanism PollingEN)
{
	if(PollingEN == PollingEnable)
		while(!(SPIx->SPI_SR & SPI_SR_TXE));

	SPIx->SPI_DR = *pTxBuffer;
}



/*
 * ===================================
 * @FN				- MCAL_SPI_ReceiveData
 * @brief			- SPI receive data
 * @param [in]		- SPIx: where x can be (1,2 depending on device used)
 * @param [in]		- pTxBuffer: buffer to store data received
 * @param [in]		- PollingEN: check polling mechanism
 * @retval			- none
 * @Note			- none
 * ===================================
 * */
void MCAL_SPI_ReceiveData(SPI_TypeDef * SPIx , uint16_t *pTxBuffer ,  enum PollingMechanism PollingEN)
{
	if(PollingEN == PollingEnable)
		while(!(SPIx->SPI_SR & SPI_SR_RXNE));

	*pTxBuffer = SPIx->SPI_DR;
}




/*
 * ===================================
 * @FN				- MCAL_SPI_TX_RX
 * @brief			- SPI transmit & receive data
 * @param [in]		- SPIx: where x can be (1,2 depending on device used)
 * @param [in]		- pTxBuffer: buffer contain data that i want to transmit |
 * 								 OR buffer to store data received
 * @param [in]		- PollingEN: check polling mechanism
 * @retval			- none
 * @Note			- none
 * ===================================
 * */
void MCAL_SPI_TX_RX(SPI_TypeDef * SPIx , uint16_t *pTxBuffer ,  enum PollingMechanism PollingEN)
{
	/* ---------------- transmit ---------------- */
	if(PollingEN == PollingEnable)
		while(!(SPIx->SPI_SR & SPI_SR_TXE));

	SPIx->SPI_DR = *pTxBuffer;

	/* ---------------- receive ---------------- */
	if(PollingEN == PollingEnable)
		while(!(SPIx->SPI_SR & SPI_SR_RXNE));

	*pTxBuffer = SPIx->SPI_DR;
}




/*
 * ===========================================================================================================
 *											ISR
 * ===========================================================================================================
 * */
void SPI1_IRQHandler(void)
{
	struct S_IRQ_SRC IRQ_src;
	IRQ_src.TXE   = ( ( (SPI1->SR) & (1<<1) ) >> 1);
	IRQ_src.RXNE  = ( ( (SPI1->SR) & (1<<0) ) >> 0);
	IRQ_src.ERRI  = ( ( (SPI1->SR) & (1<<4) ) >> 4);
	Global_SPI_Config[SPI1_Index]->P_IRQ_CallBack(IRQ_src);
}

void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC IRQ_src;
	IRQ_src.TXE   = ( ( (SPI2->SR) & (1<<1) ) >> 1);
	IRQ_src.RXNE  = ( ( (SPI2->SR) & (1<<0) ) >> 0);
	IRQ_src.ERRI  = ( ( (SPI2->SR) & (1<<4) ) >> 4);
	Global_SPI_Config[SPI2_Index]->P_IRQ_CallBack(IRQ_src);
}
