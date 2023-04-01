#include <stdio.h>
#define SWAP_INT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
void memory_represent(char *value, int n) {
   int i;
   for (i = 0; i < n; i++)
      printf(" %.2x", value[i]);
}
int main() 
{
   unsigned int x = 0x9876543210;
   int y;
     printf("Little endian value is: ");
   memory_represent((char*)&x, sizeof(x));
   
   y = SWAP_INT32(x);
   printf("\nBig endian value is: ");
   memory_represent((char*)&y, sizeof(y));
   
}
