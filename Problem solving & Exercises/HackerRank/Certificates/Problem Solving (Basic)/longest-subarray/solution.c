#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestSubarray(int arr_count, int *arr)
{
	int max = 1;
	int x = 1, y = 1;

	for (int i = 0; i < arr_count - 1; i++)
	{
		if (arr[i] == arr[i + 1]) // Equal
		{
			x++;
			y++;
		}
		else if (arr[i] - arr[i + 1] == -1) // Consecutive
		{
			x = y + 1;
			y = 1;
		}
		else if (arr[i] - arr[i + 1] == 1) // Non-consecutive
		{
			y = x + 1;
			x = 1;
		}
		else
		{
			x = 1;
			y = 1;
		}

		max = MAX(max, MAX(x, y));
	}

	return max;
}

int main()
{
	int arr_count;
	scanf("%d", &arr_count);

	int *arr = (int *)malloc(arr_count * sizeof(int));
	for (int i = 0; i < arr_count; i++)
	{
		scanf("%d", &arr[i]);
	}

	int result = longestSubarray(arr_count, arr);
	printf("%d\n", result);

	free(arr);
	return 0;
}
