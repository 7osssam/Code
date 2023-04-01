#include <stdio.h>
void Array(char *arr,int size)
{
    int i=0,j=0;
    for(i=0; i<size; i++)
    {
        if( arr[i] != -1)
        {
          for(j=i+1; j<size; j++)
          {
            if(arr[i] == arr[j])
            {
                arr[j] = -1;
                
            }
          }
        }
    }
    for(i=0; i<size; i++)
    {
        if(arr[i] != -1)
        {
            printf("%c ",arr[i]);
        }
    }
    
}
int main()
{
  int i=0;
  
  char arr[] ={'1','2','3','5','1','2','7'};
   int s = sizeof(arr)/sizeof(arr[0]);

 
  Array(arr,s);
    return 0;
}
