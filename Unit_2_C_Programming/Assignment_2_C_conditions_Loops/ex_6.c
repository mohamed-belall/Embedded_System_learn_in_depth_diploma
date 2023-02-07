/*
==================================================================
Name        : EX6: Write C Program to calculate Sum of Natural Numbers
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 2 C conditions Loops => EX 6
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    int number, i, sum = 0;
    printf("Enter an interger: ");
    scanf("%d", &number);

    for (i = 1; i <= number; i++)
    {
        sum += i;
    }

    printf("Sum = %d", sum);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}