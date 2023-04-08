//? https://www.hackerrank.com/challenges/compare-the-triplets/problem
#include <stdio.h>

int main()
{
    int a[3], b[3], result[2] = {0};

    for (int i = 0; i < 3; i++) // scan the array a
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 3; i++) // scan the array b
    {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < 3; i++) // compare the arrays
    {
        if (a[i] > b[i])
        {
            result[0] += 1; // result[0] is Alice's score
        }
        else if (a[i] < b[i])
        {
            result[1] += 1; // result[1] is Bob's score
        }
    }
    printf("%d %d\n", result[0], result[1]); // print the result
    return 0;
}
