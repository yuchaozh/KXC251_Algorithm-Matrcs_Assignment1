#include <string>
#include <iostream>
#include "student.h"
using namespace std;

student::student()
{
	studentNumber = "";
	studentName = "";
	unitTree unitTree1;
}

student::student(string studentNum,string str)
{
	studentNumber = studentNum;
	studentName = str;
	unitTree unitTree1;
}
//reset the name of the student
void student::changeStudentName(string studentNa)
{
	studentName = studentNa;
}

string student::getStudentNumber()
{
	return studentNumber;
}

string student::getStudentName()
{
	return studentName;
}

void student::setunit(string courseName)
{
	unitTree1.insert(courseName);
}
//display the courses of the student
void student::displayunit()
{
	unitTree1.print_in_order();
}
//return the unitTree of the student
unitTree student::searchunit()
{
	return unitTree1;
}