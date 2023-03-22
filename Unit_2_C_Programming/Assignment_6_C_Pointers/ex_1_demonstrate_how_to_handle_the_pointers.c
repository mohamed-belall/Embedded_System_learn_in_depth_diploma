/*
 ==================================================================
 Name        : EX1:Write a program in C to demonstrate how to handle the pointers in the program
 Author      : Mohamed Belal
 Created on  : 22/3/2023
 Description : Unit 2 C-Programming => Assignment 6 C Pointers => EX 1
 ==================================================================
 */
#include <stdio.h>

int main(void) {
	int m = 29;

	printf("Address of m : 0x%p\n", &m);
	printf("Value of m : %d\n", m);
	int *ab = &m;
	printf("\nNow ab is assigned with the address of m: \n\n");

	printf("Address of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n", *ab);

	printf("\nthe value of m assigned to 34 now: \n\n");
	m = 34;
	printf("Address of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n", *ab);

	printf("\nthe pointer variable ab is assigned with the value 7 now:\n\n");
	*ab = 7;
	printf("Address of m : 0x%p\n", &m);
	printf("Value of m : %d\n", m);

	return 0;
}

