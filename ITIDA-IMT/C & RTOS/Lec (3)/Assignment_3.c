#include <stdio.h>
#include <assert.h>

void reverseArray(int* arr, int n)
{
	int* start_ptr = arr;		// pointing to the first element of the array
	int* end_ptr = arr + n - 1; // pointing to the last element of the array

	while (start_ptr < end_ptr)
	{
		int temp = *start_ptr;
		*start_ptr = *end_ptr;
		*end_ptr = temp;

		// move the pointers opposite to each other
		start_ptr++;
		end_ptr--;
	}
}

// @test
void test_reverseArray()
{
	int arr1[] = {1, 2, 3, 4, 5};
	reverseArray(arr1, 5);
	assert(arr1[0] == 5);
	assert(arr1[1] == 4);
	assert(arr1[2] == 3);
	assert(arr1[3] == 2);
	assert(arr1[4] == 1);

	int arr2[] = {5, 4, 3, 2, 1};
	reverseArray(arr2, 5);
	assert(arr2[0] == 1);
	assert(arr2[1] == 2);
	assert(arr2[2] == 3);
	assert(arr2[3] == 4);
	assert(arr2[4] == 5);

	printf("All tests passed.\n");
}

int main()
{
	test_reverseArray();
	return 0;
}