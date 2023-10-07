/*
 * STM32F103C6_GPIO_Drivers.h
 *
 *  Created on: Aug 30, 2023
 *      Author: moham
 */

#ifndef INC_STM32F103C6_GPIO_DRIVERS_H_
#define INC_STM32F103C6_GPIO_DRIVERS_H_

//-------------------------------------
//Includes
//-------------------------------------
#include "STM32F103x6.h"



//-------------------------------------
//User Type Definition (Structures)
//-------------------------------------

typedef struct{
	/* ==== GPIO_PinNumber ====
	 * Specifies the GPIO pins to be configured
	 * this parameter must be set base on @ref GPIO_PINS_DEFINE
	 * */
	uint16_t GPIO_PinNumber;

	/* ==== GPIO_MODE ====
	 * Specifies the GPIO operating mode for the selected pins
	 * this parameter must be set base on @ref GPIO_MODE_DEFINE
	 * */
	uint8_t  GPIO_MODE;

	/* ==== GPIO_output_speed ====
	 * Specifies the speed for the selected pins
	 * this parameter must be set base on @ref GPIO_SPEED_DEFINE
	 * */
	uint8_t  GPIO_output_speed;

}GPIO_PinConfig_t;








//-------------------------------------
//Macros Configuration References
//-------------------------------------


// @ref GPIO_PINS_DEFINE
#define GPIO_PIN_0		(uint16_t)0x0001  // pin 0  selected 1
#define GPIO_PIN_1		(uint16_t)0x0002  // pin 1  selected 10
#define GPIO_PIN_2		(uint16_t)0x0004  // pin 2  selected 100
#define GPIO_PIN_3		(uint16_t)0x0008  // pin 3  selected 1000
#define GPIO_PIN_4		(uint16_t)0x0010  // pin 4  selected 10000
#define GPIO_PIN_5		(uint16_t)0x0020  // pin 5  selected 100000
#define GPIO_PIN_6		(uint16_t)0x0040  // pin 6  selected 1000000
#define GPIO_PIN_7		(uint16_t)0x0080  // pin 7  selected 10000000
#define GPIO_PIN_8		(uint16_t)0x0100  // pin 8  selected 100000000
#define GPIO_PIN_9		(uint16_t)0x0200  // pin 9  selected 1000000000
#define GPIO_PIN_10		(uint16_t)0x0400  // pin 10 selected 10000000000
#define GPIO_PIN_11		(uint16_t)0x0800  // pin 11 selected 100000000000
#define GPIO_PIN_12		(uint16_t)0x1000  // pin 12 selected 1000000000000
#define GPIO_PIN_13		(uint16_t)0x2000  // pin 13 selected 10000000000000
#define GPIO_PIN_14		(uint16_t)0x4000  // pin 14 selected 100000000000000
#define GPIO_PIN_15		(uint16_t)0x8000  // pin 15 selected 1000000000000000

#define GPIO_PIN_ALL	((uint16_t)0xFFFF)  // pin ALL selected 11111111111111111

#define GPIO_PIN_MASK	0x0000FFFFu 		// pin mask for assert test



//@ref GPIO_PINS_DEFINE
//In input mode (MODE[1:0]=00):
//00: Analog mode
//01: Floating input (reset state)
//10: Input with pull-up / pull-down
//11: Reserved
//In output mode (MODE[1:0] > 00):
//00: General purpose output push-pull
//01: General purpose output Open-drain
//10: Alternate function output Push-pull
//11: Alternate function output Open-drain
#define GPIO_MODE_Analog				0x00000000u //Analog mode
#define GPIO_MODE_INPUT_FLOATING		0x00000001u //Floating input
#define GPIO_MODE_INPUT_PU				0x00000002u //Input with pull-up
#define GPIO_MODE_INPUT_PD				0x00000003u //Input with pull-down
#define GPIO_MODE_OUTPUT_PP				0x00000004u //General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD				0x00000005u //General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP			0x00000006u //Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD			0x00000007u //Alternate function output Open-drain
#define GPIO_MODE_INPUT_AF				0x00000008u //Alternate function INPUT


//@ref GPIO_SPEED_DEFINE
//01: Output mode, max speed 10 MHz.
//10: Output mode, max speed 2 MHz.
//11: Output mode, max speed 50 MHz.
#define GPIO_SPEED_10M					0x00000001u //Output mode, max speed 10 MHz.
#define GPIO_SPEED_2M					0x00000002u //Output mode, max speed 2 MHz.
#define GPIO_SPEED_50M					0x00000003u //Output mode, max speed 50 MHz.


//@ref GPIO_PIN_state
#define GPIO_PIN_SET			1
#define GPIO_PIN_RESET			0


//@ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_ENABLE 1
#define GPIO_RETURN_LOCK_ERROR  0


/*
 * ===================================
 * APIs supported by "MCAL GPIO driver"
 * ===================================
 * */

void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx , GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx);


uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx);


void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber , uint8_t value);
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx,uint16_t value);


void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx,uint16_t PinNumber);



uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx,uint16_t PinNumber);


#endif /* INC_STM32F103C6_GPIO_DRIVERS_H_ */
