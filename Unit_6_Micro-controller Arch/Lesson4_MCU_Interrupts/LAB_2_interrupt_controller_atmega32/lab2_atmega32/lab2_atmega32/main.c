/*
 * lab2_atmega32.c
 *
 * Created: 8/22/2023 5:48:44 PM
 * Author : mohamed belal
 */ 

#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void EXTI_INIT(void);
void GPIO_INIT(void);
int main(void)
{

	EXTI_INIT();
	GPIO_INIT();

    /* Replace with your application code */
    while (1) 
    {
		PORTD &= ~(1<<5);
		PORTD &= ~(1<<6);
		PORTD &= ~(1<<7);
		_delay_ms(1000);
    }
}

void GPIO_INIT(void)
{
	
		// make pin 5 , 6 , 7 output
		DDRD |= (1<<5);
		DDRD |= (1<<6);
		DDRD |= (1<<7);
}
void EXTI_INIT(void)
{
	/*
	1. INT0 => any change (rising or falling) 
	2. INT1 => rising edge
	3. INT2 => falling edge 
	*/
	
	// 1. INT0 => any change (rising or falling)
	MCUCR |= (1<<0);
	// 2. INT1 => rising edge		
	MCUCR |= (1<<2); 
	MCUCR |= (1<<3); 
	// 3. INT2 => falling edge 
	MCUCSR &= ~(1<<6);	    
	
	// GICR general interrupt control register
	GICR |= (1<<5); // enable external interrupt INT2
	GICR |= (1<<6); // enable external interrupt INT0
	GICR |= (1<<7); // enable external interrupt INT1
	
	
	//enable global interrupt
	sei();
}

ISR(INT0_vect)
{
	PORTD |=(1<<5);
	_delay_ms(1000);
	
}
ISR(INT1_vect)
{
	PORTD |=(1<<6);
	_delay_ms(1000);
	
}
ISR(INT2_vect)
{
	PORTD |=(1<<7);
	_delay_ms(1000);
	
}
