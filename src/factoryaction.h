#pragma once
#include "action.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "display.h"

// -----------------------------------------------------------------------------
// Factory class: creates actions based on a given char
//  -- creates the appropiate object from a given char
//  -- char is encoded through a hash
//  -- has a factory array that creates the action

static const int FACTORY_A_SIZE = 26;

class FactoryAction
{
public:
	FactoryAction();
	~FactoryAction();

	// creates an action depending on the char parameter
	Action* createIt(const char &) const;

private:
	// array of child actions
	Action *_factory[FACTORY_A_SIZE];
	// hash function for char to int
	int hash(const char &) const;
};

