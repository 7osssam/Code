/*
 ===================================================================================================
 Name        : union_ex.c
 Author      : Mohamed Tarek
 Description : Program to understand how to use unions.
 ===================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

union Data
{
	short x;
	int y;
	int z;
};

int main(void)
{
	union Data D1;
	D1.y = 0xFFFF5555;

	printf("The size of the union : %d\n",sizeof(D1));

	/* member z shall be equals to the same value of y
	 * member x shall be equals to the first two bytes of y
	 */
	printf("value of x : %x\n",D1.x);
	printf("value of y : %x\n",D1.y);
	printf("value of z : %x\n",D1.z);

	D1.x = 0;

	/* member x shall be equals ZERO
	 * First two bytes of member y shall be equals ZERO
	 * First two bytes of member z shall be equals ZERO
	 */
	printf("value of x : %x\n",D1.x);
	printf("value of y : %x\n",D1.y);
	printf("value of z : %x\n",D1.z);

	return 0;
}
