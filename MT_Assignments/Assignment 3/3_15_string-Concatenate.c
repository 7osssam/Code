/******************************************************************************
(15)Write a function to concatenate two strings without using strcat function.
*******************************************************************************/
#include <stdio.h>
void stringConcatenate(char *str1, char *str2, char *strCON)
{
    //! concatenate str2 to str1 means str1 = str1 + str2 not adding them in a new string
    int i, j;
    /* This loop is to store the length of str1 in i
     * It just counts the number of characters in str1
     * You can also use strlen instead of this.
     */
    for (i = 0; str1[i] != '\0'; ++i)
        ;

    /* This loop would concatenate the string str2 at
     * the end of str1
     */
    for (j = 0; str2[j] != '\0'; ++j, ++i)
    {
        str1[i] = str2[j];
    }
    /* \0 represents end of string */
    str1[i] = '\0';

    //============== old solution ==============
    // int i;
    // int strCounter = 0; // counter for the new string

    // for (i = 0; str1[i] != '\0'; i++) // loop until the end of the first string
    // {
    //     strCON[strCounter] = str1[i]; // copy the character from the first string to the new string
    //     strCounter++;                 // increment the counter
    // }

    // for (i = 0; str2[i] != '\0'; i++) // loop until the end of the second string
    // {
    //     strCON[strCounter] = str2[i]; // copy the character from the second string to the new string
    //     strCounter++;                 // increment the counter
    // }

    // strCON[strCounter] = 0; //! null at the end
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