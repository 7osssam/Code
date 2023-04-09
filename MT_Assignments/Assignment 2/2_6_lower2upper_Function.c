// Write C Function that converts the any letter from lowercase to uppercase

#include <stdio.h>

char ConvertLower2Upper(char ch)
{
    // Convert lowercase letter to uppercase by subtracting 32 from its ASCII code
    if (ch >= 'a' && ch <= 'z')
        return ch - 32; // or return ch - 'a' + 'A';

    // Return the same input letter if it is already uppercase
    if (ch >= 'A' && ch <= 'Z')
        return ch;

    return 0; // return 0 when the input is not a letter
}

int main()
{
    char ch;

    printf("Enter char :");
    scanf("%c", &ch);

    if (ConvertLower2Upper(ch)) // if the input is a letter
    {
        printf("%c in uppercase is %c", ch, ConvertLower2Upper(ch));
    }
    else // if the input is not a letter
    {
        printf("ERROR: not a char");
    }

    // equivalent to the above if-else statement
    // ConvertLower2Upper(ch) ? printf("%c in uppercase is %c", ch, ConvertLower2Upper(ch)) : printf("ERROR: not a char");

    return 0;
}