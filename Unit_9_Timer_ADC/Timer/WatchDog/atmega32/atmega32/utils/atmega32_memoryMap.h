/*
 * atmega32_memoryMap.h
 *
 *  Created: 9/4/2023 7:07:46 PM
 *  Author: Mohamed Belal
 */ 

#ifndef ATMEGA32_MEMORYMAP_H_
#define ATMEGA32_MEMORYMAP_H_
#include "./../utils/Platform_Types.h"



/*  
 * =============================================
 *                     GPIOA 
 * =============================================
 */
#define  PORTA			*(volatile uint8_t *)(0x3B)
#define  DDRA			(*(volatile uint8_t *)(0x3A))
#define  PINA			*(volatile uint8_t *)(0x39)


/*  
 * =============================================
 *                     GPIOB 
 * =============================================
 */
#define  PORTB			*(volatile uint8_t *)(0x38)
#define  DDRB			(*(volatile uint8_t *)(0x37))
#define  PINB			*(volatile uint8_t *)(0x36)


/*  
 * =============================================
 *                     GPIOC 
 * =============================================
 */
#define  PORTC			*(volatile uint8_t *)(0x35)
#define  DDRC			(*(volatile uint8_t *)(0x34))
#define  PINC			*(volatile uint8_t *)(0x33)



/*  
 * =============================================
 *                     GPIOD 
 * =============================================
 */
#define  PORTD			*(volatile uint8_t *)(0x32)
#define  DDRD			*(volatile uint8_t *)(0x31)
#define  PIND			*(volatile uint8_t *)(0x30)



/*  
 * =============================================
 *                     TIMER0 
 * =============================================
 */
#define  TCCRO			*(volatile uint8_t *)(0x53)
#define  CS00			0
#define  CS01			1
#define  CS02			2
#define  WGM01			3
#define  COM00			4
#define  COM01			5
#define  WGM00			6
#define  FOC0			7


#define  TCNT0			*(volatile uint8_t *)(0x52)
#define  OCR0			*(volatile uint8_t *)(0x5C)

#define  TIMSK			*(volatile uint8_t *)(0x59)
#define  TOIE0			0
#define  OCIE0			1


#define  TIFR			*(volatile uint8_t *)(0x58)



/*  
 * =============================================
 *                     WatchDog 
 * =============================================
 */
#define  WDTCR			*(volatile uint8_t *)(0x41)
#define  WDP0			 (1<<0)
#define  WDP1			 (1<<1)
#define  WDP2			 (1<<2)
#define  WDE			 (1<<3)
#define  WDTOE			 (1<<4)






#define  UDR			*(volatile uint8_t *)(0x2C)

#define  UCSRA			*(volatile uint8_t *)(0x2B)
#define  U2X			1							// Double the USART Transmission Speed
#define  UDRE			5							//  USART Data Register Empty => The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data
#define  RXC			7							//  USART Receive Complete => This flag bit is set when there are unread data in the receive buffer


#define  UCSRB			*(volatile uint8_t *)(0x2A)
#define  TXEN			3							// Receiver Enable
#define  RXEN			4							// Transmitter Enable
#define  UCSZ2			2							// Character Size



#define  UCSRC			*(volatile uint8_t *)(0x40)
#define  UMSEL			6							// USART Mode Select  => 0:Asynchronous Operation
#define  UPM0			4							// Parity Mode   => 0 Disabled
#define  UPM1			5							// Parity Mode   => 0 Disabled
#define  UCSZ0			1							// Character Size
#define  UCSZ1			2							// Character Size


#define  UBRRL			*(volatile uint8_t *)(0x29)
#define  UBRRH			*(volatile uint8_t *)(0x40)




void Pin_Direction(uint8_t base  , uint8_t bin , uint8_t status);
void Port_Direction(uint8_t base  ,  uint8_t status);


#endif /* ATMEGA32_MEMORYMAP_H_ */