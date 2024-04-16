// main.c
#include <stdio.h>
#include "var1.h"
#include "var2.h"

int main()
{
	printf("Var1: %d\n", var1);
	printf("Var2: %d\n", var2);
	return 0;
}

// gcc main.c variables.c -o out
// ./out