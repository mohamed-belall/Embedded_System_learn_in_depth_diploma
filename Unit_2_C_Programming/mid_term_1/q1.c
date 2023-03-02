/*
==================================================================
Name        : q1 mid term 1
Author      : Mohamed Belal
Created on  : 2/3/2023
Description : Unit 2 C-Programming => mid term 1 => q1
==================================================================
*/
#include <stdio.h>
int sum_digits_of_number(int number);
int main(void)
{
	int entered_number;

	printf("please enter the number: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d" , &entered_number);

	printf("the sum of the digits is : %d",sum_digits_of_number(entered_number));
  return 0;
}

int sum_digits_of_number(int number)
{
	int sum =0;
	if(number != 0)
	{
		sum =  number % 10;
		return sum + sum_digits_of_number(number/10);
	}
	return 0;

}





