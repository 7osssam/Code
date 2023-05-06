/*C Program to add two distances (inch-feet) using structure and display the result.*/

#include <stdio.h>

typedef struct
{
    int inch;
    int feet;
} distance;

int main()
{
    distance S1;
    printf("Enter inch and feet\n");
    scanf("%d%d", &S1.inch, &S1.feet);
    printf("Addition is %d Feet or %.2f inch", S1.inch * 12 + S1.feet, S1.inch + ((float)S1.feet / 12));
}