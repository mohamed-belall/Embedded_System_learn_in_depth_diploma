/*
==================================================================
Name        : q2 mid term 1
Author      : Mohamed Belal
Created on  : 2/3/2023
Description : Unit 2 C-Programming => mid term 1 => q2
==================================================================
*/
#include <stdio.h>
#include <math.h>
double square_root(int number);
int main(void)
{
	int entered_number;

	printf("please enter the number: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d" , &entered_number);

	printf("the square root of (%d) is : %.3lf", entered_number,square_root(entered_number));
  return 0;
}

double square_root(int number)
{

	return sqrt(number);

}





