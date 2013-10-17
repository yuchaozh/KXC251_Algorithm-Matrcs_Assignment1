#ifndef _STUDENT_H
#define _STUDENT_H

#include "unitTree.h"
#include <string>
using namespace std;

class student
{
private:
	string studentName;
	string studentNumber;
	unitTree unitTree1;
public:
	student();
	//~student();
	//student(int studentNumber, string studentName);
	//student(int num, const string &str, unitTree unitTree1);
	student(string num, string str);
	//student & operator=(const student &t);
	//void addStudentCourse(string courseName);
	//void addStudent(int studentNum,const string &studentNa, unitTree studentUnitTree);
	//void changesStudentNumber();
	void changeStudentName(string studentName);
	string getStudentNumber();
	string getStudentName();
	void setunit(string courseName);
	//void getStudentCourse();
	void displayunit();
	unitTree searchunit();

};
//const student NO_THIS_STUDENT(-1,"");
#endif