// (6) Write a program that print the relation between two
// integer number if those numbers are equal, not equal and
// which one contain the higher value.

#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter two numbers:");
    scanf("%d%d", &num1, &num2);

    if (num1 > num2) // if num1 is greater than num2
    {
        printf("Not equal and %d is higher", num1);
    }
    else if (num2 > num1) // if num2 is greater than num1
    {
        printf("Not equal and %d is higher", num2);
    }
    else // if num1 is equal to num2
    {
        printf("Equal");
    }

    return 0;
}