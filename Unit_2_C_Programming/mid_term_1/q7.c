/*
 ==================================================================
 Name        : q7 mid term 1 c function to sum numbers from 1 to 100 without loop
 Author      : Mohamed Belal
 Created on  : 2/3/2023
 Description : Unit 2 C-Programming => mid term 1 => q7
 ==================================================================
 */
#include <stdio.h>
int sum(int);

int main(void) {
	printf("the sum of number from 1 to 100 is %d ", sum(100));
	return 0;
}

int sum(int number)
{
	return number * (number+1) / 2 ;
}

