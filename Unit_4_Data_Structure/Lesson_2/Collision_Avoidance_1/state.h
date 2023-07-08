/*
 * state.h
 *
 *  Created on: Jul 7, 2023
 *      Author: moham
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE_calling(_stateFUN_) ST_##_stateFUN_



#endif /* STATE_H_ */
