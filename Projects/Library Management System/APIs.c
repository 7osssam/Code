#include "APIs.h"
#include <stdbool.h>

/******************************************************************
 * 							Definitions				 			  *
 ******************************************************************/

#define AVAILABLE		 true
#define NOT_AVAILABLE	 false
#define LIBRARY_IS_FULL	 -1
#define STRCMP_EQUAL	 0
#define STRCMP_NOT_EQUAL 1

/******************************************************************
 * 						Private Variables			 			  *
 ******************************************************************/
static const char* Book_status_options[] = {"AVAILABLE", "NOT AVAILABLE"};
static const char* Book_operation_options[] = {"DELETE", "BORROW", "BUY"};
static int		   HashTableAvailablity[MAXIMUM_NUMBER_OF_BOOKS];

/******************************************************************
 * 						Global Variables			 			  *
 ******************************************************************/
int		  LibCounter = 0; // to count the number of books in the library
Library_t Library;		  // to store the library books

/******************************************************************
 * 						Terminal Colors			 				  *
 ******************************************************************/
static void TerminalColor_RED(void)
{
	printf("\033[41m");
}

static void TerminalColor_YELLOW(void)
{
	printf("\033[33m");
}

static void TerminalColor_BLUE(void)
{
	printf("\033[34m");
}

static void TerminalColor_RESET(void)
{
	printf("\033[0m\n"); // reset color to default
}

static void TerminalColor_GREEN(void)
{
	printf("\033[32m");
}

/******************************************************************
 * 						Private Functions			 			  *
 ******************************************************************/
static bool CheckForDuplicates(char* input_Book_title, int* updated_Book_index)
{
	for (int i = 0; i < MAXIMUM_NUMBER_OF_BOOKS; i++)
	{
		if (HashTableAvailablity[i] == AVAILABLE)
		{
			if (strcmp(input_Book_title, Library.Books[i].Book_title) == STRCMP_EQUAL)
			{
				*updated_Book_index = i; // store the index of the book
				return AVAILABLE;
			}
		}
	}
	return NOT_AVAILABLE;
}

static int CheckHashTable(void)
{
	int available_index = LIBRARY_IS_FULL; // initialize the index to -1

	for (int i = 0; i < MAXIMUM_NUMBER_OF_BOOKS; i++)
	{
		if (HashTableAvailablity[i] == NOT_AVAILABLE) // if we found an empty index in the hash table
		{
			available_index = i; // store the first free index
			break;				 // break the loop
		}
	}
	return available_index; // return the index
}

static void LibFull_Message(void)
{
	TerminalColor_RED();
	printf(" Library is full! ");
	TerminalColor_RESET();
}

static void LibEmpty_Message(void)
{
	TerminalColor_RED();
	printf(" Library is empty! ");
	TerminalColor_RESET();
}

static void WrongOption_Message(void)
{
	TerminalColor_RED();
	printf("\n Wrong Option! try again ");
	TerminalColor_RESET();
}

/******************************************************************
 * 						APIs Functions			 				  *
 ******************************************************************/
void Menu(void)
{
	int option;

	TerminalColor_BLUE();
	printf("==================================\n||");

	printf("\n||    Library Management System   \n||");
	TerminalColor_GREEN();
	printf("        Books Available: %d\n", LibCounter);
	TerminalColor_BLUE();
	printf("|| 1. Print Library Books\n");
	printf("|| 2. Add Book\n");
	printf("|| 3. Delete Book\n");
	printf("|| 4. Buy Book\n");
	printf("|| 5. Borrow Book\n");
	printf("|| 6. Exit\n");

	printf("==================================\n");
	TerminalColor_RESET();

	printf("Enter an option (1-6): ");
	int scanfResult = scanf("%d", &option);

	if (scanfResult == true) // if the user entered a number not a character
	{
		if (1 <= option && option <= 6)
		{
			switch (option)
			{
				case 1:
					system("cls"); // for Windows terminal
					Print_Library_books();
					break;
				case 2:
					Add_Book();
					system("cls"); // for Windows terminal
					break;
				case 3:
					SearchOnLibrary(DELETE_BOOK_ID);
					break;
				case 4:
					SearchOnLibrary(BUY_BOOK_ID);
					break;
				case 5:
					SearchOnLibrary(BORROW_BOOK_ID);
					break;
				case 6:
					exit(0);
					break;
			}
		}
		else
		{
			WrongOption_Message();
		}
	}
	else
	{
		// Clear the input buffer
		while (getchar() != '\n')
			;
		WrongOption_Message();
	}
}

