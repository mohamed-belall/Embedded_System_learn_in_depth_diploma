/*
 * STM32F103C6_EXTI_Driver.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Mohamed Belal
 */




#include "STM32F103C6_EXTI_Driver.h"





/*
 * ===========================================================================================================
 * Generic variables
 * ===========================================================================================================
 * */
void (* GP_IRQ_CallBack[15])(void);





/*
 * ===========================================================================================================
 * Generic Macros
 * ===========================================================================================================
 * */

#define AFIO_GPIO_EXTI_Mapping(x)	((x == GPIOA)?0:\
		(x == GPIOB)?1:\
				(x == GPIOC)?2:\
						(x == GPIOD)?3:0 )


/*
 * ===========================================================================================================
 * Generic Function
 * ===========================================================================================================
 * */
void Enable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;


	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;
	}
}



void Disable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Disable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Disable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;


	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;
	}
}



void update_EXTI(EXTI_PinConfig_t *EXTI_config)
{
	// 1. Configure GPIO to be AF input => Floating input
	GPIO_PinConfig_t pincfg;
	//update the gpio pins to be input floating
	pincfg.GPIO_PinNumber = EXTI_config->EXTI_PINS.EXTI_GPIO_PIN;
	pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(EXTI_config->EXTI_PINS.EXTI_GPIO_Port, &pincfg);
	// ===========================================================




	// 2.update AFIO to route between EXTI line with PORT A,B,C,D
	uint8_t AFIO_EXTICR_index = EXTI_config->EXTI_PINS.EXTI_Input_Line_Number /4;
	uint8_t AFIO_EXTICR_Position = (EXTI_config->EXTI_PINS.EXTI_Input_Line_Number % 4) * 4;

	//clear the four bit
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_config->EXTI_PINS.EXTI_GPIO_Port) & 0xF) << AFIO_EXTICR_Position);

	// ===========================================================





	// 3. update Rising edge or falling edge or both

	EXTI->RTSR &= ~(1 << EXTI_config->EXTI_PINS.EXTI_Input_Line_Number);
	EXTI->FTSR &= ~(1 << EXTI_config->EXTI_PINS.EXTI_Input_Line_Number);

	if(EXTI_config->Trigger_Case == EXTI_Trigger_Rising)
	{
		EXTI->RTSR |= (1<<EXTI_config->EXTI_PINS.EXTI_Input_Line_Number);
	}else if(EXTI_config->Trigger_Case == EXTI_Trigger_Falling)
	{
		EXTI->FTSR |= (1<<EXTI_config->EXTI_PINS.EXTI_Input_Line_Number);
	}else if(EXTI_config->Trigger_Case == EXTI_Trigger_RisingAndFalling)
	{
		EXTI->RTSR |= (1<<EXTI_config->EXTI_PINS.EXTI_Input_Line_Number);
		EXTI->FTSR |= (1<<EXTI_config->EXTI_PINS.EXTI_Input_Line_Number);
	}
	// ===========================================================





	// 4. update IRQ Handling callback
	GP_IRQ_CallBack[EXTI_config->EXTI_PINS.EXTI_Input_Line_Number] = EXTI_config->P_IRQ_CallBack;
	// ===========================================================





	// 5. Enable/Disable IRQ
	if(EXTI_config->IRQ_EN == EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1<<EXTI_config->EXTI_PINS.EXTI_Input_Line_Number);
		Enable_NVIC(EXTI_config->EXTI_PINS.EXTI_Input_Line_Number);
	}else
	{
		EXTI->IMR &= ~(1<<EXTI_config->EXTI_PINS.EXTI_Input_Line_Number);
		Disable_NVIC(EXTI_config->EXTI_PINS.EXTI_Input_Line_Number);
	}
	// ===========================================================



}













/*
 * ===========================================================================================================
 * APIs function Definitions
 * ===========================================================================================================
 * */


/*
 * ===================================
 * @FN				-MCAL_EXTI_GPIO_Init
 * @brief			-this is used to inialize EXTI from specific GPIO PIN and specify the MASK/trigger condition and IRQ callback
 * @param [in]		-EXTI_cfg det by @ref EXTI_define , EXTI_Trigger_define , EXTI_IRQ_define
 * @retval			-none
 * @Note			-stm32f103c6 mcu has a GPIO A,B,C,D,E modules
 * 					 but LQFP48 package has only GPIO a,b,part of C,D exported as external pins
 * 					 also mandatory to Enable RCC clock for AFIO and the corresponding GPIO
 * ===================================
 * */

