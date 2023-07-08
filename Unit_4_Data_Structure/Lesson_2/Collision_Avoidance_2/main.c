/**
 *****************************************************************************
 * @project        : Collision_Avoidance_2 using multiple Modules
 * @file           : main.c
 * @author         : mohamed belal
 * @Created on     : Jul 7, 2023
 ******************************************************************************
 */

#include <stdio.h>
#include "ultrasonic_Sensor.h"
#include "DC_Motor.h"
#include "Collision_Avoidance.h"


void setup()
{
	/*
	 * 1 => init all the divers
	 * 2 => init IQR .....
	 * 3 => init HAL US_Driver DC_Motor_Driver
	 * 4 => init Block
	 * 5 => set states pointers for each Block
	 * */
	US_init();
	DC_init();

	US_State = STATE_calling(US_busy);
	CA_state = STATE_calling(CA_waiting);
	DC_State = STATE_calling(DC_idle);


}

int main()
{

	volatile int d;
	setup();

	while(1)
	{
		// call state for each Block
		US_State();
		CA_state();
		DC_State();
		//delay
		for(d=0 ; d <= 1000 ;d++);
	}


	return 0;
}
