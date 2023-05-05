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
  int num;

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

void trick7() // unserstanding pointers and arrays
{

  int arr[5] = {1, 2, 3, 4, 5};
  int *ptr = arr;

  for (int i = 0; i < 5; i++)
  {
    // printf("%d ", arr[i]);

    // printf("%d ", *(arr + i));

    // printf("%d ", ptr[i]);

    // printf("%d ", *(ptr + i));

    // printf("%d ", *ptr);
    // ptr++;

    // printf("%d ", *arr);
    // arr++; // can't increment array name because it is constant pointer to first element of array
  }
}

void SwapPointers(int **P2ptr1, int **P2ptr2)
{
  int *temp;
  // printf("\nfuc %d %p\n", **P2ptr1, *P2ptr1);
  // printf("fuc %d %p", **P2ptr2, *P2ptr2);

  temp = *P2ptr1;
  *P2ptr1 = *P2ptr2;
  *P2ptr2 = temp;
}

int fun1(int num)
{
  return 1;
}
int fun2(int num)
{
  return 2;
}
int fun3(int num)
{
  return 3;
}

int main()
{
  // trick1();
  // trick2();
  // trick3();
  // trick4();
  // trick5();
  // trick6();

  // array of pointers
  // int arr[3][3];

  // printf("arr[0] %p \n", arr[0]);
  // printf("arr[0]+1  %p \n\n", arr[0] + 1);

  // printf("arr[1] %p \n", arr[1]);
  // printf("arr[2] %p \n\n", arr[2]);

  // printf("arr %p \n", arr);
  // printf("arr +1 %p \n\n", arr + 1);

  //! pointer to pointer
  // int x = 10;    // 4 bytes
  // int *ptr = &x; // 8 bytes

  // int **ptr2 = &ptr; // 8 bytes

  // printf("x     = %d\n", x);
  // printf("&x    = %p\n", &x);
  // printf("ptr   = %p\n", ptr);
  // printf("&ptr  = %p\n", &ptr);
  // printf("ptr2  = %p\n", ptr2);
  // printf("&ptr2 = %p\n", &ptr2);

  //! pointer of pointer
  // int x = 6;
  // int y = 7;

  // int *ptr1 = &x;
  // int *ptr2 = &y;

  // printf("%d %p\n", *ptr1, ptr1);
  // printf("%d %p", *ptr2, ptr2);

  // SwapPointers(&ptr1, &ptr2);

  // printf("\n%d %p\n", *ptr1, ptr1);
  // printf("%d %p", *ptr2, ptr2);

  void *ptr1;
  int *ptr2;

  printf("%p %p\n", ptr1, ptr2);

  ptr1++;
  ptr2++;

  printf("%p %p", ptr1, ptr2);
}
