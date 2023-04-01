/*
 ===================================================================================================
 Name        : Operators_Ex3.c
 Author      : Mohamed Tarek
 Description : Code to demonstrate the capability of the Logical operators
 ===================================================================================================
 */

#include <stdio.h>

int main()
{
    int num1 = 30;
    int num2 = 40;

    if (num1 >= 40 || num2 >= 40)
        printf("Or If Block Gets Executed\n");

    if (num1 >= 40 && num2 >= 40)
        printf("And If Block Gets Executed\n");

    if (!(num1 >= 40))
        printf("Not If Block Gets Executed\n");

    return (0);
}
