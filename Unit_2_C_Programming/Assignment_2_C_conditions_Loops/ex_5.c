/*
==================================================================
Name        : EX5: Write C Program to check whether a character is an alphabet or not
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 2 C conditions Loops => EX 5
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    char s;
    printf("Enter a character: ");
    scanf("%c", &s);

    if ((s > 'a' && s < 'z') || (s > 'A' && s < 'Z'))
    {
        printf("%c is an alphabet", s);
    }
    else
    {
        printf("%c is not an alphabet", s);
    }

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}