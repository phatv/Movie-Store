#pragma once
#include "action.h"

// -----------------------------------------------------------------------------
// Display class: child class of Action
//  -- displays entire movie inventory
//  -- sorted into categories sorted by their own criteria

class Display : public Action
{
public:
	Display();
	~Display();

	// displays manager's inventory
	// calls inventory's display function
	virtual bool execute();
	// returns new display
	Action* create() const;
	// sets manager
	bool setData(Manager *, istream &);
	// prints out display action
	void print(ostream &) const;
};

