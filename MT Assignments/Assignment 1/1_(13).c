// (13) Write a program that reads a positive integer and checks if it is a prime.

#include <stdio.h>

int isPrime(int num)
{
    int flag = 1; // prime by default
    if (num == 0 || num == 1)
    {
        flag = 0;
    }
    for (int i = 0; i < num; i++)
    {
        if (num % i == 0 && num != 1) //
        {
            if (num == i) //
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
    }

    return flag;
}
int main()
{
    int num;
    scanf("%d", &num);

    if (isPrime(num))
    {
        printf("Prime");
    }
    else
    {
        printf("NOT Prime");
    }
}
