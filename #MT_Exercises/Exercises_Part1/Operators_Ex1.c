/*
 ===================================================================================================
 Name        : Operators_Ex1.c
 Author      : Mohamed Tarek
 Description : Code to demonstrate the capability of the arithmetic operators
 ===================================================================================================
 */

#include <stdio.h>

int main(void)
{

   int a = 21;
   int b = 10;
   int c;

   /* Addition operator */
   c = a + b;
   printf("Value of c is %d\n", c);

   /* Subtraction operator */
   c = a - b;
   printf("Value of c is %d\n", c);

   /* Multiplication operator */
   c = a * b;
   printf("Value of c is %d\n", c);

   /* division operator */
   c = a / b;
   printf("Value of c is %d\n", c);

   /* Reminder operator */
   c = a % b;
   printf("Value of c is %d\n", c);

   /* Post Increment operator */
   c = a++;
   printf("Value of c is %d\n", c);

   /* Post Decrement operator */
   c = a--;
   printf("Value of c is %d\n", c);

   /* Pre Increment operator */
   c = ++b;
   printf("Value of c is %d\n", c);

   /* Pre Decrement operator */
   c = --b;
   printf("Value of c is %d\n", c);

   return 0;
}
