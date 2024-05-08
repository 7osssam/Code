#ifndef __REPTILE_H__
#define __REPTILE_H__

#include "Animal.hpp"
#include <iostream>

class Reptile : public Animal
{
private:
	bool has_a_shell_;

public:
	Reptile(const std::string& name, int age, const std::string& sound, bool has_a_shell) :
		Animal(name, age, sound), has_a_shell_{has_a_shell}
	{
	}

	void makeSound() const override
	{
		std::cout << "The " << name_ << " is a reptile and it goes " << sound_ << std::endl;
	}
	void Characteristic() const override
	{
		std::cout << "Name: " << name_ << ", Age: " << age_ << ", Has a shell?: " << std::boolalpha
				  << has_a_shell_ << std::endl;
	}
};
#endif // __REPTILE_H__