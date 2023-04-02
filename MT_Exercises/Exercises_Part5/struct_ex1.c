/*
 ===================================================================================================
 Name        : struct_ex1.c
 Author      : Mohamed Tarek
 Description : Program to understand how to access the structure members.
 ===================================================================================================
 */

#include <stdio.h>

struct student
{
    char *first_name;
    char *second_name;
    int id;
    float grade;
};

int main(void)
{
    struct student s1={"Mohamed","Tarek",1,95.75}; //initialization like array must be in th
    struct student s2,s3;

    s2.first_name = "Ahmed";
    s2.second_name = "Khaled";
    s2.id = s1.id+1;
    s2.grade = 70;

    s3=s2;
    s3.grade = 80;

    printf("Student 1 Information :\n");
    printf("Name : %s %s\nID: %d\nGrade:%f\n\n",s1.first_name,s1.second_name,s1.id,s1.grade);

    printf("Student 2 Information :\n");
    printf("Name : %s %s\nID: %d\nGrade:%f\n\n",s2.first_name,s2.second_name,s2.id,s2.grade);

    printf("Student 3 Information :\n");
    printf("Name : %s %s\nID: %d\nGrade:%f\n\n",s3.first_name,s3.second_name,s3.id,s3.grade);

    return 0;
}
