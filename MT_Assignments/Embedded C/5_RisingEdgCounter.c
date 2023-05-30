/***************************************************
(5) Write a C function that counts number of rising edges(i.e change from low to
high) that occurs on a digital input pin. You are required to complete the function
RisingEdgCounter() which called periodically and have one input parameter that
contain the last reading for the port pin (e.g 0:Low 1:High) and returns
accumulated number of rising edges since the first function call.
****************************************************/

#include <stdio.h>

unsigned char RisingEdgeCounter(unsigned char CurrentState)
{
    static unsigned char PreviousState;
    static unsigned char counter;

    if (PreviousState == 0 && CurrentState == 1)
    {
        counter++;
    }
    PreviousState = CurrentState;

    return counter;
}
int main()
{
    // Example usage
    int reading1 = 0;
    int reading2 = 1;
    int reading3 = 1;
    int reading4 = 0;

    int risingEdges;

    risingEdges = RisingEdgeCounter(reading1);
    printf("Rising edges: %d\n", risingEdges); // Output: 0

    risingEdges = RisingEdgeCounter(reading2);
    printf("Rising edges: %d\n", risingEdges); // Output: 1

    risingEdges = RisingEdgeCounter(reading3);
    printf("Rising edges: %d\n", risingEdges); // Output: 1

    risingEdges = RisingEdgeCounter(reading4);
    printf("Rising edges: %d\n", risingEdges); // Output: 1

    return 0;
}