/*
 * STM32F103C6_SPI_Driver.h
 *
 *  Created on: Oct 5, 2023
 *      Author: Mohamed Belal
 */

#ifndef INC_STM32F103C6_SPI_DRIVER_H_
#define INC_STM32F103C6_SPI_DRIVER_H_

//---------------------------------------------------------------------------------------------------------------
//														Includes
//---------------------------------------------------------------------------------------------------------------
#include "STM32F103x6.h"
#include "STM32F103C6_GPIO_Drivers.h"



//---------------------------------------------------------------------------------------------------------------
//										User Type Definition (Structures)
//---------------------------------------------------------------------------------------------------------------
struct S_IRQ_SRC{
	uint8_t TXE:1;
	uint8_t RXNE:1;
	uint8_t ERRI:1;
	uint8_t Recerved:5;
};

typedef struct{

	/* ==== Device_Mode ====
	 * specifies the SPI operate mode
	 * this parameter must be set base on @ref Device_Mode_DEFINE
	 * */
	uint16_t	Device_Mode;			// specifies the SPI operate mode @ref Device_Mode_DEFINE


	/* ==== Communication_Mode ====
	 * specifies the SPI bidirection mode
	 * this parameter must be set base on @ref Communication_Mode_DEFINE
	 * */
	uint16_t	Communication_Mode;



	/* ==== Frame_Format ====
	 *  specifies the SPI (MSB | LSB)
	 * this parameter must be set base on @ref Frame_Format_DEFINE
	 * */
	uint16_t	Frame_Format;



	/* ==== DataSize ====
	 * specifies the SPI data size   ( 8bit | 16bit )
	 * this parameter must be set base on @ref DataSize_DEFINE
	 * */
	uint16_t	DataSize;



	/* ==== CLKPolarity ====
	 * specifies the SPI operate mode
	 * this parameter must be set base on @ref CLKPolarity_DEFINE
	 * */
	uint16_t	CLKPolarity;



	/* ==== CLKPhase ====
	 * specifies the SPI operate mode
	 * this parameter must be set base on @ref CLKPhase_DEFINE
	 * */
	uint16_t	CLKPhase;



	/* ==== NSS ====
	 * specifies whether the NSS signal in managed by
	 * 				hardware (NSS BIN)
	 * 				software (using SSI bitenable
	 * this parameter must be set base on @ref SPI_NSS_DEFINE
	 * */
	uint16_t	NSS;



	/* ==== SPI_BaudRate ====
	 * specifies the baudRate prescaler value which will
	 * be configure the transmit & receive SCK clock
	 * this parameter must be set base on @ref SPI_BaudRatePrescaler_DEFINE
	 *
	 * @note:
	 * 		the communication clock is derived from master clock
	 * 		the salve clock does not need to be set
	 *
	 * take care you have to configure the RCC to enter the correct clock value to the APB1 => SPI2
	 * 																				   APB2 => SPI1
	 * */
	uint16_t	SPI_BaudRate;



	/* ==== IRQ_Enable ====
	 * this parameter must be set base on @ref SPI_IRQ_Enable_DEFINE
	 * */
	uint16_t	IRQ_Enable;



	/* ==== Device_Mode ====
	 * set c function which will be called when the IRQ happen
	 * */
	void (* P_IRQ_CallBack)(struct S_IRQ_SRC );


}SPI_Config_t;



//---------------------------------------------------------------------------------------------------------------
//											Macros Configuration References
//---------------------------------------------------------------------------------------------------------------

//-------------------------------------
//		@ref Device_Mode_DEFINE
//-------------------------------------
//   25.5.1 SPI control register 1 (SPI_CR1)
/*
 * 	 Bit 2 MSTR: Master selection
 *		0: Slave configuration
 *		1: Master configuration
 *   Note: This bit should not be changed when communication is ongoing.
 *   It is not used in I2S mode.
 */
#define Device_Mode_Slave						(0x00000000U)
#define Device_Mode_Master						(0x1U<<2)





