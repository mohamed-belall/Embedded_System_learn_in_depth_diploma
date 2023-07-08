
/**
 *****************************************************************************
 * @project        : Collision_Avoidance_2 using multiple Modules
 * @file           : ultrasonic_Sensor.c
 * @author         : mohamed belal
 * @Created on     : Jul 7, 2023
 ******************************************************************************
 */

#include "ultrasonic_Sensor.h"


unsigned int US_distance;
void (*US_State)();
int US_Get_distance_random(int min , int max , int count);


void US_init()
{
	// init US Sensor
	//call us sensor driver & functions
	printf("DC_Init\n");

}

STATE_define(US_busy)
{

		// state_name
		US_State_id = US_busy;

		// state_action
		US_distance = US_Get_distance_random(45,55,1);

		printf("US_busy state => distance=%d \n" , US_distance);
		US_Set_distance(US_distance);
		US_State = STATE_calling(US_busy);
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
