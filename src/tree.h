#pragma once

#include "nodedata.h"
#include <iostream>
using namespace std;

//------------------------------------------------------------------------------
//  Tree class: a binary search tree class (no remove) called Tree along 
//    with some additional functions. A data file consisting of many lines is 
//    used to build binary trees. One line, which consists of many strings, will
//    be used to build one tree. Each line is terminated with the string "$$".
//    The NodeData, holding a string, is stored once in the tree. 
//  
//  Features:
//   - Allows for output of the whole array using DisplaySideways() or cout
//   - Allows for comparison of two trees, element by element
//   - Allows for assignment of two trees
//   - Allows for transfer of elements to array
//   - Allows for transfer from array to tree
//   - Allows to get height of an element
//
//  Implementation and assumptions:
//   - Empty tree root is NULL
//   - Height of leaf is one
//   - cout displays tree as an inorder traversal
//   - bstree to array stores tree as inorder traversal
//------------------------------------------------------------------------------

class Tree
{
	// The operator<< will display as an inorder traversal. 
	// The NodeData class is responsible for displaying its data. 
	friend ostream& operator<<(ostream &, const Tree &);

public:

	Tree(); // constructor
	Tree(const Tree &); // copy constructor
	~Tree(); // destructor, calls makeEmpty

	// Inserts a NodeData* of a given object in the tree. 
	// Return whether successfully inserted or not. 
	bool insert(NodeData *);

	// Retrieve a NodeData* of a given object in the tree 
	// (via pass-by-reference parameter). Return whether found.
	// The second parameter may initially be garbage, will point to the actual 
	// object in the tree if it is found.
	bool retrieve(const NodeData &, NodeData * &) const;

	bool remove(const NodeData &);

	// true if tree is empty, otherwise false
	bool isEmpty() const;

	// make the tree empty so isEmpty returns true
	void makeEmpty();

	int getSize() const;

	// Find the height of a given value in the tree. 
	// A leaf is considered height of one.
	int getHeight(const NodeData &) const;

	// A routine fills an array of NodeData* by using an inorder traversal 
	// of the tree. It leaves the tree empty. 
	// Assumes array is equal to or larger than tree and full of NULLs. 
	void bstreeToArray(NodeData *[]);

	// A routine builds a balanced Tree from a sorted array (assumed) 
	// of NodeData* leaving the array filled with NULLs. 
	void arrayToBSTree(NodeData *[]);

	// Assignment operator for trees
//	Tree& operator=(const Tree &);

	// Compares equals of two trees
	bool operator==(const Tree &) const;

	// Compares not equal of two trees
	bool operator!=(const Tree &) const;

	// Displays the tree sideways
	void displaySideways() const;

private:
	struct Node {
		NodeData* data; // pointer to data object
		Node* left; // left subtree pointer
		Node* right; // right subtree pointer
	};

	Node* _root; // root of the tree
	int _size;

	// utility functions
	// recursive helper for insert
	bool insertHelper(Node * &, NodeData *);
	// recursive helper for retrieve
	bool retrieveHelper(Node * &, const NodeData &, NodeData * &) const;
	// recursive helper for remove
	bool removeHelper(Node * &curr, const NodeData &);
	// recursive helper for empty
	void emptyHelper(Node * &);
	// recursive helper for height
	int heightHelper(Node * &, const NodeData &, int &) const;
	// recursive helper to create array from treee
	int toArrayHelper(Node * &, NodeData *[], int);
	// recursive helper to create tree from array
	void toTreeHelper(Node * &, NodeData *[], const int &, const int &);
	// recursive helper for assignment
//	void assignmentHelper(Node * &, Node * &);
	// recusive helper for operator equals
	bool equalsHelper(Node * &, Node * &) const;
	// recursive helper for display sideways
	void sideways(Node*, int) const; // helper for displaySideways()
	// recursive helper for operator<<
	void outputHelper(ostream &) const;
	// another recursive helper for operator<<
	void outputHelperHelper(ostream &, Node * &) const;
	// finds max node in subtree
	NodeData* findMax(Node * &curr);
};