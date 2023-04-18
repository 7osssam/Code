/******************************************************************************
(14)Write a function to reverse a string by passing it to a function.
*******************************************************************************/
#include <stdio.h>

int stringLen(char *str) // return the length of the string without the null character
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;

    return i;
}

void stringReverse(char *str) // using stringLen function
{
    int i, strSize = stringLen(str);
    unsigned char temp;
    for (i = 0; i < strSize / 2; i++)
    {
        temp = str[i];
        str[i] = str[strSize - i - 1];
        str[strSize - i - 1] = temp;
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    gets(str);

    stringReverse(str);
    puts(str);

    return 0;
}