//-------------------------------------
//		@ref Communication_Mode_DEFINE
//-------------------------------------
//   25.5.1 SPI control register 1 (SPI_CR1)
/*
 * 	 Bit 15 BIDIMODE: Bidirectional data mode enable
			0: 2-line unidirectional data mode selected
			1: 1-line bidirectional data mode selected
	Note: This bit is not used in I2S mode
	------------------------------------
	Bit 14 BIDIOE: Output enable in bidirectional mode
	This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
			0: Output disabled (receive-only mode)
			1: Output enabled (transmit-only mode)
	Note: This bit is not used in I2S mode.
	In master mode, the MOSI pin is used while the MISO pin is used in slave mode.
	-----------------------------------
	Bit 10 RXONLY: Receive only
	This bit combined with the BIDImode bit selects the direction of transfer in 2-line
	unidirectional mode. This bit is also useful in a multislave system in which this particular
	slave is not accessed, the output from the accessed slave is not corrupted.
			0: Full duplex (Transmit and receive)
			1: Output disabled (Receive-only mode)
	Note: This bit is not used in I2S mode
 */
#define SPI_Direction_2LINE						(0x00000000U)
#define SPI_Direction_2LINE_RXonly				(0x1U<<10)
#define SPI_Direction_1LINE_receive_only		(0x1U<<15)
#define SPI_Direction_1LINE_transmit_only		((0x1U<<15)|(0x1U<<14))





//-------------------------------------
//		@ref Frame_Format_DEFINE
//-------------------------------------
//   25.5.1 SPI control register 1 (SPI_CR1)
/*
 	 Bit 7 LSBFIRST: Frame format
			0: MSB transmitted first
			1: LSB transmitted first
	Note: This bit should not be changed when communication is ongoing.
	It is not used in I2S mode
 */
#define SPI_Frame_Format_MSB_Transmitted_First	(0x00000000U)
#define SPI_Frame_Format_LSB_Transmitted_First	(0x1U<<7)






//-------------------------------------
//		@ref DataSize_DEFINE
//-------------------------------------
//   25.5.1 SPI control register 1 (SPI_CR1)
/*
 	 Bit 11 DFF: Data frame format
			0: 8-bit data frame format is selected for transmission/reception
			1: 16-bit data frame format is selected for transmission/reception
	Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation.
	It is not used in I2S mode.
 */
#define SPI_DataSize_8BIT					(0x00000000U)
#define SPI_DataSize_16BIT					(0x1U<<11)







//-------------------------------------
//		@ref CLKPolarity_DEFINE
//-------------------------------------
//   25.5.1 SPI control register 1 (SPI_CR1)
/*
 	Bit1 CPOL: Clock polarity
			0: CK to 0 when idle
			1: CK to 1 when idle
	Note: This bit should not be changed when communication is ongoing.
	It is not used in I2S mode
 */
#define SPI_CLKPolarity_0_when_idle			(0x00000000U)
#define SPI_CLKPolarity_1_when_idle			(0x1U<<1)




//-------------------------------------
//		@ref CLKPhase_DEFINE
//-------------------------------------
//   25.5.1 SPI control register 1 (SPI_CR1)
/*
 	Bit 0 CPHA: Clock phase
			0: The first clock transition is the first data capture edge
			1: The second clock transition is the first data capture edge
	Note: This bit should not be changed when communication is ongoing.
	It is not used in I2S mode
 */
#define SPI_CLKPhase_1stEdge_First_Data_Capture_Edge			(0x00000000U)
#define SPI_CLKPhase_2ndEdge_First_Data_Capture_Edge			(0x1U<<0)







//-------------------------------------
//		@ref SPI_NSS_DEFINE
//-------------------------------------
//   25.5.1 SPI control register 1 (SPI_CR1)
/*
 	Bit 9 SSM: Software slave management
	When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
			0: Software slave management disabled
			1: Software slave management enabled
	Note: This bit is not used in I2S mode
	------------------------------------------
	Bit 8 SSI: Internal slave select
	This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the
	NSS pin and the IO value of the NSS pin is ignored.
	Note: This bit is not used in I2S mode
 */
