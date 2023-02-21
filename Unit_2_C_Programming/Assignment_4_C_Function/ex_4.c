/*
 ==================================================================
 Name        : EX4: c program to calculate the power of a Number using Recursion
 Author      : Mohamed Belal
 Created on  : 21/2/2023
 Description : Unit 2 C-Programming => Assignment 4 C Function => EX 4
 ==================================================================
 */
#include <stdio.h>

int power_of_number(int ba, int po);

int main(void) {
	int base, power;

	printf("Enter base number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &base);

	do
	{
	printf("Enter power Number(Positive Number): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &power);
	}while(power<0);

	printf("%d ^ %d = %d", base, power, power_of_number(base, power));

	return 0;
}

int power_of_number(int ba, int po) {
	if (po > 1)
		return ba * power_of_number(ba, --po);
	else if(po ==0) // any number power 0 = 1
		return 1;
	else
		return ba;
}
