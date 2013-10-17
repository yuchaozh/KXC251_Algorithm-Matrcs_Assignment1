#ifndef _UINTTREE_H
#define _UNITTREE_H
#include <string>
using namespace std;
/* Define node - note that the names clash with those
   for the list types. The use of longer names like list_node and tree_node 
   would have the advantage of avoiding this clash.
*/
class node1{
public:
    string course_item;
    node1 *left;
    node1 *right;

	node1();
	node1(string courseName);
};

class unitTree
{
public:
// Constructor/Destructor 
	unitTree();
	~unitTree();
	
// Function to insert n into BST, returning tree with n inserted.
// (Leaves BST unaltered if n is already present.)
	void insert(string courseName);

// Function to print tree in order 
	void print_in_order();

// Function to find node containing n in BST, returning NULL if n not present
	node1 *find(string courseName);
	//bool find(string courseName);
// Function to remove n from BST
// (Leaves BST unaltered if n not present.) 

	void remove(string courseName);

private:
	node1 *root;

// internal function to facilitate recursive definition of insert 
	void insert(string courseName, node1* &tree);

// internal function to facilitate recursive definition of print 
	void print_in_order(node1* tree);

// internal function to facilitate recursive definition of find 
	node1 *find(string courseName, node1* tree);
	//bool find(string courseName, node1* tree);
// internal function to facilitate recursive definition of delete 
	void remove(string courseName, node1* &tree);

// helper function for remove 
	node1 *findMin(node1* tree);

// free memory 
	void makeEmpty(node1* tree);
};

#endif
