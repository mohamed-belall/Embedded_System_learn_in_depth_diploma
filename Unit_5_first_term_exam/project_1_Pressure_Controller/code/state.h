/**
 *****************************************************************************
 * @project        : Pressure_Controller_MohamedBelal
 * @file           : state.h
 * @author         : mohamed belal
 * @Created on     : Jul 19, 2023
 ******************************************************************************
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>
#include "driver.h"

#define STATE_Define(_stateFUN_) void ST_##_stateFUN_()
#define STATE_calling(_stateFUN_) ST_##_stateFUN_

// state connection
//we use this for signal to connect eachblock with another
void Set_Pressure_Value(int Pressure_Val);
void High_Pressure_Detected();
void Stop_Alarm();
void Start_Alarm();

#endif /* STATE_H_ */
