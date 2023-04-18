/******************************************************************************
(12)Write a function to find the length of a string.
*******************************************************************************/
#include <stdio.h>

int stringLen(char *str) // return the length of the string without the null character
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    // while(str[i++] != 0); // same as above

    return i;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);
    printf("The length of the string is: %d", stringLen(str));
    return 0;
}