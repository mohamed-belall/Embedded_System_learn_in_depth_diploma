/*
 * I2C.c
 *
 * Created: 9/22/2023 5:25:56 PM
 *  Author: Mohamed Belal
 */ 

#include "I2C.h"
#define prescaler 1  // 1	4	16	64
void I2C_Init(unsigned long SCL_Clock)
{
	TWBR = (unsigned char) (((F_CPU/SCL_Clock)-16)/(2*prescaler));
	if (prescaler == 0)
		TWSR =0;
	else if(prescaler == 4)
		TWSR = 1;
	else if(prescaler == 16)
		TWSR = 2;
	else if(prescaler == 64)
		TWSR = 3;
 
	
}


void I2C_Start(void)
{

	TWCR = (1<<TWINT) |   (1<<TWEN) | (1<<TWSTA);
	while(!(TWCR & (1<<7)) );
	while((TWSR) != 0x08);
	
}
void I2C_Write(unsigned char dByte)
{

	TWDR = dByte;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & 0x80));
	
}
void I2C_Stop(void)
{
	/*Transmit STOP condition*/
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
}


unsigned char I2C_Read(unsigned char ack)
{

	TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	
	while(!(TWCR & 0x80)) ;	
	return TWDR;
	
	
}