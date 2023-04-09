void Swap_Advanced(int *num1, int *num2) // with no temp variable
{
    *num1 = *num1 + *num2; // add x and y and store in x
    *num2 = *num1 - *num2; // subtract y from x and store in y // x = x + y - y = x
    *num1 = *num1 - *num2; // subtract y from x and store in x // y = x + y - x = y
}

void Swap(int *num1, int *num2) // using temp variable
{
    int temp;
    temp = *num1;  // save the value of num1
    *num1 = *num2; // assign the value of num2 to num1
    *num2 = temp;  // assign the saved value of num1 to num2
}
