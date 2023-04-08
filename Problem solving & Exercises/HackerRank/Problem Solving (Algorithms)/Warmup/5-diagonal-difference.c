// ? https://www.hackerrank.com/challenges/diagonal-difference/problem
#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int n, int **arr)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum = sum + arr[i][j];
            }
            if (i == n - j - 1)
            {
                sum = sum - arr[i][j];
            }
        }
    }
    return abs(sum);
}

int main()
{
    int n;
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", (*(arr + i) + j));
        }
    }

    int result = diagonalDifference(n, arr);

    printf("%d\n", result);

    for (int i = 0; i < n; i++)
    {
        free(*(arr + i));
    }
    free(arr);

    return 0;
}
