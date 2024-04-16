#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>

#define DYNAMIC_ARRAY_INITIAL_CAPACITY 16

typedef struct
{
	int	 size;
	int	 capacity;
	int* data;
} DynamicArray;

void DynamicArray_init(DynamicArray* arr);
void DynamicArray_append(DynamicArray* arr, int value);
void DynamicArray_prepend(DynamicArray* arr, int value);
void DynamicArray_delete(DynamicArray* arr, int index);
void DynamicArray_deleteValue(DynamicArray* arr, int value);
void DynamicArray_set(DynamicArray* arr, int index, int value);
void DynamicArray_resize(DynamicArray* arr);
void DynamicArray_freeMemory(DynamicArray* arr);

int DynamicArray_get(DynamicArray* arr, int value);
int DynamicArray_pop(DynamicArray* arr);
int DynamicArray_findValue(DynamicArray* arr, int value);
int DynamicArray_size(DynamicArray* arr);
int DynamicArray_capacity(DynamicArray* arr);

bool DynamicArray_isEmpty(DynamicArray* arr);

#endif /* DYNAMIC_ARRAY_H */
