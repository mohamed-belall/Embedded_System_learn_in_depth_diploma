/*
 * U8L6_lab1_Slave.c
 *
 * Created: 9/22/2023 5:25:11 PM
 * Author : Mohamed Belal
 */ 

#include <avr/io.h>
#include "I2C.h"

int main(void)
{
    unsigned char ch =0;
	I2C_Set_Address(0b11010000);
    while (1) 
    {
		I2C_Read(1); /* read byte send ACK */
		I2C_Write(ch++);
    }
	return 0;
}

