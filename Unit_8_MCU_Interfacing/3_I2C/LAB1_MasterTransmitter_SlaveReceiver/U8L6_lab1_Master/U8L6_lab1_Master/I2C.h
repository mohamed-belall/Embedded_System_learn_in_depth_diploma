/*
 * I2C.h
 *
 * Created: 9/22/2023 5:26:18 PM
 *  Author: Mohamed Belal
 */ 


#ifndef I2C_H_
#define I2C_H_

#undef  F_CPU
#define F_CPU 8000000UL/*16 MegaHz(16 Million)*/
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

void I2C_Init(unsigned long SCL_Clock);
void I2C_Start(void);
void I2C_Write(unsigned char dByte);
void I2C_Stop(void);


#endif /* I2C_H_ */