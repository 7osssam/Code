// (15) Write a program to calculate the power of a number. The number and its power are input from user.

#include <stdio.h>

int Power(int num, int power)
{
    int result = 1; // initial value of result is 1

    while (power != 0)
    {
        result *= num; // multiply the result by the number

        power--; // decrement the power
    }

    return result; // return the result
}
int main()
{
    int num, po;
    printf("Enter the number & the power:");
    scanf("%d%d", &num, &po);

    printf("%d power %d is = %d", num, po, Power(num, po));
}
