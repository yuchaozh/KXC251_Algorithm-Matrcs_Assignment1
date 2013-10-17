/*  list.h - Robert Ollington - 1/8/05
    (based upon Mike Cameron-Jones' C implementation for KXA251)
    
    This is just the header file for the functions implemented in list.cpp

    It illustrates the use of #ifndef and #define that prevents the definitions
    being included twice when the file itself is included twice by mistake.
*/

#ifndef _STUDENTLIST_H
#define _STUDENTLIST_H

#include "student.h"

/* Define node type */
//class student;

class node2
{
public:
    //student * studentObj;
    node2 * next;
	student data_item;

	node2();
	//node(student * studentObject);
	node2(student stu);
	//node *getNext();
	//void setNext(node *);
	//student *getstudent();
};

class list
{
private:
	node2* first;

public:
	/* Constuctor and Destructor */
	list();
	~list();

	/* Function to insert n at front of list */
	void insert_at_front(node2 *node);

	/* Function to print list */
	void print();
	void addStudent(string number, string name);
	void changedetail(string number, string name);
	/* Function to insert n in (non-decreasing) order in list - assuming list 
	items are already in (non-decreasing) order. */
	void insert_in_order(node2 *node);
	void displayinfo(string number);
	//bool find(int num);
	//student *find(int);
	void enrolunit(string number, string courseName);
	void displaystudent(string unitcode);
};

#endif
