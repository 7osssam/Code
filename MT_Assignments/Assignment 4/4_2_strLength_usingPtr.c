//(2) C Program to find length of a given string using pointer

#include <stdio.h>
int strLengthPtr(char *ptr)
{
    int i;
    for (i = 0; ptr[i] != '\0'; i++)
        ;
    return i;
}
int main()
{
    char str[50] = "this is a test";
    char *ptr = str;

    printf("String length (using pointer): %d", strLengthPtr(ptr));
}