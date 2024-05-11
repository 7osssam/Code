#ifndef __BIRD_H__
#define __BIRD_H__

#include "Animal.hpp"
#include <iostream>

class Bird : public Animal
{
private:
	double wingspan_;

public:
	Bird(const std::string& name, int age, const std::string& sound, double wingspan) :
		Animal(name, age, sound), wingspan_{wingspan}
	{
	}
	void makeSound() const override
	{
		std::cout << "The " << name_ << " is a bird and it goes " << sound_ << std::endl;
	}
	void Characteristic() const override
	{
		std::cout << "Name: " << name_ << ", Age: " << age_ << ", Wingspan: " << wingspan_ << std::endl;
	}
};
#endif // __BIRD_H__