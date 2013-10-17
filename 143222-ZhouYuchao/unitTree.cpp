//From the code given by the teacher, modified by Zhou Yuchao
/* bst.c - Robert Ollington 2/8/05
   (based upon Mike Cameron-Jones' C implementation for KXA251)

   This code illustrates the use of pointers to implement a BST of ints.
   (Implementation does not add duplicate items, and does nothing when
   attempt is made to delete item not present.)
*/
#include <iostream>
#include <string>
#include "unitTree.h"
using namespace std;

node1::node1(){
	left=NULL;
	right=NULL;
	course_item = "";
}

node1::node1(string courseName){
	left=NULL;
	right=NULL;
	course_item = courseName;
}

// Function to create an empty tree 
unitTree::unitTree()
{
	
	root = NULL;
}

// Function to return dynamically allocated memory in tree 
unitTree::~unitTree()
{
    makeEmpty(root);
}

// Function to insert n into BST, returning tree with n inserted.
//   (Leaves BST unaltered if n is already present.)

void unitTree::insert(string courseName)
{
	insert(courseName,root);
}

// the internal recursive implementation 
void unitTree::insert(string courseName, node1* &tree)
{
    if(tree==NULL) // found where to put it, create and initialise node 
    {
		tree = new node1(courseName);
    }
    // otherwise put in left / right sub-tree as appropriate 
    else if(courseName < tree->course_item)
    {
		insert(courseName, tree->left);
    }
    else if(courseName > tree->course_item)
    {
		insert(courseName, tree->right);
    }
    // if n == tree->data_item, just leave tree as is 
}

// Function to print tree in order 
void unitTree::print_in_order()
{
	print_in_order(root);
}

// the internal recursive implementation 
void unitTree::print_in_order(node1* tree)
{
    // If not empty, print left subtree, item at node, then right subtree 
    if(tree!=NULL)
    {
		print_in_order(tree->left);
		cout<<tree->course_item;
		cout<<"   ";
		print_in_order(tree->right);
    }
}

// Function to find node containing n in BST, returning NULL if n not present
node1 *unitTree::find(string courseName)
{
	return find(courseName,root);
}

// the internal recursive implementation 

node1*unitTree::find(string courseName, node1* tree)
{
    if(!tree || (courseName == tree->course_item)) // not present, or present here 
    {
		return tree;
    }
    // otherwise look in left / right subtree as appropriate 
    else if(courseName < tree->course_item)
    {
		return find(courseName, tree->left);
    }
    else
    {
		return find(courseName, tree->right);
    }
}


void unitTree::remove(string courseName)
{
	remove(courseName,root);
}

void unitTree::remove(string courseName, node1* &tree)
{
    if( tree == NULL )
        return;   // Item not found; do nothing
    if( courseName < tree->course_item )
        remove( courseName, tree->left );
    else if( tree->course_item < courseName )
        remove( courseName, tree->right );
    else if( tree->left != NULL && tree->right != NULL ) // Two children
    {
        tree->course_item = findMin( tree->right )->course_item;
        remove( tree->course_item, tree->right );
    }
    else
    {
        node1 *oldNode = tree;
        if (tree->left!=NULL)
			tree = tree->left;
		else
			tree = tree->right;

        delete oldNode;
    }
}

node1 *unitTree::findMin(node1* tree)
{
    if( tree == NULL )
        return NULL;
    if( tree->left == NULL )
        return tree;
    return findMin( tree->left );
}

void unitTree::makeEmpty(node1* tree){
	if (tree!=NULL){
		makeEmpty(tree->left);
		makeEmpty(tree->right);
		delete tree;
	}
}
