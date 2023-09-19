#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Macro for finding the maximum of two values
#define max(a, b) ((a) > (b) ? (a) : (b))
// Macro for finding the minimum of two values
#define min(a, b) ((a) < (b) ? (a) : (b))

// Function to calculate the maximum square of subarray values
long maxSubarrayValue(int n, int *arr)
{
	long MAX = 0;

	// Negate odd-indexed elements
	for (int i = 1; i < n; i += 2)
	{
		arr[i] = -arr[i];
	}

	long maxSoFar = arr[0];
	long currMax = arr[0];
	long currMin = arr[0];
	long minSoFar = arr[0];

	// Calculate maximum and minimum subarray values
	for (int i = 1; i < n; i++)
	{
		if (currMax < 0)
		{
			currMax = arr[i];
		}
		else
		{
			currMax = max(arr[i], currMax + arr[i]);
		}

		maxSoFar = max(maxSoFar, currMax);

		if (currMin > 0)
		{
			currMin = arr[i];
		}
		else
		{
			currMin += arr[i];
		}

		minSoFar = min(minSoFar, currMin);
	}

	long absMaxSoFar = abs(maxSoFar);
	long absMinSoFar = abs(minSoFar);
	MAX = absMaxSoFar > absMinSoFar ? absMaxSoFar : absMinSoFar;

	return MAX * MAX;
}

int main()
{
	int n;
	scanf("%d", &n);
	int *arr = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	long result = maxSubarrayValue(n, arr);
	printf("%ld\n", result);

	// Free dynamically allocated memory
	free(arr);

	return 0;
}
