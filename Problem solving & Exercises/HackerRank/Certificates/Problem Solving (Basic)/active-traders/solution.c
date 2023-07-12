#include <stdio.h>	// For printf, scanf functions
#include <stdlib.h> // For malloc, realloc, free functions
#include <string.h> // For strcmp function

int compare(const char **a, const char **b)
{
	return strcmp(*a, *b);
}

char **mostActive(int customers_count, char **customers, int *result_count)
{
	char **str = NULL;
	int strSize = 0;
	int counter = 0;
	int i;

	qsort(customers, customers_count, sizeof(char *), compare);

	for (i = 0; i < customers_count; i++)
	{
		if (i > 0 && strcmp(customers[i], customers[i - 1]) == 0)
		{
			counter++;
		}
		else
		{
			if (counter >= customers_count * 0.05)
			{
				strSize++;
				str = (char **)realloc(str, strSize * sizeof(char *));
				str[strSize - 1] = customers[i - 1];
			}
			counter = 1;
		}
	}

	if (counter >= customers_count * 0.05)
	{
		strSize++;
		str = (char **)realloc(str, strSize * sizeof(char *));
		str[strSize - 1] = customers[i - 1];
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

		// Allocate memory and copy the name to the customers array
		customers[i] = (char *)malloc((strlen(name) + 1) * sizeof(char));
		strcpy(customers[i], name);
	}

	int result_count;
	char **result = mostActive(customers_count, customers, &result_count);

	printf("\n");
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
