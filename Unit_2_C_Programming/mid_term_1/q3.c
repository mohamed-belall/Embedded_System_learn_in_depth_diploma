/*
 ==================================================================
 Name        : q3 mid term 1
 Author      : Mohamed Belal
 Created on  : 2/3/2023
 Description : Unit 2 C-Programming => mid term 1 => q3
 ==================================================================
 */
#include <stdio.h>
#include <math.h>
void prime(int n1, int n2);
int main(void) {
	int num1, num2;

	printf("please enter the 1st number: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &num1);

	printf("please enter the 2nd number: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &num2);

	prime(num1, num2);
	return 0;
}

void prime(int n1, int n2) {

	int i, j, flag = 0;
	for (i = n1; i <= n2; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i % j == 0)
				flag++;

			if (flag > 2)
				break;
		}

		if (flag < 3)
			printf(" %d ", i);

		flag = 0;
	}
}

