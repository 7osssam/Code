#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is a power of two
bool isPowerOfTwo(int n)
{
	return (n != 0) && ((n & (n - 1)) == 0);
}

// Function to calculate the sum of integers from 1 to n
long sumOfSortedArray(int n)
{
	return ((long)n * (n + 1)) / 2;
}

// Function to count the number of pairs with a bitwise AND that is a power of two
long countPairs(int arr_count, int *arr)
{
	int freqDictSize = 4096; // Size of the frequency dictionary for numbers up to 2^12
	int *freqDict = (int *)calloc(freqDictSize, sizeof(int));

	// Count the frequency of each element in the array
	for (int i = 0; i < arr_count; i++)
		freqDict[arr[i]]++;

	long counterOfPairs = 0;

	// Iterate through the frequency dictionary to count pairs
	for (int i = 0; i < freqDictSize; i++)
	{
		if (freqDict[i] == 0)
			continue;

		for (int j = i; j < freqDictSize; j++)
		{
			if (freqDict[j] == 0)
				continue;

			if (isPowerOfTwo(i & j))
			{
				if (i == j)
					counterOfPairs += sumOfSortedArray(freqDict[i] - 1);
				else
					counterOfPairs += freqDict[i] * freqDict[j];
			}
		}
	}

	free(freqDict); // Free the dynamically allocated memory for the frequency dictionary
	return counterOfPairs;
}

int main()
{
	int arr_count;

	// Get the number of elements in the array from the user
	scanf("%d", &arr_count);

	// Dynamically allocate memory for the array
	int *arr = (int *)malloc(arr_count * sizeof(int));

	// Get the elements of the array from the user
	for (int i = 0; i < arr_count; i++)
	{
		scanf("%d", &arr[i]);
	}

	long result = countPairs(arr_count, arr);

	printf("%ld\n", result);

	free(arr); // Free the dynamically allocated memory for the array

	return 0;
}
