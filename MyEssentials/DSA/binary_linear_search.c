#include <stdio.h>

/*
 * Linear Search
 * - search an element in an array
 * - return the index of the element if found
 * - return -1 if not found
 *
 * - time complexity: O(n)
 * - space complexity: O(1)
 */
int LinearSearch(int const *arr, int target, int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i] == target) // if the element is found
		{
			return i;
		}
	}
	return -1; // if the element is not found
}

/*
 * Binary Search
 * - search an element in a //! sorted array
 * - return the index of the element if found
 * - return -1 if not found
 *
 * - time complexity: O(log n)
 * - space complexity: O(1)
 */
int BinarySearch(int const *arr, int target, int arr_size)
{
	int first = 0;			 // first index of the array
	int last = arr_size - 1; // last index of the array

	while (first <= last) // while the array is not empty
	{
		int mid = first + (last - first) / 2;

		if (arr[mid] == target) // if the element is found
		{
			return mid;
		}
		else if (arr[mid] < target) // right side of the array
		{
			first = mid + 1; // mid + 1 because we already checked the mid element
		}
		else if (arr[mid] > target) // left side of the array
		{
			last = mid - 1; // mid - 1 because we already checked the mid element
		}
	}
	return -1; // if the element is not found
}

int main()
{
	// int arr[] = {2, 23, 43, 1, 13, 11, 12, 22, 99, 100, 21}; // unsorted array (linear search)
	int arr[] = {3, 4, 5, 7, 6, 8, 9};			 // sorted array (binary search)
	int target;									 // the element to be searched
	int arr_size = sizeof(arr) / sizeof(arr[0]); // to get the size of the array

	printf("Enter a num :");
	scanf("%d", &target);

	// int result = LinearSearch(arr, target, arr_size); // linear search
	int result = BinarySearch(arr, target, arr_size); // binary search (only sorted array)

	if (result == -1)
		printf("\nNOT FOUND");
	else
		printf("\n%dst of the array", result + 1);

	return 0;
}