#include "MemM.h"

// Define a memory pool and a pointer to the head of the free block list
static char *memoryPool = NULL;
static MemoryBlock *freeList = NULL;

/**
 * The function MemM_Init initializes a memory pool with a given size and sets up the initial memory
 * block.
 *
 * @param pool The "pool" parameter is a pointer to the start of a memory pool. A memory pool is a
 * contiguous block of memory that is used for dynamic memory allocation. It is typically pre-allocated
 * and managed by the programmer.
 * @param poolSize The poolSize parameter is the total size of the memory pool that will be used for
 * memory allocation.
 */
void MemM_Init(void *pool, size_t poolSize)
{
	memoryPool = (char *)pool;
	MemoryBlock *initialBlock = (MemoryBlock *)memoryPool;
	initialBlock->size = poolSize - sizeof(MemoryBlock);
	initialBlock->next = NULL;
	freeList = initialBlock;
}

/**
 * The function MemM_Alloc is used to allocate memory blocks of a specified size from a free list.
 *
 * @param size The size parameter represents the number of bytes that need to be allocated for the
 * memory block.
 *
 * @return The function `MemM_Alloc` returns a pointer to the allocated memory block.
 */
void *MemM_Alloc(size_t size)
{
	MemoryBlock *currentBlock = freeList;
	MemoryBlock *previousBlock = NULL;

	while (currentBlock)
	{
		if (currentBlock->size >= size)
		{
			if (currentBlock->size > size + sizeof(MemoryBlock))
			{
				// Split the block if it's larger than needed
				MemoryBlock *newBlock = (MemoryBlock *)((char *)currentBlock + sizeof(MemoryBlock) + size);
				newBlock->size = currentBlock->size - size - sizeof(MemoryBlock);
				newBlock->next = currentBlock->next;
				currentBlock->size = size;
				currentBlock->next = newBlock;
			}

			if (previousBlock)
			{
				previousBlock->next = currentBlock->next;
			}
			else
			{
				freeList = currentBlock->next;
			}

			return (void *)((char *)currentBlock + sizeof(MemoryBlock));
		}

		previousBlock = currentBlock;
		currentBlock = currentBlock->next;
	}

	return NULL; // No suitable block found
}

/**
 * The code defines two functions, MemM_Free and MemM_Stats, which are used for managing memory blocks
 * and tracking memory usage.
 *
 * @param ptr The `ptr` parameter is a pointer to the memory block that needs to be freed.
 *
 * @return In the `MemM_Free` function, nothing is being returned. The function has a `void` return
 * type, which means it does not return any value.
 */
void MemM_Free(void *ptr)
{
	if (!ptr)
		return;

	MemoryBlock *blockToFree = (MemoryBlock *)((char *)ptr - sizeof(MemoryBlock));

	// Insert the freed block back into the free list, keeping it sorted by address
	MemoryBlock *currentBlock = freeList;
	MemoryBlock *previousBlock = NULL;

	while (currentBlock && currentBlock < blockToFree)
	{
		previousBlock = currentBlock;
		currentBlock = currentBlock->next;
	}

	if (!previousBlock)
	{
		blockToFree->next = freeList;
		freeList = blockToFree;
	}
	else
	{
		blockToFree->next = previousBlock->next;
		previousBlock->next = blockToFree;
	}
}

void MemM_Stats()
{
	size_t totalMemory = 0;
	size_t freeMemory = 0;
	MemoryBlock *currentBlock = freeList;

	while (currentBlock)
	{
		freeMemory += currentBlock->size;
		totalMemory += currentBlock->size + sizeof(MemoryBlock);
		currentBlock = currentBlock->next;
	}

	printf("Total Memory: %zu bytes\n", totalMemory);
	printf("Free Memory: %zu bytes\n", freeMemory);
}
