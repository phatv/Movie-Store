#include "nodedata.h"

//------------------- constructors/destructor  -------------------------------
NodeData::NodeData()	// default
{
}

NodeData::~NodeData()	// needed so strings are deleted properly
{
}

//------------------------------------------------------------------------------
// operator<<
// prints out data
ostream& operator<<(ostream &outStream, const NodeData &nd)
{
	nd.print(outStream);
	return outStream;
}