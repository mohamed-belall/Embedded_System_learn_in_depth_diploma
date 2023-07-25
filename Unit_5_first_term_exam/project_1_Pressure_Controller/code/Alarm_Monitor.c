/**
 *****************************************************************************
 * @project        : Pressure_Controller_MohamedBelal
 * @file           : Alarm_Monitor.c
 * @author         : mohamed belal
 * @Created on     : Jul 19, 2023
 ******************************************************************************
 */

#include "Alarm_Monitor.h"
unsigned int Alarm_Periode = 600000;

void (*Alarm_Monitor_state)();

void High_Pressure_Detected()
{
    Alarm_Monitor_state = STATE_calling(Alarm_Monitor_alarm_on);
}

STATE_Define(Alarm_Monitor_alarm_off)
{
    Alarm_Monitor_state_id = Alarm_Monitor_alarm_off;

    Stop_Alarm();
    Alarm_Monitor_state = STATE_calling(Alarm_Monitor_alarm_off);
}

STATE_Define(Alarm_Monitor_alarm_on)
{
    Alarm_Monitor_state_id = Alarm_Monitor_alarm_on;

    Start_Alarm();
    Alarm_Monitor_state = STATE_calling(Alarm_Monitor_waiting);
}

STATE_Define(Alarm_Monitor_waiting)
{
    Alarm_Monitor_state_id = Alarm_Monitor_waiting;
    Stop_Alarm();
    Delay(Alarm_Periode);

    Alarm_Monitor_state = STATE_calling(Alarm_Monitor_alarm_off);
}
