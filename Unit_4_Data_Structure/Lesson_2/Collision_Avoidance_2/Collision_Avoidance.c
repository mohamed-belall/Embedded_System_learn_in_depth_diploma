
/**
 *****************************************************************************
 * @project        : Collision_Avoidance_2 using multiple Modules
 * @file           : Collision_Avoidance.c
 * @author         : mohamed belal
 * @Created on     : Jul 7, 2023
 ******************************************************************************
 */

#include "Collision_Avoidance.h"

//variable
int CA_speed     = 0;
int CA_distance  = 0;
int CA_threshold = 50;


// state pointer to function
void (*CA_state)();

void US_Set_distance(int d)
{
	CA_distance = d;
	if(CA_distance <= CA_threshold)
		CA_state = STATE_calling(CA_waiting);
	else
		CA_state = STATE_calling(CA_driving);

	printf(" US =================== distance=%d ===================> CA\n" ,CA_distance );
}



STATE_define(CA_waiting)
{
	// state_name
	CA_state_id = CA_waiting;
	printf("CA_waiting State => (distance = %d) (Speed = %d) \n" ,CA_distance , CA_speed );

	// state_action
	CA_speed = 0;
	DC_Motor(CA_speed);

}

STATE_define(CA_driving)
{
	// state_name
	CA_state_id = CA_driving;
	printf("CA_driving State => (distance = %d) (Speed = %d) \n" ,CA_distance , CA_speed );
	// state_action
	CA_speed = 30;
	DC_Motor(CA_speed);
}

