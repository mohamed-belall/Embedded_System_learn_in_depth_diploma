/**
 *****************************************************************************
 * @project        : Pressure_Controller_MohamedBelal
 * @file           : main.c
 * @author         : mohamed belal
 * @Created on     : Jul 19, 2023
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "Pressure_Sensor_Driver.h"
#include "main_Algorithm.h"
#include "Alarm_Monitor.h"
#include "Alarm_Actuator_Driver.h"

void setup()
{
	/*
	 * 1 => init all the divers
	 * 2 => init iqr .....
	 * 3 => init hal us_driver dc_motor_driver
	 * 4 => init block
	 * 5 => set states pointers for each block
	 * */
	pressure_sensor_driver_init();
	alarm_actuator_driver_init();

	pressure_sensor_driver_state = state_calling(pressure_sensor_driver_reading);
	main_algorithm_state = set_pressure_value;
	alarm_monitor_state = state_calling(alarm_monitor_alarm_off);
	alarm_actuator_driver_state = state_calling(alarm_actuator_driver_waiting);
}

int main()
{

	GPIO_INITIALIZATION();
	setup();
	while (1)
	{
		Pressure_Sensor_Driver_state();
		Main_Algorithm_state();
		Alarm_Monitor_state();
		Alarm_Actuator_Driver_state();
	}
	return 0;
}
