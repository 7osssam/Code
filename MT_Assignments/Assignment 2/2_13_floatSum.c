// 12 - In this challenge write a function to add two floating numbers.
// Determine the integer floor of the sum. The floor is the truncated float value,
// anything after the decimal point is dropped.
// For instance floor(1.1+3.05)=floor(4.15)=4

#include <stdio.h>

int floatSum(float num1, float num2)
{
    float sum = num1 + num2;
    int sumInt = (int)sum;
    return sumInt;
}
int main()
{
    float num1, num2;

    printf("Enter 2 float numbers : ");
    scanf("%f%f", &num1, &num2);

    printf("Sum = %d", floatSum(num1, num2));

    return 0;
}