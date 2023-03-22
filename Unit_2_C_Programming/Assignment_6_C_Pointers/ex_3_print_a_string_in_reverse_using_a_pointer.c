/*
 ==================================================================
 Name        : EX3: Write a program in C to print a string in reverse using a pointer
 Author      : Mohamed Belal
 Created on  : 22/3/2023
 Description : Unit 2 C-Programming => Assignment 6 C Pointers => EX 3
 ==================================================================
 */
#include <stdio.h>
#include <string.h>

int main(void) {
	int i;
	char aString[100];
	char *pString;

	printf("Input a string :");
	fflush(stdout);
	fflush(stdin);
	gets(aString);

	pString = &aString[strlen(aString) - 1];
	printf("Reverse of the string is : ");
	for (i = strlen(aString); i >= 0; i--, pString--)
		printf("%c", *pString);

	return 0;
}

