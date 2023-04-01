#include <stdio.h>

int main()
{
  int num,i=0,count=0;
  printf("Please enter the number: ");
  scanf("%d",&num);
  for(i=0; i<sizeof(int)*8; i++)
  {
      if((num>>i) & 1)
      {
          count++;
      }
  }
  printf("%d",count);

    return 0;
}
