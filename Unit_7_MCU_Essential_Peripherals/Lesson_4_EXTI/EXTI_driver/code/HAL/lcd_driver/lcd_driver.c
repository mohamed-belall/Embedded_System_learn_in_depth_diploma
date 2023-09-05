/*
 * lcd_driver.c
 *
 * Created: 8/28/2023 4:39:26 PM
 *  Author: Mohamed Belal
 */ 

#include "lcd_driver.h"



void delay_ms(uint32_t time)
{
	uint32_t i,j;
	for(i=0 ; i < time ; i++)
		for(j=0 ; j<255 ; j++);
}

void LCD_Init()
{
	GPIO_PinConfig_t PinCfg;
	delay_ms(20);


	PinCfg.GPIO_PinNumber = EN_switch ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = RW_switch;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = RS_switch;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinCfg);


	// data pins output

	PinCfg.GPIO_PinNumber = D0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, EN_switch, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RS_switch, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW_switch, GPIO_PIN_RESET);

	delay_ms(15);
	LCD_Clear_Screen();

#ifdef EIGHT_BIT_MODE
	LCD_Send_Command(LCD_FUNCTION_8BIT_2LINES);
#endif

#ifdef FOUR_BIT_MODE
	LCD_Send_Command(0x02);
	LCD_Send_Command(LCD_FUNCTION_4BIT_2LINES);
#endif

	LCD_Send_Command(LCD_ENTRY_MODE);
	LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW);
	LCD_Send_Command(LCD_DISP_0N_CURSOR_BLINK);

}

void LCD_Clear_Screen(void)
{
	LCD_Send_Command(LCD_CLEAR);
}

void LCD_Send_Command(uint8_t command)
{
#ifdef EIGHT_BIT_MODE

	MCAL_GPIO_WritePort(LCD_DATA_PORT, command);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW_switch, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RS_switch, GPIO_PIN_RESET);
	delay_ms(1);
	LCD_Kick();
#endif

#ifdef FOUR_BIT_MODE
	LCD_Check_Is_Busy();
	LCD_PORT = (LCD_PORT &0x0F) | (command & 0xF0);
	LCD_CONTROL_PORT &= ~((1<<RW_switch) | (1<<RS_switch));
	LCD_Kick();

	LCD_Check_Is_Busy();
	LCD_PORT = (LCD_PORT &0x0F) | (command << 4);
	LCD_CONTROL_PORT &= ~((1<<RW_switch) | (1<<RS_switch));
	LCD_Kick();
#endif

}
void LCD_Send_Character(uint8_t character)
{
#ifdef EIGHT_BIT_MODE

	MCAL_GPIO_WritePort(LCD_DATA_PORT, character);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW_switch, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RS_switch, GPIO_PIN_SET);

	delay_ms(1);
	LCD_Kick();
#endif

#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT &0x0F) | (character & 0xF0);
	LCD_CONTROL_PORT |= (1<<RS_switch);     //1: Data Register
	LCD_CONTROL_PORT &= ~(1<<RW_switch);    //0: Write
	LCD_Kick();

	LCD_Check_Is_Busy();
	LCD_PORT = (LCD_PORT &0x0F) | (character << 4);
	LCD_CONTROL_PORT |= (1<<RS_switch);     //1: Data Register
	LCD_CONTROL_PORT &= ~(1<<RW_switch);    //0: Write
	LCD_Kick();
#endif
}
void LCD_Send_String(char *string)
{
	int count =0;
	while(*string >0)
	{
		count++;
		LCD_Send_Character(*string++);
		if (count == 16)
		{
			LCD_gotoXY(1,0);
		}else if(count >= 32 )
		{
			LCD_Clear_Screen();
			LCD_gotoXY(0,0);
			count =0;
		}
	}
}

void LCD_Kick(void)
{

	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, EN_switch, GPIO_PIN_SET);

	delay_ms(50);

	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, EN_switch, GPIO_PIN_RESET);
}

void LCD_Check_Is_Busy(void)
{
	GPIO_PinConfig_t PinCfg;

	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);



	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW_switch, GPIO_PIN_SET);

	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RS_switch, GPIO_PIN_RESET);


	LCD_Kick();


	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW_switch, GPIO_PIN_RESET);

}




void LCD_gotoXY(uint8_t line , uint8_t position)
{
	if (line == 0) // line 1
	{
		if(position < 16 && position >= 0)
			LCD_Send_Command(0x80+position);
	}
	if (line == 1) //  line 2
	{
		if(position < 16 && position >= 0)
			LCD_Send_Command(0xC0+position);
	}
}
void LCD_Display_Number(unsigned int Number)
{
	char str[6];
	sprintf(str,"%d",Number); //adjust the formatting to your liking

	LCD_Send_String(str);
}

void LCD_Display_Real_Number(double Number)
{
	char str[16];

	char *tmpsign = (Number < 0) ? "-" : "";
	float tmpVal = (Number < 0) ? -Number : Number;

	int tmpInt1 = tmpVal; //get the integer value 
	float tmpFraction = tmpVal - tmpInt1; // get fraction value
	int tmpInt2 = tmpFraction * 10000; // turn into integer

	sprintf(str,"$s%d.%04d",tmpsign,tmpInt1,tmpInt2);
	LCD_Send_String(str);
}
