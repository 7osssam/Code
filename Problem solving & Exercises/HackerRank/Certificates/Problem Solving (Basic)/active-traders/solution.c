#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for qsort
int compare(const void *a, const void *b)
{
	return strcmp(*(const char **)a, *(const char **)b);
}

char **mostActive(int customers_count, char **customers, int *result_count)
{
	qsort(customers, customers_count, sizeof(char *), compare);

	char **str = NULL;
	int strSize = 0;
	int counter = 1;

	// Iterate over each customer
	for (int i = 1; i <= customers_count; i++)
	{
		// Check if the current customer is the same as the previous one
		if (i < customers_count && strcmp(customers[i], customers[i - 1]) == 0)
		{
			counter++;
		}
		else
		{
			if (counter >= customers_count * 0.05)
			{
				strSize++;
				str = realloc(str, strSize * sizeof(char *));
				str[strSize - 1] = customers[i - 1];
			}
			counter = 1; // Reset the counter
		}
	}

	*result_count = strSize;
	return str;
}

int main()
{
	int customers_count;
	scanf("%d\n", &customers_count);

	char **customers = (char **)malloc(customers_count * sizeof(char *));
	for (int i = 0; i < customers_count; i++)
	{
		char name[25];
		fgets(name, sizeof(name), stdin);

		customers[i] = strdup(name);
	}

	int result_count;
	char **result = mostActive(customers_count, customers, &result_count);

	for (int i = 0; i < result_count; i++)
	{
		printf("%s", result[i]);
	}

	// Free the allocated memory
	for (int i = 0; i < customers_count; i++)
	{
		free(customers[i]);
	}
	free(customers);
	free(result);

	return 0;
}
