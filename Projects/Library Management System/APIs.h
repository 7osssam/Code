#ifndef API_H_
#define API_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM_STR_LENGTH		100
#define MAXIMUM_NUMBER_OF_BOOKS 100

typedef struct
{
	char  Book_title[MAXIMUM_STR_LENGTH];
	char  Author_name[MAXIMUM_STR_LENGTH];
	int	  Published_year;
	int	  Number_of_Copies;
	float Price;
	int	  Status;

} Book_t;

typedef struct
{
	Book_t Books[MAXIMUM_NUMBER_OF_BOOKS];
} Library_t;

typedef enum
{
	DELETE_BOOK_ID,
	BORROW_BOOK_ID,
	BUY_BOOK_ID,
} Book_operation_t;

typedef enum
{
	AVAILABLE_ID,
	NOT_AVAILABLE_ID,
} Book_status_t;

void Menu();

void Add_Book();

void Print_Library_books(void);

void SearchOnLibrary(Book_operation_t operation);

#endif /* API_H_ */