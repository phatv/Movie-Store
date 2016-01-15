#pragma once
#include "media.h"
#include "movie.h"
#include "tree.h"
#include "nodemovie.h"
#include "nodeitem.h"
#include "person.h"
#include "hashitem.h"

// -----------------------------------------------------------------------------
// Inventory class: database of all inventory items. This class uses a hash to
//   store all items
//  -- Stores media items within a hash
//  -- may add item to an inventory
//  -- retrieve item from database
//  -- sorts item into categories within trees
//  -- array of trees for each category

static const int INVEN_CATEGORY = 26;
static const int INVEN_MAX_SIZE = 100;

// THIS IS A HASH
class Inventory
{
public:
	Inventory();
	~Inventory();

	// adds a movie to the inventory
	// insert item along with code
	bool add(const char &, Item *);

	// retrieves an item from the item hash
	Item* getItem(const Item *) const;
	// sets heading for a movie category
	void setHeading(const char &, const string &);
	// displays each item by category
	// displays the array of trees
	void display();

private:
	// struct used for the array of trees
	struct TreeNode
	{
		Tree tree;				// tree holding the movies of sam category
		string heading;			// heading for unique categories
	};
	// THIS IS A HASH
	HashItem _itemHash;
	// stores movie by category
	// each category will be stored as a tree
	// no detructor for this one
	//Tree _movieByCat[INVEN_CATEGORY];
	TreeNode _movieByCat[INVEN_CATEGORY];
	// hash function uesd to sort categories
	int hashcat(const char &) const;
};

