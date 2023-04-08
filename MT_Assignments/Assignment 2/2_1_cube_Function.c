// 1 - Write a C Function that prints the cube of any number
#include <stdio.h>

long cube(int num)
{
    return num * num * num; // return the cube of the number
}

int main()
{
    int num; // declare a variable to store the number

    printf("Enter num : ");
    scanf("%d", &num);

    printf("Cude of %d = %ld", num, cube(num)); // call the function and print the result

    return 0;
}