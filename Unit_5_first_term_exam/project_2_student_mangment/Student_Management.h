/**
 ******************************************************************************
 * @file           : Student_Management.h
 * @author         : mohamed belal
 * @Created on     : 22/7/2023
 ******************************************************************************
 */


#ifndef STUDENT_MANAGEMENT_H_
#define STUDENT_MANAGEMENT_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define DPRINTF(...)         \
	{                        \
		fflush(stdout);      \
		fflush(stdin);       \
		printf(__VA_ARGS__); \
		fflush(stdout);      \
		fflush(stdin);       \
	}


struct Sstudent_t
{
	char fName[50];
	char lName[50];
	int student_ID;
	float GPA;
	int course_ID[10];
};

typedef struct Sstudent_t Sstudent;

// FIFO data type
typedef struct
{
	int length;
	int count;
	Sstudent *base;
	Sstudent *head;
	Sstudent *tail;
} FIFO_Buf_t;

typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null,
} FIFO_Buf_Status;

Sstudent FIFO_Buffer[50];

// FIFO APIs
FIFO_Buf_Status FIFO_init(FIFO_Buf_t *fifo, Sstudent *buf, uint32_t length);
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t *fifo, Sstudent item);
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t *fifo, Sstudent *item);

// student database function
void Add_Student_Details_From_File(FIFO_Buf_t *studentQueue);
void Add_Student_Details_Manually(FIFO_Buf_t *studentQueue);
void Find_The_Student_By_The_Given_Roll_Number(FIFO_Buf_t *studentQueue);
void Find_The_Student_By_The_Given_First_Name(FIFO_Buf_t *studentQueue);
void Find_The_Students_Registered_In_Course(FIFO_Buf_t *studentQueue);
void Count_Of_Students(FIFO_Buf_t *studentQueue);
void Delete_A_Student(FIFO_Buf_t *studentQueue);
void Update_Student(FIFO_Buf_t *studentQueue);
void Show_Information(FIFO_Buf_t *studentQueue);


// another function
struct Sstudent_t* search_Student_by_ID(FIFO_Buf_t *studentQueue , int id);

#endif /* STUDENT_MANAGEMENT_H_ */
