
#include <stdio.h>
void SWAP (int *arr1, int *arr2, int size1, int size2)
{
  int temp, i = 0;
  if (size1 < size2)
    {
      for (i = 0; i < size1; i++)
	{
	  temp = arr1[i];
	  arr1[i] = arr2[i];
	  arr2[i] = temp;
	}
    }
  else
    {
      for (i = 0; i < size2; i++)
	{
	  temp = arr1[i];
	  arr1[i] = arr2[i];
	  arr2[i] = temp;
	}
    }
}

int main ()
{
  int s1, s2, i = 0;
  printf ("Please enter size1: ");
  scanf ("%d", &s1);
  printf ("Please enter size2: ");
  scanf ("%d", &s2);
  int a1[s1], a2[s2];
  printf ("Please enter elements of array1: ");
  for (i = 0; i < s1; i++)
    {
      scanf ("%d", &a1[i]);
    }
  printf("Please enter elements of array2: ");
  for (i = 0; i < s2; i++)
    {
      scanf ("%d", &a2[i]);
    }
    SWAP (a1, a2,s1,s2);
     printf("Elments of array1: ");
     if(s2<s1)
     {
        for (i = 0; i < s2; i++)
        {
          printf ("%d ",a1[i]);
        }
     }
     else
     {
          for (i = 0; i < s1; i++)
          {
            printf ("%d ",a1[i]);
          }
     }
     printf("\nElments of array2: ");
     if(s2<s1)
     {
        for (i = 0; i < s2; i++)
        {
          printf ("%d ",a2[i]);
        }
     }
     else
     {
          for (i = 0; i < s1; i++)
          {
            printf ("%d ",a2[i]);
          }
     }
    
  return 0;
}
