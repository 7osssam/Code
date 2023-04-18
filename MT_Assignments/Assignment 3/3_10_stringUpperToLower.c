/******************************************************************************
(10)Write a function which, given a string, converts all uppercase letters to lowercase,
leaving the others unchanged.
*******************************************************************************/

#include <stdio.h>

void stringLower(char *str) // convert string to lower case
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
}

int main()
{
    char str[] = "THIS is a TEST";
    puts("Before:");
    puts(str);

    stringLower(str);

    puts("After");
    puts(str);
}