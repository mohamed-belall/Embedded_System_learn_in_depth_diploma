/*
==================================================================
Name        : EX7 s2: Write C Program to find length of a string
Author      : Mohamed Belal
Created on  : 14/2/2023
Description : Unit 2 C-Programming => Assignment 3 C array & string => EX 7 s2
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    char eString[100];
    int i, length = 0;

    printf("Enter a string : ");
    gets(eString);

    for (i = 0; eString[i] != 0; i++)
    {
        length += 1;
    }
    
    printf("\nLength of string : %d", length);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}
