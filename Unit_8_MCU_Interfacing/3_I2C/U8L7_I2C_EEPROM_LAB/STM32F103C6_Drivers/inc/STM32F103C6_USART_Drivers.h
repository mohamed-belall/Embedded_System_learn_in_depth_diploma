/*
 * STM32F103C6_USART_Drivers.h
 *
 *  Created on: Sep 14, 2023
 *      Author: mohamed Belal
 */

#ifndef INC_STM32F103C6_USART_DRIVERS_H_
#define INC_STM32F103C6_USART_DRIVERS_H_


//-------------------------------------
//Includes
//-------------------------------------
#include "STM32F103x6.h"
#include "STM32F103C6_GPIO_Drivers.h"



//-------------------------------------
//User Type Definition (Structures)
//-------------------------------------

enum USART_IRQ_Event
{
	USART_IRQ_TXE ,	 	// TRANSMIT data register empty
	USART_IRQ_TC , 		// transmission complete
	USART_IRQ_RXNE ,	// received data ready to be read
	USART_IRQ_ORE , 	// overrun error detected
	USART_IRQ_PE , 		// parity error
};


enum Polling_Mechism
{
	enable ,
	disable
};





typedef struct{

	/* ==== USART_Mode ====
	 * Specifies the USART mode TX/RX
	 * this parameter must be set base on @ref USART_Mode_Define
	 * */
	uint8_t USART_Mode;

	/* ==== USART_BaudRate ====
	 * configures the USART communication baud rate
	 * this parameter must be set base on @ref USART_BaudRate_Define
	 * */
	uint32_t USART_BaudRate;

	/* ==== USART_PayLoad_Length ====
	 * configures number of bit transmitted or received in a frame
	 * this parameter must be set base on @ref USART_PayLoad_Length_Define
	 * */
	uint8_t USART_PayLoad_Length;

	/* ==== USART_Parity ====
	 * Specifies the parity mode
	 * this parameter must be set base on @ref USART_Parity_Define
	 * */
	uint8_t USART_Parity;


	/* ==== USART_StopBits ====
	 * Specifies number of stop bits transmitted
	 * this parameter must be set base on @ref USART_StopBits_Define
	 * */
	uint8_t USART_StopBits;


	/* ==== USART_HwFlowCtl ====
	 * Specifies whether the hardware flow control enable or disable
	 * this parameter must be set base on @ref USART_HwFlowCtl_Define
	 * */
	uint8_t USART_HwFlowCtl;


	/* ==== USART_IRQ_Enable ====
	 * enable or disable uart IRQ TX/RX
	 * this parameter must be set base on @ref USART_IRQ_Enable_Define
	 * */
	uint8_t USART_IRQ_Enable;


	/* ==== void(*P_IRQ_CallBack)(void); ====
	 * set the c function() will be called once the IRQ happen
	 * */
	void(*P_IRQ_CallBack)(void);


}UART_ConFig;





//-------------------------------------
//Macros Configuration References
//-------------------------------------


// @ref USART_Mode_Define
//Bit 3 TE: Transmitter enable
//	This bit enables the transmitter. It is set and cleared by software.
//		0: Transmitter is disabled
//		1: Transmitter is enabled
//Note: 1: During transmission, a “0” pulse on the TE bit (“0” followed by “1”) sends a preamble
//			(idle line) after the current word, except in Smartcard mode.
//		2: When TE is set there is a 1 bit-time delay before the transmission starts.
//Bit 2 RE: Receiver enable
//	This bit enables the receiver. It is set and cleared by software.
//		0: Receiver is disabled
//		1: Receiver is enabled and begins searching for a start bit
#define USART_Mode_TX					(uint32_t)(1<<3)
#define USART_Mode_RX					(uint32_t)(1<<2)
#define USART_Mode_TX_RX				(uint32_t)((1<<3) | (1<<2))


//@ref USART_BaudRate_Define
#define USART_BaudRate_2400					2400
#define USART_BaudRate_9600					9600
#define USART_BaudRate_19200				19200
#define USART_BaudRate_57600				57600
#define USART_BaudRate_115200				115200
#define USART_BaudRate_230400				230400
#define USART_BaudRate_460800				460800
#define USART_BaudRate_921600				921600
#define USART_BaudRate_2250000				2250000
#define USART_BaudRate_4500000				4500000



//@ref USART_PayLoad_Length_Define
//Bit 12 M: Word length
//	This bit determines the word length. It is set or cleared by software.
//		0: 1 Start bit, 8 Data bits, n Stop bit
//		1: 1 Start bit, 9 Data bits, n Stop bit
//Note: The M bit must not be modified during a data transfer (both transmission and reception)
#define USART_PayLoad_Length_8B				(uint32_t)(0)
#define USART_PayLoad_Length_9B				(uint32_t)(1<<12)





