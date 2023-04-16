#include <stdio.h>

int Lsearch(int arr[], int x, int n) // linear search
{
   for (size_t i = 0; i < n; i++)
   {
      if (arr[i] == x) // if the element is found
      {
         return i;
      }
   }
   return -1; // if the element is not found
}

int Bsearch(int arr[], int x, int first, int last) // binary search
{
   while (first <= last)
   {
      int mid = first + (last - first) / 2;
      if (arr[mid] == x) // if the element is found
      {
         return mid;
      }
      else if (arr[mid] > x) // right
      {
         last = mid - 1;
      }
      else if (arr[mid] < x) // left
      {
         first = mid + 1;
      }
   }
   return -1; // if the element is not found
}

int main()
{
   // int arr[] = {2, 23, 43, 1, 13, 11, 12, 22, 99, 100, 21};
   int arr[] = {3, 4, 5, 7, 6, 8, 9};
   int x;                                // the element to be searched
   int n = sizeof(arr) / sizeof(arr[0]); // to get the size of the array
   printf("Enter a num :");
   scanf("%d", &x);

   // int res = Lsearch( arr , x , n ); // linear search
   int res = Bsearch(arr, x, 0, n - 1); // binary search only sorted array

   if (res == -1)
      printf("\nNOT FOUND");
   else
      printf("\n%dst of the array", res + 1);

   return 0;
}