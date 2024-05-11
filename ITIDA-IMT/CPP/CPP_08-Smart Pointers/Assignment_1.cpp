#include <iostream>
#include <memory>
#include <string>

// 1. Define a class called Person
class Person
{
public:
	std::string name;
	int			age;

	// Constructor
	Person(const std::string& name, int age) : name(name), age(age)
	{
	}

	void introduce() const
	{
		std::cout << "Name: " << name << ", Age: " << age << std::endl;
	}
};

int main()
{
	// 2. Dynamically allocate an instance of Person using a raw pointer.
	Person* raw_ptr = new Person("Hossam Mohamed", 25);

	// 3. Create a shared_ptr and unique_ptr from the raw pointer.
	// Note: It's not safe to create both a shared_ptr and a unique_ptr from the same raw pointer.
	// Here we'll create a shared_ptr first, then a weak_ptr from the shared_ptr.
	std::shared_ptr<Person> shared_ptr(raw_ptr);

	// 4. Use the shared_ptr to call the introduce() method.
	shared_ptr->introduce();

	// 5. Attempt to call the introduce() method using the unique_ptr.
	// This is not safe and will result in undefined behavior, as the unique_ptr will try to delete the same memory that the shared_ptr is managing.
	std::unique_ptr<Person> unique_ptr(raw_ptr);
	unique_ptr->introduce();

	// 6. Modify the code to use a weak_ptr instead of a raw pointer.
	std::weak_ptr<Person> weak_ptr(shared_ptr);

	// Use the weak_ptr to call the introduce() method.
	// We need to create a shared_ptr from the weak_ptr first.
	if (auto spt = weak_ptr.lock())
	{ // Has to be copied into a shared_ptr before usage
		spt->introduce();
	}
	else
	{
		std::cout << "Person is no longer available.\n";
	}

	return 0;
}