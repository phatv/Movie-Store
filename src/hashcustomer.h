#pragma once
#include "customer.h"

// -----------------------------------------------------------------------------
// HashCustomer class: database of all customers of the store
//  -- stores customers in a hash
//  -- allows for add customer into database
//  -- customers are identified based on their ID number
//  -- allows for retrievals of customers from database
//  -- customers are never allowed to leave

static const int MAX_CUST = 37;

class HashCustomer
{
public:
	HashCustomer();
	~HashCustomer();

	// adds person to the database
	bool add(Customer *);
	// retrieves a customer
	Customer* get(const int &) const;

private:
	// database of all customers
	Customer *_table[MAX_CUST];

	// hash function creates a unique hash from an ID
	int hash(const int &) const;
	// creates a new hash, uses quadratic probing
	int rehash(const int &, const int &) const;
};