void Add_Book(void)
{
	// if the library is full print a message and exit the function
	if (LibCounter > MAXIMUM_NUMBER_OF_BOOKS)
	{
		LibFull_Message();
		return; // exit the function
	}

	char input_Book_title[MAXIMUM_STR_LENGTH];

	int Book_index = CheckHashTable();

	/* this is already handled in the previous if statement
 	if (Book_index == LIBRARY_IS_FULL)
	{
		LibFull_Message();
		return; // exit the function
	}
	*/

	printf("Enter Book Title: ");
	scanf("%99s", input_Book_title);

	if (CheckForDuplicates(input_Book_title, &Book_index) == AVAILABLE)
	{
		Library.Books[Book_index].Number_of_Copies++; // increment the number of copies of the book

		TerminalColor_RED();
		printf(" Book already exists! ");
		printf(" Number of copies are %d now :)", Library.Books[Book_index].Number_of_Copies);
		TerminalColor_RESET();

		return; // exit the function
	}
	else
	{
		// if the book is not found add it to the library
		strcpy(Library.Books[Book_index].Book_title, input_Book_title);
	}

	printf("Enter Author Name: ");
	scanf("%99s", Library.Books[Book_index].Author_name);

	printf("Enter Published Year: ");
	if (scanf("%d", &Library.Books[Book_index].Published_year) != true)
	{
		WrongOption_Message();
		return; // exit the function
	}

	printf("Enter Number of Copies: ");
	if (scanf("%d", &Library.Books[Book_index].Number_of_Copies) != true)
	{
		WrongOption_Message();
		return; // exit the function
	}

	printf("Enter Price: ");
	if (scanf("%f", &Library.Books[Book_index].Price) != true)
	{
		WrongOption_Message();
		return; // exit the function
	}

	// set the index to AVAILABLE after adding the book successfully
	HashTableAvailablity[Book_index] = AVAILABLE;
	// increment the number of books in the library
	LibCounter++;
}

void Print_Library_books(void)
{
	//system("cls"); // for Windows terminal
	if (LibCounter == 0)
	{
		LibEmpty_Message();
		return;
	}

	TerminalColor_YELLOW();
	printf("==================================\n");
	for (int i = 0; i < MAXIMUM_NUMBER_OF_BOOKS; i++)
	{
		if (HashTableAvailablity[i] == AVAILABLE)
		{
			printf("%dst Book\n", i + 1);
			printf("Book Title: %s\n", Library.Books[i].Book_title);
			printf("Author Name: %s\n", Library.Books[i].Author_name);
			printf("Published Year: %d\n", Library.Books[i].Published_year);
			printf("Number of Copies: %d\n", Library.Books[i].Number_of_Copies);
			printf("Price: %.3f\n", Library.Books[i].Price);
			if (Library.Books[i].Number_of_Copies == 0)
			{
				printf("Status: %s\n", Book_status_options[NOT_AVAILABLE_ID]);
			}
			else
			{
				printf("Status: %s\n", Book_status_options[AVAILABLE_ID]);
			}
			printf("__________________________________\n");
		}
	}
	printf("==================================\n");
	TerminalColor_RESET();
}

void SearchOnLibrary(Book_operation_t operation)
{
	char input_Book_title[MAXIMUM_STR_LENGTH];
	int	 BookFoundFlag = 0; // flag to indicate if the book is found or not

	printf("Enter Book Title to %s: ", Book_operation_options[operation]);
	scanf("%99s", input_Book_title);

	for (int i = 0; i < MAXIMUM_NUMBER_OF_BOOKS; i++)
	{
		if (HashTableAvailablity[i] == AVAILABLE)
		{
			if (strcmp(input_Book_title, Library.Books[i].Book_title) == STRCMP_EQUAL)
			{
				BookFoundFlag = 1; // set the flag to 1 to indicate that the book is found
				system("cls");	   // for Windows terminal
				TerminalColor_YELLOW();
				switch (operation)
				{
					case DELETE_BOOK_ID:
						HashTableAvailablity[i] = NOT_AVAILABLE;
						LibCounter--;
						printf("\n%s has been deleted successfully!\n", Library.Books[i].Book_title);
						break;

					case BORROW_BOOK_ID:

						// if we only have one copy of the book set the status to NOT_AVAILABLE
						if (Library.Books[i].Number_of_Copies == 1)
						{
							Library.Books[i].Status = NOT_AVAILABLE_ID;
							printf("\nLast copy of ");
						}
						else if (Library.Books[i].Number_of_Copies == 0)
						{
							TerminalColor_RED();
							printf("\n Book not available! \n");
							TerminalColor_RESET();
							return; // exit the function
						}
						Library.Books[i].Number_of_Copies--;
						printf("\n%s has been borrowed successfully!\n", Library.Books[i].Book_title);
						printf("Number of copies are %d now :)\n", Library.Books[i].Number_of_Copies);
						break;

					case BUY_BOOK_ID:
						Library.Books[i].Number_of_Copies++;
						printf("\n%s has been bought successfully!\n", Library.Books[i].Book_title);
						printf("Number of copies are %d now :)\n", Library.Books[i].Number_of_Copies);
						break;

					default:
						break;
				}
				TerminalColor_RESET();
			}
		}
	}

	if (BookFoundFlag == 0)
	{
		TerminalColor_RED();
		printf(" Book not found! ");
		TerminalColor_RESET();
	}
}
