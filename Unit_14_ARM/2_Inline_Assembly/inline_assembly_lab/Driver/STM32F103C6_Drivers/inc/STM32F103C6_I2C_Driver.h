/*
 * STM32F103C6_I2C_Driver.h
 *
 *  Created on: Oct 10, 2023
 *      Author: Mohamed Belal
 */

#ifndef INC_STM32F103C6_I2C_DRIVER_H_
#define INC_STM32F103C6_I2C_DRIVER_H_



//---------------------------------------------------------------------------------------------------------------
//														Includes
//---------------------------------------------------------------------------------------------------------------
#include "STM32F103x6.h"
#include "STM32F103C6_GPIO_Drivers.h"
#include "STM32F103C6_RCC_Drivers.h"


//---------------------------------------------------------------------------------------------------------------
//										User Type Definition (Structures)
//---------------------------------------------------------------------------------------------------------------
struct Slave_I2C_Device_Address{
	uint16_t		Enable_Dual_address;		// 1-Enable		0- Disable
	uint16_t		Primary_Slave_address;
	uint16_t		Secondary_Slave_address;
	uint16_t		I2C_Slave_Address_Mode;			// @ref I2C_Slave_Address_Mode_Define
};


typedef enum
{
	I2C_EV_STOP,
	I2C_ERROR_AF,
	I2C_EV_Address_Matched,
	I2C_EV_DATA_REQ,	// the APP layer should send the data (I2C_Slave_SendData) in this state
	I2C_EV_DATA_REV,	// the APP layer should receive data  (I2C_Slave_ReceiveData) in this state
}Slave_State;


typedef struct {
	/* ==== I2C_ClockSpeed ====
	 * specifies the i2c clock speed
	 * this parameter must be set base on @ref I2C_ClockSpeed_DEFINE
	 * */
	uint32_t									I2C_ClockSpeed;


	/* ==== I2C_STRETCH_Mode ====
	 * specifies the i2c slave clock stretch
	 * this parameter must be set base on @ref I2C_STRETCH_Mode_DEFINE
	 * */
	uint32_t									I2C_STRETCH_Mode;


	/* ==== I2C_Mode ====
	 * specifies the i2c mode   I2C |  SMBUS
	 * this parameter must be set base on @ref I2C_Mode_DEFINE
	 * */
	uint32_t									I2C_Mode;




	struct Slave_I2C_Device_Address				Slave_I2C_Address;


	/* ==== I2C_ACK_Controller ====
	 * specifies the i2c acknowledge
	 * this parameter must be set base on @ref I2C_Acknowledge_Define
	 * */
	uint32_t									I2C_ACK_Controller;




	/* ==== I2C_General_Call_Address_Detection ====
	 * this parameter must be set base on @ref I2C_ENGC_Define
	 * */
	uint32_t									I2C_General_Call_Address_Detection;


	void(* P_Slave_Event_CallBack)(Slave_State state);


}I2C_InitCFG_t;



typedef enum {
	With_STOP,
	WithOut_STOP,
}Stop_Condition;

typedef enum {
	Start,
	repeated_Start,
}Repeated_Start;

typedef enum {
	DISABLE = 0,
	ENABLE  = 1,
}FunctionalState;

typedef enum {
	RESET = 0,
	SET  = 1,
}Flag_Status;

typedef enum {
	I2C_Direction_Transmitter = 0,
	I2C_Direction_Reveive  = 1,
}I2C_Direction;

#define I2C_EVENT_MASTER_BYTE_TRANSMITTING		((uint32_t)(0x00070080)) /* TRA , BUSY ,MSL , TXE */

typedef enum {
	I2C_FLAG_BUSY = 0,
	EV5 , // EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	EV6 , // EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	EV8, // EV8: TxE=1, shift register not empty, d . ata register empty, cleared by writing DR register
	EV8_1,
	EV7 , // EV7: RxNE=1 cleared by reading DR register
	MASTER_BYTE_TRANSMITTING = ((uint32_t)(0x00070080)), /* TRA , BUSY ,MSL , TXE */

}State;



// =========================================================================================================
//											Macros Configuration References
// =========================================================================================================

//-------------------------------------
//		@ref I2C_ClockSpeed_DEFINE
//-------------------------------------
//• Supports different communication speeds:
//		– Standard Speed (up to 100 kHz)
//		– Fast Speed (up to 400 kHz)
//• Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings

// to configure the clock before enable peripheral
// I2C_CR2. Bits 5:0 FREQ[5:0]: Peripheral clock frequency

// The FREQ bits must be configured with the APB clock frequency value

//• Configure the clock control registers
//			T high = CCR * TPCLK1
//			FM | SM

