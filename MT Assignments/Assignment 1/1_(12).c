// (12) Write a program that reads a positive integer and computes the factorial.

#include <stdio.h>

int fact(int num)
{
    int factorial = 1;
    for (int i = 1; i <= num; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}

int main()
{
    int num;
    printf("Enter num:");
    scanf("%d", &num);

    printf("factorial = %d", fact(num));

    return 0;
}