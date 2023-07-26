/**
 ******************************************************************************
 * @file           : Student_Management.c
 * @author         : mohamed belal
 * @Created on     : 22/7/2023
 ******************************************************************************
 */

#include "Student_Management.h"


void Add_Student_Details_From_File(FIFO_Buf_t *studentQueue)
{
	FILE *fptr;
	Sstudent newStudent;
	int i;
	/* ======== check full ======== */
	if(studentQueue->count == studentQueue->length)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] Data Base is Full\n");
		DPRINTF("--------------------------------- \n");
		return;
	}
	/* ======== check initialization ======== */
	if(!studentQueue->base)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] Data Base is not Initialized\n");
		DPRINTF("--------------------------------- \n");
		return;
	}

	fptr = fopen("student_information.txt", "r");
	if (fptr == NULL)
	{
		DPRINTF("Error opening the file. \n");
		return;
	}

	while(!feof(fptr))
	{
		fscanf(fptr, "%d",&newStudent.student_ID);
		if(search_Student_by_ID(studentQueue , newStudent.student_ID))
		{
			DPRINTF("\n--------------------------------- \n");
			DPRINTF("[ERROR] ID number %d is already taken\n" , newStudent.student_ID);
			DPRINTF("--------------------------------- \n\n");
			// to skip this line
			fscanf(fptr, "%*[^\n]");
			continue;
		}
		fscanf(fptr, "%s",newStudent.fName);
		fscanf(fptr, "%s",newStudent.lName);
		fscanf(fptr, "%f",&newStudent.GPA);

		for(i=0;i<5;i++)
		{
			fscanf(fptr, "%d",&newStudent.course_ID[i]);
		}
		FIFO_enqueue(studentQueue ,newStudent );

		DPRINTF("\n[INFO]  ID number %d saved successfully \n" , newStudent.student_ID);

	}
	DPRINTF("\n\n\t\t\t\t------------------------------------------------------- \n");
	DPRINTF("\t\t\t\t\t[INFO]  the total number of Student is %d \n" , studentQueue->count);
	DPRINTF("\t\t\t\t\t[INFO]  you can add up to %d Students \n" , studentQueue->length);
	DPRINTF("\t\t\t\t\t[INFO]  you can add %d more Students \n" , studentQueue->length - studentQueue->count);
	DPRINTF("\t\t\t\t------------------------------------------------------- \n");

	// Close the file
	fclose(fptr);
}
void Add_Student_Details_Manually(FIFO_Buf_t *studentQueue)
{
	Sstudent newStudent;
	int i;
	/* ======== check full ======== */
	if(studentQueue->count == studentQueue->length)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] Data Base is Full\n");
		DPRINTF("--------------------------------- \n");
		return;
	}
	/* ======== check initialization ======== */
	if(!studentQueue->base)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] Data Base is not Initialized\n");
		DPRINTF("--------------------------------- \n");
		return;
	}
	DPRINTF("\t\t\t\t--------------------------------- \n");
	DPRINTF("\t\t\t\tAdd the Student Details \n");
	DPRINTF("\t\t\t\t--------------------------------- \n");

	DPRINTF("Enter the Student ID: ");
	scanf("%d",&newStudent.student_ID);

	if(search_Student_by_ID(studentQueue , newStudent.student_ID))
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] ID number %d is already taken\n" , newStudent.student_ID);
		DPRINTF("--------------------------------- \n");

	}else
	{
		DPRINTF("Enter the First Name of the Student: ");
		scanf("%s",newStudent.fName);

		DPRINTF("Enter the last Name of the Student: ");
		scanf("%s",newStudent.lName);

		DPRINTF("Enter the GPA of the Student: ");
		scanf("%f",&newStudent.GPA);

		DPRINTF("Enter the course ID of each course\n");
		for(i=0;i<5;i++)
		{

			DPRINTF("\t course %d ID: ",i+1);
			scanf("%d",&newStudent.course_ID[i]);
		}

		FIFO_enqueue(studentQueue ,newStudent );
		DPRINTF("\n[INFO]  ID number %d saved successfully \n" , newStudent.student_ID);

	}
	DPRINTF("\n\n\t\t\t\t------------------------------------------------------- \n");
	DPRINTF("\t\t\t\t\t[INFO]  the total number of Student is %d \n" , studentQueue->count);
	DPRINTF("\t\t\t\t\t[INFO]  you can add up to %d Students \n" , studentQueue->length);
	DPRINTF("\t\t\t\t\t[INFO]  you can add %d more Students \n" , studentQueue->length - studentQueue->count);
	DPRINTF("\t\t\t\t------------------------------------------------------- \n");


}
void Find_The_Student_By_The_Given_Roll_Number(FIFO_Buf_t *studentQueue)
{
	int input_ID , j;
	DPRINTF("Enter the ID number of the Student:");
	scanf("%d" , &input_ID);
	Sstudent* temp;
	temp = search_Student_by_ID(studentQueue , input_ID);
	if(!temp)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] ID number %d not Founded\n" , input_ID);
		DPRINTF("--------------------------------- \n");

	}else
	{
		DPRINTF("The Students Details are\n" );

		DPRINTF("--------------------------------- \n");

		DPRINTF("Student ID: %d \n" , temp->student_ID);
		DPRINTF("Student First Name: %s \n" , temp->fName);
		DPRINTF("Student Last Name: %s \n" , temp->lName);
		DPRINTF("Student GPA Number: %f \n" , temp->GPA);
		for(j=0;j<5;j++)
		{
			DPRINTF("the course ID are: %d \n" , temp->course_ID[j]);
		}
		DPRINTF("--------------------------------- \n");

	}

}
void Find_The_Student_By_The_Given_First_Name(FIFO_Buf_t *studentQueue)
{
	char input_name[40];
	int j , i , counter =0;
	Sstudent* temp;
	temp = studentQueue->tail;

	DPRINTF("Enter the first name of the Student:");
	gets(input_name);

	for(i=0;i<studentQueue->count;i++)
	{
		// if strcmp function == 0 this main that two string are same
		if(strcmp(temp->fName , input_name) == 0)
		{
			DPRINTF("--------------------------------- \n");
			DPRINTF("The Students Details are\n" );
			DPRINTF("Student ID: %d \n" , temp->student_ID);
			DPRINTF("Student First Name: %s \n" , temp->fName);
			DPRINTF("Student Last Name: %s \n" , temp->lName);
			DPRINTF("Student GPA Number: %f \n" , temp->GPA);
			for(j=0;j<5;j++)
			{
				DPRINTF("the course ID are: %d \n" , temp->course_ID[j]);
			}
			DPRINTF("--------------------------------- \n");
			counter++;
		}
		temp++;
	}
	if(!counter)
	{
		DPRINTF("\n--------------------------------- \n");
		DPRINTF("[ERROR] first name %s not Founded\n" , input_name);
		DPRINTF("--------------------------------- \n");
	}
}


