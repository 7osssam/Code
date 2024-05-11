#include <iostream>

// This function swaps values of two variables using pointers without using a third variable
void swap(int* num1, int* num2)
{
	*num1 = *num1 + *num2; // add x and y and store in x
	*num2 = *num1 - *num2; // subtract y from x and store in y
	*num1 = *num1 - *num2; // subtract y from x and store in x
}

void BubbleSort(int* arr, int arr_size)
{
	for (int step = 0; step < arr_size - 1; step++) // loop for steps
	{
		int isSorted = 1;							// sorted by default

		// we added (....- step) because after every step the last element is sorted and we don't need to check it again
		// - 1 to not go out of bounds in the last step so if size = 5, then we will have 4 steps (0,1,2,3)
		for (int i = 0; i < arr_size - 1 - step; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]); // swap if the element is greater than the next element

				isSorted = 0;				// not sorted
			}
		}

		if (isSorted == 1)					// if we didn't swap any element then the array is sorted
			break;
	}
}

int main()
{
	int arr[10];
	std::cout << "Enter 10 numbers: ";
	for (int i = 0; i < 10; i++)
	{
		std::cin >> arr[i];
	}

	BubbleSort(arr, 10);

	std::cout << "Sorted array: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
