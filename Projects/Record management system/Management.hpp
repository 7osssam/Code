#ifndef MANAGEMENT_HPP
#define MANAGEMENT_HPP

#include <vector>
#include <string>

class Person
{
public:
	std::string name;
	int			age;
};

enum Option
{
	ADD_RECORD = 1,
	FETCH_RECORD,
	QUIT
};

void AddRecord(std::string name, int age);
void FetchRecord(int id);

#endif // MANAGEMENT_HPP
