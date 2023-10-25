/*
 * LM35.c
 *
 * Created: 10/24/2023 8:50:07 PM
 *  Author: Mohamed Belal
 */ 

#include "LM35.h"
#include "./../../HAL/lcd_driver.h"

uint32_t ADCResult , temp;

void LM35_temperature_sensor(void)
{
	LCD_Init();
	//LCD_Send_String("LCD is ready ");
	//LCD_Clear_Screen();	
	
	
	ADC_Config_t ADCcfg;
	ADCcfg.ADC_Mode = ADC_Mode_SINGLE_CONVERSION;
	ADCcfg.ADC_Prescaler = ADC_PRESCALER_64;
	ADCcfg.ADC_Result_Presentation = ADC_Result_Presentation_RIGHT;
	ADCcfg.ADC_Voltage_Reference = ADC_Voltage_Reference_AVCC;
	ADCcfg.IRQ_Enable = IRQ_ADIE_Disable;
	ADCcfg.P_IRQ_CallBack = 0;
	MCAL_ADC_Init(&ADCcfg);
	
	LCD_Send_String("temperature: ");
	
	while (1)
	{
		MCAL_ADC_GetConversionResult(ADC1 , &ADCResult , Polling_ENABLE );
		temp = ( ( (ADCResult * 5000) / 1023 )   / 10);
		LCD_gotoXY(1, 13);
		LCD_Display_Number(temp);
		LCD_Send_String("c");	
	}
	
}