#include <stdio.h>
int BinarySearch(int *arr,int num, int size)
{
   int start=0, end = size -1 ,mid,index;
   int i=0;
   while(i<size)
   {
       if(start <= end)
       {
       mid = (start+end)/2;
       if(num == arr[mid])
       {
          index = mid;
       }
       else if(num<arr[mid])
       {
           end = mid-1;
       }
       else if(num > arr[mid])
       {
           start = mid+1;
       }
       }
       i++;
   }
   return index;
   
    
}
int main()
{
   int s,i=0,x,ind;
   printf("Please enter the size of array: ");
   scanf("%d",&s);
   int arr[s];
   printf("Enter elements of array: ");
   for(i=0; i<s; i++)
   {
       scanf("%d",&arr[i]);
   }
   printf("Please enter the number: ");
   scanf("%d",&x);
   ind = BinarySearch(arr,x,s);
   printf("Index = %d",ind);
    return 0;
}
