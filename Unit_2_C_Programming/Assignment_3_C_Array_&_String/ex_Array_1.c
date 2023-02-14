/*
==================================================================
Name        : EX1: Write C Program to find sum of two matrix 2*2 Multidimensional Array in c
Author      : Mohamed Belal
Created on  : 14/2/2023
Description : Unit 2 C-Programming => Assignment 3 C array & string => EX 1
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    int i, j;
    float a[2][2];
    float b[2][2];

    printf("Enter the elements of 1st matrix\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter a%d%d: ", i + 1, j + 1);
            fflush(stdout);
            fflush(stdin);
            scanf("%f", &a[i][j]);
        }
    }

    printf("\nEnter the elements of 2nd matrix\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter b%d%d: ", i + 1, j + 1);
            fflush(stdout);
            fflush(stdin);
            scanf("%f", &b[i][j]);
        }
    }

    printf("\nSum of Matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%.1f\t", a[i][j] + b[i][j]);
        }
        printf("\n");
    }

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}
