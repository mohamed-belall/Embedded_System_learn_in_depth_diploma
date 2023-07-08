/**
 *****************************************************************************
 * @project        : Collision_Avoidance_2 using multiple Modules
 * @file           : state.h
 * @author         : mohamed belal
 * @Created on     : Jul 7, 2023
 ******************************************************************************
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE_calling(_stateFUN_) ST_##_stateFUN_



// state connection
void US_Set_distance(int d);
void DC_Motor(int s);



#endif /* STATE_H_ */
