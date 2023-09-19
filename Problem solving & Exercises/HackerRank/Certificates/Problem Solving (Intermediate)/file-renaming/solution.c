#include <stdio.h>
#include <string.h>

// Define the modulo constant
#define MOD 1000000007

int renameFile(char *newName, char *oldName)
{
	int n = strlen(newName);
	int m = strlen(oldName);

	// Create a 2D DP array to store the number of ways to form newName
	// from a prefix of oldName.
	int dp[n + 1][m + 1];

	// Initialize the DP array with zeros.
	memset(dp, 0, sizeof(dp));

	// Base case: There is one way to form an empty string from an empty string.
	dp[0][0] = 1;

	// Fill in the DP array using a bottom-up approach.
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i > 0 && j > 0 && newName[i - 1] == oldName[j - 1])
			{
				// If the current characters match, we have two options:
				// 1. Delete the current character from both strings.
				// 2. Delete the current character from oldName.
				dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
			}
			else if (j > 0)
			{
				// If the characters don't match, we can only delete the
				// current character from oldName.
				dp[i][j] = dp[i][j - 1];
			}
		}
	}

	// The final answer is stored in dp[n][m].
	return dp[n][m];
}

int main()
{
	char newName[100000];
	char oldName[100000];

	// Read input
	scanf("%s", newName);
	scanf("%s", oldName);

	int result = renameFile(newName, oldName);

	// Output the result modulo 10^9+7
	printf("%d\n", result);

	return 0;
}
