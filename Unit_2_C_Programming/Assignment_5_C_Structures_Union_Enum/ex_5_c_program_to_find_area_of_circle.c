/*
 ==================================================================
 Name        : EX5: c_program_to_find_area_of_circle passing arguments to macros
 Author      : Mohamed Belal
 Created on  : 8/3/2023
 Description : Unit 2 C-Programming => Assignment 5 C Structure union Enum => EX 5
 ==================================================================
 */
#include <stdio.h>

#define PI 3.14
#define AREA(X) 2*PI*X

int main(void)
{
	int x;

	printf("Enter the radius: ");
	fflush(stdout); fflush(stdin);
	scanf("%d" , &x);

	printf("Area = %.2f", AREA(x));
	return 0;
}
