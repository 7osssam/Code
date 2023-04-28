/******************************************************************************
(20) Write a C function to return an array containing the values between two 8-bits unsigned integers
IN DESCENDING ORDER EXCLUSIVE. The function takes 2 values (LowerValueand UpperValue),
it shall determine the values in between, and then arrange the sequence in descending order
excluding the upper and lower values.

If the LowerValue is greater than or equal the UpperValue, return an array of 2 elements,
both containing value = 0xFF
Ex: Input: LowerValue = 2 and UpperValue = 5
    Output: Output Array = 4,3 Output Array Size = 2
*******************************************************************************/
#include <stdio.h>

// we can create a global array and return it from the function instead of passing it as a parameter
unsigned char *NuminBetweenEXCLUSIVE(unsigned char LowerValue, unsigned char UpperValue, unsigned char *size, unsigned char *OutputArray) // DESCENDING ORDER
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
        for (int i = UpperValue - 1; i > LowerValue; i--)
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

    unsigned char *arr = NuminBetweenEXCLUSIVE(LowerValue, UpperValue, &size, OutputArray);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nOutput Array Size = %d", size);
    return 0;
}