/*
 ===================================================================================================
 Name        : pointers_ex7.c
 Author      : Mohamed Tarek
 Description : Program to understand the idea of pointer to array.
 ===================================================================================================
 */

#include <stdio.h>

int main(void)
{
	long Arr2D[2][2]={{1,2},{3,4}};
	long (*Arr2D_ptr)[2] = Arr2D; // pointer to array with 2 elements
	printf("Start Address of the first Array : %p\n",&Arr2D[0][0]);
	printf("Start Address of the first Array : %p\n",Arr2D);
	printf("Start Address of the first Array : %p\n",*Arr2D);
	printf("Start Address of the first Array : %p\n",Arr2D[0]);
	printf("Start Address of the first Array : %p\n",*Arr2D_ptr);
	Arr2D_ptr++;
	printf("Start Address of the second Array : %p\n",&Arr2D[1][0]);
	printf("Start Address of the second Array : %p\n",Arr2D+1);
	printf("Start Address of the second Array : %p\n",*(Arr2D+1));
	printf("Start Address of the second Array : %p\n",Arr2D[1]);
	printf("Start Address of the second Array : %p\n",*Arr2D_ptr);
    return 0 ;
}


