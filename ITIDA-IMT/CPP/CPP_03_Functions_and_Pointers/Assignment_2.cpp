#include <iostream>

double add(double a, double b)
{
	return a + b;
}

double subtract(double a, double b)
{
	return a - b;
}

double multiply(double a, double b)
{
	return a * b;
}

double divide(double a, double b)
{
	if (b != 0)
	{
		return a / b;
	}
	else
	{
		std::cout << "Error: Division by zero is not allowed." << std::endl;
		return 0;
	}
}

int main()
{
	double (*operation)(double, double) = nullptr;
	double num1, num2;
	int	   op;

	std::cout << "Enter two numbers: ";
	std::cin >> num1 >> num2;

	//std::cout << "Enter operation (+, -, *, /): ";
	std::cout << "Choose an operation :" << std::endl;
	std::cout << "1. Addition (+)" << std::endl;
	std::cout << "2. Subtraction (-)" << std::endl;
	std::cout << "3. Multiplication (*)" << std::endl;
	std::cout << "4. Division (/)" << std::endl;

	std::cin >> op;

	switch (op)
	{
		case 1:
			operation = add;
			break;
		case 2:
			operation = subtract;
			break;
		case 3:
			operation = multiply;
			break;
		case 4:
			operation = divide;
			break;
		default:
			std::cout << "Invalid operation." << std::endl;
			return 1;
	}

	double result = operation(num1, num2);
	std::cout << "The result is: " << result << std::endl;

	return 0;
}
