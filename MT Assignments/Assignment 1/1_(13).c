// (13) Write a program that reads a positive integer and checks if it is a prime.

#include <stdio.h>

int isPrime(int num)
{

    int flag = 1; // prime by default

    if (num == 0 || num == 1) // 0 and 1 are not prime
        flag = 0;             // not prime

    // num /2 is the largest number that can divide num
    for (int i = 2; i <= num / 2; i++) // check if num is divisible by any number from 2 to num/2
    {
        if (num % i == 0)
        {
            flag = 0; // not prime
        }
    }
    return flag;
}

int main()
{
    // prime numbers are 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61 ...etc
    int num;
    printf("Enter Positive Integer:");
    scanf("%d", &num);

    if (isPrime(num)) // if isPrime returns 1
    {
        printf("Prime"); // then it is prime
    }
    else
    {
        printf("NOT Prime"); // else it is not prime
    }
}
