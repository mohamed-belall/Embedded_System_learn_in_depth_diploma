
/**
 ******************************************************************************
 * @file           : lifo.h
 * @author         : mohamed belal
 * @Created on     : Jun 24, 2023
 ******************************************************************************
 */

#ifndef LIFO_H_
#define LIFO_H_

/* ==================  type definitions ================== */
typedef struct {
	unsigned int *base;
	unsigned int *head ;
	unsigned int length;
	unsigned int count;
}LIFO_Buf_t;

typedef enum{
	LIFO_NO_error,
	LIFO_Empty,
	LIFO_Full,
	LIFO_NULL,
}LIFO_Status;

/* ========================  APIs ======================= */
LIFO_Status LIFO_Init(LIFO_Buf_t* LIFO_Buf ,unsigned int *buf, unsigned int size);
LIFO_Status LIFO_Add_Item(LIFO_Buf_t* LIFO_Buf ,unsigned int item);
LIFO_Status LIFO_get_top(LIFO_Buf_t* LIFO_Buf ,unsigned int* item);
LIFO_Status LIFO_pop_top(LIFO_Buf_t* LIFO_Buf ,unsigned int * item);


#endif /* LIFO_H_ */
