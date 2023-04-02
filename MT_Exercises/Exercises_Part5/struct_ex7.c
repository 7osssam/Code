/*
 ===================================================================================================
 Name        : struct_ex7.c
 Author      : Mohamed Tarek
 Description : Program to understand how to use self-referential structure.
 ===================================================================================================
 */

#include <stdio.h>

struct student
{
    char *first_name;
    char *second_name;
    int id;
    float grade;
    struct student *struct_ptr;
    //struct student s1; it will produce error
}s1,s2;

int main(void)
{
    /* write s1 values using s_ptr */
    s1.first_name = "Mohamed";
    s1.second_name = "Tarek";
    s1.id = 1;
    s1.grade = 95.75;
    s1.struct_ptr = &s2; //points to s2 student structure object

    /* change s2 values using the pointer in s1 */
    s1.struct_ptr->first_name = "Ahmed";
    s1.struct_ptr->second_name = "Khaled";
    s1.struct_ptr->id = s1.id+1;
    s1.struct_ptr->grade = 70;
    s1.struct_ptr->struct_ptr = NULL;

    printf("Student 1 Information :\n");
    printf("Name : %s %s\nID: %d\nGrade:%f\n\n",s1.first_name,s1.second_name,s1.id,s1.grade);


    printf("Student 2 Information :\n");
    printf("Name : %s %s\nID: %d\nGrade:%f\n\n",s2.first_name,s2.second_name,s2.id,s2.grade);

    return 0;
}

