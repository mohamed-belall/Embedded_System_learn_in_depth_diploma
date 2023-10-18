/*
 * lcd_driver.h
 *
 * Created: 8/28/2023 4:39:41 PM
 *  Author: Mohamed Belal
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_



#include "./../utils/Atmeg32_Config.h"

#define LCD_PORT                       PORTA
#define DataDir_LCD_PORT               DDRA
#define DATA_SHIFT                     0
#define LCD_CONTROL_PORT               PORTB
#define DataDir_LCD_CONTROL            DDRB
#define EN_switch                      3
#define RW_switch                      2
#define RS_switch                      1

#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE


#define LCD_REGISTER_SELECT_PIN       (0)
#define LCD_READ_WRITE_PIN            (1)
#define LCD_ENABLE_PIN                (2)
#define LCD_REGISTER_SELECT_ENABLE    (1)
#define LCD_REGISTER_SELECT_DISABLE   (0)
#define READ_FROM_LCD                 (1)
#define WRITE_TO_LCD                  (0)
#define LCD_ENABLE                    (1)
#define LCD_DISABLE                   (0)
#define LCD_FIRST_LINE                (0)
#define LCD_SECOND_LINE               (1)
#define LCD_FUNCTION_8BIT_2LINES      (0x38)
#define LCD_FUNCTION_4BIT_2LINES      (0x28)
#define LCD_MOVE_DISP_RIGHT			  (0x1C)
#define LCD_MOVE_DISP_LEFT            (0x18)
#define LCD_MOVE_CURSOR_RIGHT         (0x14)
#define LCD_MOVE_CURSOR_LEFT          (0x10)
#define LCD_DISP_OFF                  (0x08)
#define LCD_DISP_0N_CURSOR            (0x0E)
#define LCD_DISP_0N_CURSOR_BLINK      (0x0F)
#define LCD_DISP_0N_BLINK             (0x0D)
#define LCD_DISP_0N                   (0x0C)
#define LCD_ENTRY_DEC                 (0x04)
#define LCD_ENTRY_DEC_SHIFT           (0x05)
#define LCD_ENTRY_INC                 (0x06)
#define LCD_ENTRY_INC_SHIFT           (0x07)
#define LCD_BEGIN_AT_FIRST_RAW        (0x80)
#define LCD_BEGIN_AT_SECOND_RAW       (0xC0)
#define LCD_CLEAR					  (0x01)
#define LCD_ENTRY_MODE				  (0x06)

void LCD_Init(void);
void LCD_Clear_Screen(void);

void LCD_Send_Command(uint8_t command);
void LCD_Send_Character(uint8_t character);
void LCD_Send_String(char *string);

void LCD_Kick(void);
void LCD_Check_Is_Busy(void);

void LCD_gotoXY(uint8_t line , uint8_t position);
void LCD_Display_Number(unsigned int Number);
void LCD_Display_Real_Number(double Number);



#endif /* LCD_DRIVER_H_ */