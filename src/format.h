#pragma once
#include <string>
using namespace std;

// -----------------------------------------------------------------------------
// Format class: represents the format for which the inventory holds ex: DVD
//   contains information about current inventory stock and total stock for
//   the represented format. 
//  -- tracks total inventory stock
//  -- tracks current inventory stock
//  -- allows for incremental adds or rems to current inventory stock
//  -- sets quantity of total inventory stock

class Format
{
public:
	Format();
	// sets quantity and instock
	virtual ~Format();

	// adds 1 to current inventory stock
	bool add();
	// subtract 1 from current inventory stock
	bool sub();

	// get total amount of movies in inventory
	int getQuantity() const;
	// gets current inventory stock
	int getCurrStock() const;
	// returns movie format ex. DVD
	string getType() const;

	// add to total inventory
	bool addQuantity(const int);
	// subtracts from total inventory
	// inventory will not fall below zero
	bool subQuantity(const int);

	virtual Format* create() const = 0;

protected:
	// set in child class
	string _type;
	// total amount of copies
	int _quantity;
	// amount currently in stock
	int _inStock;
};

