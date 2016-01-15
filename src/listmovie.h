#pragma once
#include "movie.h"
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// ListMovie class: list of movies
//  -- movie can be added to list
//  -- movie can be removed from list
//  -- movie can be searched if it is in list

class ListMovie
{
public:
	ListMovie();
	~ListMovie();

	// adds movie to list
	bool append(Movie *);
	// removes movie from list
	bool remove(Movie *);
	// searches for movie in list
	bool search(Movie *) const;
	// prints out list
	void print() const;

private:
	struct Node {
		Movie *_data;		// movie
		int _quantity;		// amount of times movie was added to list
		Node *_next;
		Node *_back;
	};
	Node *_head, *_tail;

	// searches through list for a movie
	Node* find(Movie *);
};

