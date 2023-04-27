
/*
 *  Author : mohamed belal
 *  Date   : Apr 26, 2023
 */

#include "uart.h"
#define UART0DR   *((volatile unsigned int* const)((unsigned int*)0x101f1000))


void Uart_Send_String(unsigned char* p_tx_String)
{
	while(*p_tx_String != '\0')   /* loop until end of string*/ 
	{
		UART0DR = (unsigned int)(*p_tx_String);  /*transmit char by char from sended string to UART0*/
		p_tx_String++;  /*	 inc prt to sent another char 	*/
	}
}