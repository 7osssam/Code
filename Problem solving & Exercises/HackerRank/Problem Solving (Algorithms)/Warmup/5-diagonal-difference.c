// ? https://www.hackerrank.com/challenges/diagonal-difference/problem
//
#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int n, int **arr)
{
    int sum = 0;
    for (int i = 0; i < n; i++) // loop through the array
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) // if the index of the array is equal to the index of the array
            {
                sum = sum + arr[i][j]; // add the element to the sum
            }
            if (i == n - j - 1) // n - j - 1 is the index of the array from the end
            {
                sum = sum - arr[i][j]; // subtract the element from the sum
            }
        }
    }
    return abs(sum); // return the absolute value of the sum
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
            //  scanf("%d", (*(arr + i) + j));
            scanf("%d", &arr[i][j]);
        }
    }

    int result = diagonalDifference(n, arr);

    printf("%d\n", result);

    for (int i = 0; i < n; i++)
    {
        // free(*(arr + i));
        free(arr[i]);
    }
    free(arr);

    return 0;
}
