/*
 * keypad_Driver.c
 *
 * Created: 8/29/2023 10:29:29 AM
 *  Author: Mohamed Belal
 */ 
#include "keypad_Driver.h"

int keypad_Row[]	={R0,R1,R2,R3};
int keypad_Column[] ={C0,C1,C2,C3};
	
	
void keypad_Init()
{
	KEYPAD_DDR &= ~((1<<R0) | (1<<R1) |(1<<R2) | (1<<R3)); // set row as input
	KEYPAD_DDR |=  ((1<<C0) | (1<<C1) |(1<<C2) | (1<<C3)); // set column as output
	
	KEYPAD_PORT = 0xFF;
}

char keypad_GetKey()
{
	int i,j;
	
	for(i = 0; i < 4 ; i++)
	{
		KEYPAD_PORT |= ((1<<keypad_Column[0]) | (1<<keypad_Column[1]) | (1<<keypad_Column[2]) | (1<<keypad_Column[3]));
		KEYPAD_PORT &= ~(1<<keypad_Column[i]); //send low to a particular row of the keypad
		for(j=0;j<4 ; j++)
		{
			if(!(KEYPAD_PIN & (1<<keypad_Row[j]))) // check if key is pressed
			{
				while(!(KEYPAD_PIN & (1<<keypad_Row[j]))); // wait for  single press
				switch (i)
				{
					case(0):
						if(j == 0) return '7';
						else if(j == 1) return '4';
						else if(j == 2) return '1';
						else if(j == 3) return '?';
						break;
					case(1):
						if(j == 0) return '8';
						else if(j == 1) return '5';
						else if(j == 2) return '2';
						else if(j == 3) return '0';
						break;
					case(2):
						if(j == 0) return '9';
						else if(j == 1) return '6';
						else if(j == 2) return '3';
						else if(j == 3) return '=';
						break;
					case(3):
						if(j == 0) return '/';
						else if(j == 1) return '*';
						else if(j == 2) return '-';
						else if(j == 3) return '+';
						break;
						
				}
			}
		}
	}
	return 'A'; // return A if no key is pressed
}