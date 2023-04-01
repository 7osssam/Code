#include <stdio.h>

void trick1()
{
  printf("\n%d %d %d %d", sizeof(5), sizeof(500), sizeof('a'), sizeof("a")); // int , int , int , array of char // output: 4 4 4 2
  printf("\n%d %d %d", sizeof(3.14), sizeof(3.14f), sizeof("3.14"));         // double , float , array of char // output: 8 4 5
}

void trick2()
{
  int a = 5, b;
  b = a++ + ++a;                   // b = 5 + 7 = 12
  printf("\na = %d b = %d", a, b); // a = 7 b = 12
}

void trick3()
{
  int x = 1, y = 1, z = 1, k;
  // k = ++x || ++y && ++z; // x = 2, y = 1, z = 1, k = 1
  // k = ++x && ++y || ++z; // x = 2, y = 2, z = 1, k = 1

  printf("\nx = %d y = %d z = %d k = %d", x, y, z, k);
}

void trick4()
{
  unsigned int i, size = 5;
  for (i = size; i >= 0; i--) // infinite loop because when i = 0, i-- = 4294967295
  {
    printf("\n%d", i);
  }
}

void trick5()
{
  float x = 9.3f / 3.0f;
  if (x == 3.1f)
  {
    printf("\nEqual");
  }
  else
  {
    printf("\nNot Equal");
  }
}

void trick6()
{
  int x, y;
  x = 5;
  switch (x)
  {
  case 3:
    printf("\n3");

  case 4:
    printf("\n4");

  case 5:
    printf("\n5");
  }
}

void trick7()
{
  int i = 0;
  do
  {
    printf("\nenter negative number: ");
    scanf("%d", &i);
  } while (i >= 0);

  printf("\nYAY! %d", i);
}

int main()
{
  // trick1();
  // trick2();
  // trick3();
  // trick4();
  // trick5();
  // trick6();
  trick7();
  return 0;
}
