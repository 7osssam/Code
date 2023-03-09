#include <stdio.h>

int main(void) {

	int n, sum;
	printf("Enter the value of n: ");
	scanf("%d", &n);

	sum = n*(n+1)/2;

	printf("sum = %d\n", sum);

	return 0;
}
