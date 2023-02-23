#include <stdio.h> // include the standard input output library

// c program to set , clear , toggle , get a bit in a number

int main() { // main function
int x, bitnum; // declare the variables

// c program to set a bit in a number //we use the OR operator to set a bit
    printf("(set) enter X:"); // print the message 
    scanf("%d",&x);// read the input from the user

    printf("(set) enter bitnum:");  // print the message
    scanf("%d",&bitnum);// read the input from the user

    x= x|(1<<bitnum); // set the bit
    printf("the NEW X is %d", x);

// c program to clear a bit in a number //we use the AND operator to clear a bit
    printf("(clear) enter X:"); // print the message
    scanf("%d",&x);// read the input from the user

    printf("(clear) enter bitnum:"); // print the message
    scanf("%d",&bitnum);// read the input from the user

    x= x&~(1<<bitnum); //clear the bit
    printf("the NEW X is %d", x);

// c program to toggle a bit in a number //we use the XOR operator to toggle a bit
    printf("(toggle) enter X:"); // print the message
    scanf("%d",&x);// read the input from the user

    printf("(toggle) enter bitnum:"); // print the message
    scanf("%d",&bitnum);// read the input from the user

    x= x^(1<<bitnum); //toggle the bit
    printf("the NEW X is %d", x);

// c program to get a bit in a number //we use the AND operator to get a bit
    printf("(get) enter X:"); // print the message
    scanf("%d",&x);// read the input from the user

    printf("(get) enter bitnum:"); // print the message
    scanf("%d",&bitnum);// read the input from the user

    x= x&(1<<bitnum); //get the bit
    printf("the NEW X is %d", x); // print the result

    return 0;
}