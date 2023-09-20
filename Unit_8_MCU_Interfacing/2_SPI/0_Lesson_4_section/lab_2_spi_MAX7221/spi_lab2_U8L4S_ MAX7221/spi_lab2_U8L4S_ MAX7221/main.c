/*
 * spi_lab2_U8L4S_ MAX7221.c
 *
 * Created: 9/20/2023 5:33:10 PM
 * Author : Mohamed Belal
 */

#define F_CPU 1000000UL

#include <avr/io.h>
#include "util/delay.h"

#define SS 4
#define MOSI 5
#define SCK 7

void SPI_MasterInit(void)
{

	// set MOSI and SCK  and SS ==>  output
	DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS);

	// enable SPI , Master ,Set clock rate fck/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void execute(unsigned char cmd, unsigned char data)
{
	// initialized the packet by pulling SS low
	PORTB &= ~(1 << SS);

	// start cmd transmission
	SPDR = cmd;

	// wait cmd transfer to finish
	while (!(SPSR & (1 << SPIF)))
		;

	// start data transmission
	SPDR = data;

	// wait data transfer to finish
	while (!(SPSR & (1 << SPIF)))
		;

	// terminate the packet by pulling SS high
	PORTB |= (1 << SS);
}

int main(void)
{
	unsigned char counter = 0;
	unsigned char index_display = 1;

	SPI_MasterInit();

	execute(0x09, 0xFF); /* decode all display => 11111111 */
	execute(0x0A, 0xFF); /* set Scan Limit (digit0 to digit7) */
	execute(0x0B, 0xF7); /* max intensity */
	execute(0x0C, 0x01); /* Turn On Display */

	while (1)
	{
		for (index_display = 1; index_display < 9; index_display++)
		{

			execute(index_display, counter++);

			_delay_ms(300);
		}
	}
}
