/*
==================================================================
Name        : EX3: Write C Program to find transpose of a matrix
Author      : Mohamed Belal
Created on  : 14/2/2023
Description : Unit 2 C-Programming => Assignment 3 C array & string => EX 3
==================================================================
*/
#include <stdio.h>

int main(void)
{
    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    int row, column, r, c;

    printf("Enter Rows then Colum of the matrix: ");
    scanf("%d%d", &row, &column);

    int a[row][column];
    int b[column][row];

    /* ========================== enter element of the matrix ========================== */
    printf("\nEnter elements of the matrix:\n");
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < column; c++)
        {
            printf("Enter element a%d%d: ", r + 1, c + 1);
            scanf("%d", &a[r][c]);
        }
    }

    /* ========================== printing element of the matrix ========================== */
    printf("\nEntered Matrix: \n");
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < column; c++)
        {
            printf("%d\t", a[r][c]);
        }
        printf("\n");
    }

    /* ========================== transpose element of the matrix ========================== */
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < column; c++)
        {
            b[c][r] = a[r][c];
        }
    }

    /* ==================== printing element of the matrix after transpose ================== */
    printf("\nTranspose of Matrix: \n");
    for (r = 0; r < column; r++)
    {
        for (c = 0; c < row; c++)
        {
            printf("%d  ", b[r][c]);
        }
        printf("\n");
    }

    printf("\n\n============ Console-output ============ \n\n"); // for a good view in terminal

    return 0;
}
