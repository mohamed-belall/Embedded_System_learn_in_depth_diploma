/*
 ==================================================================
 Name        : q4 mid term 1 c function to reverse digits in number
 Author      : Mohamed Belal
 Created on  : 2/3/2023
 Description : Unit 2 C-Programming => mid term 1 => q4
 ==================================================================
 */
#include <stdio.h>
#include <math.h>
int reversed_digit(int number);

int main(void) {
	int num1;

	printf("please enter the 1st number: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &num1);

	printf("the reversed digit in number %d is %d ",num1,reversed_digit(num1));
	return 0;
}

int reversed_digit(int number)
{
	int reversedNum =0;
	int i=0;
	while(number != 0)
	{
		reversedNum = reversedNum * 10 + number % 10;
		number /= 10;
		i++;
	}
	return reversedNum;
}

