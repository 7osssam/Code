/*
 * Selection Sort Algorithm
 * ---------------------
 * Time Complexity:
 * - Worst Case: O(n^2)
 * - Average Case: O(n^2)
 * - Best Case: O(n^2)
 *
 * Space Complexity: O(1)
 *
 * Algorithm:
 * - Find the minimum value in the list
 * - Swap it with the value in the first position
 * - Repeat the steps above for the remainder of the list (starting at the second position and advancing each time)
 * - until the list is sorted
 *
 */
#include <stdio.h>

void swap(int *num1, int *num2) //! using the swap function with no third variable may cause unexpected results
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void SelectionSort(int *arr, int arr_size)
{
	int indexOfMin; // the index of the minimum value

	for (int steps = 0; steps < arr_size - 1; steps++) // -1 because the last element is already sorted
	{
		indexOfMin = steps; // the first index of the unsorted array

		for (int j = steps + 1; j < arr_size; j++) // +1 because the first element is already sorted
		{
			if (arr[j] < arr[indexOfMin])
			{
				indexOfMin = j;
			}
		}

		swap(&arr[indexOfMin], &arr[steps]); // swap the minimum value with the first element of the unsorted array
	}
}
int main()
{ // 1 2 3 4 5 6 7 7 8 9

	int arr[10] = {9, 8, 7, 1, 3, 2, 4, 5, 6, 7};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	// printf("Enter %d elements in the array to sort\n", arr_size);
	// for (int i = 0; i < arr_size; i++) // get the array
	// {
	//     scanf("%d", &arr[i]);
	// }

	printf("The Before Array\n");
	for (int i = 0; i < arr_size; i++) // print the array
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	SelectionSort(arr, arr_size);

	printf("The After Array (Sorted)\n");
	for (int i = 0; i < arr_size; i++) // print the sorted array
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
