#include "MemM.h"
#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 1024

int main()
{
	// Create a memory pool of 1024 bytes
	char memoryPool[MEM_SIZE];

	// Initialize the memory manager
	MemM_Init(memoryPool, sizeof(memoryPool));

	// Allocate memory
	int *ptr1 = (int *)MemM_Alloc(sizeof(int));
	int *ptr2 = (int *)MemM_Alloc(2 * sizeof(int));

	if (ptr1 && ptr2) // Check if memory allocation was successful
	{
		*ptr1 = 42;
		ptr2[0] = 10;
		ptr2[1] = 20;

		// Display memory usage statistics
		MemM_Stats();

		// Free allocated memory
		MemM_Free(ptr1);
		MemM_Free(ptr2);

		// Display memory usage statistics after freeing
		MemM_Stats();
	}
	else
	{
		printf("Memory allocation failed.\n");
	}

	return 0;
}
