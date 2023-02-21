/*
==================================================================
Name        : EX1: prime Numbers between two intervals by making user defined
Author      : Mohamed Belal
Created on  : 21/2/2023
Description : Unit 2 C-Programming => Assignment 4 C Function => EX 1
==================================================================
*/
#include <stdio.h>

// function prototype
void primeNumber(int start, int end);

int main(void)
{


    int x, y;
    printf("Enter two numbers(intervals: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d %d", &x, &y);
    primeNumber(x, y);  // function call
    return 0;
}

//function Definition
void primeNumber(int start, int end)
{
    int i, j, count = 0;
    printf("prime number between %d and %d are: ",start,end);

    for (i = start; i <= end; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
            if (count > 2)
            {
                break;
            }
        }
        if (count == 2)  // prime number is a number greater than 1 whose only factors are 1 and itself
        {
            printf("%d ", i);
        }
        count = 0;
    }
}
