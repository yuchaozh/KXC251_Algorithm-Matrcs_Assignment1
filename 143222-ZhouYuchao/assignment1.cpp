#include <iostream>
#include <string>
#include "studentList.h"
using namespace std;

student stu;
list list1;

void function1()
{
	string studentID;
	string studentName;
	cout<<"please enter the student's number (eg. 940561): "<<endl;
	cin>>studentID;
	cout<<endl;
	cout<<"please enter the student's name:"<<endl;
	cin.sync();
	getline(cin, studentName);
	list1.addStudent(studentID, studentName);
	cout<<endl;
}

void function2()
{
	string studentID;
	string newstudentName;
	cout<<"please enter the student's number: "<<endl;
	cin>>studentID;
	cout<<endl;
	cout<<"please enter the student's new name:"<<endl;
	cin.sync();
	getline(cin, newstudentName);
	list1.changedetail(studentID, newstudentName);
}

void function3()
{
	string studentID;
	string courseName;
	cout<<"please enter the student's number: "<<endl;
	cin>>studentID;
	cout<<endl;
	cout<<"please enter the unit code to enrol them in: "<<endl;
	cin>>courseName;
	list1.enrolunit(studentID, courseName);
}

void function4()
{
	string studentID;
	cout<<"please enter the student's number: "<<endl;
	cin>>studentID;
	list1.displayinfo(studentID);
}

void function5()
{
	list1.print();
}

void function6()
{
	string unitcode;
	cout<<"please enter the unit code"<<endl;
	cin>>unitcode;
	list1.displaystudent(unitcode);
}

int main()
{
	bool running = true;
	while(running)
	{
	int choosenumber;
	cout<<"Welcome to UnitData"<<endl;
	cout<<"1)Add student"<<endl;
	cout<<"2)Change student details"<<endl;
	cout<<"3)Enrol a student in a unit"<<endl;
	cout<<"4)Display student details"<<endl;
	cout<<"5)Display all students"<<endl;
	cout<<"6)Display Enrolment Details"<<endl;
	cout<<"0)Exit"<<endl;
	cout<<endl;
	cout<<"Please choose an option:"<<endl;
	cin>>choosenumber;
	
	switch(choosenumber)
	{
		case 1:
			function1();
			break;
		case 2:
			function2();
			break;
		case 3:
			function3();
			break;
		case 4:
			function4();
			break;
		case 5:
			function5();
			break;
		case 6:
			function6();
			break;
		case 0:
			//list1.~list();
			running = false;
			break;
		default:
			running = false;
			break;
	return 0;
	}
	}
}
