/*
 ==================================================================
 Name        : EX2:Write a program in C to print all the alphabets using a pointer.
 Author      : Mohamed Belal
 Created on  : 22/3/2023
 Description : Unit 2 C-Programming => Assignment 6 C Pointers => EX 2
 ==================================================================
 */
#include <stdio.h>

int main(void) {
	char *pAlpha;
	char aAlpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	pAlpha = aAlpha;
	printf("Alphabets are: \n");

	for (; pAlpha < &aAlpha[sizeof(aAlpha)]; pAlpha++)
		printf("%c ", *pAlpha);

	return 0;
}

