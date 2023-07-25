/**
 *****************************************************************************
 * @project        : Pressure_Controller_MohamedBelal
 * @file           : Alarm_Monitor.h
 * @author         : mohamed belal
 * @Created on     : Jul 19, 2023
 ******************************************************************************
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"

// Define State
enum
{
    Alarm_Monitor_alarm_off,
    Alarm_Monitor_alarm_on,
    Alarm_Monitor_waiting,
} Alarm_Monitor_state_id;



// declare state function
STATE_Define(Alarm_Monitor_alarm_off);
STATE_Define(Alarm_Monitor_alarm_on);
STATE_Define(Alarm_Monitor_waiting);



// state pointer to function
extern void (*Alarm_Monitor_state)();

#endif /* ALARM_MONITOR_H_ */