/*
 ============================================================================
 Name        : Func_Ex6.c
 Author      : Mohamed Tarek
 Description : Functions print the binary of a number and number of ones and zeros in this number
 ============================================================================
 */

#include <stdio.h>

/* Description :
 * function responsible for printing the binary representation for any integer number
 */
void print_binary(unsigned int num)
{
    unsigned int i;
    unsigned int mask=0x80000000;
    printf("The Binary Representation of number %d is : ",num);

    /*
     * start looping from index n-1 to 0 and check every bit
     * if it is equals to one print 1
     * if it is zero print 0
     */
    for(i=0;i<32;i++)
    {
        ((num<<i) & mask) ? printf("1"):printf("0");
    }

    printf("\n");
}

/* Description :
 * function responsible for printing the number of ones and zeros in the binay number
 */
void print_number_of_ones_zeros(int num)
{
	unsigned int i;
	unsigned int mask=0x80000000;
    int ones_count=0,zeros_count=0;

    /*
     * start looping from index n-1 to 0 and check every bit
     * if it is equals to one increment ones_count
     * if it is zero increment zeros_count
     */
    for(i=0;i<32;i++)
    {
        ((num<<i) & mask) ? ++ones_count:++zeros_count;
    }

    printf("Number of ones inside the integer number %d is %d\n",num,ones_count);
    printf("Number of zeros inside the integer number %d is %d\n",num,zeros_count);
}

int main(void)
{
    unsigned int input;
    printf("Please Enter Number : ");
    /* enter the required number */
    scanf("%d",&input);
    printf("\n");
    /* display number binary representation */
    print_binary(input);
    /* display number of ones and zeros in the entered number */
    print_number_of_ones_zeros(input);
    return 0;
}
