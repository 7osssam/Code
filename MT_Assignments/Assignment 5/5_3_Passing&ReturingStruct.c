/*
3.C function to add two complex numbers by passing two structure to a function and display the results.
*/

#include <stdio.h>
typedef struct
{
    int real;
    int imaginary;
} Complex;

Complex AddComplex(Complex *ptr1, Complex *ptr2)
{
    Complex temp_result;
    temp_result.real = ptr1->real + ptr2->real;
    temp_result.imaginary = ptr1->imaginary + ptr2->imaginary;

    return temp_result;
}

int main()
{
    Complex num1 = {8, 7};
    Complex num2 = {4, 3};
    Complex result;

    result = AddComplex(&num1, &num2);
    printf("Sum = %d + %di", result.real, result.imaginary);
}