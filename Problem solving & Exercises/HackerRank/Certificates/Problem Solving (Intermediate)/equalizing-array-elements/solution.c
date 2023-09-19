#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting
int compare(const void *a, const void *b)
{
	return *(const int *)a - *(const int *)b;
}

// Function to calculate the minimum operations needed
int minOperations(int arr_count, int *arr, int threshold, int d)
{
	int dp[200001][2] = {0};
	// Sort the array in ascending order
	qsort(arr, arr_count, sizeof(int), compare);

	int minOperations = INT_MAX;

	for (int i = 0; i < arr_count; i++)
	{
		int steps = 0;

		while (1)
		{
			int currentValue = arr[i];
			dp[currentValue][0] += 1;
			dp[currentValue][1] += steps;

			// Check if the threshold is met, and update minOperations if necessary
			if (dp[currentValue][0] >= threshold)
			{
				minOperations = (minOperations <= dp[currentValue][1]) ? minOperations : dp[currentValue][1];
			}

			if (currentValue == 0)
			{
				break;
			}

			arr[i] /= d; // Divide the current value by d
			steps += 1;
		}
	}
	return minOperations;
}

int main()
{
	int n;
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int threshold, d;
	scanf("%d %d", &threshold, &d);

	int result = minOperations(n, arr, threshold, d);
	printf("%d\n", result);

	return 0;
}
