#ifndef __TEACHER_H__
#define __TEACHER_H__

#include "Person.hpp"

class Teacher : virtual public Person
{
private:
	int teacherID;

public:
	Teacher(std::string name, int teacherID) : Person::Person{name}, teacherID{teacherID}
	{
	}

	int getTeacherID()
	{
		return teacherID;
	}
};
#endif // __TEACHER_H__