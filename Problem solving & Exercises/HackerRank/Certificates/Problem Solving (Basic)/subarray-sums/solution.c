#include <stdio.h>

long *findSum(int numbers_count, int *numbers, int queries_rows, int queries_columns, int **queries, int *result_count)
{
	long *result = (long *)malloc(queries_rows * sizeof(long));

	long Sum[numbers_count + 1];	 // prefix sum
	long ZeroSum[numbers_count + 1]; // prefix sum of zeros
	Sum[0] = 0;
	ZeroSum[0] = 0;

	for (int i = 0; i < numbers_count; i++)
	{
		Sum[i + 1] = Sum[i] + numbers[i];

		// if the current number is zero, then increase the zero sum by 1
		ZeroSum[i + 1] = ZeroSum[i] + (numbers[i] == 0);
	}

	for (int i = 0; i < queries_rows; i++)
	{
		int l = queries[i][0]; // start
		int r = queries[i][1]; // end
		int x = queries[i][2]; // the x

		result[i] = Sum[r] - Sum[l - 1] + x * (ZeroSum[r] - ZeroSum[l - 1]);
	}

	*result_count = queries_rows;
	return result;
}

int main()
{
	int numbers_count;
	scanf("%d", &numbers_count);

	int *numbers = (int *)malloc(numbers_count * sizeof(int));
	for (int i = 0; i < numbers_count; i++)
	{
		scanf("%d", &numbers[i]);
	}

	int queries_count;
	scanf("%d", &queries_count);

	int **queries = (int **)malloc(queries_count * sizeof(int *));
	for (int i = 0; i < queries_count; i++)
	{
		queries[i] = (int *)malloc(3 * sizeof(int));
		scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
	}

	int result_count = 0;
	long *result = findSum(numbers_count, numbers, queries_count, 3, queries, &result_count);

	// Print the results
	for (int i = 0; i < result_count; i++)
	{
		printf("%ld\n", result[i]);
	}

	// Cleanup
	free(numbers);
	for (int i = 0; i < queries_count; i++)
	{
		free(queries[i]);
	}
	free(queries);
	free(result);

	return 0;
}