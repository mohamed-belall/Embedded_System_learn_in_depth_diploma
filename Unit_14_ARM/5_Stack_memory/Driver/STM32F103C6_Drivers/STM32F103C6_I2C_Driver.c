/*
 * STM32F103C6_I2C_Driver.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Mohamed belal
 */



#include "STM32F103C6_I2C_Driver.h"

/*
 * ===========================================================================================================
 *											 Generic variables
 * ===========================================================================================================
 * */
I2C_InitCFG_t Global_I2C_Config[2] = {NULL , NULL};


/*
 * ===========================================================================================================
 * 											 Generic Macros
 * ===========================================================================================================
 * */
#define I2C1_Index			0
#define I2C2_Index			1


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
 * @FN				- MCAL_I2C_INIT
 * @brief			- initialization I2C according to specific parameter
 * @param [in]		- I2Cx: where x can be (1,2 depending on device used)
 * @param [in]		- I2C_INITstruct: all SPI configuration SPI_Config_t
 * @retval			- none
 * @Note			-
 * ===================================
 * */
void MCAL_I2C_INIT(I2C_TypeDef* I2Cx ,I2C_InitCFG_t* I2C_INITstruct )
{
	uint16_t tempREG =0 , FreqRange =0;
	uint32_t pclk1 = 8000000;
	uint16_t result = 0;


	// enable clock
	if(I2Cx == I2C1)
	{
		Global_I2C_Config[I2C1_Index] = *I2C_INITstruct;
		RCC_I2C1_CLK_EN();

	}else if(I2Cx == I2C2)
	{
		Global_I2C_Config[I2C2_Index] = *I2C_INITstruct;
		RCC_I2C2_CLK_EN();
	}
	if(I2C_INITstruct->I2C_Mode == I2C_Mode_I2C)
	{
		/*1. INIT Timing*/
		// Get I2C_CR2 value
		tempREG = I2Cx->I2C_CR2;
		// clear Bits 5:0 FREQ[5:0]: Peripheral clock frequency
		tempREG &= ~(I2C_CR2_FREQ_Msk);
		// get PCLK value from RCC Driver
		pclk1 = MCAL_RCC_GetPCLK1Freq();
		// write this value on tmpreg
		FreqRange = (uint16_t)(pclk1/1000000);

		tempREG |= FreqRange;
		// write to I2C_CR2
		I2Cx->I2C_CR2 = tempREG;


		//• Configure the clock control registers
		// disable selected I2C clock to configure timing
		I2Cx->I2C_CR1 &= ~(I2C_CR1_PE);
		tempREG =0;

		// configure speed in standard mode
		if(I2C_INITstruct->I2C_ClockSpeed == I2C_SCLK_SM_50K || I2C_INITstruct->I2C_ClockSpeed == I2C_SCLK_SM_100K)
		{

			/*
			 * Thigh = CRR * Tpclk
			 * Ti2c/2 = CRR * Tpclk
			 * CRR = Ti2c/ (2 * Tpclk)
			 * CRR = Fpclk/ (2 * Fi2c)
			 * */
			// result = pclk1 / (I2C_INITstruct->I2C_ClockSpeed * 2); same as EQ in next line
			result = (uint16_t)( pclk1 / (I2C_INITstruct->I2C_ClockSpeed << 1) );

			tempREG |= result;

			// write I2Cx->I2C_CCR
			I2Cx->I2C_CCR = tempREG;

			/* --------------- I2C_TRISE configuration ---------------*/
			//			For instance: in Sm mode, the maximum allowed SCL rise time is 1000 ns.
			//			If, in the I2C_CR2 register, the value of FREQ[5:0] bits is equal to 0x08 and TPCLK1 = 125 ns
			//			therefore the TRISE[5:0] bits must be programmed with 09h.
			//			(1000 ns / 125 ns = 8 + 1)
			I2Cx->I2C_TRISE = FreqRange + 1;
		}else
		{
			// fast mode not supported yet
		}

		/* --------------- I2C_CR1 configuration ---------------*/
		tempREG = I2Cx->I2C_CR1;

		tempREG |= I2C_INITstruct->I2C_ACK_Controller;
		tempREG |= I2C_INITstruct->I2C_General_Call_Address_Detection;
		tempREG |= I2C_INITstruct->I2C_Mode;
		tempREG |= I2C_INITstruct->I2C_STRETCH_Mode;

		// write on I2Cx->I2C_CR1
		I2Cx->I2C_CR1 = tempREG ;

		/* --------------- I2C_OAR1 & I2C_OAR2 configuration ---------------*/
		tempREG =0;
		if(I2C_INITstruct->Slave_I2C_Address.Enable_Dual_address ==1)
		{
			//Enable Dual Address
			tempREG |= I2C_OAR2_ENDUAL_Msk;
			/*Set Secondary Address*/
			tempREG |= (I2C_INITstruct->Slave_I2C_Address.Secondary_Slave_address << I2C_OAR2_ADD2_Pos);
			I2Cx->I2C_OAR2 = tempREG;
		}
		tempREG = 0;

		tempREG |= (I2C_INITstruct->Slave_I2C_Address.Primary_Slave_address << 1);
		tempREG |= (I2C_INITstruct->Slave_I2C_Address.I2C_Slave_Address_Mode);
		I2Cx->I2C_OAR1 = tempREG;

	}else if(I2C_INITstruct->I2C_Mode == I2C_Mode_SMBUS)
	{
		// SMBUS not supported yet
	}

	// INTERRUPT MODE (salve mode ) // check callback != NULL
	if(I2C_INITstruct->P_Slave_Event_CallBack != NULL)  // that enable salve IRQ State Mode
	{
		// enable IRQ
		I2Cx->I2C_CR2 |= (I2C_CR2_ITEVTEN);
		I2Cx->I2C_CR2 |= (I2C_CR2_ITERREN);
		I2Cx->I2C_CR2 |= (I2C_CR2_ITBUFEN);

		if(I2Cx == I2C1)
		{
			NVIC_IRQ31_I2C1_EV_Enable;
			NVIC_IRQ32_I2C1_ER_Enable;
		}else if(I2Cx == I2C2)
		{
			NVIC_IRQ33_I2C2_EV_Enable;
			NVIC_IRQ34_I2C2_ER_Enable;
		}
		I2Cx->I2C_SR1 =0;
		I2Cx->I2C_SR2 =0;

	}

	// enable selected I2C peripheral
	I2Cx->I2C_CR1 |= I2C_CR1_PE;


}








