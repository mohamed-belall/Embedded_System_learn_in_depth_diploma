
/**
 *****************************************************************************
 * @project        : Collision_Avoidance_2 using multiple Modules
 * @file           : Collision_Avoidance.h
 * @author         : mohamed belal
 * @Created on     : Jul 7, 2023
 ******************************************************************************
 */

#ifndef COLLISION_AVOIDANCE_H_
#define COLLISION_AVOIDANCE_H_
#include "state.h"

//Define State
enum{
	CA_waiting,
	CA_driving
}CA_state_id;


//declare states function CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

// state pointer to function
extern	void (*CA_state)();

#endif /* COLLISION_AVOIDANCE_H_ */
