/*
 ===================================================================================================
 Name        : struct_ex5.c
 Author      : Mohamed Tarek
 Description : Program to understand how to pass structure member to a function by value/address.
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

void Student_member_by_Value(int id)
{
    id = 2;
}

void Student_member_by_Reference(int * ptr_id)
{
   *ptr_id = 2;
}

int main(void)
{
    struct student s1={"Mohamed","Tarek",1,95.75}; //initialization like array must be in th
    printf("Student 1 Information :\n");
    printf("Name : %s %s\nID: %d\nGrade:%f\n\n",s1.first_name,s1.second_name,s1.id,s1.grade);

    Student_member_by_Value(s1.id); //pass s1.id by value
    printf("Student 1 Information :\n");
    printf("Name : %s %s\nID: %d\nGrade:%f\n\n",s1.first_name,s1.second_name,s1.id,s1.grade);

    Student_member_by_Reference(&s1.id); //pass s1.id by address
    printf("Student 1 Information :\n");
    printf("Name : %s %s\nID: %d\nGrade:%f\n\n",s1.first_name,s1.second_name,s1.id,s1.grade);
    return 0;
}
