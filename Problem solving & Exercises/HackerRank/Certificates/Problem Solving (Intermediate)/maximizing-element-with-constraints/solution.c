#include <stdbool.h>
#include <stdio.h>

// Alternative solution
/*
int maxElement(int n, int maxSum, int k)
{
	if (n == 1)
		return maxSum;
	int right = k;
	int left = k;
	int count = 1;
	int limitRight = n - 1;

	while (n <= maxSum && (left > 0 || right < limitRight))
	{

		n += right - left + 1;
		if (left > 0)
			left--;
		if (right < limitRight)
			right++;
		count++;
	}

	if (n < maxSum)
		count += (maxSum - n) / (right - left + 1) + 1;

	return count - 1;
}
*/

// Function to check if a given value 'm' is valid for element at index 'k'
bool isValid(int n, int k, int maxSum, int m)
{
	for (int d = 1; maxSum >= 0 && d < m && k + d < n; d++)
		maxSum -= m - d;
	for (int d = 1; maxSum >= 0 && d < m && k - d >= 0; d++)
		maxSum -= m - d;
	return maxSum >= 0;
}

// Function to find the maximum possible value for the element at index 'k'
int maxElement(int n, int maxSum, int k)
{
	int left = 0, right = maxSum;

	while (left < right)
	{
		int mid = (left + right + 1) / 2;
		if (isValid(n, k, maxSum - n - mid, mid))
			left = mid;
		else
			right = mid - 1;
	}

	return left + 1;
}

int main()
{
	int n, maxSum, k;
	scanf("%d %d %d", &n, &maxSum, &k);

	int result = maxElement(n, maxSum, k);
	printf("%d\n", result);

	return 0;
}
