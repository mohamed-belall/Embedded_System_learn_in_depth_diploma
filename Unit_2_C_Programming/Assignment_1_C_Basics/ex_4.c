/*
==================================================================
Name        : EX4: Write C Program to Multiply two Floating Point Numbers
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 1 C Basics => EX 4
==================================================================
*/

#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    float x, y;
    printf("Enter two number: ");
    scanf("%f%f", &x, &y);
    printf("product: %f", x * y);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}