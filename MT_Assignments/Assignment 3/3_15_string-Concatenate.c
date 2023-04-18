/******************************************************************************
(15)Write a function to concatenate two strings without using strcat function.
*******************************************************************************/
#include <stdio.h>
void stringConcatenate(char *str1, char *str2, char *strCON)
{
    int i;
    int strCounter = 0; // counter for the new string

    for (i = 0; str1[i] != '\0'; i++) // loop until the end of the first string
    {
        strCON[strCounter] = str1[i]; // copy the character from the first string to the new string
        strCounter++;                 // increment the counter
    }

    for (i = 0; str2[i] != '\0'; i++) // loop until the end of the second string
    {
        strCON[strCounter] = str2[i]; // copy the character from the second string to the new string
        strCounter++;                 // increment the counter
    }

    strCON[strCounter] = 0; //! null at the end
}
int main()
{
    char str1[] = "Hossam ";
    char str2[] = "is efjw2403d";

    char strCON[sizeof(str1) + sizeof(str2)];

    puts(str1);
    puts(str2);

    stringConcatenate(str1, str2, strCON);

    puts(strCON);
}