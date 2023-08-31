/*
 * keypad_Driver.h
 *
 * Created: 8/29/2023 10:29:40 AM
 *  Author: mohamed belal
 */ 


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

//keypad Information
#define R0				0
#define R1				1
#define R2				2
#define R3				3
#define C0				4
#define C1				5
#define C2				6
#define C3              7

#define KEYPAD_PORT     PORTD
#define KEYPAD_PIN      PIND
#define KEYPAD_DDR      DDRD 

//keypad functions and global ariable

void keypad_Init();
char keypad_GetKey();

#endif /* KEYPAD_DRIVER_H_ */