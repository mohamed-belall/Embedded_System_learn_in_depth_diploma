/*
 ==================================================================
 Name        : EX5: Write a program in C to show a pointer to an array which contents are pointer to structure
 Author      : Mohamed Belal
 Created on  : 22/3/2023
 Description : Unit 2 C-Programming => Assignment 6 C Pointers => EX 5
 ==================================================================
 */
#include <stdio.h>
#include <string.h>
struct SEmployee
{
	char m_Name[30];
	int m_ID;
};

int main(void)
{
	struct SEmployee employee[2] = {{"Alex" ,1002},{"mohamed" , 1003}};
	struct SEmployee* pSEmp = &employee ;


	printf("Employee Name : %s \n" , pSEmp->m_Name);
	printf("Employee ID : %d " , pSEmp->m_ID);


	return 0;
}

