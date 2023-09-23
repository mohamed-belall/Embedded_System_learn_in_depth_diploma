/*
 * I2C.c
 *
 * Created: 9/22/2023 5:25:56 PM
 *  Author: Mohamed Belal
 */ 
#include "I2C.h"


void I2C_Set_Address(unsigned char address)
{
	TWAR =address;
	
}
unsigned char I2C_Read(unsigned char ack)
{
	
	
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & 0x80) == 0);
	
	
	
}

void I2C_Write(unsigned char dByte)
{

	TWDR = dByte;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & 0x80));
	
}