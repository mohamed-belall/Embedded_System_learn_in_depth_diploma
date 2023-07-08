/**
 *****************************************************************************
 * @project        : Collision_Avoidance_2 using multiple Modules
 * @file           : DC_Motor.h
 * @author         : mohamed belal
 * @Created on     : Jul 7, 2023
 ******************************************************************************
 */



#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"


enum{
	DC_idle,
	DC_busy
}DC_State_id;


//PROTOTYPE
void DC_init();
STATE_define(DC_idle);
STATE_define(DC_busy);

//global pointer to function
extern void (* DC_State)();

#endif /* DC_MOTOR_H_ */
