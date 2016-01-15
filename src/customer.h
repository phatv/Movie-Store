#pragma once
#include "person.h"
#include "listaction.h"
#include "listmovie.h"
#include "tree.h"

// -----------------------------------------------------------------------------
// Customer class: derived class of Person, represents a customer of the store
//  -- holds a unique customer id
//  -- has a history of transaction by the customer
//  -- has a list of items currently checked out

static const int CUST_CATEGORY = 10;

class Customer : public Person
{
public:
	Customer();
	// creates a brand new customer
	Customer(const string, const string, const int);
	// creates a customer from a person
	Customer(Person, int);
	~Customer();

	// returns id of customer
	int getId() const;
	// adds a transaction to a customer's histry
	void addHistory(Action *);
	// prints out list of customer's action history
	void printHistory() const;

	// add movie to customer's checked out list
	bool bor(Movie *);
	// subtract movie from customer's checked out list
	bool ret(Movie *);
	// search for a movie in customer's checked out list
	bool search(Movie *) const;

	// operator overloads
	bool operator==(const Customer &) const;
	bool operator!=(const Customer &) const;

private:
	// customer id number
	int _id;
	// linked list of customer's history
	ListAction _history;
	// list of items checked out
	ListMovie _outMovies;
};

