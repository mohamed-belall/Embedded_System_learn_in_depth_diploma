/*
 * STM32F103C6_GPIO_Driver.c
 *
 *  Created on: Aug 30, 2023
 *      Author: Mohamed Belal
 */

#include "STM32F103C6_GPIO_Drivers.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;

	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}

/*
 * ===================================
 * @FN				-MCAL_GPIO_Init
 * @brief			-Initialize GPIOx PINy according to the specified parameter in the PinConfig
 * @param [in]		-GPIOx: where x can be (A,B,C,D,E depending on device used) to select the GPIO peripheral
 * @param [in]		-PinConfig: pointer to a GPIO_PinConfig_t structure that contains
 * 					 the configuration information for the specified GPIO PIN
 * @retval			-none
 * @Note			-STM32F103C6 MCU has GPIO A,B,C,D,E modules
 * 					 but LQFP48 package has only GPIO A,B,part of (C,D) exported as external PINS from the MCU
 * ===================================
 * */
void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx , GPIO_PinConfig_t* PinConfig)
{
	// port configuration register low (GPIOx_CRL) configure pin from 0 => 7
	// port configuration register high (GPIOx_CRH) configure pin from 8 => 15
	volatile uint32_t*  configRegister = NULL;
	uint8_t PIN_Config =0;

	configRegister = (PinConfig->GPIO_PinNumber < 8) ? &GPIOx->CRL  :  &GPIOx->CRH;

	//clear CNF0[1:0] MODE0[1:0]
	(*configRegister) &= ~(0xf << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	// if pin is output
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) )
	{
		//SET CNF0[1:0] MODE0[1:0]
		PIN_Config = ( (((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_output_speed)) & 0x0F );
	}
	// if pin is input
	else //  00: Input mode (reset state)
	{
		if((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLOATING) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog))
		{
			//SET CNF0[1:0] MODE0[1:0] = 00
			PIN_Config =( ((PinConfig->GPIO_MODE) << 2) & 0x0F);
		}else if((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_AF)) // Consider it as input floating
		{
			//SET CNF0[1:0] MODE0[1:0] = 00
			PIN_Config =( ((GPIO_MODE_INPUT_FLOATING) << 2) & 0x0F);
		}else // PU PD
		{
			PIN_Config =( ((GPIO_MODE_INPUT_PU) << 2) & 0x0F);
			if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU) // pull up
			{
				//Table 20. Port bit configuration table PxODR 1 => input pull up
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}else // pull down
			{
				//Table 20. Port bit configuration table PxODR 0 => input pull down
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}

	}
	// write on CRL OR CRH
	(*configRegister) |= (PIN_Config << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
}




/*
 * ===================================
 * @FN				-MCAL_GPIO_DeInit
 * @brief			-Reset all the GPIOx registers
 * @param [in]		-GPIOx: where x can be ( A,B,C,D,E depending on device used) to select the GPIO peripheral
 * @retval			-none
 * @Note			-none
 * ===================================
 * */
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx)
{
	/*
	GPIOx->BRR  = 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->CRH  = 0x44444444;
	GPIOx->CRL  = 0x44444444;
	//GPIOx->IDR = ;  (read only)
	GPIOx->LCKR = 0x00000000;
	GPIOx->ODR  = 0x00000000;*/

	//or you can use the reset controller
	// APB2 peripheral reset register (RCC_APB2RSTR)
	// SET AND clear by software
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |=  (1<<2); //BIT 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);
	}else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |=  (1<<3); //BIT 3 IOPARST: IO port B reset
		RCC->APB2RSTR &= ~(1<<3);
	}else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |=  (1<<4); //BIT 4 IOPARST: IO port C reset
		RCC->APB2RSTR &= ~(1<<4);
	}else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |=  (1<<5); //BIT 5 IOPARST: IO port D reset
		RCC->APB2RSTR &= ~(1<<5);
	}else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |=  (1<<6); //BIT 6 IOPARST: IO port E reset
		RCC->APB2RSTR &= ~(1<<6);
	}
}




