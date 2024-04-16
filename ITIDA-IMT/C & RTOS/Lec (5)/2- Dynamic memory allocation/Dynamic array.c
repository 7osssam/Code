#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int* data;	   // Pointer to array's first element
	int	 size;	   // Number of elements in the array
	int	 capacity; // Total capacity of the array
} DynamicArray;

void initArray(DynamicArray* arr, int initialCapacity)
{
	arr->data = malloc(initialCapacity * sizeof(int));
	if (arr->data == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for array\n");
		exit(EXIT_FAILURE);
	}
	arr->size = 0;
	arr->capacity = initialCapacity;
}

void freeArray(DynamicArray* arr)
{
	if (arr->data != NULL)
	{
		free(arr->data);
		arr->data = NULL;
	}
	arr->size = arr->capacity = 0;
}

void addElement(DynamicArray* arr, int element)
{
	if (arr->size == arr->capacity)
	{
		arr->capacity *= 2;
		arr->data = realloc(arr->data, arr->capacity * sizeof(int));
	}
	arr->data[arr->size] = element;
	arr->size++;
}

void removeElement(DynamicArray* arr)
{
	if (arr->size > 0)
	{
		arr->size--;
	}
}

void printArray(const DynamicArray* arr)
{
	for (int i = 0; i < arr->size; i++)
	{
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}

int main()
{
	DynamicArray arr;
	initArray(&arr, 1);

	addElement(&arr, 10);
	addElement(&arr, 20);
	addElement(&arr, 30);

	printArray(&arr);

	removeElement(&arr);
	printArray(&arr);

	addElement(&arr, 40);
	printArray(&arr);

	addElement(&arr, 50);
	printArray(&arr);

	removeElement(&arr);
	removeElement(&arr);
	removeElement(&arr);

	printArray(&arr);

	freeArray(&arr);

	return 0;
}