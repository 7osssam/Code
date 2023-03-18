// of the following are equivalent ways of accessing the array elements
//*(arr + i); scanf("%d", arr + i);   | printf("%d", *(arr + i));
//  *(i + arr); scanf("%d", i + arr);  | printf("%d", *(i + arr));
//  arr[i]; scanf("%d", arr[i]);       | printf("%d", arr[i]);
//  i[arr]; scanf("%d", i[arr]);       | printf("%d", i[arr]);

#include <stdio.h>
#include <stdlib.h>

int isPrime(int num)
{
    int flag = 1;             // prime by default
    if (num == 0 || num == 1) // 0 and 1 are not prime numbers
        flag = 0;             // not prime
    // For example: 2, 3, 5, 7, 11, 13, 17 are prime numbers

    for (size_t i = 2; i <= num / 2; i++)
    {
        if (num % i == 0) // if the number is divisible by any number other than 1 and itself then it is not prime
        {
            flag = 0; // not prime
            break;
        }
    }
    return flag; // return 1 if prime else 0
}