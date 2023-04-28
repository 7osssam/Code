/******************************************************************************
(21)Write a C function to return an array containing the values between two 8-bits unsigned integers
IN DESCENDING ORDER INCLUSIZE.The function takes 2 values (LowerValueand UpperValue),
it shall determine the values in between, and then arrange the sequence in descending order
including the upper and lower values.

If the LowerValue is greater than the UpperValue, return an array of 2 elements,
both containing value = 0xFF
Ex: Input: LowerValue = 2 and UpperValue = 5
    Output: Output Array = 5,4,3,2 Output Array Size = 4
*******************************************************************************/
#include <stdio.h>
// literally the same as the previous one, except for the for loop condition (line 50)

// we can create a global array and return it from the function instead of passing it as a parameter
unsigned char *NuminBetweenINCLUSIZE(unsigned char LowerValue, unsigned char UpperValue, unsigned char *size, unsigned char *OutputArray) // DESCENDING ORDER
{
    *size = 0;

    if (LowerValue >= UpperValue || (UpperValue - 1 == LowerValue))
    {
        OutputArray[0] = 0xFF;
        OutputArray[1] = 0xFF;

        *size = 2;

        return OutputArray;
    }
    else
    {
        for (int i = UpperValue; i >= LowerValue; i--)
        {
            OutputArray[*size] = i;
            (*size)++;
        }
    }
    return OutputArray;
}
int main()
{
    unsigned char LowerValue;
    unsigned char UpperValue;
    unsigned char size = 0;
    unsigned char OutputArray[255];

    puts("Enter Upper and Lower Values");
    scanf("%d", &UpperValue);
    scanf("%d", &LowerValue);

    unsigned char *arr = NuminBetweenINCLUSIZE(LowerValue, UpperValue, &size, OutputArray);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nOutput Array Size = %d", size);
    return 0;
}