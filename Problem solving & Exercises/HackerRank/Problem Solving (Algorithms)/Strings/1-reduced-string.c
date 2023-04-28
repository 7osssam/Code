//? https://www.hackerrank.com/challenges/reduced-string/problem
// Remove the repeated characters in a string until there is no repeated characters left in the string
// and return the new string. If the final string is empty, return "Empty String".
#include <stdio.h>

char *superReducedString(char *str) // return the new string after removing the repeated characters
{
    int i, j, newPos; // newPos is the new position of the character after removing the repeated characters

    for (i = 0; str[i] != '\0'; i++) //! <<
    {
        if (str[i] == str[i + 1]) // if the current character is equal to the next character
        {
            newPos = i; // set the new position to the current position
            // newPos = 0 is wrong because it will start from the beginning of the string

            for (j = i + 2; str[j] != '\0'; j++) // start from the next character after the repeated character
            {
                str[newPos] = str[j]; // copy the character to the new position
                newPos++;             // increment the new position
            }

            str[newPos] = 0; //! null at the end

            i = -1; //! reset the counter to start from the beginning
            // i = 0 is wrong because i will be incremented to 1 //!^^ (i++)
        }
    }

    if (str[0] == '\0') // if the string is empty (first character is null)
    {
        str = "Empty String"; // set the string to "Empty String"
    }

    return str;

    // to return the new string, we create a char pointer (in the main function) and assign it to the return value
    // fro example:
    // char str[100];
    // char *str_new;

    // gets(str);
    // str_new = superReducedString(str);

    // puts(str_new);
}

int main()
{
    char str[100];
    char *str_new;

    gets(str);
    str_new = superReducedString(str);

    puts(str_new);

    return 0;
}