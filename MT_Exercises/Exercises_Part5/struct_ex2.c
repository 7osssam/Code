/*
 ===================================================================================================
 Name        : struct_ex2.c
 Author      : Mohamed Tarek
 Description : Program to understand how to create and access array of structures.
 ===================================================================================================
 */

#include<stdio.h>
#include<string.h> //for strcpy function

struct student
{
    int id;
    char name[30];
}record[2];

int main(void)
{
    // 1st student's record
    record[0].id=1;
    strcpy(record[0].name, "Khaled");
    // 2nd student's record
    record[1].id=2;
    strcpy(record[1].name, "Ayman");
    printf("%d %s\n%d %s", record[0].id, record[0].name,record[1].id, record[1].name);
    return 0;
}
