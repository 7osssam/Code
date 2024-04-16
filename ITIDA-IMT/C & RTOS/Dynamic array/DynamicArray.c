#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

void DynamicArray_init(DynamicArray* arr)
{
	/* Initialize array structure */
	arr->size = 0;
	arr->capacity = DYNAMIC_ARRAY_INITIAL_CAPACITY;
	/* Allocate memory for array data */
	arr->data = (int*)malloc(sizeof(int) * arr->capacity);
	if (arr->data == NULL)
	{
		/* Error handling for memory allocation failure */
		perror("Error initializing array");
		exit(EXIT_FAILURE);
	}
}

int DynamicArray_get(DynamicArray* arr, int index)
{
	/* Check if index is out of bounds */
	if (index >= arr->size || index < 0)
	{
		/* Error handling for index out of bounds */
		fprintf(stderr, "Index %d out of bounds for array of size %d\n", index, arr->size);
		exit(EXIT_FAILURE);
	}

	return arr->data[index];
}

void DynamicArray_set(DynamicArray* arr, int index, int value)
{
	/* Resize array if necessary to guarantee space for index */
	while (index >= arr->size)
	{
		DynamicArray_append(arr, 0);
	}

	/* Set value at index */
	arr->data[index] = value;
}

// append means add to the end of the array
void DynamicArray_append(DynamicArray* arr, int value)
{
	/* Resize array if necessary */
	DynamicArray_resize(arr);

	/* Append value to array */
	arr->data[arr->size] = value;
	arr->size++;
}

void DynamicArray_prepend(DynamicArray* arr, int value)
{
	/* Shift existing elements to make space for new value */
	DynamicArray_set(arr, 0, value);
}

int DynamicArray_pop(DynamicArray* arr)
{
	/* Check if array is empty */
	if (arr->size == 0)
	{
		/* Error handling for popping from an empty array */
		fprintf(stderr, "Cannot pop from empty array\n");
		exit(EXIT_FAILURE);
	}

	/* Retrieve and remove last element */
	int data = arr->data[arr->size - 1];
	arr->size--;
	return data;
}

void DynamicArray_delete(DynamicArray* arr, int index)
{
	/* Check if index is out of bounds */
	if (index < 0 || index >= arr->size)
	{
		/* Error handling for index out of bounds */
		fprintf(stderr, "Index %d out of bounds for array of size %d\n", index, arr->size);
		exit(EXIT_FAILURE);
	}

	/* Shift elements after index to fill the gap */
	for (int i = index; i < arr->size - 1; i++)
	{
		arr->data[i] = arr->data[i + 1];
	}
	arr->size--;
}

void DynamicArray_deleteValue(DynamicArray* arr, int value)
{
	/* Find index of value and delete it */
	int index = DynamicArray_findValue(arr, value);
	if (index != -1)
	{
		DynamicArray_delete(arr, index);
	}
}

int DynamicArray_findValue(DynamicArray* arr, int value)
{
	/* Search for value in array */
	for (int i = 0; i < arr->size; i++)
	{
		if (arr->data[i] == value)
		{
			return i;
		}
	}

	/* Value not found */
	return -1;
}

void DynamicArray_resize(DynamicArray* arr)
{
	/* Double the capacity if array is full */
	if (arr->size >= arr->capacity)
	{
		arr->capacity *= 2; // Double the capacity of the array when it is full
		arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
		if (arr->data == NULL)
		{
			/* Error handling for memory allocation failure */
			perror("Error resizing array");
			exit(EXIT_FAILURE);
		}
	}
}

int DynamicArray_size(DynamicArray* arr)
{
	return arr->size;
}

int DynamicArray_capacity(DynamicArray* arr)
{
	return arr->capacity;
}

bool DynamicArray_isEmpty(DynamicArray* arr)
{
	return arr->size == 0;
}

void DynamicArray_freeMemory(DynamicArray* arr)
{
	/* Free memory allocated for array data */
	free(arr->data);
}
