#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to sort integers in descending order
int compare(const void *x, const void *y)
{
	return *(const int *)y - *(const int *)x;
}

long long minTime(int files_count, int *files, int numCores, int limit)
{
	long long total = 0;
	int divisible_count = 0;
	int *divisible_files = malloc(files_count * sizeof(int));

	// Iterate through files to identify divisible files and calculate total time
	for (int i = 0; i < files_count; i++)
	{
		if (files[i] % numCores == 0)
		{
			divisible_files[divisible_count] = files[i];
			divisible_count++;
		}
		else
		{
			total += files[i];
		}
	}

	// Check if the limit exceeds the actual count of divisible files
	if (limit > divisible_count)
	{
		limit = divisible_count;
	}

	// Sort the divisible_files array in descending order
	qsort(divisible_files, divisible_count, sizeof(int), compare);

	// Calculate the total time considering the limit
	for (int i = 0; i < limit; i++)
	{
		total += divisible_files[i] / numCores;
	}

	free(divisible_files);

	return total;
}

int main()
{
	int files_count;
	scanf("%d", &files_count);

	int *files = malloc(files_count * sizeof(int));

	// Read the file sizes
	for (int i = 0; i < files_count; i++)
	{
		scanf("%d", &files[i]);
	}

	int numCores, limit;
	scanf("%d %d", &numCores, &limit);

	long long result = minTime(files_count, files, numCores, limit);

	printf("%lld\n", result);

	free(files);

	return 0;
}
