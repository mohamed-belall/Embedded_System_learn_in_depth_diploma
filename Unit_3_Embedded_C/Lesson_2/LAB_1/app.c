/*
 *  Author : mohamed belal
 *  Date   : Apr 26, 2023
 */

#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth:MohamedBelal";
unsigned char const string_buffer2[100] = "learn-in-depth:MohamedBelal";
void main()
{
	Uart_Send_String(string_buffer);    /*	string_buffer == &string_buffer[0]	*/
}