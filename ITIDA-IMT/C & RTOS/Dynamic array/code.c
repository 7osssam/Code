#include <assert.h>
#include <stdio.h>
#include "DynamicArray.h"

void test_DynamicArray()
{
	DynamicArray arr;
	DynamicArray_init(&arr);

	// Test initial size
	assert(arr.size == 0);
	assert(arr.capacity == DYNAMIC_ARRAY_INITIAL_CAPACITY);

	// Test setting and getting values
	DynamicArray_set(&arr, 0, 123);
	assert(DynamicArray_get(&arr, 0) == 123);

	// Test automatic resizing
	DynamicArray_set(&arr, 100, 456);
	assert(DynamicArray_get(&arr, 100) == 456);
	assert(arr.size == 101);
}

int main()
{
	test_DynamicArray();
	printf("======= All tests passed =======\n");
	return 0;
}