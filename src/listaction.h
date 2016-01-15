#pragma once
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// ListAction class: list of actions
//  -- action can be added to list
//  -- action can not be removed
//  -- displays all actions

class Action;
class ListAction
{
public:
	ListAction();
	~ListAction();

	// adds an action to the list
	void append(Action *);
	// prints out list of actions
	void print() const;

private:
	struct Node {
		Action *_data;		// action data
		Node *_next;		// next node
	};
	Node *_head, *_tail;	// head and tail node
};

