/******************************************************************************
(2) Write a function which, given a string,
return TRUE if all characters are distinct and FALSE if any character is repeated.
*******************************************************************************/

#include <stdio.h>

int stringIsCharRepeated(char *str) // function to check if the string has repeated characters
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = i; str[j] != '\0'; j++)
        {
            if (str[i] == ' ') // if the character is a space, skip it
            {
                continue;
            }

            if (str[i] == str[j + 1]) // if the character is repeated, return 0
            {
                return 0;
            }
        }
    }

    return 1;
}
int main()
{
    char str[10];
    int flag;

    gets(str);
    flag = stringIsCharRepeated(str);

    if (flag == 1)
    {
        puts("[TRUE] Distinct");
    }
    else
    {
        puts("[FALSE] Repeated");
    }
}