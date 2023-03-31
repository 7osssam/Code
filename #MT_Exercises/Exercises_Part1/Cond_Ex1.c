/*
 ===================================================================================================
 Name        : Cond_Ex1.c
 Author      : Mohamed Tarek
 Description : Code to print the maximum number of three numbers.
 ===================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1, num2, num3;
    int max_num;
    printf("Please enter the three number to compare:");
    scanf("%d %d %d", &num1, &num2, &num3);

    /* Assume that the first number has the maximum value */
    max_num = num1;

    /* Compare the maximum value with the second number */
    if (num2 > max_num)
    {
        max_num = num2;
    }

    /* Compare the maximum value with the third number */
    if (num3 > max_num)
    {
        max_num = num3;
    }
    printf("\nThe maximum number is :%d", max_num);
    return 0;
}
