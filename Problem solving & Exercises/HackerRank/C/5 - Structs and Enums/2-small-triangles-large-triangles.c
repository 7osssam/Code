// ? https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

void getArea(triangle *tr, float *arrayOfAreas, int n) // get the area of each triangle and store it in an array
{

    for (int i = 0; i < n; i++)
    {
        float p = (float)(tr[i].a + tr[i].b + tr[i].c) / 2;

        float size = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c));

        arrayOfAreas[i] = size; // store the area in the array
    }
    // testing
    // for (int i = 0; i < n; i++)
    // {
    //     printf("getArea() of %.1f \n", arrayOfAreas[i]);
    // }
}

void sort_by_area(triangle *tr, int n)
{

    float *arrayOfAreas = (float *)malloc(sizeof(float) * n); // act as a hash table to store the area of each triangle

    getArea(tr, arrayOfAreas, n); // get the area of each triangle and store it in an array

    //! usual bubble sort, checks on arrayOfAreas elements and swap the corresponding tr elements with that arrayOfAreas elements
    for (int steps = 0; steps < n - 1; steps++)
    {
        int isSorted = 1; // sorted by default

        for (int i = 0; i < n - 1 - steps; i++)
        {
            if (arrayOfAreas[i] > arrayOfAreas[i + 1]) // if the current element is bigger than the next element
            {
                isSorted = 0; // not sorted

                // swaping arrayOfAreas elements
                float tempFloat = arrayOfAreas[i];
                arrayOfAreas[i] = arrayOfAreas[i + 1];
                arrayOfAreas[i + 1] = tempFloat;

                // swaping tr elements
                triangle temp = tr[i];
                tr[i] = tr[i + 1];
                tr[i + 1] = temp;
            }
        }
        if (isSorted == 1) // if we didn't swap any element then the array is sorted
            break;
    }
    // testing
    // for (int i = 0; i < n; i++)
    // {
    //     printf("sort_by_area() of %.1f \n", arrayOfAreas[i]);
    //     printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    // }
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}