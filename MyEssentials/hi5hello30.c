#include <stdio.h>

void frame(char *str)
{
  int i, flag = 0; // flag = 0,1,2,3
  int num[2] = {0};
  char str1[10] = {0};
  char str2[10] = {0};
  int strCount = 0; // string counter
  for (i = 0; str[i] != 0; i++)
  {
    if (str[i] == ',') // if comma
    {
      flag++; // flag
    }
    else
    {
      if (flag == 0) // first frame
      {
        str1[strCount] = str[i]; // string 1
        strCount++;
      }
      else if (flag == 1) // second frame
      {
        num[0] = num[0] * 10 + (str[i] - '0'); // num 1
        strCount = 0;
      }
      else if (flag == 2) // third frame
      {
        str2[strCount] = str[i]; // string 2
        strCount++;
      }
      else if (flag == 3) // fourth frame
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
  frame(str); //
}