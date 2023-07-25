/**
 *****************************************************************************
 * @project        : Pressure_Controller_MohamedBelal
 * @file           : Alarm_Actuator_Driver.h
 * @author         : mohamed belal
 * @Created on     : Jul 19, 2023
 ******************************************************************************
 */

#ifndef ALARM_ACTUATOR_DRIVER_H_
#define ALARM_ACTUATOR_DRIVER_H_

#include "state.h"

// Define State
enum
{
    Alarm_Actuator_Driver_alarm_off,
    Alarm_Actuator_Driver_alarm_on,
    Alarm_Actuator_Driver_waiting,
} Alarm_Actuator_Driver_state_id;


// declare state function
void Alarm_Actuator_Driver_init();
STATE_Define(Alarm_Actuator_Driver_alarm_off);
STATE_Define(Alarm_Actuator_Driver_alarm_on);
STATE_Define(Alarm_Actuator_Driver_waiting);


// state pointer to function
extern void (*Alarm_Actuator_Driver_state)();

#endif /* ALARM_ACTUATOR_DRIVER_H_ */