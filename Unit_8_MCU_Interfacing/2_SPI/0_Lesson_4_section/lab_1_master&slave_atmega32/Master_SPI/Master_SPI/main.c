/*
 * Master_SPI.c
 *
 * Created: 9/20/2023 3:23:41 PM
 * Author : Mohamed Belal
 */
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define DDR_SPI DDRB
#define SPI_SS 4
#define SPI_MOSI 5
#define SPI_MISO 6
#define SPI_SCK 7

/*
	MSTR bit  =>  SPCR   => cleared  => SPI Slave
				  MOSI & SCK  => INPUT

	SPIF FLAG  =>  SPSR   => SET  =>if( SPI interrupt enable & i-bit in SREG is set )
				 interrupt routine will be executed

*/

void SPI_MasterInit(void)
{

	// set MOSI and SCK  ==>  output
	// all other input
	DDR_SPI |= (1 << SPI_MOSI) | (1 << SPI_SCK) | (1 << SPI_SS);
	DDR_SPI &= ~(1 << SPI_MISO);

	// enable SPI , Master ,Set clock rate fck/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

unsigned char SPI_MasterTransmit(unsigned char cData)
{
	/* ========= start transmission ========= */
	SPDR = cData;

	/* ========= Wait for transmission complete ========= */
	while (!(SPSR & (1 << SPIF)))
		;

	return SPDR;
}

int main(void)
{
	unsigned char ch = 0;
	DDRA = 0xFF;
	SPI_MasterInit();

	for (ch = 0; ch <= 255; ch++)
	{

		_delay_ms(100);
		PORTA = SPI_MasterTransmit(ch);
	}

	return 0;
}
