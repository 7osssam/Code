#include <stdio.h>

int stringLen(unsigned char *str) // return the length of the string without the null character
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;

    // while(str[i++] != 0); // same as above

    return i;
}

void stringPrint(unsigned char *str) // same as puts(str)
{
    int i;
    for (i = 0; str[i] != 0; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n"); // new line
}

void stringScan(unsigned char *str) // same as gets(str)
{
    int i;
    for (i = 0;; i++) // infinite loop until user enters new line
    {
        scanf("%c", &str[i]);

        if (str[i] == '\n') // break when a new line is entered
            break;

        // for (i = 0; str[i] != '\n'; i++) is not working it iterates i++ then checks the condition
        // so it will not stop at new line and will go out of the array
    }
    str[i] = 0; //! null at the end
}

void stringReverse(unsigned char *str) // using stringLen function
{
    int i, strSize = stringLen(str);
    unsigned char temp;
    for (i = 0; i < strSize / 2; i++)
    {
        temp = str[i];
        str[i] = str[strSize - 1 - i];
        str[strSize - 1 - i] = temp;
    }
}

void stringCopy(unsigned char *strFrom, unsigned char *strTo) // copy from array of char to empty array of char
{
    int i;
    for (i = 0; strFrom[i] != '\0'; i++)
    {
        strTo[i] = strFrom[i];
    }
    strTo[i] = 0; //! null at the end
}

void stringUpper(unsigned char *str) // convert string to upper case
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if ('a' <= str[i] && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
}

void stringLower(unsigned char *str) // convert string to lower case
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

int stringComp(unsigned char *str1, unsigned char *str2) // return 1 if equal and 0 if not equal (using index)
{
    int i, isEqual = 1; // equal by default

    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) // loop until one of the strings is null
    {
        if (str1[i] != str2[i])
        {
            isEqual = 0; // not equal
            break;
        }
    }
    // last character should be null on both strings
    if (str1[i] != str2[i])
    {
        isEqual = 0; // not equal
    }
    return isEqual;
}

int stringComp2(unsigned char *str1, unsigned char *str2) // return 1 if equal and 0 if not equal (using pointers)
{
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) // loop until one of the strings is null or the characters are not equal
    {                                                        // if one of them is false the loop will stop
        // increment the pointer
        str1++;
        str2++;
    }
    return (*str1 == 0 && *str2 == 0); // return 1 if both strings are null
}

void stringLongestWord(unsigned char *str, unsigned char *word) // find the longest word in a string and copy it to word array
{
    int i, Counter = 0, Max = 0, indexOfMax;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ') // if space
        {
            Counter = 0; // reset counter
        }
        else // if not space
        {
            Counter++; // increment counter

            if (Counter > Max) // if counter is greater than max
            {
                Max = Counter;            // update max
                indexOfMax = i - Max + 1; // update index of max
                // i is the index of the last char in the word & max is the length of the word
            }
        }
    }

    //? testing
    // printf("\ncount %d\n", Counter); // count the last word
    // printf("Max %d", Max);           // length of the longest word
    // for (i = indexOfMax; i < +indexOfMax + Max; i++) // loop on the longest word to print it, it's still at str array
    // {
    //     printf("%c", str[i]);
    // }

    for (i = 0; i < Max; i++) // copy the longest word to word array
    {
        word[i] = str[indexOfMax + i]; // i in str[indexOfMax + i] act as a counter
    }
    word[i] = 0; //! null at the end
}

int stringToInt(unsigned char *str) // convert string to int (only numbers)
{
    int i, num = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ('1' <= str[i] && str[i] <= '9') // if the char is a number
        {
            num = num * 10; // shift the number to the left

            num = num + (str[i] - '0'); // add the number to the right of the shifted number (previous number)
        }
    }
    return num;
}

void intToSting(int num, unsigned char *str) // convert int to string
{
    int mod;            // remainder
    int i = 0;          // index
    int isNegative = 0; // flag

    if (num < 0) // if the number is negative
    {
        isNegative = 1; // set the flag
        num = num * -1; // make the number positive
    }

    do // we use do while to make sure that the loop will run at least once even if the number is 0
    {
        mod = num % 10;       // get the remainder
        str[i++] = mod + '0'; // convert the remainder to char and put it in the array and increment the index

        num = num / 10; // update the number (remove the last digit)

    } while (num > 0); // num is positive

    if (isNegative) // if the number is negative
    {
        str[i++] = '-'; // put the negative sign at the end of the string and increment the index
    }
    str[i] = 0; //! null at the end

    /*
     the array of this number is reversed
     so we need to reverse it (we can use the function we made before)
     but this is better because we didn't stringlength function,
     we already have the index of the last char in the array (i)
    ! but note that i is the index of the null char so we need to decrement it by 1
    */

    i--; // decrement i by 1

    char temp = 0;                   // temp char to swap
    for (int k = 0; k <= i / 2; k++) // don't forget = in <= (if the number is 2 digits)
    {
        temp = str[k];
        str[k] = str[i - k];
        str[i - k] = temp;
    }
}

unsigned char stringMostRepeatedChar(unsigned char *str)
{
    int i, j;
    int Counter = 0, Max = 0;
    unsigned char C;
    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = i + 1; str[j] != '\0'; j++)
        {
            if (str[i] == ' ')
            {
                continue;
            }
            if (str[i] == str[j])
            {
                Counter++;
            }
            if (Counter > Max)
            {
                Max = Counter;
                C = str[i];
            }
        }
        Counter = 0;
    }

    return C;
}

int main()
{
    unsigned char str[100] = " 2  ahlyhse 2 2  ahmed   ali ererwerewwemjk mohamedmo@@412fdff";

    unsigned char str3[20] = "Hello World";
    unsigned char str2[20] = "Hello ";

    unsigned char str4[20] = "123456";
    unsigned char word[20];

    int num = 0;
    unsigned char stingNum[20];

    unsigned char str5[20] = "Hossam       ";
    printf("%c", stringMostRepeatedChar(str5));

    // stringPrint(stingNum); // before
    // intToSting(num, stingNum);
    // stringPrint(stingNum); // after

    // printf("%d", stringToInt(str4));
    //  stringLongestWord(str, word);
    //   stringReverse(str);

    // stringComp2(str2, str3) ? printf("Equal") : printf("Not Equal");
    //  printf("%s", str);

    return 0;
}