/******************************************************************************
(13)Write a function to remove all characters in a string expect alphabet.
*******************************************************************************/
#include <stdio.h>

void removeNonAlphabets(char *str) // remove all characters in a string expect alphabet
{
    int i, position = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) // check if the char is alphabet
        {
            str[position] = str[i]; // add the char to the new string

            position++; // increment the position
        }
    }
    str[position] = '\0'; // !add null char at the end of the string
}

int main()
{
    char str[] = "A5hme@$D";
    puts(str);
    removeNonAlphabets(str);
    puts(str);
}