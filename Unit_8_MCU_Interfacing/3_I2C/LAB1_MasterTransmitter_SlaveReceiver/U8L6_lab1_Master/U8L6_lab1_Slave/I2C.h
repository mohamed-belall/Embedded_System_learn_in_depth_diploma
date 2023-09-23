/*
 * I2C.h
 *
 * Created: 9/22/2023 5:26:18 PM
 *  Author: Mohamed Belal
 */ 


#ifndef I2C_H_
#define I2C_H_

#undef  F_CPU
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>


void I2C_Set_Address(unsigned char address);
unsigned char I2C_Read(unsigned char ack);




#endif /* I2C_H_ */