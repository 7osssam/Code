#include <stdio.h>

int *frame(char *str)
{
  int i, intger = 0, flag = 0, numcount = 0;
  static int num[4];
  for (i = 0; str[i] != 0; i++)
  {
    if (str[i] == ' ')
    {
      flag++; // flag
      numcount++;
    }
    else
    {
      if (flag == numcount)
      {
        num[numcount] = num[numcount] * 10 + (str[i] - '0');
      }

    } //
  }
  return num;
}
int main()
{
  char str[] = "22 12 5 13";
  int *PtrArr, sum;
  PtrArr = frame(str);

  for (size_t i = 0; i < 4; i++)
  {
    printf("%d   ", PtrArr[i]);
  }

  for (size_t i = 0; i < 4; i++)
  {
    sum = sum + PtrArr[i];
  }
  printf("\nsum is %d", sum);
}