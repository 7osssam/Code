#include<stdio.h>

int BinaryRecursive(int low, int high, int * arr, int element)
{
    if(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == element)
        {
            return mid;
        }
        else if(arr[mid] > element)
        {
            return BinaryRecursive(low, mid-1, arr, element);
        }
        else
        {
            return BinaryRecursive(mid+1, high, arr, element);
        }
    }
    return -1;
}


int main(void)
{
    int arr[] = {1, 6, 8, 9, 12, 18, 25, 36, 52, 57, 61};
    int n = 13;

   
    printf("Recursive: %d\n", BinaryRecursive(0, n-1, arr, 36));

    return 0;
}
