#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *findSubstring(char *s, int k)
{
	char *result = NULL;
	char vowels[] = "aeiou";
	int count = 0;
	int ans = 0;
	char *ptr;

	for (int i = 0; i < k; i++)
	{
		ptr = strchr(vowels, s[i]);
		count += (ptr != NULL);
	}

	int max = count;

	for (int i = k; i < strlen(s); i++)
	{
		ptr = strchr(vowels, s[i]);
		count += (ptr != NULL);
		ptr = strchr(vowels, s[i - k]);
		count -= (ptr != NULL);

		if (count > max)
		{
			max = count;
			ans = i - k + 1;
		}
	}

	if (max > 0)
	{
		result = (char *)malloc((k + 1) * sizeof(char));
		strncpy(result, s + ans, k);
		result[k] = '\0';
	}
	else
	{
		result = (char *)malloc(11 * sizeof(char)); // Allocate memory for "Not found!"
		strcpy(result, "Not found!");
	}

	return result;
}

int main()
{
	char str[200000];
	int k;

	fgets(str, sizeof(str), stdin);

	scanf("%d", &k);

	char *substring = findSubstring(str, k);
	printf("%s\n", substring);

	free(substring);

	return 0;
}
