#include <stdio.h>
#include <stdlib.h>

int mostBalancedPartition(int parent_count, int *parent, int files_size_count, int *files_size)
{

	for (int i = parent_count - 1; i > 0; i--)
	{
		files_size[parent[i]] += files_size[i];
	}

	// for testing
	// for (int i = 0; i < parent_count; i++)
	//{
	//	printf("%d ", files_size[i]);
	//}

	int mindiff = files_size[0];

	for (int i = 1; i < files_size_count; i++)
	{
		int diff = abs(files_size[0] - (2 * files_size[i])); // 2 * files_size[i] = sum of all files sizes - files_size[i]

		if (diff < mindiff)
		{
			mindiff = diff;
		}
	}
	return mindiff;
}

int main()
{
	int parent_count;
	scanf("%d", &parent_count);

	int *parent = (int *)malloc(parent_count * sizeof(int));
	for (int i = 0; i < parent_count; i++)
	{
		scanf("%d", &parent[i]);
	}

	int files_size_count;
	scanf("%d", &files_size_count);

	int *files_size = (int *)malloc(files_size_count * sizeof(int));
	for (int i = 0; i < files_size_count; i++)
	{
		scanf("%d", &files_size[i]);
	}

	int result = mostBalancedPartition(parent_count, parent, files_size_count, files_size);
	printf("\n%d\n", result);

	free(parent);
	free(files_size);

	return 0;
}