/*
 * Collision_Avoidance.c
 *
 *  Created on: Jul 7, 2023
 *      Author: moham
 */

#include "Collision_Avoidance.h"

//variable
int CA_speed     = 0;
int CA_distance  = 0;
int CA_threshold = 50;


// state pointer to function
void (*CA_state)();
int US_Get_distance_random(int min , int max , int count);


STATE_define(CA_waiting)
{
	// state_name
	CA_state_id = CA_waiting;

	// state_action
	CA_speed = 0;
	//DC_Motor(CA_speed)

	// state_checker
	//US_Get_distance(CA_distance)
	CA_distance = US_Get_distance_random(45,55,1);
	if(CA_distance <= CA_threshold)
		CA_state = STATE_calling(CA_waiting);
	else
		CA_state = STATE_calling(CA_driving);

	printf("CA_waiting State => (distance = %d) (Speed = %d) \n" ,CA_distance , CA_speed );

}

STATE_define(CA_driving)
{
	// state_name
	CA_state_id = CA_driving;

	// state_action
	CA_speed = 30;
	//DC_Motor(CA_speed)

	// state_checker
	//US_Get_distance(CA_distance)
	CA_distance = US_Get_distance_random(45,55,1);
	if(CA_distance <= CA_threshold)
		CA_state = STATE_calling(CA_waiting);
	else
		CA_state = STATE_calling(CA_driving);

	printf("CA_driving State => (distance = %d) (Speed = %d) \n" ,CA_distance , CA_speed );

}

int US_Get_distance_random(int min , int max , int count)
{
	// this code will generate random number in range  L and R
	int i ;
	for(i=0 ; i<count ; i++)
	{
		int rand_num = (rand() % (max-min+1) )+min;
		return rand_num;
	}
}
