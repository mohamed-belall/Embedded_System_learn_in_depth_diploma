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

	GPIO_PinConfig_t PinCfg;

	PinCfg.GPIO_PinNumber = R0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);



	MCAL_GPIO_WritePin(KEYPAD_PORT, R0, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(KEYPAD_PORT, R1, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(KEYPAD_PORT, R2, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(KEYPAD_PORT, R3, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(KEYPAD_PORT, C0, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(KEYPAD_PORT, C1, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(KEYPAD_PORT, C2, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(KEYPAD_PORT, C3, GPIO_PIN_SET);

}

char keypad_GetKey()
{
	int i,j;

	for(i = 0; i < 4 ; i++)
	{

		MCAL_GPIO_WritePin(KEYPAD_PORT, C0, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C1, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C2, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C3, GPIO_PIN_SET);

		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_Column[i], GPIO_PIN_RESET);
		for(j=0;j<4 ; j++)
		{

			if(MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_Row[j] ) == 0) // check if key is pressed
			{
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_Row[j] ) == 0); // wait for  single press
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
