/*
 * ADC.h
 *
 * Created: 10/23/2023 10:56:00 PM
 *  Author: Mohamed Belal
 */ 


#ifndef ADC_H_
#define ADC_H_

/* ========================================================================================= */
/* ======================================= Includes ======================================== */
/* ========================================================================================= */
#include "./../../utils/Atmeg32_Config.h"
#include "./../../MCAL/DIO.h"


/* ========================================================================================= */
/* =========================== User Type Definition (Structures) =========================== */
/* ========================================================================================= */
typedef struct  
{
	 /* ==== ADC_Mode ====
	 * specifies the ADC mode (Single conversion mode | Free Running Mode)
	 * this parameter must be set base on @ref ADC_Mode_Define
	 * bit 7:6 => ADMUX
	 * */
	uint8_t		ADC_Mode;
	
	/* ==== ADC_Voltage_Reference ====
	 * select ADC VREF source 
	 * this parameter must be set base on @ref ADC_Voltage_Reference_Define
	 * bit 7:6 => ADMUX
	 * */
	uint8_t		ADC_Voltage_Reference;
	
	
	

	
	/* ==== ADC_Prescaler ====
	 * Selects the division factor between the XTAL frequency and the input clock to ADC   
	 * this parameter must be set base on @ref ADC_PRESCALER_Define
	 * bit 2:0 => ADMUX
	 * */
	uint8_t		ADC_Prescaler;
	
	
	
	
	/* ==== ADC_Result_Presentation ====
	 * specifies ADC Output result presentation(right adjusted or left adjusted)  
	 * this parameter must be set base on @ref ADC_Result_Presentation_Define
	 * bit 5 => ADMUX
	 * */
	uint8_t		ADC_Result_Presentation;
	
	

	
	
	/* ==== IRQ_Enable ====
	 * specifies Enable or Disable IRQ and use polling mechanism
	 * this parameter must be set base on @ref IRQ_Enable_Define
	 * */
	uint8_t		IRQ_Enable;



	/* ==== (*P_IRQ_CallBack)(void) ====
	 * set the C Function which will be called once IRQ Happens
	 * */
	void (*P_IRQ_CallBack)(void);
	
} ADC_Config_t;


/* ========================================================================================= */
/* ============================= Macros Configuration References =========================== */
/* ========================================================================================= */



//-------------------------------------
//		@ref ADC_Mode_Define
//-------------------------------------
#define ADC_Mode_SINGLE_CONVERSION						(uint8_t)(0)
#define ADC_Mode_FREE_RUNNING							(uint8_t)(1<<ADCSRA) //(uint8_t)(0b01<<REFS0)




//-------------------------------------
//		@ref ADC_Voltage_Reference_Define
//-------------------------------------
#define ADC_Voltage_Reference_EXTERNAL_AREF				(uint8_t)(0)		
#define ADC_Voltage_Reference_AVCC						(uint8_t)(0b01<<REFS0) 
#define ADC_Voltage_Reference_Internal					(uint8_t)(0b11<<REFS0) 



//-------------------------------------
//		@ref ADC_Result_Presentation_Define
//-------------------------------------
#define ADC_Result_Presentation_RIGHT				(uint8_t)(0)
#define ADC_Result_Presentation_LEFT				(uint8_t)(1<<ADLAR)




//-------------------------------------
//		@ref ADC_PRESCALER_Define (ADCSRA)
//-------------------------------------	
#define ADC_PRESCALER_2									(uint8_t)(0b001<<ADPS0)	
#define ADC_PRESCALER_4									(uint8_t)(0b010<<ADPS0)
#define ADC_PRESCALER_8									(uint8_t)(0b011<<ADPS0)
#define ADC_PRESCALER_16								(uint8_t)(0b100<<ADPS0)
#define ADC_PRESCALER_32								(uint8_t)(0b101<<ADPS0)
#define ADC_PRESCALER_64								(uint8_t)(0b110<<ADPS0)
#define ADC_PRESCALER_128								(uint8_t)(0b111<<ADPS0)



//-------------------------------------
//		@ref IRQ_Enable_Define
//-------------------------------------
#define IRQ_ADIE_Disable						((uint8_t)(0))
#define IRQ_ADIE_Enable							((uint8_t)(1<<ADIE))




//-------------------------------------
//				channel enum
//-------------------------------------

typedef enum{
	ADC0 = 0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	}Channel_Select_t;
	
	
	
typedef enum
{
	Polling_ENABLE,
	Polling_DISABLE
}Polling_Mechanism_t;


/* ========================================================================================= */
/* ========================= APIs Supported by "MCAL Timer0 DRIVER" ======================== */
/* ========================================================================================= */
void MCAL_ADC_Init(ADC_Config_t* ADC_cfg);
void MCAL_ADC_DeInit(void);

void MCAL_ADC_GetConversionResult(Channel_Select_t channel , uint16_t * result  , Polling_Mechanism_t polling);




#endif /* ADC_H_ */