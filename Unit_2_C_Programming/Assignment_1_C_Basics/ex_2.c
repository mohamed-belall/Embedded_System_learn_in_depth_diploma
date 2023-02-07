/*
==================================================================
Name        : EX2: Write C Program to Print a Integer Entered by a User
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 1 C Basics => EX 2
==================================================================
*/

#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("you entered: %d", number);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}