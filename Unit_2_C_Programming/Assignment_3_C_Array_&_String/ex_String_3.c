/*
==================================================================
Name        : EX8 s3: Write C Program to reverse string
Author      : Mohamed Belal
Created on  : 14/2/2023
Description : Unit 2 C-Programming => Assignment 3 C array & string => EX8 s3
==================================================================
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    char eString[100], reverse[100];
    int i, j;

    printf("Enter the string  : ");
    gets(eString);

    j = 0;
    i = strlen(eString) - 1;
    while (i >= 0)
    {
        reverse[j] = eString[i];
        j++;
        i--;
    }
    reverse[j] = 0;

    printf("\nreverse string is : %s", reverse);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}
