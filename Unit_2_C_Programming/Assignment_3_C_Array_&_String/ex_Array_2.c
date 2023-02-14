/*
==================================================================
Name        : EX2: Write C Program to calculate Average using arrays
Author      : Mohamed Belal
Created on  : 14/2/2023
Description : Unit 2 C-Programming => Assignment 3 C array & string => EX 2
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    int n, i;
    float sum = 0.0;

    printf("Enter the number of data: ");
    scanf("%d", &n);

    float numbers[n];
    for (i = 0; i < n; i++)
    {
        printf("%d. Enter number: ", i + 1);
        scanf("%f", &numbers[i]);
    }

    for (i = 0; i < n; i++)
    {
        sum += numbers[i];
    }

    printf("Average = %.2f", sum / n);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}
