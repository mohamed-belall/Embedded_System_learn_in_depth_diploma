/*
 * DIO.c
 *
 * Created: 9/4/2023 7:16:39 PM
 *  Author: Mohamed Belal
 */ 


#include "DIO.h"
/*  
 * ******************************************************************************************
 *											pin 
 * ******************************************************************************************
 */



/*
 * ===================================
 * @FN				- DIO_SetPinDirection
 * @brief			- set pin direction  
 * @param [in]		- port:      @REF DIO_PORTx_define  =>  where x = (a,b,c,d)
 * @param [in]		- pin:       @REF DIO_PINx_define  =>  where x = (0,1,2,3,4,5,6,7)
 * @param [in]		- direction: @REF DIO_PIN_define  =>  output|input
 * @retval			- none
 * @Note			- none
 * ===================================
 * */
void DIO_SetPinDirection (uint8_t port , uint8_t  pin , uint8_t  direction)
{
	if (port<= DIO_PORTD && pin <= DIO_PIN7)
	{
		if (direction == DIO_PIN_OUTPUT)
		{
			switch(port)
			{
				case DIO_PORTA :  SETBIT(DDRA , pin); break;
				case DIO_PORTB :  SETBIT(DDRB , pin); break;
				case DIO_PORTC :  SETBIT(DDRC , pin); break;
				case DIO_PORTD :  SETBIT(DDRD , pin); break;
			}
		}else if (direction == DIO_PIN_INPUT)
		{
			switch(port)
			{
				case DIO_PORTA :  CLEARBIT(DDRA , pin); break;
				case DIO_PORTB :  CLEARBIT(DDRB , pin); break;
				case DIO_PORTC :  CLEARBIT(DDRC , pin); break;
				case DIO_PORTD :  CLEARBIT(DDRD , pin); break;
			}
		}
	}
		
}


/*
 * ===================================
 * @FN				- DIO_SetPinValue
 * @brief			- set pin value  
 * @param [in]		- port:      @REF DIO_PORTx_define  =>  where x = (a,b,c,d)
 * @param [in]		- pin:       @REF DIO_PINx_define  =>  where x = (0,1,2,3,4,5,6,7)
 * @param [in]		- value:     @REF DIO_PIN_define  =>  high|low
 * @retval			- none
 * @Note			- none
 * ===================================
 * */
void DIO_SetPinValue(uint8_t port , uint8_t  pin , uint8_t  value)
{
	if (port<= DIO_PORTD && pin <= DIO_PIN7)
	{
		if (value == DIO_PIN_HIGH)
		{
			switch(port)
			{
				case DIO_PORTA :  SETBIT(PORTA , pin); break;
				case DIO_PORTB :  SETBIT(PORTB , pin); break;
				case DIO_PORTC :  SETBIT(PORTC , pin); break;
				case DIO_PORTD :  SETBIT(PORTD , pin); break;
			}
		}else if (value == DIO_PIN_LOW)
		{
			switch(port)
			{
				case DIO_PORTA :  CLEARBIT(PORTA , pin); break;
				case DIO_PORTB :  CLEARBIT(PORTB , pin); break;
				case DIO_PORTC :  CLEARBIT(PORTC , pin); break;
				case DIO_PORTD :  CLEARBIT(PORTD , pin); break;
			}
		}
	}
}

/*
 * ===================================
 * @FN				- DIO_GetPinValue
 * @brief			- read pin value  
 * @param [in]		- port:      @REF DIO_PORTx_define  =>  where x = (a,b,c,d)
 * @param [in]		- pin:       @REF DIO_PINx_define  =>  where x = (0,1,2,3,4,5,6,7)
 * @retval			- value of PINx 
 * @Note			- none
 * ===================================
 * */
uint8_t DIO_GetPinValue(uint8_t port , uint8_t  pin )
{
	uint8_t inVal =0;
	if (port<= DIO_PORTD && pin <= DIO_PIN7)
	{
		switch(port)
		{
			case DIO_PORTA :  inVal = READBIT(PINA , pin); break;
			case DIO_PORTB :  inVal = READBIT(PINB , pin); break;
			case DIO_PORTC :  inVal = READBIT(PINC , pin); break;
			case DIO_PORTD :  inVal = READBIT(PIND , pin); break;
		}
	}
	return inVal;
}

/*
 * ===================================
 * @FN				- DIO_TogglePin
 * @brief			- toggle pin   
 * @param [in]		- port:      @REF DIO_PORTx_define  =>  where x = (a,b,c,d)
 * @param [in]		- pin:       @REF DIO_PINx_define  =>  where x = (0,1,2,3,4,5,6,7)
 * @retval			- none
 * @Note			- none
 * ===================================
 * */
