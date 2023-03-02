/*
 ==================================================================
 Name        : q8 mid term 1 c function to take an array and reverse its element
 Author      : Mohamed Belal
 Created on  : 2/3/2023
 Description : Unit 2 C-Programming => mid term 1 => q8
 ==================================================================
 */
#include <stdio.h>
void reverse(int arr[] , int size);

int main(void) {

	int i, size=5;
	int x[] = {1,2,3,4,5};

	reverse(x, size);
	for(i=0;i<size;i++)
	{
		printf("%d ",x[i]);
	}
	return 0;
}

void reverse(int arr[] , int size)
{
	int i,j = size-1,temp[size];
	for(i=0;i<size;i++)
	{
		temp[j] = arr[i];
		j--;
	}
	for(i=0;i<size;i++)
	{
		arr[i] = temp[i];
	}
}

