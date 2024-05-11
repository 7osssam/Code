#include "Student.hpp"
#include "Teacher.hpp"
#include "TeachingAssistant.hpp"
#include <iostream>

/*
 * Person -> Student
 * Person -> Teacher 
 * Student, Teacher -> TeachingAssistant
 */

int main()
{
	Student student{"Hossam", 123};
	std::cout << "Student Name: " << student.getName() << ", ID: " << student.getStudentID() << std::endl;

	Teacher teacher{"Ali", 456};
	std::cout << "Teacher Name: " << teacher.getName() << ", ID: " << teacher.getTeacherID() << std::endl;

	TeachingAssistant ta{"Mohanad", 123, 789, "Math"};
	std::cout << "TA Name: " << ta.getName() << ", Student ID: " << ta.getStudentID()
			  << ", Teacher ID: " << ta.getTeacherID() << ", Course: " << ta.getCourse() << std::endl;

	return 0;
}