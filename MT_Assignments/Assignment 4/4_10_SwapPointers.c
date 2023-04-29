// (10) Write a c function two SWAP two pointers.Hint: use pointer to pointer as a function argument.

#include <stdio.h>

// we are swapping the addresses that the pointers are pointing to
void SwapPointers(int **ptr1, int **ptr2) // pointer to pointer
{
    int *temp; // pointer to int

    temp = *ptr1;  // temp points to the address that ptr1 is pointing to
    *ptr1 = *ptr2; // ptr1 points to the address that ptr2 is pointing to
    *ptr2 = temp;  // ptr2 points to the address that temp is pointing to
}

int main()
{

    int *ptr1;
    int *ptr2;

    printf("%p %p\n", ptr1, ptr2); // before swap
    SwapPointers(&ptr1, &ptr2);
    printf("%p %p\n", ptr1, ptr2); // after swap
}