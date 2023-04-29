// (7) C function to swap two numbers using bitwise operation and call it using pointer to function.

#include <stdio.h>

// swap two numbers using bitwise operation
void swapBitwise(int *num1, int *num2)
{
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}
int main()
{
    int num1 = 3, num2 = 5;
    void (*PtrFun)(int *, int *) = swapBitwise; // pointer to function that takes two pointers to int and returns void

    printf("num1: %d num2: %d", num1, num2); // before swap

    (*PtrFun)(&num1, &num2); // call the function using the pointer to function

    printf("\nnum1: %d num2: %d", num1, num2); // after swap
}