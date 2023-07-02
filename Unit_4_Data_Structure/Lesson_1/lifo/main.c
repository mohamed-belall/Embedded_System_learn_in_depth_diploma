
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mohamed belal
 * @Created on     : Jun 24, 2023
 ******************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

unsigned int buffer1[5];  // 5*4 = 20 bytes

int main()
{
	int i ;
	unsigned int temp =0;
	LIFO_Buf_t uart_lifo , i2c_lifo;
	LIFO_Init(&uart_lifo, buffer1, 5);
	unsigned int* buffer2 = (unsigned int*)malloc(5 *sizeof(unsigned int));
	LIFO_Init(&i2c_lifo, buffer2,5);

	for(i=0 ; i<5 ; i++)
	{
		if(LIFO_Add_Item(&uart_lifo, i) == LIFO_NO_error)
			printf("UART_LIFO add : %d \n" , i);
	}

	for(i=0 ; i<5 ; i++)
	{
		if(LIFO_pop_top(&uart_lifo, &temp) == LIFO_NO_error)
			printf("UART_LIFO get : %d \n" , temp);
	}


return 0;
}
