// 2 - Write a C Function that takes one character and checks if it alphabet or not.

#include <stdio.h>

int CheckChar(char ch) // Function to check if the character is an alphabet or not
{
    if ('A' <= ch && ch <= 'Z' || 'a' <= ch && ch <= 'z') // if character is between A-Z or a-z
    {
        return 1;
    }

    return 0; // if character is not an alphabet
}

int main()
{
    char ch;
    printf("Enter Char to check ");
    scanf("%c", &ch);

    if (CheckChar(ch)) // CheckChar(ch) is same as CheckChar(ch) == 1
    {
        printf("%c is an alphabet", ch);
    }
    else
    {
        printf("This is NOT an alphabet");
    }

    return 0;
}