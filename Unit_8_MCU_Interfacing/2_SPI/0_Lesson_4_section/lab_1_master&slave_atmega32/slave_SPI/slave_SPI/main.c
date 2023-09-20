/*
 * slave_SPI.c
 *
 * Created: 9/20/2023 4:00:43 PM
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

void SPI_SlaveInit(void)
{

	// set MISO AS output
	DDR_SPI |= (1 << SPI_MISO);

	DDR_SPI &= ~(1 << SPI_MOSI) & ~(1 << SPI_SCK) & ~(1 << SPI_SS);

	// enable SPI , Master ,Set clock rate fck/16
	SPCR = (1 << SPE);
}

unsigned char SPI_SlaveReceive(unsigned char cData)
{

	SPDR = cData;

	/* ========= Wait for receive complete ========= */
	while (!(SPSR & (1 << SPIF)))
		;

	return SPDR;
}

int main(void)
{
	unsigned char x = 255;
	DDRA = 0xFF;
	SPI_SlaveInit();
	while (1)
	{
		for (x = 255; x > 0; x--)
		{

			PORTA = SPI_SlaveReceive(x);
		}
	}
	return 0;
}
