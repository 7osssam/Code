/*
 * Quick Sort Algorithm
 * ---------------------
 * Time Complexity:
 * - Worst Case: O(n^2)
 * - Average Case: O(n log n)
 * - Best Case: O(n log n)
 *
 * Space Complexity: O(log n)
 *
 * Algorithm:
 * - Pick an element, called a pivot, from the array.
 * - Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot,
 * - while all elements with values greater than the pivot come after it (equal values can go either way).
 * - After this partitioning, the pivot is in its final position. This is called the partition operation.
 * - Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.
 */
#include <stdio.h>

/// Function to swap two elements
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

// This function takes last element as pivot, places the pivot element at its correct position in sorted array,
// and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
int Partition(int *arr, int low, int high)
{
	// select the rightmost element as pivot
	int pivot = arr[high];
	// pointer for greater element
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot) // if current element is smaller than or equal to pivot
		{
			i++;					// increment index of smaller element
			swap(&arr[i], &arr[j]); // swap arr[i] and arr[j]
		}
	}

	swap(&arr[i + 1], &arr[high]); // swap arr[i + 1] and arr[high] (or pivot)

	return (i + 1);
}

void QuickSort(int *arr, int low, int high)
{
	if (low < high) // if low is less than high then the array has more than one element
	{
		// pivotIndex is partitioning index, arr[pivotIndex] is now at right place
		int pivotIndex = Partition(arr, low, high);

		// recursive call on the left of pivot
		QuickSort(arr, low, pivotIndex - 1);

		// recursive call on the right of pivot
		QuickSort(arr, pivotIndex + 1, high);
	}
}

int main()
{

	int arr[10];
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Enter %d elements in the array to sort\n", arr_size);
	for (int i = 0; i < arr_size; i++) // get the array
	{
		scanf("%d", &arr[i]);
	}

	QuickSort(arr, 0, arr_size - 1); // sort the array

	printf("Sorted array: \n");
	for (int i = 0; i < arr_size; i++) // print the array
	{
		printf("%d ", arr[i]);
	}

	return 0;
}