void MCAL_I2C_DeINIT(I2C_TypeDef* I2Cx  )
{
	if(I2Cx == I2C1)
	{
		NVIC_IRQ31_I2C1_EV_Disable;
		NVIC_IRQ32_I2C1_ER_Disable;
		RCC_I2C1_Rest();
	}else if(I2Cx == I2C2)
	{
		NVIC_IRQ33_I2C2_EV_Disable;
		NVIC_IRQ34_I2C2_ER_Disable;
		RCC_I2C2_Rest();
	}

}

void MCAL_I2C_GPIO_Set_PIN(I2C_TypeDef* I2Cx  )
{
	//	9.1.11 GPIO configurations for device peripherals
	//		Table 27. I2C
	//		I2C pinout 			Configuration 			GPIO configuration
	//		I2Cx_SCL 			I2C clock				Alternate function open drain
	//		I2Cx_SDA 			I2C Data I/O 			Alternate function open drain
	if(I2Cx == I2C1)
	{
		// PB6 : I2C1_SCL
		// PB7 : I2C1_SDA
		GPIO_PinConfig_t I2C_PINCFG;
		// PB6 : I2C1_SCL
		I2C_PINCFG.GPIO_PinNumber = GPIO_PIN_6;
		I2C_PINCFG.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		I2C_PINCFG.GPIO_output_speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &I2C_PINCFG);

		// PB7 : I2C1_SDA
		I2C_PINCFG.GPIO_PinNumber = GPIO_PIN_7;
		I2C_PINCFG.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		I2C_PINCFG.GPIO_output_speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &I2C_PINCFG);

	}else if(I2Cx == I2C2)
	{
		// PB10 : I2C2_SCL
		// PB11 : I2C2_SDA
		GPIO_PinConfig_t I2C_PINCFG;


		// PB10 : I2C2_SCL
		I2C_PINCFG.GPIO_PinNumber = GPIO_PIN_10;
		I2C_PINCFG.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		I2C_PINCFG.GPIO_output_speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &I2C_PINCFG);

		// PB11 : I2C2_SDA
		I2C_PINCFG.GPIO_PinNumber = GPIO_PIN_11;
		I2C_PINCFG.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		I2C_PINCFG.GPIO_output_speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &I2C_PINCFG);

	}

}



