/*
==================================================================
Name        : EX2: c program to calculate factorial of a number using recursion
Author      : Mohamed Belal
Created on  : 21/2/2023
Description : Unit 2 C-Programming => Assignment 4 C Function => EX 2
==================================================================
*/
#include <stdio.h>

int factorial(int n); // function prototype

int main(void)
{
	int num;
	do // to check if the user enter negative number ask him to enter another number
	{
		printf("Enter an positive integer: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&num);
	}while(num<=0);


	printf("factorial of %d = %d",num,factorial(num));
    return 0;
}

int factorial(int n) //function Definition
{
	if(n==1)
		return 1;
	else
		return n * factorial(n-1);
}
