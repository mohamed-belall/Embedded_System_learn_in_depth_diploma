/*
 ==================================================================
 Name        : q6 mid term 1 c function to return unique number in array with one loop
 Author      : Mohamed Belal
 Created on  : 2/3/2023
 Description : Unit 2 C-Programming => mid term 1 => q6
 ==================================================================
 */
#include <stdio.h>
#include <math.h>
int unique_number(int arr[] , int size);

int main(void) {

	int arr[] = {4,2,5,2,5,7,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("the unique number in array is %d ",unique_number(arr , size));
	return 0;
}

int unique_number(int arr[] , int size)
{
	int num =0 , i;
	for(i=0;i<size;i++)
	{
		num ^= arr[i];
	}

	return num;
}

