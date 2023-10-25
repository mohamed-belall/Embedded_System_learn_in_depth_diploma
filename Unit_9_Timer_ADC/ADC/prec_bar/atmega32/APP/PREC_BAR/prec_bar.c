/*
 * prec_bar.c
 *
 * Created: 10/25/2023 7:09:46 AM
 *  Author: Mohamed Belal
 */ 

#include "prec_bar.h"
#include "./../../HAL/lcd_driver.h"

uint32_t ADC_Result , prec , barSize;
void prec_bar_app(void)
{
	LCD_Init();
	
	ADC_Config_t ADCcfg;
	ADCcfg.ADC_Mode = ADC_Mode_SINGLE_CONVERSION;
	ADCcfg.ADC_Prescaler = ADC_PRESCALER_64;
	ADCcfg.ADC_Result_Presentation = ADC_Result_Presentation_LEFT;
	ADCcfg.ADC_Voltage_Reference = ADC_Voltage_Reference_AVCC;
	ADCcfg.IRQ_Enable = IRQ_ADIE_Disable;
	
	MCAL_ADC_Init(&ADCcfg);
	
	LCD_Send_String("PREC: ");
	
	while (1)
	{
		
		
	 MCAL_ADC_GetConversionResult(ADC0,&ADC_Result , Polling_ENABLE);
	 prec = (ADC_Result *100)/1023;
	 barSize = (160 / (1000 / prec));
	 LCD_Display_Number(prec);
	 LCD_Send_Character('%');
	 
	 int i;
	 LCD_gotoXY(2,0);

	 for(i=0;i<barSize;i++)
	 {
		 LCD_Send_Character(0xff);
	 }
	  for(i=barSize;i<16;i++)
	  {
		  LCD_Send_Character(0x00);
	  }
	LCD_gotoXY(1,6);

	 
	}
	
	
}