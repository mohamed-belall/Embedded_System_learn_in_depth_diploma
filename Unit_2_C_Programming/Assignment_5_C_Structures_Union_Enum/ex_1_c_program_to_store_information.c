/*
 ==================================================================
 Name        : EX1: C program to store information (name , roll , marks) of student using structure
 Author      : Mohamed Belal
 Created on  : 8/3/2023
 Description : Unit 2 C-Programming => Assignment 5 C Structure union Enum => EX 1
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
	struct SStudent student1;
	printf("Enter information of students: \n \n");

	printf("Enter name: ");
	fflush(stdout); fflush(stdin);
	gets(student1.m_Name);

	printf("Enter roll number: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &student1.m_Roll);

	printf("Enter marks: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &student1.m_Marks);

	printf("\nDisplay Information \n");

	printf("name: %s\n", student1.m_Name);
	printf("Roll: %d\n", student1.m_Roll);
	printf("Marks: %.2f\n", student1.m_Marks);

	return 0;
}

