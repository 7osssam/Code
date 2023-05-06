/*
5.C Function to store information (name, id and grade) for 10 students in array of structures using pointers
and another function to print all the structures using pointers.
*/

#include <stdio.h>
#define size 3

typedef struct Data
{
    char name[10];
    int id;
    float grade;
} Data;

void GetData(Data *Ptrstudent)
{
    for (int i = 1; i <= size; i++)
    {
        printf("\nEntar data for student %d:\n", i);
        printf("Enter Name:");
        scanf("%s", &Ptrstudent->name);
        printf("Enter ID:");
        scanf("%d", &Ptrstudent->id);
        printf("Enter grade:");
        scanf("%f", &Ptrstudent->grade);
        Ptrstudent++;
    }
}

void PrintData(Data *Ptrstudent)
{
    for (int i = 1; i <= size; i++)
    {
        printf("\nData for student %d:\n", i);
        printf("Name: %s\n", Ptrstudent->name);

        printf("ID: %d\n", Ptrstudent->id);

        printf("grade: %.2f\n", Ptrstudent->grade);
        Ptrstudent++;
    }
}
int main()
{
    Data student[size];
    Data *ptr = student; // pointer from type struct Data

    GetData(ptr);
    PrintData(student);
}