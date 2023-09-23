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
	
	unsigned char x=0;

	TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	while(!(TWCR & (1<<7)));
	while((TWSR) != 0x60)  x=TWSR;
	
	
	TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	while(!(TWCR & (1<<7)));
	while((TWSR) != 0x80)  x=TWSR;
	
	return TWDR;
	
	
}