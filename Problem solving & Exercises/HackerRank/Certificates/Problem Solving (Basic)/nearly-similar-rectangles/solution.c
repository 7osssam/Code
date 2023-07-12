#include <stdio.h>
#include <stdlib.h>

// --------------------------------------  O(n log n)  Using Quick sort  ---------------------------------------------------//

long gcd(long a, long b) // Greatest Common Divisor Function
{
	return b > 0 ? gcd(b, a % b) : a;
}

int compare(const long long *a, const long long *b) // Compare Function To Sort 2D Array
{
	return (*a - *b) ? (*a - *b) : (*(a + 1) - *(b + 1));
};

long nearlySimilarRectangles(int sides_rows, int sides_columns, long long **sides)
{
	long arr[sides_rows][2];

	for (int i = 0; i < sides_rows; i++)
	{
		long z = gcd(sides[i][0], sides[i][1]);
		arr[i][0] = sides[i][0] / z;
		arr[i][1] = sides[i][1] / z;
	}

	qsort(arr, sides_rows, sizeof(arr[0]), compare);

	long count = 1;
	long sum = 0;
	long acc = 0;

	for (int i = 0; i < sides_rows - 1; i++)
	{
		if (arr[i][0] == arr[i + 1][0] && arr[i][1] == arr[i + 1][1])
		{
			count++;
			acc = ((count * (count - 1)) / 2); // n(n-1)/2
			continue;
		}
		sum += acc;
		count = 1;
		acc = 0;
	}
	sum += acc;

	return sum;
};

long nearlySimilarRectangles2(int sides_rows, int sides_columns, long long **sides)
{
	long long count = 0;

	for (int i = 0; i < sides_rows - 1; i++)
	{
		for (int j = i + 1; j < sides_rows; j++)
		{
			if (sides[i][0] * sides[j][1] == sides[i][1] * sides[j][0])
			{
				count++;
			}
		}
	}

	return count;
};

int main()
{
	int sides_rows, sides_columns;
	long long **sides;

	// Get the number of rows from the user
	scanf("%d", &sides_rows);

	// Get the number of columns from the user
	scanf("%d", &sides_columns);

	// Allocate memory for the 2D array
	sides = (long **)malloc(sides_rows * sizeof(long *));
	for (int i = 0; i < sides_rows; i++)
	{
		sides[i] = (long *)malloc(sides_columns * sizeof(long));
	}

	// Get the pairs of elements from the user
	for (int i = 0; i < sides_rows; i++)
	{
		for (int j = 0; j < sides_columns; j++)
		{
			scanf("%lld", &sides[i][j]);
		}
	}

	// Call the nearlySimilarRectangles function
	long count = nearlySimilarRectangles2(sides_rows, sides_columns, sides);

	// Print the result
	printf("%ld\n", count);

	// Free the memory
	for (int i = 0; i < sides_rows; i++)
	{
		free(sides[i]);
	}
	free(sides);

	return 0;
}