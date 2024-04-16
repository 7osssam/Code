// in this assignmentm, i've used assert.h library to test the function GetMaxAndSecondMaxInArray

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void GetMaxAndSecondMaxInArray(int* arr, int arr_size, int* first, int* second)
{
	int SecoundMaxNum = 0;
	int FirstMaxNum = 0;
	for (int i = 0; i < arr_size; i++)
	{
		// if number is greater than first max number then update first max number and second max number
		if (arr[i] > FirstMaxNum)
		{
			SecoundMaxNum = FirstMaxNum;
			FirstMaxNum = arr[i];
		}
		// if number is greater than second max number and not equal to first max number then update second max number
		else if (arr[i] > SecoundMaxNum && arr[i] != FirstMaxNum)
		{
			SecoundMaxNum = arr[i];
		}
	}

	*first = FirstMaxNum;
	*second = SecoundMaxNum;
}

void test_GetMaxAndSecondMaxInArray()
{
	int arr1[] = {1, 2, 3, 4, 5};
	int first1, second1;
	GetMaxAndSecondMaxInArray(arr1, 5, &first1, &second1);
	assert(first1 == 5);
	assert(second1 == 4);

	int arr2[] = {5, 4, 3, 2, 1};
	int first2, second2;
	GetMaxAndSecondMaxInArray(arr2, 5, &first2, &second2);
	assert(first2 == 5);
	assert(second2 == 4);

	int arr3[] = {1, 3, 5, 4, 2};
	int first3, second3;
	GetMaxAndSecondMaxInArray(arr3, 5, &first3, &second3);
	assert(first3 == 5);
	assert(second3 == 4);

	int arr4[] = {1};
	int first4, second4;
	GetMaxAndSecondMaxInArray(arr4, 1, &first4, &second4);
	assert(first4 == 1);
	assert(second4 == 0);

	int arr5[] = {1, 1, 1, 1, 1};
	int first5, second5;
	GetMaxAndSecondMaxInArray(arr5, 5, &first5, &second5);
	assert(first5 == 1);
	assert(second5 == 0);

	printf("=====All tests passed.======\n");
}

int main()
{
	test_GetMaxAndSecondMaxInArray();
	return 0;
}
