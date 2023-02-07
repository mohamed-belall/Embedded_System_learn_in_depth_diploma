/*
==================================================================
Name        : EX2: Write C Program to check Volwel or Consonant
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 2 C conditions Loops => EX 2
==================================================================
*/

#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    char s;

    printf("Enter an alphabet: ");
    scanf("%c", &s);

    switch (s)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        printf("%c is a vowel", s);
        break;
    default:
        printf("%c is a consonant", s);
        break;
    }

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}