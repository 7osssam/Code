#include <stdio.h>
#include <stdlib.h>

int longestSubarray(int arr_count, int *arr)
{
	int x, y, max;
	x = y = max = 1;

	for (int i = 0; i < arr_count - 1; i++)
	{
		if (arr[i] == arr[i + 1]) // if array elements are equal
		{
			x++;
			y++;
		}
		else if (arr[i] - arr[i + 1] == -1)
		{
			x = y + 1;
			y = 1;
		}
		else if (arr[i] - arr[i + 1] == 1)
		{
			y = x + 1;
			x = 1;
		}
		else
		{
			x = y = 1;
		};

		if (x > max)
		{
			if (x > y)
			{
				max = x;
			}
			else
			{
				max = y;
			}
		}
		else
		{
			if (y > max)
			{
				max = y;
			}
		}
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
