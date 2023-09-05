/*
 * calculator_with_lcd_keypad.c
 *
 * Created: 8/28/2023 4:36:45 PM
 * Author : Mohamed Belal
 */ 

#include "LCD_Driver/lcd_driver.h"
#include "keypad_Driver/keypad_Driver.h"


int main(void)
{
	char keyPressed;

	unsigned int number1 =0, number2 =0, result;
	char flag =0 , operator;
	
	
	LCD_Init();
	keypad_Init();
	
	LCD_Send_String("welcome to Bello calculator");
	_delay_ms(500);
	LCD_Clear_Screen();
	
    /* Replace with your application code */
    while (1) 
    {
		keyPressed = keypad_GetKey();
		switch(keyPressed)
		{
			case('A'):
			break; //do nothing if no key pressed
			case('?'):
				LCD_Clear_Screen();
				number1 =0;
				number2 =0;
				flag =0;
			break; //do nothing if no key pressed
			default:
				LCD_Send_Character(keyPressed); // send the key to LCD
				if(keyPressed == '=')
				{
					LCD_gotoXY(1,0);
					if (operator == '*')
					{
						//LCD_Send_String("result: ");
						result = number1*number2;
						LCD_Display_Number(result);
				
					}else if (operator == '/')
					{
						//LCD_Send_String("result: ");
						result = number1/number2;
						LCD_Display_Number(result);
					}else if (operator == '+')
					{
						//LCD_Send_String("result: ");
						result = number1+number2;
						LCD_Display_Number(result);
					}else if (operator == '-')
					{
						//LCD_Send_String("result: ");
						result = number1-number2;
						LCD_Display_Number(result);
					}
				}else if((keyPressed == '*' )||(keyPressed ==  '/') ||(keyPressed ==  '-')||(keyPressed ==  '+') )
				{
					operator = keyPressed;
					flag = 1;
				}else
				{
					if (flag == 0)
					{
						number1 = number1*10+(keyPressed-48);
					}else
					{
						number2 = number2*10+(keyPressed-48);
					}
				}
			break;
		}
    }
}
