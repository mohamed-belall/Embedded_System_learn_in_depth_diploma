
/**
 ******************************************************************************
 * @file           : lifo.c
 * @author         : mohamed belal
 * @Created on     : Jun 24, 2023
 ******************************************************************************
 */
#include "lifo.h"
#include <stdlib.h>


/* ========================  APIs ======================= */
LIFO_Status LIFO_Init(LIFO_Buf_t* LIFO_Buf ,unsigned int *buf , unsigned int size)
{
	if(buf == NULL)
		return LIFO_NULL;

	LIFO_Buf->base = buf;
	LIFO_Buf->head = buf;
	LIFO_Buf->length = size;
	LIFO_Buf->count = 0;
	return LIFO_NO_error;
}

LIFO_Status LIFO_Add_Item(LIFO_Buf_t* LIFO_Buf ,unsigned int item)
{
	// check lifo in valid
	if(!LIFO_Buf->base || !LIFO_Buf->head)
		return LIFO_NULL;

	// check lifo in fill
	if(LIFO_Buf->count == LIFO_Buf->length)
		return LIFO_Full;

	// add value
	*(LIFO_Buf->head) = item;
	LIFO_Buf->head++;
	LIFO_Buf->count++;
	return LIFO_NO_error;

}

LIFO_Status LIFO_get_top(LIFO_Buf_t* LIFO_Buf ,unsigned int* item)
{
	// check lifo is valid
	if(!LIFO_Buf->base || !LIFO_Buf->head)
		return LIFO_NULL;

	// check lifo is empty
	if(LIFO_Buf->count == 0)
		return LIFO_Empty;

	// pop item
	LIFO_Buf->head--;
	*item = *(LIFO_Buf->head);
	LIFO_Buf->head++;

	return LIFO_NO_error;
}

LIFO_Status LIFO_pop_top(LIFO_Buf_t* LIFO_Buf ,unsigned int * item)
{
	// check lifo is valid
	if(!LIFO_Buf->base || !LIFO_Buf->head)
		return LIFO_NULL;

	// check lifo is empty
	if(LIFO_Buf->count == 0)
		return LIFO_Empty;

	// pop item
	LIFO_Buf->head--;
	*item = *(LIFO_Buf->head);
	LIFO_Buf->count--;

	return LIFO_NO_error;


}
