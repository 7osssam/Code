#include <stdio.h>

void str_print(char *str) //! same as printf("%s" , str);
{
  int i;
  for (i = 0; str[i] != 0; i++)
  {
    printf("%c", str[i]);
  }
  printf("\n"); // new line
}

int strToInt(char *str)
{
  int i = 0, intger = 0;
  for (i = 0; str[i] != 0; i++)
  {
    if (str[i] >= '0' && str[i] <= '9')
      intger = intger * 10 + (str[i] - '0');
  }
  return intger;
}

void fun(void)
{
  static int y = 10;
  y--;
  printf("\n%d", y);
}

// ahmed Saeed
int main()
{
  fun();
  fun();
  fun();
  fun();
  fun();
}