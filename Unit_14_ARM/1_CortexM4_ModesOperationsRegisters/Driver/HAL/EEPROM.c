/*
 * EEPROM.c
 *
 *  Created on: Oct 13, 2023
 *      Author: moham
 */
#include "EEPROM.h"

void EEPROM_Init(void)
{
	// PB6 : I2C1_SCL
	// PB7 : I2C1_SDA
	I2C_InitCFG_t I2C1CFG;

	// i2c controller act as master
	I2C1CFG.I2C_General_Call_Address_Detection =I2C_ENGC_Enable;
	I2C1CFG.I2C_ACK_Controller = I2C_Acknowledge_Enable;
	I2C1CFG.I2C_ClockSpeed = I2C_SCLK_SM_100K;
	I2C1CFG.I2C_Mode = I2C_Mode_I2C;
	I2C1CFG.P_Slave_Event_CallBack = NULL;
	I2C1CFG.I2C_STRETCH_Mode = I2C_STRETCH_Mode_Enable;

	MCAL_I2C_GPIO_Set_PIN(I2C1);
	MCAL_I2C_INIT(I2C1, &I2C1CFG);

}


uint8_t EEPROM_Write_Nbytes(uint32_t MemoryAddress , uint8_t* Bytes , uint8_t DataLength)
{
	uint8_t i=0;

	uint8_t buffer[256];
	buffer[0] = (uint8_t)(MemoryAddress>>8); // upper byte of memory address
	buffer[1] = (uint8_t)(MemoryAddress);	 // lower byte of memory address

	for(i=2;i<(DataLength+2) ; i++)
	{
		buffer[i] = Bytes[i-2];
	}
	MCAL_I2C_Master_TX(I2C1, EEPROM_Slave_Address, buffer, (DataLength+2), With_STOP, Start);
	return 0;
}





uint8_t EEPROM_Read_Nbytes (uint32_t MemoryAddress , uint8_t* Bytes , uint8_t DataLength)
{


	uint8_t buffer[2];
	buffer[0] = (uint8_t)(MemoryAddress>>8); // upper byte of memory address
	buffer[1] = (uint8_t)(MemoryAddress);	 // lower byte of memory address

	MCAL_I2C_Master_TX(I2C1, EEPROM_Slave_Address, &buffer, 2, WithOut_STOP, Start);
	MCAL_I2C_Master_RX(I2C1, EEPROM_Slave_Address, Bytes, DataLength, With_STOP, repeated_Start);
	return 0;
}
