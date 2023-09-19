#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Custom comparison function for qsort
int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

// Function to find the maximum number of pairs
int maxPairs(int skillLevel_count, int *skillLevel, int minDiff)
{
	// Sort the skill levels in ascending order
	qsort(skillLevel, skillLevel_count, sizeof(int), compare);

	int left = 0;						  // Left pointer
	int right = skillLevel_count / 2 + 1; // Right pointer

	while (right - left > 1)
	{
		int middle = (left + right) / 2;
		bool good = true;

		// Check if skill levels meet the minimum difference requirement
		for (int i = 0; i < middle; i++)
		{
			good &= (skillLevel[skillLevel_count - middle + i] - skillLevel[i] >= minDiff);
		}

		if (good)
		{
			left = middle;
		}
		else
		{
			right = middle;
		}
	}

	return left;
}

int main()
{
	int skillLevel_count;
	scanf("%d", &skillLevel_count);

	int *skillLevel = (int *)malloc(skillLevel_count * sizeof(int));

	for (int i = 0; i < skillLevel_count; i++)
	{
		scanf("%d", &skillLevel[i]);
	}

	int minDiff;
	scanf("%d", &minDiff);

	int result = maxPairs(skillLevel_count, skillLevel, minDiff);
	printf("%d\n", result);

	free(skillLevel);

	return 0;
}
