/*
 ==================================================================
 Name        : q10 mid term 1 count the max number of ones between two zeros
 Author      : Mohamed Belal
 Created on  : 2/3/2023
 Description : Unit 2 C-Programming => mid term 1 => q10
 ==================================================================
 */
#include <stdio.h>
int max_ones(int);

int main(void) {
	int number = 110;
	printf("%d" ,max_ones(number));
	return 0;
}

int max_ones(int number)
{
	int count =0 , max=0;
	while( number != 0)
	{
		if(number % 2 == 0)
		{
			if (count > max)
			{
				max = count;
			}
			count =0;
		}else
		{
			count++;
		}
		number /=2;
	}
	return max;
}

