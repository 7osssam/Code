/*
6.Create Union type called family_name it shall have two members first_name and last_name.
The two members are array of characters with same size 30.
Try to write string in the first member first_name then print the second member last_name plus print the size of the union.
*/

#include <stdio.h>
#define arr_size 30
typedef union family_name
{
    char first_name[arr_size];
    char last_name[arr_size];

} family_name;

int main()
{
    family_name test;
    printf("Enter First name:");
    scanf("%s", test.first_name);

    printf("Print of Last name is : %s\n", test.last_name);
    printf("size of union = %d", sizeof(test));
}