/*
 * SevenSegment.h
 *
 *  Created: 9/29/2023 5:24:07 PM
 *  Author: Mohamed Belal
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "./../../MCAL/DIO.h"

#define SSD_COMMON_ANODE 0
#define SSD_COMMON_CATHODE 1

typedef struct  
{
	uint8_t type       ;
	uint8_t DataPort   ;
	uint8_t EnablePort ;
	uint8_t EnablePin  ;
}SSD_Cfg;


void SSD_init(SSD_Cfg config);
void SSD_Write(SSD_Cfg config , uint8_t number);

#endif /* SEVENSEGMENT_H_ */



/*
value &= 0x0F
PORTA &= 0xF0
PORTA |= value;



*/