#include "listaction.h"
#include "action.h"

//------------------------------------------------------------------------------
// Constructor
ListAction::ListAction()
{
	_head = NULL;
	_tail = NULL;
}

//------------------------------------------------------------------------------
// Destructor
ListAction::~ListAction()
{
	while (_head != NULL)
	{
		Node *temp = _head;
		_head = _head->_next;
		delete temp->_data;
		temp->_data = NULL;
		delete temp;
		temp = NULL;
	}
	_tail = NULL;
}

//------------------------------------------------------------------------------
// append
// adds an action to the list
void ListAction::append(Action *action)
{
	// creates new node if head is NULL
	if (_head == NULL)
	{
		_head = new Node;
		_head->_data = action;
		_head->_next = NULL;
		_tail = _head;
	}
	else
	{
		// adds item to end of list
		_tail->_next = new Node;
		_tail = _tail->_next;
		_tail->_data = action;
		_tail->_next = NULL;
	}
}

//------------------------------------------------------------------------------
// print
// traverses and prints out list
// calls action's output operator
void ListAction::print() const
{
	if (_head == NULL)
	{
		cout << "Empty" << endl;
	}
	else
	{
		Node *curr = _head;
		while (curr != NULL)
		{
			cout << *curr->_data << endl;
			curr = curr->_next;
		}
	}
}