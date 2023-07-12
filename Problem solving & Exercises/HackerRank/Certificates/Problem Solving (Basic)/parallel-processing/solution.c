#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

long compare(void *a, void *b)
{
	return *(long *)b - *(long *)a;
}

long minTime(int files_count, int *files, int numCores, int limit)
{
	long total = 0; // total time
	int NumOfMax = 0;

	long *max = (long *)calloc(NumOfMax, sizeof(long)); // allocate memory for max

	for (int i = 0; i < files_count; i++)
	{
		if (files[i] % numCores == 0)
		{
			NumOfMax++;
			max = (long *)realloc(max, NumOfMax * sizeof(long));

			max[NumOfMax - 1] = files[i];
			continue;
		}
		total += files[i];
	}

	// sort max in descending order
	qsort(max, NumOfMax, sizeof(long), compare);

	for (int i = 0; i < NumOfMax; i++)
	{
		if (i < limit)
		{
			total += (max[i] / numCores);
		}
		else
		{
			total += max[i];
		}
	}
	free(max);
	return total;
}

int main()
{
	int files_count;
	scanf("%d", &files_count);

	int *files = (int *)malloc(files_count * sizeof(int));

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
