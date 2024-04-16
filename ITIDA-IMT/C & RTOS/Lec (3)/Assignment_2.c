#include <stdio.h>

#define MAX_SIZE 100 // Maximum array size

int main()
{
	int arr[MAX_SIZE] = {0};
	int arr_size;

	printf("Enter size of the array: ");
	scanf("%d", &arr_size);

	printf("Enter elements in array : ");
	for (int i = 0; i < arr_size; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Negative elements in array are : ");
	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i] < 0)
		{
			printf("%d ", arr[i]);
		}
	}
	return 0;
}