//• Configure the rise time register
//• Program the I2C_CR1 register to enable the peripheral
//• Set the START bit in the I2C_CR1 register to generate a Start condition
//			The peripheral input clock frequency must be at least:
//				• 2 MHz in Sm mode
//				• 4 MHz in Fm mode
#define I2C_SCLK_SM_50K					(50000U )
#define I2C_SCLK_SM_100K				(100000U)
#define I2C_SCLK_FM_200K				(200000U)		// fast mode not supported yet
#define I2C_SCLK_FM_400K				(400000U)		// fast mode not supported yet



//-------------------------------------
//		@ref I2C_STRETCH_Mode_DEFINE
//-------------------------------------
//I2C_CR1 . Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
//	This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until it is reset by software.
//			0: Clock stretching enabled
//			1: Clock stretching disabled
#define I2C_STRETCH_Mode_Enable			0x00000000U
#define I2C_STRETCH_Mode_Disable		I2C_CR1_NOSTRETCH




//-------------------------------------
//		@ref I2C_Mode_DEFINE
//-------------------------------------
//I2C_CR1.	Bit 1 SMBUS: SMBus mode
//			0: I2C mode
//			1: SMBus mode
#define I2C_Mode_I2C					0
#define I2C_Mode_SMBUS					I2C_CR1_SMBUS



//-------------------------------------
//		@ref I2C_Slave_Address_Mode_Define
//-------------------------------------
//I2C_OAR1.	Bit 15 ADDMODE Addressing mode (slave mode)
//				0: 7-bit slave address (10-bit address not acknowledged)
//				1: 10-bit slave address (7-bit address not acknowledged)
#define I2C_Slave_Address_7Bit			0
#define I2C_Slave_Address_10Bit			((uint16_t)(1<<15))


//-------------------------------------
//		@ref I2C_Acknowledge_Define
//-------------------------------------
//Bit 10 ACK: Acknowledge enable
//	This bit is set and cleared by software and cleared by hardware when PE=0.
//		0: No acknowledge returned
//		1: Acknowledge returned after a byte is received (matched address or data)
#define I2C_Acknowledge_Enable			I2C_CR1_ACK
#define I2C_Acknowledge_Disable			(0x00000000U)




//-------------------------------------
//		@ref I2C_ENGC_Define
//-------------------------------------
//I2C_CR1.   Bit 6 ENGC: General call enable
//				0: General call disabled. Address 00h is NACKed.
//				1: General call enabled. Address 00h is ACKed.
#define I2C_ENGC_Enable				I2C_CR1_ENGC
#define I2C_ENGC_Disable			(0x00000000U)




/*
 * =========================================================================================================
 * 									APIs supported by "MCAL I2C Driver"
 * ========================================================================  =================================
 * */

void MCAL_I2C_INIT			(I2C_TypeDef* I2Cx ,I2C_InitCFG_t* I2C_INITstruct );
void MCAL_I2C_DeINIT		(I2C_TypeDef* I2Cx  );

void MCAL_I2C_GPIO_Set_PIN	(I2C_TypeDef* I2Cx  );



// master polling mechanism
// we pass the repeat parameter to check if (repeatCondition ==1 ) => bus will not check if bus is idle or not
void MCAL_I2C_Master_TX(I2C_TypeDef * I2Cx , uint16_t DeviceAddress, uint8_t* dataOut , uint32_t dataLen, Stop_Condition Stop , Repeated_Start Rstart);
void MCAL_I2C_Master_RX(I2C_TypeDef * I2Cx , uint16_t DeviceAddress, uint8_t* dataOut , uint32_t dataLen, Stop_Condition Stop , Repeated_Start Rstart);




// slave interrupt mechanism
void MCAL_I2C_Slave_TX(I2C_TypeDef * I2Cx , uint8_t data);
uint8_t MCAL_I2C_Slave_RX(I2C_TypeDef * I2Cx );



/*
 * ----------------------------------------------
 * 					general APIs
 * ----------------------------------------------
 * */

void 		I2C_GenerateStart(I2C_TypeDef * I2Cx , FunctionalState NewSatate , Repeated_Start start);
void 		I2C_GenerateStop (I2C_TypeDef * I2Cx , FunctionalState NewSatate);
Flag_Status I2C_GetFlagStatus(I2C_TypeDef * I2Cx , State flag);
void 		I2C_SenAddress   (I2C_TypeDef * I2Cx , uint16_t address , I2C_Direction Direction);
void I2C_AcknowledgeConfiguration(I2C_TypeDef* I2Cx , FunctionalState NewState);

#endif /* INC_STM32F103C6_I2C_DRIVER_H_ */
