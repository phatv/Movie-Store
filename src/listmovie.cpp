#include "listmovie.h"

//------------------------------------------------------------------------------
// Constructor
ListMovie::ListMovie()
{
	_head = NULL;
	_tail = NULL;
}

//------------------------------------------------------------------------------
// Destructor
ListMovie::~ListMovie()
{
	while (_head != NULL)
	{
		Node *temp = _head;
		_head = _head->_next;
	//	delete temp->_data;
		temp->_data = NULL;
		delete temp;
		temp = NULL;
	}
	_tail = NULL;
}

//------------------------------------------------------------------------------
// append
// adds an movie to the end of the list
bool ListMovie::append(Movie *movie)
{
	// creates new head node if head is NULL
	if (_head == NULL)
	{
		_head = new Node;
		_head->_data = movie;
		_head->_quantity = 1;
		_head->_next = NULL;
		_head->_back = NULL;
		_tail = _head;
		return true;
	}
	else
	{
		// checks to see if movie is in list, increment if it is
		// else, creates new node and adds it to end of list
		Node *temp = find(movie);
		if (temp == NULL)
		{
			_tail->_next = new Node;
			_tail->_next->_back = _tail;
			_tail = _tail->_next;
			_tail->_data = movie;
			_tail->_quantity = 1;
			_tail->_next = NULL;
			return true;
		}
		else
		{
			temp->_quantity++;
			return true;
		}
	}
}

//------------------------------------------------------------------------------
// remove
// removes a movie from list
bool ListMovie::remove(Movie *movie)
{
	// checks head
	if (_head->_data->getGenre() == movie->getGenre())
	{
		if (*_head->_data == *movie)
		{
			if (_head->_quantity > 1)
			{
				_head->_quantity--;
				return true;
			}
			else
			{
				Node *temp = _head;
				_head = _head->_next;
				if (_head != NULL)
				{
					_head->_back = NULL;
				}
				delete temp;
				temp = NULL;
				return true;
			}
		}
	}
	// finds movie
	Node *temp = find(movie);
	// if found, decrement it or removes it
	if (temp != NULL)
	{
		if (temp->_quantity > 1)
		{
			temp->_quantity--;
			return true;
		}
		else
		{
			if (temp == _tail)
			{
				_tail = _tail->_back;
			}
			if (temp->_back != NULL)
			{
				temp->_back->_next = temp->_next;
			}
			if (temp->_next != NULL)
			{
				temp->_next->_back = temp->_back;
			}
			delete temp;
			temp = NULL;
			return true;
		}
	}
	return false;
}

//------------------------------------------------------------------------------
// search
// searches for a movie in the list
bool ListMovie::search(Movie *movie) const
{
	Node *curr = _head;
	while (curr != NULL)
	{
		if (curr->_data->getGenre() == movie->getGenre())
		{
			if (*curr->_data == *movie)
			{
				return true;
			}
			else
			{
				curr = curr->_next;
			}
		}
	}
	return false;
}

//------------------------------------------------------------------------------
// print
// prints out list of movie to cout
void ListMovie::print() const
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

//------------------------------------------------------------------------------
// find
// goes through list searching for passed in movie
ListMovie::Node* ListMovie::find(Movie *movie)
{
	Node *curr = _head;
	while (curr != NULL)
	{
		if (curr->_data->getGenre() == movie->getGenre())
		{
			if (*curr->_data == *movie)
			{
				return curr;
			}
		}
		curr = curr->_next;
	}
	return NULL;
}