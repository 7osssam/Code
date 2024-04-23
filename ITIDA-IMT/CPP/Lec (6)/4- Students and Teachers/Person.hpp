#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

class Person
{
private:
	std::string name;

public:
	Person(std::string name) : name{name} 
	{
	}

	std::string getName()
	{
		return name;
	}
};
#endif // __PERSON_H__