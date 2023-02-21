/*
 ==================================================================
 Name        : EX3: c program to Reverse a Sentence Using Recursion
 Author      : Mohamed Belal
 Created on  : 21/2/2023
 Description : Unit 2 C-Programming => Assignment 4 C Function => EX 3
 ==================================================================
 */
#include <stdio.h>

void reversedSentence(void);

int main(void) {
	printf("Enter a Sentence: ");
	fflush(stdin);
	fflush(stdout);

	reversedSentence();

	return 0;
}

void reversedSentence(void) {

	char ch;
	scanf("%c", &ch);

	if (ch != '\n') {
		reversedSentence();
		printf("%c", ch);
	}
}
