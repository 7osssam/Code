#include <stdio.h>

// Function to calculate the maximum number of similar pairs
long taskOfPairing(int freq_count, long *freq)
{
	long totalPairs = 0;

	for (int weight = 0; weight < freq_count; weight++)
	{
		// Pair up weights of the same value
		long pairsFromSameWeights = freq[weight] / 2;
		totalPairs += pairsFromSameWeights;

		// Update the remaining weights after pairing
		freq[weight] -= 2 * pairsFromSameWeights;

		// Check if we can pair this weight with the next one
		if (weight < freq_count - 1 && freq[weight] > 0 && freq[weight + 1] > 0)
		{
			totalPairs++;
			freq[weight]--;
			freq[weight + 1]--;
		}
	}

	return totalPairs;
}

int main()
{
	int n;
	scanf("%d", &n);

	long freq[n];

	// Input the frequencies of weights
	for (int weight = 0; weight < n; weight++)
	{
		scanf("%ld", &freq[weight]);
	}

	long maxPairs = taskOfPairing(n, freq);

	// Output the maximum number of similar pairs
	printf("%ld\n", maxPairs);

	return 0;
}
