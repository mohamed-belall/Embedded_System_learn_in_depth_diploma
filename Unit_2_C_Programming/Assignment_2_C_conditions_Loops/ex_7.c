/*
==================================================================
Name        : EX7: Write C Program to find factorial of a number
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 2 C conditions Loops => EX 7
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    int n, f = 1, i;
    printf("Enter an interger: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Error!!! Factorial of negative number doesn't exist.");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            f *= i;
        }
        printf("Facorial = %d", f);
    }

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}
