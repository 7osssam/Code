//? https://hackerRank.com/challenges/bitwise-operators-in-c/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k)
{

    int maxAnd = 0, maxOr = 0, maxXor = 0;

    for (int i = 1; i <= n; i++) // n is the limit of the integers
    {
        for (int j = i + 1; j <= n; j++) // j is the second integer to compare with i
        {                                // j = i + 1 to avoid comparing the same integers twice (i.e. 1 & 1, 2 & 2, etc.)
            if ((i & j) > maxAnd && (i & j) < k)
                maxAnd = i & j;
            if ((i | j) > maxOr && (i | j) < k)
                maxOr = i | j;
            if ((i ^ j) > maxXor && (i ^ j) < k)
                maxXor = i ^ j;
        }
    }
    printf("%d\n%d\n%d", maxAnd, maxOr, maxXor);
}

int main()
{
    int n, k; // n is the number of integers, k is the maximum value of the integers

    scanf("%d %d", &n, &k);

    calculate_the_maximum(n, k);

    return 0;
}
