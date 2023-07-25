/**
 *****************************************************************************
 * @project        : Pressure_Controller_MohamedBelal
 * @file           : main_Algorithm.h
 * @author         : mohamed belal
 * @Created on     : Jul 19, 2023
 ******************************************************************************
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_
#include "state.h"

// Define State
enum
{
    Main_Algorithm_High_Pressure_Detect,
} Main_Algorithm_state_id;


// declare state function
STATE_Define(Main_Algorithm_High_Pressure_Detect);


// state pointer to function
extern void (*Main_Algorithm_state)();

#endif /* MAIN_ALGORITHM_H_ */