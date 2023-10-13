/*
 * STM32F103C6_RCC_Drivers.h
 *
 *  Created on: Sep 15, 2023
 *      Author: Mohamed Belal
 */

#ifndef INC_STM32F103C6_RCC_DRIVERS_H_
#define INC_STM32F103C6_RCC_DRIVERS_H_

//-------------------------------------
//Includes
//-------------------------------------
#include "STM32F103x6.h"


#define HSE_Clock			(uint32_t)16000000
#define HSI_RC_Clock		(uint32_t)8000000


uint32_t MCAL_RCC_GetSYS_ClockFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);






#endif /* INC_STM32F103C6_RCC_DRIVERS_H_ */
