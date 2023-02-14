/*
==================================================================
Name        : EX6 s1: Write C Program to find the frequency of characters in a string
Author      : Mohamed Belal
Created on  : 14/2/2023
Description : Unit 2 C-Programming => Assignment 3 C array & string => EX 6 s1
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    char eString[100];
    char character;
    int i, frequancy = 0;

    printf("Enter a string : ");
    gets(eString);

    printf("\nEnter a character to find frequency: ");
    scanf("%c", &character);

    for (i = 0; eString[i] != 0; i++)
    {
        if (eString[i] == character)
        {
            frequancy += 1;
        }
    }
    printf("\nFrequency of %c = %d", character, frequancy);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}
