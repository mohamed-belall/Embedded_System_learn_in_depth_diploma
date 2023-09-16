/*
 * keypad_Driver.h
 *
 * Created: 8/29/2023 10:29:40 AM
 *  Author: mohamed belal
 */


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

#include "STM32F103C6_GPIO_Drivers.h"
#include "STM32F103x6.h"

#include <string.h>

#define KEYPAD_PORT     GPIOB

//keypad Information
#define R0				GPIO_PIN_0
#define R1				GPIO_PIN_1
#define R2				GPIO_PIN_10
#define R3				GPIO_PIN_11
#define C0				GPIO_PIN_15
#define C1				GPIO_PIN_14
#define C2				GPIO_PIN_13
#define C3              GPIO_PIN_12




//keypad functions and global ariable

void keypad_Init();
char keypad_GetKey();



#endif /* KEYPAD_DRIVER_H_ */
