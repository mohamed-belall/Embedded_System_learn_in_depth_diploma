/*
==================================================================
Name        : EX1: Write C Program to check whether a Number is Even or Odd
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 2 C conditions Loops => EX 1
==================================================================
*/

#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    int num;

    printf("Enter an integer you want to check: ");
    scanf("%d", &num);

    if (num % 2 == 0)
        printf("%d is even.", num);
    else
        printf("%d is odd.", num);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}