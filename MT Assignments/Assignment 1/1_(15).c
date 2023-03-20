// (15) Write a program to calculate the power of a number. The number and its power are input from user.

#include <stdio.h>

int Power(int num, int power)
{
    int res = 1;
    for (int i = 1; i <= power; i++)
    {
        res = res * num; // res *= num;
    }

    return res;
}
int main()
{
    int num, po;
    printf("Enter the number then the power");
    scanf("%d%d", &num, &po);

    printf("%d power %d is = %d", num, po, Power(num, po));
}
