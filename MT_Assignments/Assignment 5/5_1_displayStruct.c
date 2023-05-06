/*
1.C Program to store information (name, roll and marks) for a student using structure and display it.
*/

#include <stdio.h>

typedef struct
{
    char name[20];
    int ID;
    float marks;

} student;

int main()
{
    student d1;
    printf("Enter student data (name, id and marks)\n");
    scanf("%s%d%f", &d1.name, &d1.ID, &d1.marks);

    printf("You have entered %s %d %.2f", d1.name, d1.ID, d1.marks);
}