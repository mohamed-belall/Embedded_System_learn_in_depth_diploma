/*
 * main.c
 *
 *  Created on: Jul 7, 2023
 *      Author: moham
 */




#include <stdio.h>
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
	CA_state = STATE_calling(CA_waiting);

}

int main()
{

	volatile int d;
	setup();

	while(1)
	{
		// call state for each Block
		CA_state();

		//delay
		for(d=0 ; d <= 1000 ;d++);
	}


	return 0;
}