void Find_The_Students_Registered_In_Course(FIFO_Buf_t *studentQueue)
{
	int input_course_id;
	int j , i, counter =0;
	Sstudent* temp = studentQueue->tail;

	DPRINTF("Enter the Course ID: ");
	scanf("%d" , &input_course_id);

	for(i=0;i<studentQueue->count;i++)
	{
		for(j=0;j<5;j++)
		{
			if(temp->course_ID[j] == input_course_id)
			{
				DPRINTF("--------------------------------- \n");
				DPRINTF("The Students Details are\n" );
				DPRINTF("Student ID: %d \n" , temp->student_ID);
				DPRINTF("Student First Name: %s \n" , temp->fName);
				DPRINTF("Student Last Name: %s \n" , temp->lName);
				DPRINTF("Student GPA Number: %f \n" , temp->GPA);
				counter++;
			}

		}
		temp++;
	}
	if(!counter)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] the course ID %d not Founded\n" , input_course_id);
		DPRINTF("--------------------------------- \n");
	}
}


void Count_Of_Students(FIFO_Buf_t *studentQueue)
{
	DPRINTF("\n\n\t\t\t\t------------------------------------------------------- \n");
	DPRINTF("\t\t\t\t\t[INFO]  the total number of Student is %d \n" , studentQueue->count);
	DPRINTF("\t\t\t\t\t[INFO]  you can add up to %d Students \n" , studentQueue->length);
	DPRINTF("\t\t\t\t\t[INFO]  you can add %d more Students \n" , studentQueue->length - studentQueue->count);
	DPRINTF("\t\t\t\t------------------------------------------------------- \n");
}