// @ref USART_Parity_Define
#define USART_Parity_NONE					( (uint32_t) (0) )
#define USART_Parity_Even					( (uint32_t) (1<<10) )
#define USART_Parity_Odd					( (uint32_t) ((1<<10) | (1<<9)) )



// @ref USART_StopBits_Define
#define USART_StopBits_half					( (uint32_t) (1<<12) )
#define USART_StopBits_1					( (uint32_t) (0) 	 )
#define USART_StopBits_1_half				( (uint32_t) (3<<12) )
#define USART_StopBits_2					( (uint32_t) (2<<12) )


// @ref USART_HwFlowCtl_Define
#define USART_HwFlowCtl_NONE				( (uint32_t) (0) 	)
#define USART_HwFlowCtl_CTS					( (uint32_t) (1<<9) )
#define USART_HwFlowCtl_RTS					( (uint32_t) (1<<8) )
#define USART_HwFlowCtl_CTS_RTS				( (uint32_t) ( (1<<9) | (1<<8) ) )



// @ref USART_IRQ_Enable_Define
#define USART_IRQ_Enable_NONE				( (uint32_t) (0) )
#define USART_IRQ_Enable_TXE				( (uint32_t) (1<<7) ) // transmit data register empty
#define USART_IRQ_Enable_TC					( (uint32_t) (1<<6) ) // transmission complete
#define USART_IRQ_Enable_RXNEIE				( (uint32_t) (1<<5) ) // received data ready to be read & overrun error datected
#define USART_IRQ_Enable_PE					( (uint32_t) (1<<8) ) // parity error





//enum USART_IRQ_Event
//{
//	USART_IRQ_TXE ,	 	// TRANSMIT data register empty
//	USART_IRQ_TC , 		// transmission complete
//	USART_IRQ_RXNE ,	// received data ready to be read
//	USART_IRQ_ORE , 	// overrun error detected
//	USART_IRQ_PE , 		// parity error
//};
//
//
//enum Polling_Mechism
//{
//	enable ,
//	disable
//};


/*
 * ***********************************************
 *             Baud Rate Calculation
 * ***********************************************
 * USARTDIV = FCLK / ( 16 * BaudRate )
 * USARTDIV_MULL100 = uint32( (100 * FCLK) / (16 * BaudRate )) = uint32( (25 * FCLK) / (4 * BaudRate ))
 * DIV_Mantissa_MULL100 = integer part of(USARTDIV) * 100
 * DIV_Mantissa = integer part of(USARTDIV)
 * DIV_Fraction = ( (USARTDIV_MULL100 -  DIV_Mantissa_MULL100) *16 ) / 100
 * */
#define USARTDIV(_PCLK_ , _BaudRate_)					(uint32_t) (_PCLK_ / ( 16 * _BaudRate_ ))
#define USARTDIV_MULL100(_PCLK_ , _BaudRate_)			(uint32_t) ((25 * _PCLK_) / (4 * _BaudRate_ ))
#define Mantissa_MULL100(_PCLK_ , _BaudRate_) 			(uint32_t) (USARTDIV(_PCLK_ , _BaudRate_)*100)
#define Mantissa(_PCLK_ , _BaudRate_)					(uint32_t) (USARTDIV(_PCLK_ , _BaudRate_))
#define DIV_Fraction(_PCLK_ , _BaudRate_)				(uint32_t) (((USARTDIV_MULL100(_PCLK_ , _BaudRate_) -  Mantissa_MULL100(_PCLK_ , _BaudRate_)) *16 ) / 100)
#define UART_BRR_Register(_PCLK_ , _BaudRate_)			((Mantissa(_PCLK_ , _BaudRate_)) << 4) | ((DIV_Fraction(_PCLK_ , _BaudRate_)) & 0xF)




/*
 * =========================================================================================================
 * 									APIs supported by "MCAL USART driver"
 * =========================================================================================================
 * */

void MCAL_UART_Init(USART_TypeDef* USARTx , UART_ConFig* USART_CFG);
void MCAL_UART_DeInit(USART_TypeDef* USARTx );

void MCAL_UART_GPIO_Set_Pins(USART_TypeDef* USARTx );

void MCAL_UART_SendData(USART_TypeDef* USARTx , uint16_t* pTxBuffer , enum Polling_Mechism PollingEN);
void MCAL_UART_ReceiveData(USART_TypeDef* USARTx , uint16_t* pRxBuffer , enum Polling_Mechism PollingEN);

void MCAL_UART_Wait_TC(USART_TypeDef* USARTx );



//TODO: MCAL_USART_LIN_Init()
//TODO: MCAL_USART_Init()
//TODO: MCAL_USART_DMA_Init()

#endif /* INC_STM32F103C6_USART_DRIVERS_H_ */
