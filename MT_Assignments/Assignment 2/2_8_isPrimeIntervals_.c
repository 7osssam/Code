// 8 - Write a C Function that display Prime Numbers between Intervals (two numbers) by Making Function

#include <stdio.h>
#include <math.h>

// void isPrimeIntervals(int low, int high) //! using only one function
// {
//     int isPrime;
//     for (int num = low; num <= high; num++)
//     {
//         isPrime = 1;  // prime by default
//         if (num == 2) // 2 is prime // the only even prime number
//         {
//             printf("%d\n", num);
//             continue; // skip the rest of the loop and go to the next iteration
//         }
//         if (num == 0 || num == 1 || num % 2 == 0) // 0 and 1 are not prime and all even numbers are not prime except 2
//             continue;                             // skip the rest of the loop and go to the next iteration
//         // i = i + 2 to skip even numbers since all even numbers are not prime except 2
//         for (int i = 3; i <= num / 2; i = i + 2) // i <= sqrt(num)
//         {
//             if (num % i == 0) // if num is divisible by i
//             {
//                 isPrime = 0;
//                 break;
//             }
//         }
//         if (isPrime == 1) // if isPrime still 1 after the loop
//         {
//             printf("%d\n", num);
//         }
//     }
// }

int isPrime(int num) // optimized function to check if num is prime
{

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
    for (int i = 3; i <= sqrt(num); i = i + 2) // alternatively, we can use i <= num / 2
    {
        if (num % i == 0)
        {
            return 0; // not prime
        }
    }
    return 1; // prime
}

void isPrimeIntervals(int low, int high) // using 2 functions
{
    for (int num = low; num <= high; num++)
    {
        if (isPrime(num)) // if isPrime returns 1
        {
            printf("%d\n", num); // then it is prime
        }
    }
}

int main()
{
    int num1, num2; // 1 - 15   // 1 2 3 5 7 11 13
    printf("Enter 2 numbers : ");
    scanf("%d%d", &num1, &num2);

    printf("The Prime numbers between %d and %d :\n", num1, num2);

    isPrimeIntervals(num1, num2);

    return 0;
}