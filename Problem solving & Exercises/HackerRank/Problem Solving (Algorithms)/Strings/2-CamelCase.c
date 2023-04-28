//? https://www.hackerrank.com/challenges/camelcase/problem/
// count the number of words starting with a capital letter in a string (CamelCase)
#include <stdio.h>

int CamelCase(char *str) // Function to count the number of words starting with a capital letter in a string
{
    int i;
    int wordCounter = 1; // The first word is always counted
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') // If the character is a capital letter
        {
            wordCounter++;
        }
    }
    return wordCounter;
}

int main()
{
    char str[100000]; // The string is limited to 100000 characters

    gets(str);

    printf("%d", CamelCase(str));

    return 0;
}