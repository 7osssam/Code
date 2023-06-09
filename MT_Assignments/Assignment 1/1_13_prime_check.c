// (13) Write a program that reads a positive integer and checks if it is a prime.

// a prime number is a number that is divisible only by 1 and itself.
// For example, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61 ...etc

// 1 & 0 are not a prime number
// all even numbers are not a prime number except 2
// then we need to check if odd numbers only

#include <stdio.h>
#include <math.h>

int isPrime(int num) // optimized function to check if num is prime
{
    int i;
    if (num == 2) // 2 is prime //! the only even prime number
    {
        return 1; // prime
    }

    if (num == 0 || num == 1 || num % 2 == 0) // 0 and 1 are not prime and all even numbers are not prime except 2
    {
        return 0; // not prime
    }

    // i = i + 2 to skip even numbers since all even numbers are not prime except 2
    // sqrt(num) is the square root of num
    for (i = 3; i <= sqrt(num); i = i + 2) // alternatively, we can use i <= num / 2
    {
        if (num % i == 0)
        {
            return 0; // not prime
        }
    }
    return 1;
}

int main()
{
    int num;
    do
    {
        printf("Enter a postive number num:");
        scanf("%d", &num);
    } while (num < 0); // if num is negative (true), then loop again

    if (isPrime(num)) // if isPrime returns 1
    {
        printf("Prime"); // then it is prime
    }
    else
    {
        printf("NOT Prime"); // else it is not prime
    }
}
