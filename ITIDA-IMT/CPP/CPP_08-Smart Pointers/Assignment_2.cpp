#include <iostream>
#include <memory>
#include <string>

// 1. Define a class called Book
class Book
{
public:
	std::string title;
	std::string author;

	// Constructor
	Book(const std::string& title, const std::string& author) : title(title), author(author)
	{
	}

	void display() const
	{
		std::cout << "Title: " << title << ", Author: " << author << std::endl;
	}
};

int main()
{
	// 2. Dynamically allocate an instance of Book using a unique_ptr.
	std::unique_ptr<Book> unique_ptr = std::make_unique<Book>("The Lord of the Rings", "Bla Bla Bla");

	// 3. Use the unique_ptr to call the display() method.
	unique_ptr->display();

	// 4. Create a shared_ptr from the unique_ptr. (using std::move as unique_ptr is not copyable)
	std::shared_ptr<Book> shared_ptr = std::move(unique_ptr);

	// 5. Use the shared_ptr to call the display() method.
	shared_ptr->display();

	// 6. Create a weak_ptr from the shared_ptr.
	std::weak_ptr<Book> weak_ptr = shared_ptr;

	// 7. Use the weak_ptr to call the display() method.
	// We need to create a shared_ptr from the weak_ptr first.
	if (auto spt = weak_ptr.lock())
	{ // Has to be copied into a shared_ptr before usage
		spt->display();
	}
	else
	{
		std::cout << "Book is no longer available.\n";
	}

	return 0;
}