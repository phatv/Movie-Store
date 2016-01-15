#pragma once
#include "action.h"

// -----------------------------------------------------------------------------
// History class: derived class of Transaction
//  -- displays the history for a customer

class History : public Action
{
public:
	History();
	~History();

	// prints out history of a customer
	virtual bool execute();
	// returns new history action
	Action* create() const;
	// sets customer
	bool setData(Manager *, istream &);
	// prints out history
	void print(ostream &) const;
	
private:
	// customer id to be found
	int _id;
	// customer to be displayed
	Customer *_customer;
};

