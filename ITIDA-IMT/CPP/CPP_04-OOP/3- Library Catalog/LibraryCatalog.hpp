#ifndef LIBRARYCATALOG_HPP
#define LIBRARYCATALOG_HPP

#include "BookClass.hpp"
#include <vector>
#include <string>

class LibraryCatalog
{
private:
	std::vector<Book> books;

public:
	void add_book(std::string title, std::string author, int year)
	{
		Book new_book(title, author, year);
		books.push_back(new_book);
	}

	void search_by_author(std::string author) const
	{
		for (const Book& book: books)
		{
			if (book.get_author() == author)
			{
				book.display_info();
			}
		}
	}

	void display_catalog() const
	{
		for (const Book& book: books)
		{
			book.display_info();
		}
	}
};

#endif // LIBRARYCATALOG_HPP