//   25.5.2 SPI control register 2 (SPI_CR2)
/*
 	Bit 2 SSOE: SS output enable
			0: SS output is disabled in master mode and the cell can work in multimaster configuration
			1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work
	in a multimaster environment.
	Note: This bit is not used in I2S mode
 */
/* ========= hardware =========  SPI_CR2 */
#define SPI_NSS_HW_Slave										(0x00000000U)
#define SPI_NSS_HW_Master_SS_Output_Enable						(0x1U<<2)
#define SPI_NSS_HW_Master_SS_Output_Disable						~(0x1U<<2)
/* ========= software ========= SPI_CR1*/    /* NSS is driven by SW(master salve) */
#define SPI_NSS_SW_NSSInternalSoft_Reset						(0x1U<<9)
#define SPI_NSS_SW_NSSInternalSoft_Set							((0x1U<<9)|(0x1U<<8))








//-------------------------------------
//		@ref SPI_BaudRatePrescaler_DEFINE
//-------------------------------------
//   25.5.1 SPI control register 1 (SPI_CR1)
/*
 	Bits 5:3 BR[2:0]: Baud rate control
			000: fPCLK/2
			001: fPCLK/4
			010: fPCLK/8
			011: fPCLK/16
			100: fPCLK/32
			101: fPCLK/64
			110: fPCLK/128
			111: fPCLK/256
	Note: These bits should not be changed when communication is ongoing.
	They are not used in I2S mode.
 */
#define SPI_BaudRatePrescaler_2								(0x00000000U)
#define SPI_BaudRatePrescaler_4								(0b001U<<3)
#define SPI_BaudRatePrescaler_8								(0b010U<<3)
#define SPI_BaudRatePrescaler_16							(0b011U<<3)
#define SPI_BaudRatePrescaler_32							(0b100U<<3)
#define SPI_BaudRatePrescaler_64							(0b101U<<3)
#define SPI_BaudRatePrescaler_128							(0b110U<<3)
#define SPI_BaudRatePrescaler_256							(0b111U<<3)






//-------------------------------------
//		 @ref SPI_IRQ_Enable_DEFINE
//-------------------------------------
//   25.5.2 SPI control register 2 (SPI_CR2)
/*
 	Bit 7 TXEIE: Tx buffer empty interrupt enable
			0: TXE interrupt masked
			1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
			-------------------------------
	Bit 6 RXNEIE: RX buffer not empty interrupt enable
			0: RXNE interrupt masked
			1: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is set.
			-------------------------------
	Bit 5 ERRIE: Error interrupt enable
		This bit controls the generation of an interrupt when an error condition occurs (CRCERR,
		OVR, MODF in SPI mode and UDR, OVR in I2S mode).
			0: Error interrupt is masked
			1: Error interrupt is enabled
 */
#define SPI_IRQ_Enable_NONE					(0x00000000U)
#define SPI_IRQ_Enable_TXEIE				(0x1U<<7)
#define SPI_IRQ_Enable_RXNEIE				(0x1U<<6)
#define SPI_IRQ_Enable_ERRIE				(0x1U<<5)





enum PollingMechanism{
	PollingEnable,
	PollingDisable
};


/*
 * =========================================================================================================
 * 									APIs supported by "MCAL SPI Driver"
 * =========================================================================================================
 * */

void MCAL_SPI_Init		   (SPI_TypeDef * SPIx , SPI_Config_t * SPI_config );
void MCAL_SPI_DeInit	   (SPI_TypeDef * SPIx );

void MCAL_SPI_GPIO_Set_Pins(SPI_TypeDef * SPIx );

void MCAL_SPI_SendData     (SPI_TypeDef * SPIx , uint16_t *pTxBuffer ,  enum PollingMechanism PollingEN);
void MCAL_SPI_ReceiveData  (SPI_TypeDef * SPIx , uint16_t *pTxBuffer ,  enum PollingMechanism PollingEN);

void MCAL_SPI_TX_RX        (SPI_TypeDef * SPIx , uint16_t *pTxBuffer ,  enum PollingMechanism PollingEN);





#endif /* INC_STM32F103C6_SPI_DRIVER_H_ */
