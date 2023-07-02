
/**
 ******************************************************************************
 * @file           : fifo.c
 * @author         : mohamed belal
 * @Created on     : Jun 24, 2023
 ******************************************************************************
 */
#include "fifo.h"


FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo , element_type* buf , uint32_t length)
{
	if(fifo == NULL)
		return FIFO_null;

	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_no_error;

}

FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t* fifo , element_type item )
{
	// check null
	if(!fifo->head || !fifo->tail || !fifo->base)
		return FIFO_null;
	// check full
	if(fifo->count == fifo->length)
	{
		printf("fifo is full \n");
		return FIFO_full;
	}

	// enqueue
	if(!(fifo->count >= fifo->length)) // fifo no error and not full
	{
		*fifo->head = item;
		fifo->count++;

		//circular fifo
		if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
			fifo->head = fifo->base;
		else
			fifo->head++;

		return FIFO_no_error;
	}else
	{
		printf("fifo full \n");
		printf("fifo ENQUEUE FAILED \n");
		return FIFO_full;
	}

}


FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t* fifo , element_type* item )
{
	// check null
	if(!fifo->head || !fifo->tail || !fifo->base)
		return FIFO_null;
	// check empty
	if(fifo->count == 0)
	{
		printf("fifo is empty \n");
		return FIFO_empty;
	}

	// enqueue
		*item = *(fifo->tail);
		fifo->count--;
		//circular fifo
		if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
			fifo->tail = fifo->base;
		else
			fifo->tail++;

		return FIFO_no_error;

}
void FIFO_print(FIFO_Buf_t* fifo)
{
	element_type* temp;
	int i;
	if(fifo->count == 0)
	{
		printf("fifo is empty \n");
	}
	printf("\n =========================== \n");
	printf(" ========= FIFO print ====== ");
	printf("\n =========================== \n");
	temp = fifo->tail;
	for(i=0;i<fifo->count ;i++)
	{
		printf("\t %x \n" , *temp);
		temp++;
	}
	printf(" =========================== \n\n");


}
