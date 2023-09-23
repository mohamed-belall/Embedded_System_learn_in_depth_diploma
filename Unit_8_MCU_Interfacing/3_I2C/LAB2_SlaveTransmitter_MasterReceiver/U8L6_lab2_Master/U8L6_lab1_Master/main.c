/*
 * U8L6_lab1_Master.c
 *
 * Created: 9/22/2023 5:24:15 PM
 * Author : Mohamed Belal
 */ 

#include <avr/io.h>
#include "I2C.h"


int main(void)
{
    unsigned char ch=0;
	DDRA = 0xFF;
	I2C_Init(0x48);
    while (1) 
    {
		_delay_ms(300);
		I2C_Start();				/* Transmit Start condition */
		I2C_Write(0b11010000+1);    /* transmit salve address + READ(1)*/
		ch = I2C_Read(0);		/* read last byte sen NACK*/
		I2C_Stop();					/* Transmit Stop condition */
		PORTA = ch;
    }
	return 0;
}