void Delete_A_Student(FIFO_Buf_t *studentQueue)
{
	int input_ID , j , flag=0;
	DPRINTF("Enter ID number which you want to delete: ");
	scanf("%d" , &input_ID);


	/* ======== check empty ======== */
	if(studentQueue->count ==0)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] Data Base is Empty\n");
		DPRINTF("--------------------------------- \n");
		return;
	}

	/* ======== check initialization ======== */
	if(!studentQueue->base)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] Data Base is not Initialized\n");
		DPRINTF("--------------------------------- \n");
		return;
	}

	Sstudent* pCurrent = studentQueue->tail;
	Sstudent* pnext = (studentQueue->tail)+1;
	Sstudent temp;

	/*
	 * 1. pcurrent = tail             pnext = tail+1
	 * 2. then check every id
	 * 3. if input_id != pcurrent->student_id
	 * 4.             pcurrent++               pnext++    to check next id
	 * 5. if input_id == pcurrent->student_id
	 * 6.             we want to make this id at the end of queue
	 * 7.             we uese a temp to swap current with next
	 * 8.			  flag = 1    to check if this id founded and deleted or not
	 * 9. pcurrent++             pnext++
	 * 10.   number of student in queue --            and         head -- to delete this id
	 * */
	for(j=0;j<studentQueue->count;j++)
	{
		if(pCurrent->student_ID == input_ID)
		{
			flag =1;
			temp = *pCurrent;
			*pCurrent = *pnext;
			*pnext = temp;

		}
		pCurrent++;
		pnext++;
	}

	if(flag)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[INFO] ID number %d is removed Successfully\n" , input_ID);
		DPRINTF("--------------------------------- \n");
		studentQueue->count--;
		studentQueue->head--;
	}else
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] ID number %d not Founded\n" , input_ID);
		DPRINTF("--------------------------------- \n");

	}
}
void Update_Student(FIFO_Buf_t *studentQueue)
{
	Sstudent* temp;
	int i , choice , inputID ,x , flag = 0;

	DPRINTF("Enter the Student ID to update the entry: ");
	scanf("%d",&inputID);

	temp = studentQueue->tail;
	for(i=0;i<studentQueue->count;i++)
	{
		if(temp->student_ID == inputID)
		{
			flag = 1;
			DPRINTF(" 1. first name \n 2. last name \n 3. ID \n 4. GPA \n 5. courses\n");
					scanf("%d" , &choice);

					switch (choice) {
					case 1:
						DPRINTF("Enter the New First Name of the Student: ");
						scanf("%s",temp->fName);
						break;
					case 2:
						DPRINTF("Enter the New last Name of the Student: ");
						scanf("%s",temp->lName);
						break;
					case 3:
						DPRINTF("Enter the New ID: ");
						scanf("%d",&x);
						while(search_Student_by_ID(studentQueue , x))
							{
								DPRINTF("\n\n--------------------------------- \n");
								DPRINTF("[ERROR] ID number %d is already taken\n" , x);
								DPRINTF("--------------------------------- \n");

								DPRINTF("Enter another New ID: ");
								scanf("%d",&x);
							}
						temp->student_ID =x;
						break;
					case 4:
						DPRINTF("Enter the New GPA of the Student: ");
						scanf("%f",&temp->GPA);
						break;
					case 5:
						DPRINTF("Enter the course ID of each course\n");
						for(i=0;i<5;i++)
						{
							DPRINTF("course %d ID: ",i+1);
							scanf("%d",&temp->course_ID[i]);
						}
						break;
					default:
						DPRINTF("Wrong option\n");
						break;
					}

					DPRINTF("\n\n--------------------------------- \n");
					DPRINTF("[INFO]  Updated successfully \n");
					DPRINTF("--------------------------------- \n");
					break;
		}
		temp++;
	}
	if(!flag)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] ID number %d not Founded\n" , inputID);
		DPRINTF("--------------------------------- \n");
	}
}


