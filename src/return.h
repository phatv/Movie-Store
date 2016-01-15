#pragma once
#include "transaction.h"

// -----------------------------------------------------------------------------
// Return class: derived class of Transaction
//  -- Returns a media item to the store

class Return : public Transaction
{
public:
	Return();
	// customer, media
	Return(Customer *, Media *);
	~Return();

	// returns an item to store and removes it from customer's 
	// checked out list
	bool execute();
	// returns new return action
	Action* create() const;
	// prints out return information
	// customer and media
	void print(ostream &) const;
};

