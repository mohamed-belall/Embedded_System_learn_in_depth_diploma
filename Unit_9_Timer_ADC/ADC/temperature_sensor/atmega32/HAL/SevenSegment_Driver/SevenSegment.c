/*
 * SevenSegment.c
 *
 * Created: 9/29/2023 5:23:54 PM
 *  Author: Mohamed Belal
 */ 
#include "SevenSegment.h"

// common cathode
static uint8_t seg_CAnodeVal[10]   = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
static uint8_t seg_CCathodeVal[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
/*
 * ===================================
 * @FN				- SSD_init
 * @brief			- initialize 7 segment port   
 * @param [in]		- config:     
 * @retval			- none
 * @Note			- none
 * ===================================
 * */
void SSD_init(SSD_Cfg config)
{
	DIO_SetPortDirection(config.DataPort , DIO_PIN_OUTPUT);
}

/*
 * ===================================
 * @FN				- DIO_SetPortValue
 * @brief			- set port value  
 * @param [in]		- port:      @REF DIO_PORTx_define  =>  where x = (a,b,c,d)
 * @param [in]		- value:     @REF DIO_PIN_define  =>  high|low
 * @retval			- none
 * @Note			- none
 * ===================================
 * */
void SSD_Write(SSD_Cfg config , uint8_t number)
{
	if(config.type == SSD_COMMON_CATHODE)
		DIO_SetPortValue(config.DataPort , seg_CCathodeVal[number]);
	else if(config.type == SSD_COMMON_ANODE)
		DIO_SetPortValue(config.DataPort , seg_CAnodeVal[number]);
}