void Show_Information(FIFO_Buf_t *studentQueue)
{
	int i,j;
	Sstudent* temp;


	if(studentQueue->count ==0)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] Data Base is Empty\n");
		DPRINTF("--------------------------------- \n");
		return;
	}


	if(!studentQueue->base)
	{
		DPRINTF("\n\n--------------------------------- \n");
		DPRINTF("[ERROR] Data Base is not Initialized\n");
		DPRINTF("--------------------------------- \n");
		return;
	}


	temp = studentQueue->tail;
	for(i=0;i<studentQueue->count;i++)
	{
		DPRINTF("--------------------------------- \n");

		DPRINTF("Student ID: %d \n" , temp->student_ID);
		DPRINTF("Student First Name: %s \n" , temp->fName);
		DPRINTF("Student Last Name: %s \n" , temp->lName);
		DPRINTF("Student GPA Number: %f \n" , temp->GPA);
		for(j=0;j<5;j++)
		{
			DPRINTF("the course ID are: %d \n" , temp->course_ID[j]);
		}
		DPRINTF("--------------------------------- \n");
		temp++;
	}


	DPRINTF("\n\n\t\t\t\t------------------------------------------------------- \n");
	DPRINTF("\t\t\t\t\t[INFO]  the total number of Student is %d \n" , studentQueue->count);
	DPRINTF("\t\t\t\t\t[INFO]  you can add up to %d Students \n" , studentQueue->length);
	DPRINTF("\t\t\t\t\t[INFO]  you can add %d more Students \n" , studentQueue->length - studentQueue->count);
	DPRINTF("\t\t\t\t------------------------------------------------------- \n");
}


struct Sstudent_t* search_Student_by_ID(FIFO_Buf_t *studentQueue , int id)
{
	int i;
	Sstudent* temp;
	temp = studentQueue->tail;
	for(i=0;i<studentQueue->count;i++)
	{
		if(temp->student_ID == id)
		{
			return temp;
		}
		temp++;
	}
	temp = NULL;
	return temp;
}




FIFO_Buf_Status FIFO_init(FIFO_Buf_t *fifo, Sstudent *buf, uint32_t length)
{
	if (fifo == NULL)
		return FIFO_null;

	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_no_error;
}

FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t *fifo, Sstudent item)
{
	// check null
	if (!fifo->head || !fifo->tail || !fifo->base)
		return FIFO_null;
	// check full
	if (fifo->count == fifo->length)
	{
		printf("fifo is full \n");
		return FIFO_full;
	}

	// enqueue
	if (!(fifo->count >= fifo->length)) // fifo no error and not full
	{
		*fifo->head = item;
		fifo->count++;

		// circular fifo
		if (fifo->head == (fifo->base + (fifo->length * sizeof(Sstudent))))
			fifo->head = fifo->base;
		else
			fifo->head++;

		return FIFO_no_error;
	}
	else
	{
		printf("fifo full \n");
		printf("fifo ENQUEUE FAILED \n");
		return FIFO_full;
	}
}

FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t *fifo, Sstudent *item)
{
	// check null
	if (!fifo->head || !fifo->tail || !fifo->base)
		return FIFO_null;
	// check empty
	if (fifo->count == 0)
	{
		printf("fifo is empty \n");
		return FIFO_empty;
	}

	// enqueue
	*item = *(fifo->tail);
	fifo->count--;
	// circular fifo
	if (fifo->tail == (fifo->base + (fifo->length * sizeof(Sstudent))))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return FIFO_no_error;
}


