#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for hashing
#define BASE (131)
#define MODULO (1000000007)

// Function to calculate and set the password hash
int setPasswordHash(const char *password)
{
	long passwordHash = 0;

	while (*password)
	{
		passwordHash = (passwordHash * BASE + *password) % MODULO;
		password++;
	}

	return (int)passwordHash;
}

// Function to authorize a user based on their input hash
int authorizeUser(long correctHash, long inputHash)
{
	if (correctHash == inputHash)
		return 1;

	correctHash = (correctHash * BASE) % MODULO;

	// Try adding digits, lowercase, and uppercase characters
	for (int i = '0'; i <= '9'; i++)
	{
		if ((correctHash + i) % MODULO == inputHash)
			return 1;
	}

	for (int i = 'a'; i <= 'z'; i++)
	{
		if ((correctHash + i) % MODULO == inputHash)
			return 1;
	}

	for (int i = 'A'; i <= 'Z'; i++)
	{
		if ((correctHash + i) % MODULO == inputHash)
			return 1;
	}

	return 0;
}

// Function to process authentication events and return results
int *authEvents(int events_rows, int events_columns, char ***events, int *result_count)
{
	int *results = malloc(events_rows * sizeof(int));
	int resultIdx = 0;
	int currentHash = 0;

	for (int i = 0; i < events_rows; i++)
	{
		switch (events[i][0][0])
		{
		case 's':
			currentHash = setPasswordHash(events[i][1]);
			break;

		case 'a':
			results[resultIdx] = authorizeUser(currentHash, atoi(events[i][1]));
			resultIdx++;
			break;
		}
	}

	*result_count = resultIdx;
	return results;
}

int main()
{
	int events_rows;
	int events_columns = 2;

	scanf("%d", &events_rows);

	scanf("%d", &events_columns); // events_columns is not used

	char ***events = (char ***)malloc(events_rows * sizeof(char **));
	for (int i = 0; i < events_rows; i++)
	{
		events[i] = (char **)malloc(events_columns * sizeof(char *));
		for (int j = 0; j < events_columns; j++)
		{
			events[i][j] = (char *)malloc(10 * sizeof(char));
		}
	}

	for (int i = 0; i < events_rows; i++)
	{
		scanf("%s %s", events[i][0], events[i][1]);
	}

	int result_count;
	int *result = authEvents(events_rows, events_columns, events, &result_count);

	for (int i = 0; i < result_count; i++)
	{
		printf("%d\n", result[i]);
	}

	// Clean up memory
	for (int i = 0; i < events_rows; i++)
	{
		for (int j = 0; j < events_columns; j++)
		{
			free(events[i][j]);
		}
		free(events[i]);
	}
	free(events);
	free(result);

	return 0;
}
