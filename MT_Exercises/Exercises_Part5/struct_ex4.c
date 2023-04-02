/*
 ===================================================================================================
 Name        : struct_ex4.c
 Author      : Mohamed Tarek
 Description : Program to understand how to pass structure to a function by value/address.
 ===================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct student
{
    char *first_name;
    char *second_name;
    int id;
    float grade;
};

void Student_By_Value(struct student s)
{
    s.first_name = "Ahmed";
    s.second_name = "khaled";
    s.grade = 50;
    s.id = 2;
}

void Student_By_Reference(struct student *s_ptr)
{
    s_ptr->first_name = "Ahmed";
    s_ptr->second_name = "khaled";
    s_ptr->grade = 50;
    s_ptr->id = 2;
}

int main(void)
{
    struct student s1={"Mohamed","Tarek",1,95.75}; //intialization like array must be in th
    printf("Student 1 Information :\n");
    printf("Name : %s %s\nID: %d\nGrade:%f\n\n",s1.first_name,s1.second_name,s1.id,s1.grade);

    Student_By_Value(s1); //pass s1 by value
    printf("Student 1 Information :\n");
    printf("Name : %s %s\nID: %d\nGrade:%f\n\n",s1.first_name,s1.second_name,s1.id,s1.grade);

    Student_By_Reference(&s1); //pass s1 by address
    printf("Student 1 Information :\n");
    printf("Name : %s %s\nID: %d\nGrade:%f\n\n",s1.first_name,s1.second_name,s1.id,s1.grade);
    return 0;
}
