/*
==================================================================
Name        : EX8: Write C Program to Make a Simple Calculator to + , - , * , / using switch
Author      : Mohamed Belal
Created on  : 7/2/2023
Description : Unit 2 C-Programming => Assignment 2 C conditions Loops => EX 8
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    char operator;
    float n1, n2;
    printf("Enter operator either + or - or * or / : ");
    scanf("%c", &operator);
    printf("Enter Two operands : ");
    scanf("%f%f", &n1, &n2);

    switch (operator)
    {
    case '*':
        printf("%.1f %c %.1f = %.1f", n1, operator, n2, n1 * n2);
        break;
    case '+':
        printf("%.1f %c %.1f = %.1f", n1, operator, n2, n1 + n2);
        break;
    case '-':
        printf("%.1f %c %.1f = %.1f", n1, operator, n2, n1 - n2);
        break;
    case '/':
        printf("%.1f %c %.1f = %.1f", n1, operator, n2, n1 / n2);
        break;
    default:
        printf("you enter wrong operator");
        break;
    }

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}