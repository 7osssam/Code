
#include <stdio.h>

  // Function to set the kth bit of num
int setBit(int num, int k)
{
	return (num | (1 << k));  //  OR with 1
}

    // Function to clear the kth bit of num
int clearBit(int num, int k)
{
	return (num & (~(1 << k))); //  AND with 1 complement
}

  // Function to toggle the kth bit of num
int toggleBit(int num, int k)
{
	return (num ^ (1 << k)); // XOR with 1
}

  // Function to find the kth bit of num
int findBit(int num, int k)
{
	return ((num >> k) & 1);  //  Right shift k times and AND with 1

}


void bitOperations(int num, int k, int p)
{

	printf("K= %d bit of %d is %d\n", k, num, findBit(num, k));

	printf("Setting K(= %d)th bit modifies N to %d\n", k, setBit(num, k)); //

	printf("Clearing K(= %d)th bit modifies N to %d\n", k, clearBit(num, k));

	printf("Toggling K(= %d)th bit modifies N to %d\n", k, toggleBit(num, k));
}

int main()
{
	int num = 42, k = 1, p = 1;
	bitOperations(num, k, p);  //  5 = 0101 // 42 = 101010 // 56 = 111000

	return 0;
}
