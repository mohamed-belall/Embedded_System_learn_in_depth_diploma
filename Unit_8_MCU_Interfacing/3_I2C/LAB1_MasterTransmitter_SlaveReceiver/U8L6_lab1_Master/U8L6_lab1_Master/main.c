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
	I2C_Init(0x48);
    while (1) 
    {
		_delay_ms(500);
		I2C_Start();				/* Transmit Start condition */
		I2C_Write(0b11010000+0);    /* transmit salve address + Write(0)*/
		while((TWSR) != 0x18);		/* SLA+W has been transmitted,and ACK/NACK has been received*/
		I2C_Write(ch++);			/* Transmit Data */
		while((TWSR) != 0x28);		/* DATA has been transmitted, and ACK/NACK has been received*/
		I2C_Stop();					/* Transmit Stop condition */
    }
}