/*
 * ===================================
 * @FN				-MCAL_GPIO_ReadPin
 * @brief			-read specific pin
 * @param [in]		-GPIOx: where x can be ( A,B,C,D,E depending on device used) to select the GPIO peripheral
 * @param [in]		-PinNumber: Set PIN Number according to @ref GPIO_PINS_DEFINE
 * @retval			-the input pin value (two values based on @ref GPIO_PIN_state
 * @Note			-none
 * ===================================
 * */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber)
{
	uint8_t bitStatus;
	if(((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		bitStatus = GPIO_PIN_SET;
	}else
	{
		bitStatus = GPIO_PIN_RESET;
	}
	return bitStatus;
}





/*
 * ===================================
 * @FN				-MCAL_GPIO_ReadPort
 * @brief			-read INPUT PORT value
 * @param [in]		-GPIOx: where x can be ( A,B,C,D,E depending on device used) to select the GPIO peripheral
 * @retval			-the input port value
 * @Note			-none
 * ===================================
 * */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx)
{
	uint16_t port_value;
	port_value = (uint16_t)(GPIOx->IDR);
	return port_value;
}



/*
 * ===================================
 * @FN				-MCAL_GPIO_WritePin
 * @brief			-write on a specific pin
 * @param [in]		-GPIOx: where x can be ( A,B,C,D,E depending on device used) to select the GPIO peripheral
 * @param [in]		-PinNumber: Set PIN Number according to @ref GPIO_PINS_DEFINE
 * @param [in]		-value: PIN value
 * @retval			-none
 * @Note			-none
 * ===================================
 * */
void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber , uint8_t value)
{
	if(value != GPIO_PIN_RESET)
	{
		//GPIOx->ODR |= PinNumber;
		// OR
		//		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Set the corresponding ODRx bit
		GPIOx->BSRR = (uint32_t)PinNumber;
	}else
	{
		//		Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Reset the corresponding ODRx bit
		GPIOx->BRR = (uint32_t)PinNumber;

	}

}







/*
 * ===================================
 * @FN				-MCAL_GPIO_WritePort
 * @brief			-write on output port
 * @param [in]		-GPIOx: where x can be ( A,B,C,D,E depending on device used) to select the GPIO peripheral
 * @param [in]		-value: port value
 * @retval			-none
 * @Note			-none
 * ===================================
 * */
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx,uint16_t value)
{
	GPIOx->ODR = (uint32_t)value;
}





/*
 * ===================================
 * @FN				-MCAL_GPIO_TogglePin
 * @brief			-toggle the specific GPIO pin
 * @param [in]		-GPIOx: where x can be ( A,B,C,D,E depending on device used) to select the GPIO peripheral
 * @param [in]		-PinNumber: Set PIN Number according to @ref GPIO_PINS_DEFINE
 * @retval			-none
 * @Note			-none
 * ===================================
 * */
void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= (PinNumber);
}






/*
 * ===================================
 * @FN				-MCAL_GPIO_LockPin
 * @brief			-the locking mechanism allow the IO configuration to be frozen
 * @param [in]		-GPIOx: where x can be ( A,B,C,D,E depending on device used) to select the GPIO peripheral
 * @param [in]		-PinNumber: Set PIN Number according to @ref GPIO_PINS_DEFINE
 * @retval			-ok if pin config is locked or ERROR if pin not locked (OK & ERROR are defined @ref GPIO_RETURN_LOCK)
 * @Note			-none
 * ===================================
 * */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.
	//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked

	//set LCKK[16]
	volatile uint32_t temp = 1<<16;
	//set LCKy
	temp |= PinNumber;

	//	LOCK key writing sequence:
	//	Write 1
	GPIOx->LCKR = temp;
	//	Write 0
	GPIOx->LCKR = PinNumber;
	//	Write 1
	GPIOx->LCKR = temp;
	//	Read 0
	temp = GPIOx->LCKR;
	//	Read 1 (this read is optional but confirms that the lock is active)
	if((uint32_t)(GPIOx->LCKR &(1<<16)))
	{
		return GPIO_RETURN_LOCK_ENABLE;
	}else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}
}
