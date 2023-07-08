
/**
 *****************************************************************************
 * @project        : Collision_Avoidance_2 using multiple Modules
 * @file           : ultrasonic_Sensor.h
 * @author         : mohamed belal
 * @Created on     : Jul 7, 2023
 ******************************************************************************
 */

#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_


#include "state.h"

enum {
	US_busy
}US_State_id;


//prototype
void US_init();
STATE_define(US_busy);


//global pointer to function
extern void (*US_State)();


#endif /* ULTRASONIC_SENSOR_H_ */
