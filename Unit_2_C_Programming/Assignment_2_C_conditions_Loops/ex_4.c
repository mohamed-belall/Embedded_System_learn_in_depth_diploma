/*
==================================================================
Name        : EX4: Write C Program to check whether a Number is Positive or Negative
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 2 C conditions Loops => EX 4
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    float number;
    printf("Enter a numbers: ");
    scanf("%f", &number);

    if (number > 0)
        printf("%.2f is positive", number);
    else if (number < 0)
        printf("%.2f is negative", number);
    else
        printf("you entered zero");

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}