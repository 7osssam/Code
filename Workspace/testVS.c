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
  int num, result;

  printf("Enter ");
  scanf("%d", &num);

  switch (num % 2)
  {
  case 0:
    printf("\nEVEN");
    break;

  default:
    printf("\nODD");
    break;
  }
}

unsigned int temperature(int x)
{
  if (x > 0 && x <= 30)
  {
    return 7;
  }
  else if (x > 30 && x <= 60)
  {
    return 5;
  }
  else if (x > 60 && x <= 90)
  {
    return 3;
  }
  else if (x > 90 && x < 100)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  // trick1();
  // trick2();
  // trick3();
  // trick4();
  // trick5();
  // trick6();

  int x;

  printf("Enter number ");
  scanf("%d", &x);

  printf("Time = %d", temperature(x));
  return 0;
}
