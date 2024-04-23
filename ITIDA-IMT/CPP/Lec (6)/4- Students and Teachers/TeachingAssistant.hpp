#ifndef __TEACHINGASSISTANT_H__
#define __TEACHINGASSISTANT_H__

#include "Student.hpp"
#include "Teacher.hpp"

class TeachingAssistant : public Student, public Teacher
{
private:
	std::string course;

public:
	TeachingAssistant(std::string name, int studentID, int teacherID, std::string course) :
		Person::Person(name), Student::Student(name, studentID), Teacher::Teacher(name, teacherID),
		course(course)
	{
	}

	std::string getCourse()
	{
		return course;
	}
};
#endif // __TEACHINGASSISTANT_H__