void MCAL_I2C_Master_TX(I2C_TypeDef * I2Cx , uint16_t DeviceAddress, uint8_t* dataOut , uint32_t dataLen, Stop_Condition Stop , Repeated_Start start)
{
	int i=0;
	/*
	 * TODO: support Timeout ( configure Timer working for specific duration rise interrupt )
	 * time_interrupt(){flag =1)
	 * so any code exist in while (check flag || any polling condition)
	 * */

	// 1. Set the start bit in I2C_CR1 register to generate start condition
	I2C_GenerateStart(I2Cx , ENABLE , start);

	// 2. wait for EV5
	// EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(! I2C_GetFlagStatus(I2Cx , EV5));

	// 3. send Address
	I2C_SenAddress(I2Cx ,DeviceAddress , I2C_Direction_Transmitter);

	// 4. WAIT for EV6
	// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	while(! I2C_GetFlagStatus(I2Cx , EV6));

	// 5. /* TRA , BUSY , MSL , TXE flag */
	while(! I2C_GetFlagStatus(I2Cx , MASTER_BYTE_TRANSMITTING));

	// 6. send data
	for(i=0;i< dataLen ; i++)
	{
		// write in the DR register data to be transmitted
		I2Cx->I2C_DR = dataOut[i];

		// 7. wait EV8
		// EV8: TxE=1, shift register not empty, d . ata register empty, cleared by writing DR register
		while(!I2C_GetFlagStatus(I2Cx , EV8));
	}

	// 8. wait EV8_2
	// EV8_2: TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition
	// while(!I2C_GetFlagStatus(I2Cx , EV8_2));

	// 9. stop condition
	if(Stop == With_STOP)
	{
		I2C_GenerateStop(I2Cx , ENABLE);
	}else
	{
		I2C_GenerateStop(I2Cx , DISABLE);
	}


}



void MCAL_I2C_Master_RX(I2C_TypeDef * I2Cx , uint16_t DeviceAddress, uint8_t* dataOut , uint32_t dataLen, Stop_Condition Stop , Repeated_Start Rstart)
{
	int i=0;
	uint8_t index = I2Cx == I2C1 ? I2C1_Index : I2C2_Index;

	// 1. Set the start bit in I2C_CR1 register to generate start condition
	I2C_GenerateStart(I2Cx , ENABLE , Rstart);

	// 2. wait for EV5
	// EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(!I2C_GetFlagStatus(I2Cx , EV5));

	// 3. send Address
	I2C_SenAddress(I2Cx ,DeviceAddress , I2C_Direction_Reveive);

	// 4. WAIT for EV6
	// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	while(!I2C_GetFlagStatus(I2Cx , EV6));


	I2C_AcknowledgeConfiguration(I2Cx , ENABLE);

	// 6. send data
	if(dataLen)
	{
		for(i= dataLen ; i>1;i--)
		{
			// 7. wait EV7
			// // EV7: RxNE=1 cleared by reading DR register
			while(!I2C_GetFlagStatus(I2Cx , EV7));

			*dataOut = I2Cx->I2C_DR;
			dataOut++;
		}
		I2C_AcknowledgeConfiguration(I2Cx , DISABLE);
	}

	// 9. stop condition
	if(Stop == With_STOP)
	{
		I2C_GenerateStop(I2Cx , ENABLE);
	}

	// re enable ACK
	if (Global_I2C_Config[index].I2C_ACK_Controller == I2C_Acknowledge_Enable)
	{
		I2C_AcknowledgeConfiguration(I2Cx , ENABLE);
	}
}



void MCAL_I2C_Slave_TX(I2C_TypeDef * I2Cx , uint8_t data)
{
	I2Cx->I2C_DR = data;
}
uint8_t MCAL_I2C_Slave_RX(I2C_TypeDef * I2Cx )
{
	return (uint8_t)(I2Cx->I2C_DR);
}




void I2C_GenerateStart(I2C_TypeDef * I2Cx ,FunctionalState NewSatate , Repeated_Start start)
{
	if(start != repeated_Start)
	{
		// check if the BUS in idle
		while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));
	}

	//	Bit 8 START: Start generation
	//		This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
	//
	//		In Master Mode:
	//				0: No Start generation
	//				1: Repeated start generation
	//		In Slave mode:
	//				0: No Start generation
	//				1: Start generation when the bus is free
	if(NewSatate != DISABLE)
	{
		// generate start condition
		I2Cx->I2C_CR1 |= (I2C_CR1_START);
	}else
	{
		// disable start condition generation
		I2Cx->I2C_CR1 &= ~(I2C_CR1_START);
	}

}


// supported only 7bit address mode
void I2C_SenAddress(I2C_TypeDef * I2Cx ,uint16_t address , I2C_Direction Direction)
{
	address = (address<<1);
	if(Direction != I2C_Direction_Transmitter )
	{
		// set bit 0 for read
		address |= (1<<0);
	}else
	{
		// reset bit 0 for write
		address &= ~(1<<0);
	}
	I2Cx->I2C_DR = address;
}

