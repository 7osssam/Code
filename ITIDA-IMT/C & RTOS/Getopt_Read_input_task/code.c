/* 
 * how to run:
 * gcc code.c -o code
 * ./code -i input.txt -o output.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char* inputFile = NULL;
	char* outputFile = NULL;
	int	  opt;

	/* 
	* Parse command line arguments using getopt function
	* "i" and "o" are the options that the program accepts 
	* ':' is used to specify that the option requires an argument
	* getopt returns the option character for the next command line option
	* and sets the variable optarg to point to the option argument
	* optarg is used to store the argument of the option that is currently being processed by getopt function
	* if the option requires an argument
	* getopt returns -1 when there are no more options to parse 
	*/
	while ((opt = getopt(argc, argv, "i:o:")) != -1)
	{
		switch (opt)
		{
			case 'i':

				inputFile = optarg;	 // Assign input file path directly
				break;
			case 'o':

				outputFile = optarg; // Assign output file path directly
				break;
			default:
				//? using fprintf to print the error message to stderr stream (standard error stream) in unix-like systems
				// Provide usage information in case of incorrect options
				fprintf(stderr, "ERROR: Incorrect options (Usage: %s -i inputfile -o outputfile)\n", argv[0]);

				// Exit the program with EXIT_FAILURE status
				exit(EXIT_FAILURE);
		}
	}

	// Check if both input and output files are specified
	if (inputFile == NULL || outputFile == NULL)
	{
		// Provide error message if files are not specified
		fprintf(stderr, "ERROR: Both input and output files must be specified\n");
		exit(EXIT_FAILURE);
	}

	//? FILE is a type of structure defined in stdio.h to handle file operations
	// Open input file for reading
	FILE* input = fopen(inputFile, "r");
	if (input == NULL)
	{
		// Print error message in case of failure to open input file
		//? perror function prints the error message to stderr stream (standard error stream)
		perror("ERROR: Failed to open input file");
		exit(EXIT_FAILURE);
	}

	// Open output file for writing
	FILE* output = fopen(outputFile, "w");
	if (output == NULL)
	{
		// Print error message in case of failure to open output file
		perror("ERROR: Failed to open output file");
		fclose(input); // Close the input file before exiting
		exit(EXIT_FAILURE);
	}

	// Copy content from input file to output file
	int characterRead;
	while ((characterRead = fgetc(input)) != EOF)
	{
		fputc(characterRead, output);
	}

	printf("File copied successfully from %s to %s\n", inputFile, outputFile);

	// Close input and output files to avoid memory leaks
	fclose(input);
	fclose(output);

	return 0;
}
