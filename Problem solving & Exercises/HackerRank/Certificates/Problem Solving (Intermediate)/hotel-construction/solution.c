#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES_CNT (50)

int numberOfWays(int roads_rows, int roads_columns, int **roads)
{
	int citiesCnt = roads_rows + 1;

	char isThereRoad[MAX_CITIES_CNT][MAX_CITIES_CNT] = {0};
	int distance[MAX_CITIES_CNT][MAX_CITIES_CNT];

	// Initialize the distance matrix
	for (int src = 0; src < citiesCnt; src++)
	{
		for (int des = 0; des < citiesCnt; des++)
		{
			distance[src][des] = -1;
		}
	}

	// Build the isThereRoad matrix and calculate distances
	for (int i = 0; i < roads_rows; i++)
	{
		int city1 = roads[i][0] - 1;
		int city2 = roads[i][1] - 1;
		isThereRoad[city1][city2] = 1;
		isThereRoad[city2][city1] = 1;
		distance[city1][city2] = distance[city2][city1] = 1;
	}

	int cnt = 0;

	// Calculate distances using Floyd-Warshall algorithm
	for (int k = 0; k < citiesCnt; k++)
	{
		for (int i = 0; i < citiesCnt; i++)
		{
			for (int j = i + 1; j < citiesCnt; j++)
			{
				if (distance[i][j] == -1 && distance[i][k] != -1 && distance[k][j] != -1)
				{
					distance[i][j] = distance[j][i] = distance[i][k] + distance[k][j];
				}
			}
		}
	}

	// Count the number of valid triples
	for (int city1 = 0; city1 < citiesCnt; city1++)
	{
		for (int city2 = city1 + 1; city2 < citiesCnt; city2++)
		{
			for (int city3 = city2 + 1; city3 < citiesCnt; city3++)
			{
				if (distance[city1][city2] == distance[city1][city3] && distance[city1][city2] == distance[city2][city3])
				{
					cnt++;
				}
			}
		}
	}

	return cnt;
}

int main()
{
	int roads_rows;
	scanf("%d", &roads_rows);

	// Read the integer 2 from the second line (not used in the code)
	int dummy;
	scanf("%d", &dummy);

	// Allocate memory for roads
	int **roads = (int **)malloc(roads_rows * sizeof(int *));
	for (int i = 0; i < roads_rows; i++)
	{
		roads[i] = (int *)malloc(2 * sizeof(int));
	}

	for (int i = 0; i < roads_rows; i++)
	{
		scanf("%d %d", &roads[i][0], &roads[i][1]);
	}

	long long result = numberOfWays(roads_rows, 2, roads);
	printf("%lld", result); // Use %lld for long long

	// Free allocated memory
	for (int i = 0; i < roads_rows; i++)
	{
		free(roads[i]);
	}
	free(roads);

	return 0;
}
