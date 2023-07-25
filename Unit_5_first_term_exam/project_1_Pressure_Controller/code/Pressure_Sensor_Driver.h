/**
 *****************************************************************************
 * @project        : Pressure_Controller_MohamedBelal
 * @file           : Pressure_Sensor_Driver.h
 * @author         : mohamed belal
 * @Created on     : Jul 19, 2023
 ******************************************************************************
 */

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_

#include "state.h"

// Define State
enum
{
    Pressure_Sensor_Driver_Reading,
    Pressure_Sensor_Driver_waiting,
}Pressure_Sensor_Driver_state_id;

// declare state function
void Pressure_Sensor_Driver_init();
STATE_Define(Pressure_Sensor_Driver_Reading);
STATE_Define(Pressure_Sensor_Driver_waiting);

// state pointer to function
extern void (*Pressure_Sensor_Driver_state)();

#endif /* PRESSURE_SENSOR_DRIVER_H_ */