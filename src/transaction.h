#pragma once
#include "action.h"
#include "factorymovie.h"
#include "factoryformat.h"

// -----------------------------------------------------------------------------
// Transaction class: child class of Action
//  -- parent class of actions that make changes to inventory/customer
//  -- executes action depending on child class
//  -- virtual function execute must be overloaded by child
//  -- holds customer ID, used to retrieve customer from database
//  -- hold media item with partial data, used to retrieve media from inventory

class Transaction : public Action
{
public:
	Transaction();
	~Transaction();

	// returns pointer to customer
	Customer* getCustomer() const;
	// returns pointer to movie
	Media* getMedia() const;

	virtual bool setData(Manager *, istream &);

protected:
	// customer id number
	int _id;
	// customer being worked with
	Customer *_customer;
	// format char
	char _cFormat;
	// movie genre
	char _genre;
	// media item being handled
	Media *_item;
	// format
	Format *_format;

	// factory to create movie
	FactoryMovie _factoryMovie;
	// factory to create format
	FactoryFormat _factoryFormat;

	// verifies if customer and movie items exist in databases
	bool validate();
};

