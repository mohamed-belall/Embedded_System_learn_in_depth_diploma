/*
==================================================================
Name        : EX5: Write C Program to search an element in array
Author      : Mohamed Belal
Created on  : 14/2/2023
Description : Unit 2 C-Programming => Assignment 3 C array & string => EX 5
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    int n, i, sElement, fLocation;

    printf("Enter the mo of elements: ");
    scanf("%d", &n);
    printf("\n");
    int a[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n");

    printf("the element to be searched : ");
    scanf("%d", &sElement);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        if (a[i] == sElement)
        {
            printf("Number found at the location = %d", i + 1);
            break;
        }
        if (i == n - 1)
        {
            printf("number not found");
        }
    }
    printf("\n");

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}
