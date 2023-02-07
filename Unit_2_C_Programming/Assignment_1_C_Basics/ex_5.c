/*
==================================================================
Name        : EX5: Write C Program to Find ASCII Value of a Character
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 1 C Basics => EX 5
==================================================================
*/

#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    printf("ASCII value if %c = %d", c, c);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}