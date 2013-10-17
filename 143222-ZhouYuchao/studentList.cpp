//From the code given by the teacher, modified by Zhou Yuchao
/*  list.cpp - Robert Ollington - 1/8/05
    (based upon Mike Cameron Jones' C implementation for KXA251)
    
    This code illustrates the use of pointers to implement a linked list,
    with a dummy header node. The last node's next will be NULL. (The use of
    the dummy header node simplifies some of the code as it ensures that there
    is always a node before every node containing an item, even the first
    one.)
*/

#include <string>
#include <iostream>
#include "studentList.h"
using namespace std;

node2::node2()
{
}

node2::node2( student stu)
{
	data_item =stu;
	next = NULL;
}

/* Function to create an empty list 
   (the void argument list indicates that it takes no arguments) */

list::list()
{
    first = new node2();
    first->next = NULL; /* necessary initialisation to indicate last node */
}

/* Function to return dynamically allocated memory in list */
list::~list()
{
    /* Note that we don't really need to have the variable "current" here,
       as we could just advance list itself if we preferred. (Some of the other
       list functions also make use of an additional such variable.) */
    node2* current = first;

    while(current)
    {
			node2 *to_free = current;
			current = current->next;
			delete to_free;
			/* Note that the simpler: 
			   delete current; 
			   current = current->next;
			   makes the mistake of using dynamically allocated memory after
			   it's been freed */
    }
}

/* Function to insert n at front of list */
void list::insert_at_front(node2 *node)
{
    node->next = first;
    first = node;
}

void list::addStudent(string number, string name)
{
	student stutem(number, name);
	node2* new_node = new node2(stutem);
	insert_in_order(new_node);
}

/* Function to print list */
void list::print()
{
	node2* current = first->next;
    while(current)
    {
		cout<<current->data_item.getStudentNumber()<<",    ";
		cout<<current->data_item.getStudentName()<<endl;
		current = current->next;
    }
	cout<<endl;
}

void list::changedetail(string number, string name)
{
	node2* current = first;
	while(current->data_item.getStudentNumber() != number)
	{
		current = current->next;
	}
	current->data_item.changeStudentName(name);
	cout<<endl;
}

void list::insert_in_order(node2 *node)
{
    node2* before = first;

    /* Move along list until right place is found, looking for node after
       which new node should go */
	while(before->next && (before->next->data_item.getStudentNumber() < node->data_item.getStudentNumber()))
    {
        before = before->next;
    }

    node->next = before->next;
    before->next = node;
}

void list::enrolunit(string number, string courseName)
{
	node2* current = first;
	while(current->data_item.getStudentNumber() != number)
	{
		current = current->next;
	}
	current->data_item.setunit(courseName);
}

void list::displayinfo(string number)
{
	node2* current = first;
	while(current->data_item.getStudentNumber() != number)
	{
		current = current->next;
	}
	cout<<endl;
	cout<<current->data_item.getStudentName()<<endl;
	current->data_item.displayunit();
}

void list::displaystudent(string unitcode)
{
	node2* current = first->next;
	while(current)
	{
		if (current->data_item.searchunit().find(unitcode)!= NULL)
		{
			cout<<current->data_item.getStudentNumber()<<",   ";
			cout<<endl;
		}
		current = current->next;
	}
	

}