void DIO_TogglePin(uint8_t port , uint8_t  pin )
{
	switch(port)
	{
		case DIO_PORTA :  TOGGLEBIT(PORTA , pin); break;
		case DIO_PORTB :  TOGGLEBIT(PORTB , pin); break;
		case DIO_PORTC :  TOGGLEBIT(PORTC , pin); break;
		case DIO_PORTD :  TOGGLEBIT(PORTD , pin); break;
	}	
}




/*  
 * ******************************************************************************************
 *											PORT 
 * ******************************************************************************************
 */

/*
 * ===================================
 * @FN				- DIO_SetPortDirection
 * @brief			- set port direction  
 * @param [in]		- port:      @REF DIO_PORTx_define  =>  where x = (a,b,c,d)
 * @param [in]		- direction: @REF DIO_PIN_define  =>  output|input
 * @retval			- none
 * @Note			- none
 * ===================================
 * */
void	DIO_SetPortDirection (uint8_t port ,  uint8_t  direction)
{
	if (direction == DIO_PIN_OUTPUT)
	{
		switch(port)
		{
			case DIO_PORTA :  DDRA = 0xFF ; break;
			case DIO_PORTB :  DDRB = 0xFF ; break;
			case DIO_PORTC :  DDRC = 0xFF ; break;
			case DIO_PORTD :  DDRD = 0xFF ; break;
		}
	}else if (direction == DIO_PIN_INPUT)
	{
		switch(port)
		{
			case DIO_PORTA :  DDRA = 0x0 ; break;
			case DIO_PORTB :  DDRB = 0x0 ; break;
			case DIO_PORTC :  DDRC = 0x0 ; break;
			case DIO_PORTD :  DDRD = 0x0 ; break;
		}
	}else
	{
		switch(port)
		{
			case DIO_PORTA :  DDRA = direction ; break;
			case DIO_PORTB :  DDRB = direction ; break;
			case DIO_PORTC :  DDRC = direction ; break;
			case DIO_PORTD :  DDRD = direction ; break;
		}

	}
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
void	DIO_SetPortValue     (uint8_t port ,  uint8_t  value)
{
	if (value == DIO_PIN_HIGH)
	{
		switch(port)
		{
			case DIO_PORTA :  PORTA = 0xFF ; break;
			case DIO_PORTB :  PORTB = 0xFF ; break;
			case DIO_PORTC :  PORTC = 0xFF ; break;
			case DIO_PORTD :  PORTD = 0xFF ; break;
		}
	}else if (value == DIO_PIN_LOW)
	{
		switch(port)
		{
			case DIO_PORTA :  PORTA = 0x0 ; break;
			case DIO_PORTB :  PORTB = 0x0 ; break;
			case DIO_PORTC :  PORTC = 0x0 ; break;
			case DIO_PORTD :  PORTD = 0x0 ; break;
		}
	}else
	{
		switch(port)
		{
			case DIO_PORTA :  PORTA = value ; break;
			case DIO_PORTB :  PORTB = value ; break;
			case DIO_PORTC :  PORTC = value ; break;
			case DIO_PORTD :  PORTD = value ; break;
		}
	}
}



/*
 * ===================================
 * @FN				- DIO_GetPortValue
 * @brief			- read port value  
 * @param [in]		- port:      @REF DIO_PORTx_define  =>  where x = (a,b,c,d)
 * @retval			- value of port
 * @Note			- none
 * ===================================
 * */
uint8_t DIO_GetPortValue(uint8_t port )
{
	uint8_t inVal =0;
	
	switch(port)
	{
		case DIO_PORTA :  inVal = PINA ; break;
		case DIO_PORTB :  inVal = PINB ; break;
		case DIO_PORTC :  inVal = PINC ; break;
		case DIO_PORTD :  inVal = PIND ; break;
	}
	
	return inVal;
}

/*
 * ===================================
 * @FN				- DIO_TogglePort
 * @brief			- toggle port value  
 * @param [in]		- port:      @REF DIO_PORTx_define  =>  where x = (a,b,c,d)
 * @retval			- none
 * @Note			- none
 * ===================================
 * */
void DIO_TogglePort(uint8_t port )
{
	switch(port)
	{
		case DIO_PORTA :  PORTA = ~PORTA ; break;
		case DIO_PORTB :  PORTB = ~PORTB; break;
		case DIO_PORTC :  PORTC = ~PORTC; break;
		case DIO_PORTD :  PORTD = ~PORTD; break;
	}
}