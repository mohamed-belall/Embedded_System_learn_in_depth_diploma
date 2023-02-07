/*
==================================================================
Name        : EX7: Write Source Code to Swap Two Numbers without temp variable.
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 1 C Basics => EX 7
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
    /* it is a common way that we use (+-) operator or (/*) operator to swap without temp variable */

    // mathod 1 by using +- operator
    a = a + b;
    b = a - b;
    a = a - b;

    // method 2 by using */ operator
    // a = a*b;
    // b = a/b;
    // a = a/b;

    printf("After swapping, value of a = %.2f\r\n", a);
    printf("After swapping, value of b = %.2f\r\n", b);

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}
