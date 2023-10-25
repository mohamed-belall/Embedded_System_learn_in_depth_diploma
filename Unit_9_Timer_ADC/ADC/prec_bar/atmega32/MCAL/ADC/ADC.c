/*
 * ADCc.c
 *
 * Created: 10/23/2023 10:55:48 PM
 *  Author: Mohamed Belal
 */ 
/* ============================================================================ */
/* ================================= Includes ================================= */
/* ============================================================================ */
#include "ADC.h"


/* ============================================================================ */
/* ===========================  Global Variables ============================== */
/* ============================================================================ */
ADC_Config_t G_ADC_ConFig;


/* ============================================================================ */
/* ==================== APIs Supported by "MCAL ADC DRIVER" =================== */
/* ============================================================================ */
void MCAL_ADC_Init(ADC_Config_t* ADC_cfg)
{
	G_ADC_ConFig = *ADC_cfg;
	
	// 1. select ADC mode
	ADCSRA |= ADC_cfg->ADC_Mode;
	
	// 2. select ADC Voltage Reference
	ADMUX |= ADC_cfg->ADC_Voltage_Reference;
	
	
	// 3. select ADC Result Presentation
	ADMUX |= ADC_cfg->ADC_Result_Presentation;
		
	// 4. select ADC Prescaler
	ADMUX |= ADC_cfg->ADC_Prescaler;
	

	
	// 5. configure Enable | Disable IRQ
	ADCSRA |= ADC_cfg->IRQ_Enable;
	
	if (ADC_cfg->IRQ_Enable ==	IRQ_ADIE_Enable)
	{
		sei();
	}
	
	
	// 6. enable ADC 
	SETBIT(ADCSRA , ADEN);
	
	
	// 7. start conversion with ADC free running mode 
	if (ADC_cfg->ADC_Mode == ADC_Mode_FREE_RUNNING)
	{
		SETBIT(ADCSRA , ADSC);
	}	
}




void MCAL_ADC_DeInit(void)
{
	ADMUX  = 0x00;
	ADCSRA = 0x00;
	
}

void MCAL_ADC_GetConversionResult(Channel_Select_t channel , uint16_t * result  , Polling_Mechanism_t polling)
{
	
	ADMUX &= ~(0x1F);
	
	
	// 1. select channel 
	ADMUX |= (uint8_t)channel;
	CLEARBIT(DDRA,channel);
	
	// 2. start conversion
	if (G_ADC_ConFig.ADC_Mode == ADC_Mode_SINGLE_CONVERSION)
	{
		SETBIT(ADCSRA , ADSC);
	}
	
	// 3. wait until  ADC conversion completes and the Data Registers are updated   => ADCSRA >> ADIF flag
	if (polling == Polling_ENABLE)
	{
		while(!READBIT(ADCSRA , ADIF));
	}
	
	
	// 4. read conversion data
	if (G_ADC_ConFig.ADC_Result_Presentation == ADC_Result_Presentation_RIGHT)
	{
		*result = (ADCL | ((ADCH & (0x03)) << 8));
	}else if (G_ADC_ConFig.ADC_Result_Presentation == ADC_Result_Presentation_LEFT)
	{
		*result = (((ADCL & 0xC0) >> 6)|(ADCH<<2));
	}


	// 5. Clear ADIF flag
	CLEARBIT(ADCSRA, ADIF);
	
}





/* ============================================================================ */
/* ================================== IRQ Handlers ============================ */
/* ============================================================================ */
ISR(ADC_vect)
{
	G_ADC_ConFig.P_IRQ_CallBack();
}