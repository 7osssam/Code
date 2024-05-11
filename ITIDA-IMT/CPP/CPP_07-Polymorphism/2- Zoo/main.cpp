#include <vector>
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Reptile.hpp"

int main()
{
	std::vector<Animal*> zoo = {new Mammal("Lion", 5, "Roar", "Yellow"), new Bird("Eagle", 3, "Screech", 2.5),
								new Reptile("Turtle", 100, "Hiss", true)};

	for (const auto& animal: zoo)
	{
		animal->makeSound();
		animal->Characteristic();
		std::cout << "-------------------" << std::endl;
	}

	// deleting the allocated memory
	for (const auto animal: zoo)
	{
		delete animal;
	}

	return 0;
}