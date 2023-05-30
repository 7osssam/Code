/***************************************************
(4) Write a C function that counts number of falling edges (i.e change from high to
low) that occurs on a digital input pin. You are required to complete the function
FallingEdgCounter() which called periodically and have one input parameter that
contain the last reading for the port pin (e.g 0:Low 1:High) and returns
accumulated number of falling edges since the first function call.
****************************************************/

#include <stdio.h>

unsigned char FallingEdgeCounter(unsigned char CurrentState)
{
    static unsigned char PreviousState;
    static unsigned char counter;

    if (PreviousState == 1 && CurrentState == 0)
    {
        counter++;
    }
    PreviousState = CurrentState;

    return counter;
}

int main()
{
    // Example usage
    unsigned char reading1 = 1;
    unsigned char reading2 = 0;
    unsigned char reading3 = 0;
    unsigned char reading4 = 1;

    unsigned char fallingEdges;

    fallingEdges = FallingEdgeCounter(reading1);
    printf("Falling edges: %d\n", fallingEdges); // Output: 0

    fallingEdges = FallingEdgeCounter(reading2);
    printf("Falling edges: %d\n", fallingEdges); // Output: 1

    fallingEdges = FallingEdgeCounter(reading3);
    printf("Falling edges: %d\n", fallingEdges); // Output: 1

    fallingEdges = FallingEdgeCounter(reading4);
    printf("Falling edges: %d\n", fallingEdges); // Output: 1

    return 0;
}