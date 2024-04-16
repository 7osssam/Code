#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void BubbleSort(int* arr, int arr_size)
{
	for (int step = 0; step < arr_size - 1; step++) // loop for steps
	{
		// sorted by default
		int isSorted = 1;

		for (int i = 0; i < arr_size - 1 - step; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				// swap if the element is greater than the next element
				swap(&arr[i], &arr[i + 1]);

				// clear the sorted flag
				isSorted = 0;
			}
		}

		if (isSorted == 1) // if we didn't swap any element then the array is sorted
			break;
	}
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void test_BubbleSort()
{
	// Normal array
	int arr1[] = {64, 34, 25, 12, 22, 11, 90};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	BubbleSort(arr1, n1);
	int sorted1[] = {11, 12, 22, 25, 34, 64, 90};
	for (int i = 0; i < n1; i++)
	{
		assert(arr1[i] == sorted1[i]);
	}

	// Array with negative numbers
	int arr2[] = {-5, -10, 0, -3, 8, 5, -1};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	BubbleSort(arr2, n2);
	int sorted2[] = {-10, -5, -3, -1, 0, 5, 8};
	for (int i = 0; i < n2; i++)
	{
		assert(arr2[i] == sorted2[i]);
	}

	// Array with same numbers
	int arr3[] = {0, 0, 0};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	BubbleSort(arr3, n3);
	int sorted3[] = {0, 0, 0};
	for (int i = 0; i < n3; i++)
	{
		assert(arr3[i] == sorted3[i]);
	}

	printf("==== All test cases passed ====\n");
}

int main()
{
	// unit testings
	test_BubbleSort();

	int n;
	printf("Enter the number of values to be sorted: ");
	scanf("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));
	printf("Enter the values: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	BubbleSort(arr, n);
	printf("Sorted array in ascending order: ");
	printArray(arr, n);

	return 0;
}