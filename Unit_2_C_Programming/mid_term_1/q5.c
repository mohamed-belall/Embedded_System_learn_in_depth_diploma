/*
 ==================================================================
 Name        : q5 mid term 1 c function to count number of ones in binary number
 Author      : Mohamed Belal
 Created on  : 2/3/2023
 Description : Unit 2 C-Programming => mid term 1 => q5
 ==================================================================
 */
#include <stdio.h>
#include <math.h>
int ones_in_number(int number);

int main(void) {

	int num1;

	printf("please enter number: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &num1);

	printf("the number of ones in %d is %d ",num1,ones_in_number(num1));
	return 0;
}

int ones_in_number(int number)
{
	int num_Of_Ones =0;

	while(number != 0)
	{
		if(number % 2 == 1)
			num_Of_Ones++;

		number /=2;
	}
	return num_Of_Ones;
}

