/*
 ? Link: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem
 * Difficulty: Easy
 * Name: Breaking the Records
 *
 * Tags: Algorithms, Implementation
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

//////////////////////!
int *breakingRecords(int scores_count, const int *scores)
{
	int i;
	static int result[2] = {0};
	int max = scores[0];
	int min = scores[0];
	for (i = 0; i < scores_count; i++)
	{
		if (max > scores[i])
		{
			result[1]++;
			max = scores[i];
		}
		if (min < scores[i])
		{
			result[0]++;
			min = scores[i];
		}
	}
	return result;
}
//////////////////////!
int main()
{
	int n;

	scanf("%d", &n);
	int *scores = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &scores[i]);
	}

	int *result = breakingRecords(n, scores);

	for (int i = 0; i < 2; i++)
	{
		printf("%d ", *(result + i));
	}

	free(scores);

	return 0;
}
