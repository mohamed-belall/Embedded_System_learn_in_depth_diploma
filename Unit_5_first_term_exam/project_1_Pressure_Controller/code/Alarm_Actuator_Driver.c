/**
 *****************************************************************************
 * @project        : Pressure_Controller_MohamedBelal
 * @file           : Alarm_Actuator_Driver.c
 * @author         : mohamed belal
 * @Created on     : Jul 19, 2023
 ******************************************************************************
 */

#include "Alarm_Actuator_Driver.h"
void (*Alarm_Actuator_Driver_state)();

void Stop_Alarm()
{

    Alarm_Actuator_Driver_state = STATE_calling(Alarm_Actuator_Driver_alarm_off);
}

void Start_Alarm()
{

    Alarm_Actuator_Driver_state = STATE_calling(Alarm_Actuator_Driver_alarm_on);
}

// declare state function
void Alarm_Actuator_Driver_init()
{
    // GPIO_INITIALIZATION();
}

STATE_Define(Alarm_Actuator_Driver_waiting)
{
    Alarm_Actuator_Driver_state_id = Alarm_Actuator_Driver_waiting;

    Alarm_Actuator_Driver_state = STATE_calling(Alarm_Actuator_Driver_waiting);
}

STATE_Define(Alarm_Actuator_Driver_alarm_off)
{
    Alarm_Actuator_Driver_state_id = Alarm_Actuator_Driver_alarm_off;

    // we send (1) beacase of we connect led with power 
    // then to reset the led we send (1) as (5 volte) and another bolarty is (5 volte) this main that (0 volte)  turn off led
    Set_Alarm_actuator(1);
    Alarm_Actuator_Driver_state = STATE_calling(Alarm_Actuator_Driver_waiting);
}

STATE_Define(Alarm_Actuator_Driver_alarm_on)
{
    Alarm_Actuator_Driver_state_id = Alarm_Actuator_Driver_alarm_on;

    // we send (0) beacase of we connect led with power 
    // then to set the led we send (0) as (0 volte) and another bolarty is (5 volte) this main that (5 volte)  turn off led
    Set_Alarm_actuator(0);
    Alarm_Actuator_Driver_state = STATE_calling(Alarm_Actuator_Driver_waiting);
}