void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_cfg)
{
	update_EXTI(EXTI_cfg);
}







/*
 * ===================================
 * @FN				-MCAL_EXTI_GPIO_DeInit
 * @brief			-DeIntialized external interrupt and NVIC
 * @param [in]		-none
 * @retval			-none
 * @Note			-none
 * ===================================
 * */
void MCAL_EXTI_GPIO_DeInit()
{
	EXTI->IMR   = 0x00000000;
	EXTI->EMR   = 0x00000000;
	EXTI->RTSR  = 0x00000000;
	EXTI->FTSR  = 0x00000000;
	EXTI->SWIER = 0x00000000;
	//rc_w1 cleared by writing a "1"  into the PR
	EXTI->PR    = 0xFFFFFFFF;


	// disable the EXTI IRQ from NVIC
	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;

}





/*
 * ===================================
 * @FN				-MCAL_EXTI_GPIO_Update
 * @brief			-this is used to inialize EXTI from specific GPIO PIN and specify the MASK/trigger condition and IRQ callback
 * @param [in]		-EXTI_cfg det by @ref EXTI_define , EXTI_Trigger_define , EXTI_IRQ_define
 * @retval			-none
 * @Note			-stm32f103c6 mcu has a GPIO A,B,C,D,E modules
 * 					 but LQFP48 package has only GPIO a,b,part of C,D exported as external pins
 * 					 also mandatory to Enable RCC clock for AFIO and the corresponding GPIO
 * ===================================
 * */
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_cfg)
{
	update_EXTI(EXTI_cfg);

}




/*
 * =========================================================================
 * =========================================================================
 * ======================        ISR Function        =======================
 * =========================================================================
 * =========================================================================
 */
void EXTI0_IRQHandler(void)
{
	//clear by writing "1" into the bit Pending register (EXTI_PR)
	EXTI->PR |= (1<<0);
	//CALL IRQ_CALLback
	GP_IRQ_CallBack[0]();

}

void EXTI1_IRQHandler(void)
{
	//clear by writing "1" into the bit Pending register (EXTI_PR)
	EXTI->PR |= (1<<1);
	//CALL IRQ_CALLback
	GP_IRQ_CallBack[1]();
}
void EXTI2_IRQHandler(void)
{
	//clear by writing "1" into the bit Pending register (EXTI_PR)
	EXTI->PR |= (1<<2);
	//CALL IRQ_CALLback
	GP_IRQ_CallBack[2]();

}
void EXTI3_IRQHandler(void)
{
	//clear by writing "1" into the bit Pending register (EXTI_PR)
	EXTI->PR |= (1<<3);
	//CALL IRQ_CALLback
	GP_IRQ_CallBack[3]();

}
void EXTI4_IRQHandler(void)
{
	//clear by writing "1" into the bit Pending register (EXTI_PR)
	EXTI->PR |= (1<<4);
	//CALL IRQ_CALLback
	GP_IRQ_CallBack[4]();

}
void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & (1<<5)) { EXTI->PR |= (1<<5) ;          GP_IRQ_CallBack[5](); }
	if(EXTI->PR & (1<<6)) { EXTI->PR |= (1<<6) ;          GP_IRQ_CallBack[6](); }
	if(EXTI->PR & (1<<7)) { EXTI->PR |= (1<<7) ;          GP_IRQ_CallBack[7](); }
	if(EXTI->PR & (1<<8)) { EXTI->PR |= (1<<8) ;          GP_IRQ_CallBack[8](); }
	if(EXTI->PR & (1<<9)) { EXTI->PR |= (1<<9) ;          GP_IRQ_CallBack[9](); }
}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & (1<<10)) { EXTI->PR |= (1<<10) ;          GP_IRQ_CallBack[10](); }
	if(EXTI->PR & (1<<11)) { EXTI->PR |= (1<<11) ;          GP_IRQ_CallBack[11](); }
	if(EXTI->PR & (1<<12)) { EXTI->PR |= (1<<12) ;          GP_IRQ_CallBack[12](); }
	if(EXTI->PR & (1<<13)) { EXTI->PR |= (1<<13) ;          GP_IRQ_CallBack[13](); }
	if(EXTI->PR & (1<<14)) { EXTI->PR |= (1<<14) ;          GP_IRQ_CallBack[14](); }
	if(EXTI->PR & (1<<15)) { EXTI->PR |= (1<<15) ;          GP_IRQ_CallBack[15](); }

}

















