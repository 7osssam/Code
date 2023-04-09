// 9 - Write a C Function that swaps the value of two integer numbers

#include <stdio.h>

void Swap(int *num1, int *num2) // using temp variable
{
    int temp;
    temp = *num1;  // save the value of num1
    *num1 = *num2; // assign the value of num2 to num1
    *num2 = temp;  // assign the saved value of num1 to num2
}

int main()
{
    int num1, num2;
    printf("Enter 2 numbers to swap: ");
    scanf("%d%d", &num1, &num2);

    Swap(&num1, &num2);
    printf("After swapping: %d %d", num1, num2);
}