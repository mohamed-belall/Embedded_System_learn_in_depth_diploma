/**
 *****************************************************************************
 * @project        : Pressure_Controller_MohamedBelal
 * @file           : Pressure_Sensor_Driver.c
 * @author         : mohamed belal
 * @Created on     : Jul 19, 2023
 ******************************************************************************
 */

#include "Pressure_Sensor_Driver.h"

static int Pressure_Value = 0;
unsigned int Pressure_Sensor_Pull_Time = 100;
void (*Pressure_Sensor_Driver_state)();

void Pressure_Sensor_Driver_init()
{
    // GPIO_INITIALIZATION();
}

STATE_Define(Pressure_Sensor_Driver_Reading)
{
    // state_name
    Pressure_Sensor_Driver_state_id = Pressure_Sensor_Driver_Reading;

    Pressure_Value = getPressureVal();
    Set_Pressure_Value(Pressure_Value);

    Pressure_Sensor_Driver_state = STATE_calling(Pressure_Sensor_Driver_waiting);
}

STATE_Define(Pressure_Sensor_Driver_waiting)
{
    // state_name
    Pressure_Sensor_Driver_state_id = Pressure_Sensor_Driver_waiting;

    Delay(60000);
    
    Pressure_Sensor_Driver_state = STATE_calling(Pressure_Sensor_Driver_Reading);
}
