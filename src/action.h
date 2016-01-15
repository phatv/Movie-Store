#pragma once
#include "media.h"
#include "customer.h"

// -----------------------------------------------------------------------------
// Action class: object representing a transaction to be made
//  -- executes action depending on child class
//  -- virtual function execute must be overloaded by child
//  -- holds a pointer to manager class
//  -- manager class used to access the customer database and inventory

class Manager;
class Action
{
	friend ostream& operator<<(ostream &, const Action &);
public:
	Action();
	virtual ~Action();

	// runs the transaction
	// must be overloaded by child class
	virtual bool execute() = 0;
	// sets data required to execute action
	virtual bool setData(Manager *, istream &) = 0;
	// returns a new child action
	virtual Action* create() const = 0;

	// prints out action for information
	virtual void print(ostream &) const = 0;

protected:
	// pointer to manager class that holds the inventory
	Manager *_manager;
};

