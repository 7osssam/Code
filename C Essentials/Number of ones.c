#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE sizeof(int) * 8 /* Total number of bits in integer */

int ones(int num)
{
  int ones = 0, test; // ,zeros=0
  for (size_t i = 0; i < INT_SIZE; i++)
  {
    // test = num&(1<<i);
    if (num & 1) // (num >> i ) & 1
      ones++;

    num >>= 1; // num = num >>1
  }
  return ones;
}
int main()
{
  unsigned int num = 2286;

  printf("%d", ones(num));

  return 0;
}
