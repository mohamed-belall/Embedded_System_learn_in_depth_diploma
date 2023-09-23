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
    DDRA = 0xFF;
	I2C_Set_Address(0b11010000);
    while (1) 
    {
		PORTA = I2C_Read(1);
    }
	return 0;
}