void I2C_GenerateStop (I2C_TypeDef * I2Cx , FunctionalState NewSatate)
{
	if(NewSatate != DISABLE)
	{
		// generate Stop condition
		I2Cx->I2C_CR1 |= I2C_CR1_STOP;
	}else
	{
		// disable Stop condition generation
		I2Cx->I2C_CR1 &= ~(I2C_CR1_STOP);
	}

}

Flag_Status I2C_GetFlagStatus(I2C_TypeDef * I2Cx ,State flag)
{
	//	volatile uint32_t dummyRead;

	uint32_t flag1 = 0 , flag2 = 0 , lastEvent =0;
	Flag_Status bitStatus = RESET;


	switch(flag)
	{
	case I2C_FLAG_BUSY:
	{
		// Bit 1 BUSY: Bus busy
		//		0: No communication on the bus
		//		1: Communication ongoing on the bus
		//	– Set by hardware on detection of SDA or SCL low
		//	– cleared by hardware on detection of a Stop condition.
		//		It indicates a communication in progress on the bus. This information is still updated when
		//		the interface is disabled (PE=0).
		if((I2Cx->I2C_SR2) & (I2C_SR2_BUSY))
			bitStatus = SET;
		else
			bitStatus = RESET;
		break;
	}


	case EV5:
	{
		//		Bit 0 SB: Start bit (Master mode)
		//			0: No Start condition
		//			1: Start condition generated.
		//		– Set when a Start condition generated.
		//		– Cleared by software by reading the SR1 register followed by writing the DR register, or by
		//		hardware when PE=0
		if( (I2Cx->I2C_SR1) & (I2C_SR1_SB) )
			bitStatus = SET;
		else
			bitStatus = RESET;
		break;
	}
	case EV6:
	{
		//		Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
		//		This bit is cleared by software reading SR1 register followed reading SR2, or by hardware
		//		when PE=0.
		//		Address matched (Slave)
		//				0: Address mismatched or not received.
		//				1: Received address matched.
		if( (I2Cx->I2C_SR1) & (I2C_SR1_ADDR) )
			bitStatus = SET;
		else
			bitStatus = RESET;

		// to clear ADDR field : leared by reading SR1 register followed by reading SR2
		//dummyRead = I2Cx->I2C_SR2;
		break;
	}

	case MASTER_BYTE_TRANSMITTING:
	{
		// red the I2Cx status register
		flag1 = I2Cx->I2C_SR1;
		flag2 = I2Cx->I2C_SR2;
		flag2 = flag2 << 16;
		lastEvent = (flag1 | flag2) & ((uint32_t) 0x00FFFFFF);

		if((lastEvent & flag) == flag)
			bitStatus = SET;
		else
			bitStatus = RESET;

		break;
	}
	case EV8_1: //EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR
	case EV8:
	{
		//EV8: TxE=1, shift register not empty, d . ata register empty, cleared by writing DR register
		//		Bit 7 TxE: Data register empty (transmitters)
		//				0: Data register not empty
		//				1: Data register empty
		//		– Set when DR is empty in transmission. TxE is not set during address phase.
		//		– Cleared by software writing to the DR register or by hardware after a start or a stop condition or when PE=0.
		//		TxE is not set if either a NACK is received, or if next byte to be transmitted is PEC (PEC=1)
		//		Note: TxE is not cleared by writing the first data being transmitted, or by writing data when
		//		BTF is set, as in both cases the data register is still empty.
		if( (I2Cx->I2C_SR1) & (I2C_SR1_TXE) )
			bitStatus = SET;
		else
			bitStatus = RESET;

		break;
	}

	case EV7:
	{
		// EV7: RxNE=1 cleared by reading DR register
		//		Bit 6 RxNE: Data register not empty (receivers)
		//			0: Data register empty
		//			1: Data register not empty
		//		– Set when data register is not empty in receiver mode. RxNE is not set during address phase.
		//		– Cleared by software reading or writing the DR register or by hardware when PE=0.
		//		RxNE is not set in case of ARLO event.
		//		Note: RxNE is not cleared by reading data when BTF is set, as the data register is still full.
		if( (I2Cx->I2C_SR1) & (I2C_SR1_RXNE) )
			bitStatus = SET;
		else
			bitStatus = RESET;

		break;
	}
	}
	return bitStatus;

}

void I2C_AcknowledgeConfiguration(I2C_TypeDef* I2Cx , FunctionalState NewState)
{
	if(NewState != DISABLE)
	{
		I2Cx->I2C_CR1 |= I2C_CR1_ACK;
	}else
	{
		I2Cx->I2C_CR1 &= ~(I2C_CR1_ACK);
	}
}
















/*
 * ===========================================================================================================
 *											ISR
 * ===========================================================================================================
 * */

