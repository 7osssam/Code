// guard
#ifndef BOOKCLASS_HPP
#define BOOKCLASS_HPP

#include <string>

// This class represents a book in a library catalog
// It does not set any value for the member variables alone (only the default constructor)
// as any book should have a title, author, and year of publication
class Book
{
private:
	std::string title;
	std::string author;
	int			year;

public:
	// Default constructor
	Book(std::string new_title = "", std::string new_author = "", int new_year = 0) :
		title(new_title), author(new_author), year(new_year)
	{
	}

	// Setters and getters
	std::string get_title() const
	{
		return title;
	}

	std::string get_author() const
	{
		return author;
	}

	int get_year() const
	{
		return year;
	}

	void display_info() const;
};

#endif // BOOKCLASS_HPP