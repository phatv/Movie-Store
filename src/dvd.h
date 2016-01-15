#pragma once
#include "format.h"

// -----------------------------------------------------------------------------
// DVD class: derived class of format

class DVD : public Format
{
public:
	DVD();
	// sets amount of DVDs
	DVD(const int);
	~DVD();

	// returns new dvd
	Format* create() const;
};

