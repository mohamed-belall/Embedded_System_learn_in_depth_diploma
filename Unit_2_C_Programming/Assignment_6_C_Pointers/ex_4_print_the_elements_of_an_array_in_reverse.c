/*
 ==================================================================
 Name        : EX4: Write a program in C to print the elements of an array in reverse order
 Author      : Mohamed Belal
 Created on  : 22/3/2023
 Description : Unit 2 C-Programming => Assignment 6 C Pointers => EX 4
 ==================================================================
 */
#include <stdio.h>

int main(void) {
	int n, i;
	int *pArr;
	int arr[15];

	printf("input the number of elements to store in the array (max 15): ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &n);

	printf("input %d number of elements in the array: \n", n);
	for (i = 0; i < n; i++) {
		printf("\nelement - %d : ", i + 1);
		fflush(stdout);
		fflush(stdin);
		scanf("%d", &arr[i]);
	}

	pArr = &arr[n - 1];
	printf("the element of the array in reverse order are : ");
	for (i = n - 1; i >= 0; i--, pArr--) {
		printf("\nelement - %d : %d", i + 1, *pArr);

	}

	return 0;
}

