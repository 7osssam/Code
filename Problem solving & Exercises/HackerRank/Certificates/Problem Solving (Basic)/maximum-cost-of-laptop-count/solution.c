#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxCost(int cost_count, int *cost, int labels_count, char **labels, int dailyCount)
{
	int maxCost = 0;
	int sumCost = 0;
	int legalCount = 0;

	for (int i = 0; i < cost_count; i++)
	{
		if (strcmp(labels[i], "legal") == 0)
		{
			legalCount++;
		}

		sumCost += cost[i];

		if (legalCount == dailyCount)
		{
			if (sumCost > maxCost)
			{
				maxCost = sumCost;
			}

			sumCost = 0;
			legalCount = 0;
		}
	}

	return maxCost;
}
int main()
{
	int cost_count;
	scanf("%d", &cost_count);

	int *cost = (int *)malloc(cost_count * sizeof(int));
	for (int i = 0; i < cost_count; i++)
	{
		scanf("%d", &cost[i]);
	}

	int labels_count;
	scanf("%d", &labels_count);

	char **labels = (char **)malloc(labels_count * sizeof(char *));
	for (int i = 0; i < labels_count; i++)
	{
		labels[i] = (char *)malloc(10 * sizeof(char)); // Assuming the maximum label length is 10 characters
		scanf("%s", labels[i]);
	}

	int dailyCount;
	scanf("%d", &dailyCount);

	int result = maxCost(cost_count, cost, labels_count, labels, dailyCount);

	printf("%d\n", result);

	// Free allocated memory
	free(cost);
	for (int i = 0; i < labels_count; i++)
	{
		free(labels[i]);
	}
	free(labels);

	return 0;
}
