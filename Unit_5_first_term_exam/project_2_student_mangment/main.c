
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Belal
 * @Created on     : 22/7/2023
 ******************************************************************************
 */

#include "Student_Management.h"

int main()
{

	FIFO_Buf_t mainBuffer;
	FIFO_init(&mainBuffer, FIFO_Buffer, 50);

	DPRINTF("===============================================\n");
	DPRINTF("=================INIT COMPLETE=================\n");
	DPRINTF("===============================================\n");

	DPRINTF("\n ========================================================= \n");
	DPRINTF(" ======== Welcome to the student management system =======");
	DPRINTF("\n ========================================================= \n");
	char temp[40];

	while (1)
	{
		DPRINTF("\n\n\n##################################################### \n");
		DPRINTF("###### choose the task that you want to perform #####");
		DPRINTF("\n##################################################### \n");
		DPRINTF("\n 01: Add Student Details Manually.");
		DPRINTF("\n 02: Add Student Details From File.");
		DPRINTF("\n 03: Find the student by the given Roll Number.");
		DPRINTF("\n 04: Find the student by the given First Name.");
		DPRINTF("\n 05: Find the students registered in a course ID.");
		DPRINTF("\n 06: Find the Total Number of Students");
		DPRINTF("\n 07: Delete the Student Details by Roll Number.");
		DPRINTF("\n 08: Update the Student Details by Roll Number.");
		DPRINTF("\n 09: Show all Information.");
		DPRINTF("\n 10: To Exit.");
		DPRINTF("\n\t\t\t -------------------------------");
		DPRINTF("\n Enter Option Number: ");
		gets(temp);
		DPRINTF("\n#####################################################");
		DPRINTF("\n##################################################### \n\n\n");

		switch (atoi(temp))
		{
		case 1:
			Add_Student_Details_Manually(&mainBuffer);
			break;
		case 2:
			Add_Student_Details_From_File(&mainBuffer);
			break;
		case 3:
			Find_The_Student_By_The_Given_Roll_Number(&mainBuffer);
			break;
		case 4:
			Find_The_Student_By_The_Given_First_Name(&mainBuffer);
			break;
		case 5:
			Find_The_Students_Registered_In_Course(&mainBuffer);
			break;
		case 6:
			Count_Of_Students(&mainBuffer);
			break;
		case 7:
			Delete_A_Student(&mainBuffer);
			break;
		case 8:
			Update_Student(&mainBuffer);
			break;
		case 9:
			Show_Information(&mainBuffer);
			break;
		case 10:
			return 0;
			break;
		default:
			DPRINTF("\n wrong option ");
			break;
		}
	}

	return 0;
}

