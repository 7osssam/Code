#include <stdio.h>
#include <stdlib.h>

#define A_LIMIT (1000000)
#define M (1000000007)

// Data structure for Fenwick Tree (FWT)
typedef struct FenwickTree
{
	int n;	// Size of the tree
	int *a; // Array to store values
} FenwickTree;

// Function to initialize the Fenwick Tree
FenwickTree *FenwickTree_init(int n)
{
	FenwickTree *fwTree = (FenwickTree *)malloc(sizeof(FenwickTree));
	fwTree->n = n;
	fwTree->a = (int *)calloc(n, sizeof(int));
	return fwTree;
}

// Function to update the rank in the Fenwick Tree
void updateRank(FenwickTree *fwTree, int x, int k)
{
	for (int i = x; i <= fwTree->n; i += i & -i)
	{
		fwTree->a[i] = (fwTree->a[i] + k) % M;
	}
}

// Function to query the rank in the Fenwick Tree
int queryRank(FenwickTree *fwTree, int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		res = (res + fwTree->a[i]) % M;
	}
	return res;
}

// Function to calculate the sortedSum
int sortedSum(int arr_count, int *a)
{
	// Initialize two Fenwick Trees to keep track of ranks
	FenwickTree *preRank = FenwickTree_init(A_LIMIT + 1);
	FenwickTree *postRank = FenwickTree_init(A_LIMIT + 1);

	int currentFunction = 0, answer = 0, total = 0;

	for (int i = 0; i < arr_count; i++)
	{
		int position = queryRank(preRank, a[i]) + 1;
		int greater = (total - queryRank(postRank, a[i])) % M;

		if (greater < 0)
			greater += M;

		currentFunction = (currentFunction + 1LL * position * a[i] % M + greater) % M;
		answer = (answer + currentFunction) % M;

		updateRank(preRank, a[i], 1);
		updateRank(postRank, a[i], a[i]);
		total = (total + a[i]) % M;
	}

	// Free memory allocated for Fenwick Trees
	free(preRank->a);
	free(preRank);
	free(postRank->a);
	free(postRank);

	return answer;
}

int main()
{
	int arr_count;
	scanf("%d", &arr_count);

	int *a = (int *)malloc(arr_count * sizeof(int));

	for (int i = 0; i < arr_count; i++)
	{
		scanf("%d", &a[i]);
	}

	int result = sortedSum(arr_count, a);
	printf("%d\n", result);

	free(a);

	return 0;
}
