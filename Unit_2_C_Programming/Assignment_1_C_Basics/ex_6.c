/*
==================================================================
Name        : EX6: Write Source Code to Swap Two Numbers
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 1 C Basics => EX 6
==================================================================
*/

#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    float a, b, temp;

    printf("Enter value of a: ");
    scanf("%f", &a);
    printf("Enter value of b: ");
    scanf("%f", &b);

    // swapping
    temp = a;
    a = b;
    b = temp;

    printf("After swapping, value of a = %.2f\r\n", a);
    printf("After swapping, value of b = %.2f\r\n", b);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}