#include "nodemovie.h"


//------------------------------------------------------------------------------
// Constructor
NodeMovie::NodeMovie()
{
	_data = NULL;
}


//------------------------------------------------------------------------------
// Destructor
NodeMovie::~NodeMovie()
{
	//delete _data;
	//_data = NULL;
}

//------------------------------------------------------------------------------
// NodeMovie(movie)
// sets data to parameter movie
NodeMovie::NodeMovie(Movie *nd)
{
	_data = nd;
}

//------------------------------------------------------------------------------
// getMovie
// returns node data
Movie* NodeMovie::getMovie() const
{
	return _data;
}

//------------------------- operator==,!= ------------------------------------
bool NodeMovie::operator==(const NodeData& rhs) const
{
	const NodeMovie& nd = static_cast<const NodeMovie&>(rhs);
	return *_data == *nd._data;
}

bool NodeMovie::operator!=(const NodeData& rhs) const
{
	const NodeMovie& nd = static_cast<const NodeMovie&>(rhs);
	return *_data != *nd._data;
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool NodeMovie::operator<(const NodeData& rhs) const
{
	const NodeMovie& nd = static_cast<const NodeMovie&>(rhs);
	return *_data < *nd._data;
}

bool NodeMovie::operator>(const NodeData& rhs) const
{
	const NodeMovie& nd = static_cast<const NodeMovie&>(rhs);
	return *_data > *nd._data;
}

bool NodeMovie::operator<=(const NodeData& rhs) const
{
	const NodeMovie& nd = static_cast<const NodeMovie&>(rhs);
	return *_data <= *nd._data;
}

bool NodeMovie::operator>=(const NodeData& rhs) const
{
	const NodeMovie& nd = static_cast<const NodeMovie&>(rhs);
	return *_data >= *nd._data;
}

void NodeMovie::print(ostream &outStream) const
{
	outStream << *_data;
}