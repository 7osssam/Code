#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "Person.hpp"

class Student : virtual public Person
{
private:
	int studentID;

public:
	Student(std::string name, int studentID) : Person::Person{name}, studentID{studentID}
	{
	}

	int getStudentID()
	{
		return studentID;
	}
};
#endif // __STUDENT_H__