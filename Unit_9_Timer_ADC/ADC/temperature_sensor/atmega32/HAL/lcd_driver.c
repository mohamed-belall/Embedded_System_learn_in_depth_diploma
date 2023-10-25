/*
 * lcd_driver.c
 *
 * Created: 8/28/2023 4:39:26 PM
 *  Author: Mohamed Belal
 */ 

#include "lcd_driver.h"

void LCD_Init(void)
{
	_delay_ms(20);
	DataDir_LCD_CONTROL |=  (1<<EN_switch | 1<<RW_switch | 1<<RS_switch);
	LCD_CONTROL_PORT    &= ~(1<<EN_switch | 1<<RW_switch | 1<<RS_switch);


	
	DataDir_LCD_PORT = 0xFF;
	
	_delay_ms(15);
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
	LCD_Send_Command(LCD_DISP_0N);
	
}

void LCD_Clear_Screen(void)
{
	LCD_Send_Command(LCD_CLEAR);
}

void LCD_Send_Command(uint8_t command)
{
	#ifdef EIGHT_BIT_MODE
	LCD_Check_Is_Busy();
	
	LCD_PORT = command;
	LCD_CONTROL_PORT &= ~((1<<RW_switch) | (1<<RS_switch));
	_delay_ms(1);
	LCD_Kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_Check_Is_Busy();
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_CONTROL_PORT &= ~((1<<RW_switch) | (1<<RS_switch));
	LCD_Kick();
	

	LCD_PORT = (LCD_PORT &0x0F) | (command << 4);
	LCD_CONTROL_PORT &= ~((1<<RW_switch) | (1<<RS_switch));
	LCD_Kick();
	#endif
	
}
void LCD_Send_Character(uint8_t character)
{
	#ifdef EIGHT_BIT_MODE
	LCD_Check_Is_Busy();

	LCD_PORT = (character << DATA_SHIFT);
	LCD_CONTROL_PORT &= ~(1<<RW_switch);    //0: Write
	LCD_CONTROL_PORT |= (1<<RS_switch);     //1: Data Register
	_delay_ms(1);
	LCD_Kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT &0x0F) | (character & 0xF0);
	LCD_CONTROL_PORT &= ~(1<<RW_switch);    //0: Write
	LCD_CONTROL_PORT |= (1<<RS_switch);     //1: Data Register
	LCD_Kick();
	

	LCD_PORT = (LCD_PORT &0x0F) | (character << 4);
	LCD_CONTROL_PORT &= ~(1<<RW_switch);    //0: Write
	LCD_CONTROL_PORT |= (1<<RS_switch);     //1: Data Register
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
			LCD_gotoXY(2,0);
		}else if(count >= 32 )
		{
			LCD_Clear_Screen();
			LCD_gotoXY(1,0);
			count =0;
		}
	}
}

void LCD_Kick(void)
{	
	LCD_CONTROL_PORT |= (1<<EN_switch);
	_delay_ms(50);
	LCD_CONTROL_PORT &= ~(1<<EN_switch);
	//asm volatile ("nop");
	//asm volatile ("nop");
	

}
void LCD_Check_Is_Busy(void)
{
	DataDir_LCD_PORT &= ~(0xFF << DATA_SHIFT);
	LCD_CONTROL_PORT |= (1<<RW_switch);            //1: Read
	LCD_CONTROL_PORT &= ~(1<<RS_switch);           // 0: Command Register
	
	LCD_Kick();
	
	DataDir_LCD_PORT |= (0xFF << DATA_SHIFT);
	LCD_CONTROL_PORT &= ~(1<<RW_switch);       //0: Write
}

void LCD_gotoXY(uint16_t line , uint16_t position)
{
	if (line == 1) // line 1
	{
		if(  position >= 0 && position < 16)
			LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW+position);
	}
	else if (line == 2) //  line 2
	{
		if(  position >= 0 && position < 16)
			LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW+position);
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