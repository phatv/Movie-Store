#pragma once
#include "item.h"
#include <iostream>

// -----------------------------------------------------------------------------
// HashItem class: database of all items in the store
//  -- stores items in a hash
//  -- allows for add items into inventory
//  -- items are hashed from their own hash function
//  -- allows for retrievals of items from inventory
//  -- items cannot be removed, though quantity can be set to zero

static const int MAX_SIZE = 63;

// uses quadratic probing

class HashItem
{
public:
	HashItem();
	~HashItem();

	// adds an item to the hash
	// uses item's own hash function
	bool add(Item *);
	// retrieves an item from hash
	// uses item's hash function
	Item* get(const Item *) const;

private:
	// array of items stored by hash
	Item *_table[MAX_SIZE];

	// rehashes a key if it is already taken
	int rehash(const int &, const int &) const;
};

