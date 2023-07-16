#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

long gcd(long a, long b)
{
	while (b > 0)
	{
		long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int compare(const void *a, const void *b)
{
	long *sideA = *(long **)a;
	long *sideB = *(long **)b;

	long ratioA = sideA[0] * sideB[1];
	long ratioB = sideB[0] * sideA[1];

	return ratioA - ratioB;
}

long nearlySimilarRectangles(int sides_rows, int sides_columns, long **sides)
{
	for (int i = 0; i < sides_rows; i++)
	{
		long z = gcd(sides[i][0], sides[i][1]);
		sides[i][0] /= z;
		sides[i][1] /= z;
	}

	qsort(sides, sides_rows, sizeof(sides[0]), compare);

	long count = 1;
	long sum = 0;

	for (int i = 0; i < sides_rows - 1; i++)
	{
		if (sides[i][0] == sides[i + 1][0] && sides[i][1] == sides[i + 1][1])
		{
			count++;
		}
		else
		{
			sum += count * (count - 1) / 2;
			count = 1;
		}
	}
	sum += count * (count - 1) / 2;

	return sum;
}

int main()
{
	int sides_rows, sides_columns;
	scanf("%d", &sides_rows);

	scanf("%d", &sides_columns);

	// Allocate memory for the sides array
	long **sides = (long **)malloc(sides_rows * sizeof(long *));
	for (int i = 0; i < sides_rows; i++)
	{
		sides[i] = (long *)malloc(sides_columns * sizeof(long));
	}

	// Read the sides of each rectangle from the user
	for (int i = 0; i < sides_rows; i++)
	{
		scanf("%ld %ld", &sides[i][0], &sides[i][1]);
	}

	// Call the nearlySimilarRectangles function
	long result = nearlySimilarRectangles(sides_rows, sides_columns, sides);
	printf("%ld\n", result);

	// Free memory
	for (int i = 0; i < sides_rows; i++)
	{
		free(sides[i]);
	}
	free(sides);

	return 0;
}