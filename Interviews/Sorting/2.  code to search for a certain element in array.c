#include <stdio.h>
void Element_Search(int *arr, int size, int num)
{
    int i=0,flag=0;
    for(i=0; i<size; i++)
    {
        if(arr[i] == num)
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if(flag == 1)
    {
        printf("The index is: %d",i);
    }
    else
    {
        printf("The element is not found");
    }
}

int main()
{
  int s,i=0;
  printf("Please enter the size of array: ");
  scanf("%d",&s);
  int a[s];
  for(i=0; i<s; i++)
  {
      scanf("%d",&a[i]);
  }
   Element_Search(a, s, 5);

    return 0;
}
