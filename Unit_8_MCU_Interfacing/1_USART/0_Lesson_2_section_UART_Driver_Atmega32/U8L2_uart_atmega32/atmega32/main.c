/*
 * atmega32.c
 *
 * Created: 9/11/2023 12:36:33 PM
 * Author : Mohamed Belal
 */ 


#include "utils/atmega32_memoryMap.h"
#include "HAL/lcd_driver.h"
#include "MCAL/UART.h"

int main(void)
{
	uint8 *arr;
	LCD_Init();
	
	UART_Init();
	LCD_Send_String("UART is ready");

	UART_Send_String("welcome to UART ( enter * to send string to lcd ) => ");
	LCD_gotoXY(2,0);
    while (1) 
    {
			
			arr = UART_Receive_String();
			LCD_Send_String(arr);
    }
}

