/*
 ? Link: https://www.hackerrank.com/challenges/diagonal-difference/problem
 * Difficulty: Easy
 * Name: Diagonal Difference
 *
 * Tags: Algorithms, Warmup
 *
 * Summary:
 * sum of 2D array elements, diagonal difference
 */
#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int arr_rows, int arr_columns, int **arr)
{
	int right = 0;
	int left = 0;
	// int sum = 0;
	for (int i = 0; i < arr_rows; i++)
	{
		for (int j = 0; j < arr_columns; j++)
		{
			if (i == j)
			{
				// sum = sum + arr[i][j];
				right = right + arr[i][j];
			}
			if (i + j == arr_rows - 1)
			{
				// sum = sum - arr[i][j];
				left = left + arr[i][j];
			}
		}
	}
	return (abs(right - left));
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

	int result = diagonalDifference(n, n, arr);

	printf("%d\n", result);

	for (int i = 0; i < n; i++)
	{
		// free(*(arr + i));
		free(arr[i]);
	}
	free(arr);

	return 0;
}
