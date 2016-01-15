#pragma once
#include "transaction.h"

// -----------------------------------------------------------------------------
// Borrow class: derived class of Transaction
//  -- borrows an item from the store

class Borrow : public Transaction
{
public:
	Borrow();
	// creates a borrow action, setting media and customer
	Borrow(Customer *, Media *);
	~Borrow();

	// executes the borrow action
	// subtracts movie from inventory, adds it to customer
	bool execute();
	// returns new borrow
	Action* create() const;
	// prints out borrow action, customer, and movie
	void print(ostream &) const;
};

