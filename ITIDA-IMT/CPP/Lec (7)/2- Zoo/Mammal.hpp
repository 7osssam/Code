#ifndef __MAMMAL_H__
#define __MAMMAL_H__

#include "Animal.hpp"

#include <iostream>

class Mammal : public Animal
{
private:
	std::string fur_color_;

public:
	Mammal(const std::string& name, int age, const std::string& sound, const std::string& fur_color) :
		Animal(name, age, sound), fur_color_{fur_color}
	{
	}

	void makeSound() const override
	{
		std::cout << "The " << name_ << " is a mammal and it goes " << sound_ << std::endl;
	}
	void Characteristic() const override
	{
		std::cout << "Name: " << name_ << ", Age: " << age_ << ", Fur Color: " << fur_color_ << std::endl;
	}
};
#endif // __MAMMAL_H__