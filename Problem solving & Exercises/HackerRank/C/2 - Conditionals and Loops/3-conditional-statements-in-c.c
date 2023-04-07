//? hackerRank.com/challenges/conditional-statements-in-c/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    int mod, sum = 0;
    scanf("%d", &n);
    // for (int i = 0; i < 5; i++)
    // {
    //     mod = n % 10;
    //     n = n / 10;
    //     sum += mod;
    // }

    while (n > 0)
    {
        mod = n % 10; // getting the last digit
        n = n / 10;   // removing the last digit
        sum += mod;   // adding the last digit to the sum
    }
    printf("%d", sum);

    return 0;
}
