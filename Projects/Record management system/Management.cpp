#include <iostream>
#include "Management.hpp"
std::vector<Person> records;

void AddRecord(std::string name, int age)
{
	if (records.size() >= 100)
	{
		std::cout << "Max number of records reached.\n";
		return;
	}
	Person p;
	p.name = name;
	p.age = age;
	records.push_back(p);
}

void FetchRecord(int id)
{
	if (id >= records.size())
	{
		std::cout << "Invalid ID.\n";
		return;
	}
	Person p = records[id];
	std::cout << "Name: " << p.name << ", Age: " << p.age << "\n";
}
