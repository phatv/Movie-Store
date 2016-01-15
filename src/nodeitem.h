#pragma once
#ifndef NODEITEM_H
#define NODEITEM_H
#include "nodedata.h"
#include "item.h"

// -----------------------------------------------------------------------------
// NodeItem class: child of NodeData
//  -- stores an item in a tree
//  -- can print out data

class NodeItem : public NodeData
{
public:
	NodeItem();
	~NodeItem();
	NodeItem(Item *);

	// returns item data
	Item* get() const;
	// prints out item data
	void print(ostream &) const;

	// operator overload
	bool operator==(const NodeData &) const;
	bool operator!=(const NodeData &) const;
	bool operator<(const NodeData &) const;
	bool operator>(const NodeData &) const;
	bool operator<=(const NodeData &) const;
	bool operator>=(const NodeData &) const;

private:
	// item
	Item *_data;
};
#endif