#include <stdio.h>
void ReverseString(char *arr,int size)
{
    int i=size-1;
    
    while(arr[i] != '\0')
    {
        printf("%c",arr[i]);
        i--;
    }
}
  

int main()
{
   int s,i;
   printf("Please enter size of string: ");
   scanf("%d",&s);
   char arr[s];
   printf("Please enter the string: ");
   for(i=0; i<s;i++)
   {
      scanf("%c",&arr[i]);
   }
   ReverseString(arr,s);

    return 0;
}
