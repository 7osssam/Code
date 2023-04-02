/*
 ============================================================================
 Name        : Func_Ex8.c
 Author      : Mohamed Tarek
 Description : Factorial using Recursive method
 ============================================================================
 */

#include <stdio.h>

int factorial(int n);

int main(void)
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("\nFactorial of %d = %d", n, factorial(n));
    return 0;
}

int factorial(int n)
{
    if (n > 1)
        return n * factorial(n-1);
    else
        return 1;
}
