#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_chars(const void *a, const void *b)
{

	return *(char *)a - *(char *)b;
}

char **possibleChanges(int usernames_count, char **usernames, int *result_count)
{

	char **result = (char **)malloc(usernames_count * sizeof(char *));

	for (int i = 0; i < usernames_count; i++)
	{

		// plus 1 for the null terminator
		char *temp = (char *)malloc(strlen(usernames[i]) + 1 * sizeof(char));

		strcpy(temp, usernames[i]);								// copy the string to temp
		qsort(temp, strlen(temp), sizeof(char), compare_chars); // sort the string

		if (strcmp(usernames[i], temp)) // if the string is not equal to the sorted string
		{
			result[i] = "YES";
		}
		else
		{
			result[i] = "NO";
		}
		free(temp);
	}

	*result_count = usernames_count;
	return result;
}

int main()
{
	int usernames_count;
	scanf("%d", &usernames_count);
	getchar(); // Consume the newline character after scanf

	char **usernames = (char **)malloc(usernames_count * sizeof(char *));
	for (int i = 0; i < usernames_count; i++)
	{
		usernames[i] = (char *)malloc(100 * sizeof(char)); // Assuming maximum username length of 100
		fgets(usernames[i], 100, stdin);
		usernames[i][strlen(usernames[i]) - 1] = '\0'; // Remove the trailing newline character
	}

	int result_count = 0;
	char **result = possibleChanges(usernames_count, usernames, &result_count);

	// Print the results
	for (int i = 0; i < result_count; i++)
	{
		printf("%s\n", result[i]);
	}

	// Cleanup
	for (int i = 0; i < usernames_count; i++)
	{
		free(usernames[i]);
	}
	free(usernames);
	free(result);

	return 0;
}