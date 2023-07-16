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
		char *temp = strdup(usernames[i]); // duplicate the string

		qsort(temp, strlen(temp), sizeof(char), compare_chars); // sort the string

		// Compare the sorted string with the original string and store the result
		result[i] = strcmp(usernames[i], temp) ? "YES" : "NO";

		free(temp);
	}

	*result_count = usernames_count;
	return result;
}

int main()
{
	int usernames_count;
	scanf("%d\n", &usernames_count);

	char **usernames = (char **)malloc(usernames_count * sizeof(char *));
	for (int i = 0; i < usernames_count; i++)
	{
		usernames[i] = (char *)malloc(101 * sizeof(char)); // Increased to 101 to accommodate the null terminator
		fgets(usernames[i], 101, stdin);
		usernames[i][strcspn(usernames[i], "\n")] = '\0'; // Remove the trailing newline character
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
