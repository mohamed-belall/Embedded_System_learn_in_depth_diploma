/**
 *****************************************************************************
 * @project        : Collision_Avoidance_2 using multiple Modules
 * @file           : DC_Motor.c
 * @author         : mohamed belal
 * @Created on     : Jul 7, 2023
 ******************************************************************************
 */


#include "DC_Motor.h"

unsigned int DC_speed;
void (* DC_State)();


void DC_init()
{
	// init DC_motor
	printf("DC_init\n");
}

void DC_Motor(int s)
{
	DC_speed = s;
	DC_State = STATE_calling(DC_busy);

	// state action
	// call PWM to make speed = DC_speed
	printf(" CA =================== speed=%d ===================> DC\n" ,DC_speed );

}

STATE_define(DC_idle)
{
	DC_State_id = DC_idle;
	DC_State = STATE_calling(DC_idle);
	printf("DC_Idle state => speed=%d \n\n\n" , DC_speed);
}

STATE_define(DC_busy)
{
	DC_State_id = DC_busy;
	DC_State = STATE_calling(DC_busy);
	printf("DC_busy state => speed=%d \n\n\n" , DC_speed);
}
