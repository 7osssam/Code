#ifndef MEMM_H
#define MEMM_H

#include <stdio.h>

// Define the memory block structure
typedef struct MemoryBlock
{
	size_t size;
	struct MemoryBlock *next;
} MemoryBlock;

// Initialize the memory manager
void MemM_Init(void *memoryPool, size_t poolSize);

// Allocate memory
void *MemM_Alloc(size_t size);

// Free allocated memory
void MemM_Free(void *ptr);

// Display memory usage statistics
void MemM_Stats();

#endif // MEMM_H
