/*
==================================================================
Name        : EX3: Write C Program to Add Two Integers
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 1 C Basics => EX 3
==================================================================
*/

#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    int x, y;
    printf("Enter two integers: ");
    scanf("%d%d", &x, &y);
    printf("Sum: %d", x + y);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}