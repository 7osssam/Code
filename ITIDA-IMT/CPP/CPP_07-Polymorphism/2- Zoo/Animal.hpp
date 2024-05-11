#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>

class Animal
{
protected:
	std::string name_;
	int			age_;
	std::string sound_;

public:
	Animal(const std::string& name, int age, const std::string& sound_) : name_{name}, age_{age}, sound_{}

	{
	}
	virtual ~Animal()
	{
	}
	virtual void makeSound() const = 0;
	virtual void Characteristic() const = 0;
};
#endif // __ANIMAL_H__