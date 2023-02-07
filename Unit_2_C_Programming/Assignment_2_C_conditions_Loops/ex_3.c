/*
==================================================================
Name        : EX3: Write C Program to find the largest Number Among Three Numbers
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 2 C conditions Loops => EX 3
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    float x, y, z, largest;

    printf("Enter three numbers: ");
    scanf("%f%f%f", &x, &y, &z);

    if (x > y && x > z)
    {
        largest = x;
    }
    else if (y > x && y > z)
    {
        largest = y;
    }
    else if (z > x && z > y)
    {
        largest = z;
    }

    printf("Largest number = %.2f", largest);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}