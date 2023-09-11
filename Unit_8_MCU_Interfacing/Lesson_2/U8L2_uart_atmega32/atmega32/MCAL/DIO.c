/*
 * DIO.c
 *
 * Created: 9/4/2023 7:16:39 PM
 *  Author: Mohamed Belal
 */ 

#include "./../utils/atmega32_memoryMap.h"

void Pin_Direction(uint8_t base  , uint8_t bin , uint8_t status)
{
	if(status == output)
	{
		base |= (1<<bin);
	}else
	{	
		base &= ~(1<<bin);
	}
}
void Port_Direction(uint8_t base  , uint8_t status)
{
	if(status == output)
	{
		base = 0xFF;
	}else
	{	
		base = 0x00;
	}
}
