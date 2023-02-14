/*
==================================================================
Name        : EX4: Write C Program to insert an element in an array
Author      : Mohamed Belal
Created on  : 14/2/2023
Description : Unit 2 C-Programming => Assignment 3 C array & string => EX 4
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    int n, ielement, location;

    printf("Enter the mo of elements: ");
    scanf("%d", &n);
    printf("\n");

    int a[n], i;
    int b[n + 1], j;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n");

    printf("the element to be inserted : ");
    scanf("%d", &ielement);
    printf("\n");

    printf("enter the location : ");
    scanf("%d", &location);
    printf("\n");

    i = 0;
    j = 0;
    while (i < n)
    {
        if (j + 1 != location)
        {
            b[j] = a[i];
            j++;
            i++;
        }
        else
        {
            b[j] = ielement;
            j++;
        }
    }

    for (j = 0; j < n + 1; j++)
    {
        printf("%d ", b[j]);
    }

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}
