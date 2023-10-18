/*
 * DIO.h
 *
 * Created: 9/11/2023 12:41:21 PM
 *  Author: Mohamed Belal
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "./../utils/Atmeg32_Config.h"


// @REF DIO_PIN_define  =>  output|input
#define DIO_PIN_OUTPUT			1
#define DIO_PIN_INPUT			0

// @REF DIO_PIN_define  =>  high|low
#define DIO_PIN_HIGH			1
#define DIO_PIN_LOW				0

// @REF DIO_PORTx_define  =>  where x = (a,b,c,d)
#define DIO_PORTA				0
#define DIO_PORTB				1
#define DIO_PORTC				2
#define DIO_PORTD				3

// @REF DIO_PINx_define  =>  where x = (0,1,2,3,4,5,6,7)
#define DIO_PIN0				0
#define DIO_PIN1				1
#define DIO_PIN2				2
#define DIO_PIN3				3
#define DIO_PIN4				4
#define DIO_PIN5				5
#define DIO_PIN6				6
#define DIO_PIN7				7


/*  
 * ******************************************************************************************
 *											pin 
 * ******************************************************************************************
 */
void	DIO_SetPinDirection (uint8_t port , uint8_t  pin , uint8_t  direction);
void	DIO_SetPinValue     (uint8_t port , uint8_t  pin , uint8_t  value);
uint8_t DIO_GetPinValue     (uint8_t port , uint8_t  pin );
void	DIO_TogglePin	    (uint8_t port , uint8_t  pin );




/*  
 * ******************************************************************************************
 *											PORT 
 * ******************************************************************************************
 */
void	DIO_SetPortDirection (uint8_t port ,  uint8_t  direction);
void	DIO_SetPortValue     (uint8_t port ,  uint8_t  value);
uint8_t DIO_GetPortValue     (uint8_t port );
void	DIO_TogglePort	     (uint8_t port );


#endif /* DIO_H_ */