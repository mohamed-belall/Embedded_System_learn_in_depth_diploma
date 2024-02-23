/*
 * EEPROM.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Mohamed Belal
 */

#ifndef INCLUDES_EEPROM_H_
#define INCLUDES_EEPROM_H_

#include "STM32F103C6_I2C_Driver.h"

/*
 * E2PROM is an I2C slave
 * idle Mode			   : device is in a high impedance state and wait for data
 * master transmitter mode : the device transmit data to slave receiver
 * master receiver mode    : the device receive data from slave transmitter
 * */

#define EEPROM_Slave_Address	0x2A

void EEPROM_Init(void);
uint8_t EEPROM_Write_Nbytes(uint32_t MemoryAddress , uint8_t* Bytes , uint8_t DataLength);
uint8_t EEPROM_Read_Nbytes (uint32_t MemoryAddress , uint8_t* Bytes , uint8_t DataLength);

#endif /* INCLUDES_EEPROM_H_ */
