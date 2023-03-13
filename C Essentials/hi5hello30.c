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

int *frameNum(char *str)
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

void frame(char *str)
{
  int i, flag = 0;
  int num[2] = {0};
  char str1[10] = {0};
  char str2[10] = {0};
  int strCount = 0;
  for (i = 0; str[i] != 0; i++)
  {
    if (str[i] == ',')
    {
      flag++; // flag
    }
    else
    {
      if (flag == 0)
      {
        str1[strCount] = str[i]; // string 1
        strCount++;
      }
      else if (flag == 1)
      {
        num[0] = num[0] * 10 + (str[i] - '0'); // num 1
        strCount = 0;
      }
      else if (flag == 2)
      {
        str2[strCount] = str[i]; // string 2
        strCount++;
      }
      else if (flag == 3)
      {
        num[1] = num[1] * 10 + (str[i] - '0'); // num 2
        strCount = 0;
      }
    }
  }

  // print
  for (i = 0; i < num[0]; i++) // string 1
  {
    for (size_t j = 0; str1[j] != 0; j++)
    {
      printf("%c", str1[j]);
    }
    printf("\n");
  }
  for (i = 0; i < num[1]; i++) // string 1
  {
    for (size_t j = 0; str2[j] != 0; j++)
    {
      printf("%c", str2[j]);
    }
    printf("\n");
  }
}

int main()
{
  // char str[] = "22 12 12 232";
  char str[] = "hi,5,hello,30";
  int *PtrArr, sum;
  frame(str);
}