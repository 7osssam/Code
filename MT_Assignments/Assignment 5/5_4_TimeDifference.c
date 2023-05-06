/*
4.C Function to calculate the difference between two time periods using structures.
*/

#include <stdio.h>

typedef struct
{
    int sec;
    int min;
    int h;
} Time;

Time TimeDifference(Time *startPtr, Time *stopPtr)
{
    Time result_temp;

    if (startPtr->sec > stopPtr->sec)
    {
        stopPtr->sec = stopPtr->sec + 60;
        --stopPtr->min; // do not use stopPtr->min--;
    }
    if (startPtr->min > stopPtr->min)
    {
        stopPtr->min = stopPtr->min + 60;
        --stopPtr->h;
    }

    result_temp.sec = stopPtr->sec - startPtr->sec;
    result_temp.min = stopPtr->min - startPtr->min;
    result_temp.h = stopPtr->h - startPtr->h;
    return result_temp;
}
int main()
{
    Time start, stop;
    Time result;
    printf("Enter the start period (h : min : sec)\n");
    scanf("%d%d%d", &start.h, &start.min, &start.sec);

    printf("Enter the stop period (h : min : sec)\n");
    scanf("%d%d%d", &stop.h, &stop.min, &stop.sec);

    result = TimeDifference(&start, &stop);

    printf("Difference is %d:%d:%d", result.h, result.min, result.sec);
}
