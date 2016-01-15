#include "nodeitem.h"


//------------------------------------------------------------------------------
// Constructor
NodeItem::NodeItem()
{
	_data = NULL;
}


//------------------------------------------------------------------------------
// Destructor
NodeItem::~NodeItem()
{
	//delete _data;
	//_data = NULL;
}

//------------------------------------------------------------------------------
// NodeItem(item)
// sets item data to parameter
NodeItem::NodeItem(Item *nd)
{
	_data = nd;
}

//------------------------------------------------------------------------------
// get
// returns item data
Item* NodeItem::get() const
{
	return _data;
}

//------------------------- operator==,!= ------------------------------------
bool NodeItem::operator==(const NodeData& rhs) const
{
	const NodeItem& nd = static_cast<const NodeItem&>(rhs);
	return *_data == *nd._data;
}

bool NodeItem::operator!=(const NodeData& rhs) const
{
	const NodeItem& nd = static_cast<const NodeItem&>(rhs);
	return *_data != *nd._data;
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool NodeItem::operator<(const NodeData& rhs) const
{
	const NodeItem& nd = static_cast<const NodeItem&>(rhs);
	return *_data < *nd._data;
}

bool NodeItem::operator>(const NodeData& rhs) const
{
	const NodeItem& nd = static_cast<const NodeItem&>(rhs);
	return *_data > *nd._data;
}

bool NodeItem::operator<=(const NodeData& rhs) const
{
	const NodeItem& nd = static_cast<const NodeItem&>(rhs);
	return *_data <= *nd._data;
}

bool NodeItem::operator>=(const NodeData& rhs) const
{
	const NodeItem& nd = static_cast<const NodeItem&>(rhs);
	return *_data >= *nd._data;
}

void NodeItem::print(ostream &outStream) const
{
	outStream << *_data;
}