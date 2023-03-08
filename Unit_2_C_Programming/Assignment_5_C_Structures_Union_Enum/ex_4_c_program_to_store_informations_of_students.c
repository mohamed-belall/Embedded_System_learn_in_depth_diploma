/*
 ==================================================================
 Name        : EX4: c_program_to_store_informations_of_students using structure
 Author      : Mohamed Belal
 Created on  : 8/3/2023
 Description : Unit 2 C-Programming => Assignment 5 C Structure union Enum => EX 4
 ==================================================================
 */
#include <stdio.h>

struct SStudent {
	char m_Name[50];
	int m_Roll;
	float m_Marks;
};

int main(void)
{
	int i;
	struct SStudent student[10];
	printf("Enter information of students: \n");

	for(i=0;i<10;i++)
	{
		student[i].m_Roll = i+1;
		printf("\nfor roll number %d \n",i+1);

		printf("Enter name: ");
		fflush(stdout); fflush(stdin);
		gets(student[i].m_Name);

		printf("Enter marks: ");
		fflush(stdout); fflush(stdin);
		scanf("%f", &student[i].m_Marks);
	}

	printf("\nDisplay Information of students \n");

	for(i=0;i<10;i++)
	{
		printf("\ninformation for roll number %d: \n",student[i].m_Roll);
		printf("name: %s\n", student[i].m_Name);
		printf("Marks: %.2f\n", student[i].m_Marks);
	}
	return 0;
}
