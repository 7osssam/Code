#include <stdio.h>
#include <assert.h>

void swapArrays(int* arr1, int* arr2, int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		int temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}

void test_swapArrays()
{
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {50, 40, 30, 20, 10};
	swapArrays(arr1, arr2, 5);

	// assertions
	assert(arr1[0] == 50);
	assert(arr1[1] == 40);
	assert(arr1[2] == 30);
	assert(arr1[3] == 20);
	assert(arr1[4] == 10);

	assert(arr2[0] == 1);
	assert(arr2[1] == 2);
	assert(arr2[2] == 3);
	assert(arr2[3] == 4);
	assert(arr2[4] == 5);

	printf("==== All tests passed ====\n");
}

int main()
{
	test_swapArrays();
	return 0;
}