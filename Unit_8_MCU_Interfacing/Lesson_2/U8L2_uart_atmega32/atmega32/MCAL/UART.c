/*
 * UART.c
 *
 * Created: 9/11/2023 12:46:31 PM
 *  Author: Mohamed Belal
 */ 
#include "UART.h"

void UART_Init(void)
{
	//Baud Rate(bps) 9600   =>   U2X = 0
	//UBRR => 51
	
	// Baud rate
	UBRRL = 51;
	CLEARBIT(UCSRA , U2X);
	
	//frame
	CLEARBIT(UCSRC,UMSEL); // USART Mode Select  => 0:Asynchronous Operation
	
	CLEARBIT(UCSRC,UPM0); // Parity Mode   => 0 Disabled   00
	CLEARBIT(UCSRC,UPM1); // Parity Mode   => 0 Disabled
	
	// 8bit data is set as default 0 1 1
	SETBIT(UCSRC , UCSZ0);
	SETBIT(UCSRC , UCSZ1);
	CLEARBIT(UCSRB , UCSZ2);
	
	
	//enable
	SETBIT(UCSRB , TXEN);
	SETBIT(UCSRB , RXEN);
}
void UART_Send(uint8 data)
{
	while(!READBIT(UCSRA , UDRE));
	UDR = data;	
}
uint8 UART_Receive(void)
{
		while(!READBIT(UCSRA ,RXC));
		return UDR;
}


void UART_Send_Number(uint32 number)
{
	uint8 *p = &number;
	UART_Send(p[0]);
	UART_Send(p[1]);
	UART_Send(p[2]);
	UART_Send(p[3]);

}


uint32 UART_Receive_Number(void)
{
	uint32 number;
	uint8 *p = &number;
	p[0] = UART_Receive();
	p[1] = UART_Receive();
	p[2] = UART_Receive();
	p[3] = UART_Receive();
	return number;
}


void UART_Send_String(uint8 *string)
{
	while(*string)
	{
		UART_Send(*string);
		string++;
	}
}


uint8 *UART_Receive_String(void)
{
	static uint8 string[50];
	uint8 *p = &string;
	*string = UART_Receive();
	while(*p != '*')
	{
		p++;
		*p = UART_Receive();
	}
	*p = '\0';
	return string;
}