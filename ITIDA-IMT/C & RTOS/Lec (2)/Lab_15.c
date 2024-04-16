#include <stdio.h>
#include <stdbool.h>

enum Operation
{
	ADD = 1,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	AND,
	OR,
	XOR,
	REMAINDER,
	INCREMENT,
	DECREMENT,
	NOT
};

long add(int a, int b)
{
	return (long)a + (long)b;
}

int subtract(int a, int b)
{
	return a - b;
}

long multiply(int a, int b)
{
	return (long)a * (long)b;
}

float divide(float a, float b)
{
	return a / b;
}

int logical_and(int a, int b)
{
	return a & b;
}

int logical_or(int a, int b)
{
	return a | b;
}

int logical_xor(int a, int b)
{
	return a ^ b;
}

int reminder(int a, int b)
{
	return a % b;
}

int increment(int a)
{
	return ++a;
}

int decrement(int a)
{
	return --a;
}

int bitwise_not(int a)
{
	return ~a;
}

int main()
{
	int operation, operand1, operand2, result;

	printf("Enter operation ID (1-Add, 2-Subtract, 3-Multiply, 4-Divide, 5-And, 6-Or, 7-Xor, 8-Reminder, "
		   "9-Increment, 10-Decrement, 11-Not): ");
	scanf("%d", &operation);

	// Check for valid operation ID
	if (operation < ADD || operation > NOT)
	{
		printf("Invalid operation ID!\n");
		return 1;
	}

	// Take operands based on the operation
	if (operation >= ADD && operation <= REMAINDER)
	{
		printf("Enter two operands: ");
		scanf("%d%d", &operand1, &operand2);

		// Check for division by zero
		if (operation == DIVIDE && operand2 == 0)
		{
			printf("Division by zero is not allowed.\n");
			return 1;
		}
	}
	else
	{
		printf("Enter one operand: ");
		scanf("%d", &operand1);
	}

	// Perform the selected operation
	switch (operation)
	{
		case ADD:
			result = add(operand1, operand2);
			break;
		case SUBTRACT:
			result = subtract(operand1, operand2);
			break;
		case MULTIPLY:
			result = multiply(operand1, operand2);
			break;
		case DIVIDE:
			result = divide(operand1, operand2);
			break;
		case AND:
			result = logical_and(operand1, operand2);
			break;
		case OR:
			result = logical_or(operand1, operand2);
			break;
		case XOR:
			result = logical_xor(operand1, operand2);
			break;
		case REMAINDER:
			result = reminder(operand1, operand2);
			break;
		case INCREMENT:
			result = increment(operand1);
			break;
		case DECREMENT:
			result = decrement(operand1);
			break;
		case NOT:
			result = bitwise_not(operand1);
			break;
	}

	printf("Result: %d\n", result);

	return 0;
}
