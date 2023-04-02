/*
 ===================================================================================================
 Name        : struct_ex6.c
 Author      : Mohamed Tarek
 Description : Program to understand how to declare a structure inside another structure.
 ===================================================================================================
 */

#include <stdio.h>

struct employee
{
	char name[100];
	int age;
	float salary;
	struct address
	{
		int houseNumber;
        char street[100];
    }location;
};

int main(void){
   struct employee employee_one;

   printf("Enter Name, Age, Salary of Employee : \n");
   scanf("%s %d %f", employee_one.name, &employee_one.age,&employee_one.salary);

   printf("Enter House Number and Street of Employee : \n");
   scanf("%d %s", &employee_one.location.houseNumber,employee_one.location.street);

   printf("Employee Details :\n");
   printf(" Name : %s\n Age : %d\n Salary = %f\n House Number : %d\n Street : %s\n", \
   employee_one.name, employee_one.age, employee_one.salary, \
   employee_one.location.houseNumber, employee_one.location.street);

   return 0;
}
