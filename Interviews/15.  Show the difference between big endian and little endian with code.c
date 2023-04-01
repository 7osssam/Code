#include <stdio.h>

int main()
{
  int x = 0x12345678;
  char *ptr =(char*) &x;
  printf("%x",*ptr);
    return 0;
}
