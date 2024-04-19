#include <iostream>

int** allocateMatrix(int rows, int cols)
{
	int** matrix = new int*[rows]; // Allocate pointers to rows
	for (int i = 0; i < rows; ++i)
		matrix[i] = new int[cols]; // Allocate columns for each row
	return matrix;
}

void deallocateMatrix(int** matrix, int rows)
{
	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

void inputMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			std::cin >> matrix[i][j];
}

void multiplyMatrices(int** matrix1, int** matrix2, int** result, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
		{
			result[i][j] = 0;
			for (int k = 0; k < cols; ++k)
				result[i][j] += matrix1[i][k] * matrix2[k][j];
		}
}

void printMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << matrix[i][j] << " ";
		std::cout << "\n";
	}
}

int main()
{
	int rows1, cols1, rows2, cols2;

	std::cout << "Enter the number of rows and columns for the first matrix: ";
	std::cin >> rows1 >> cols1;

	std::cout << "Enter the number of rows and columns for the second matrix: ";
	std::cin >> rows2 >> cols2;

	// error handling
	if (cols1 != rows2)
	{
		std::cout << "Impossible to Calculate the Multiplication\n";
		return 1;
	}

	int** matrix1 = allocateMatrix(rows1, cols1);
	int** matrix2 = allocateMatrix(rows2, cols2);
	int** result = allocateMatrix(rows1, cols2);

	std::cout << "Enter the elements of the first matrix:\n";
	inputMatrix(matrix1, rows1, cols1);

	std::cout << "Enter the elements of the second matrix:\n";
	inputMatrix(matrix2, rows2, cols2);

	multiplyMatrices(matrix1, matrix2, result, rows1, cols2);

	std::cout << "The result of the multiplication of the two matrices is:\n";

	printMatrix(result, rows1, cols2);

	deallocateMatrix(matrix1, rows1);
	deallocateMatrix(matrix2, rows2);
	deallocateMatrix(result, rows1);

	return 0;
}