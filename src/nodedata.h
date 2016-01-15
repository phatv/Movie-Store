#ifndef NODEDATA_H
#define NODEDATA_H
#include <iostream>
#include <fstream>
using namespace std;

// -----------------------------------------------------------------------------
// NodeData class: parent class for a node in a tree

class NodeData
{
   friend ostream & operator<<(ostream &, const NodeData &);

public:
   NodeData();          // default constructor, data is set to an empty string
   virtual ~NodeData() = 0;

   // prints out node data
   virtual void print(ostream &) const = 0;

   // operator overload
   virtual bool operator==(const NodeData &) const = 0;
   virtual bool operator!=(const NodeData &) const = 0;
   virtual bool operator<(const NodeData &) const = 0;
   virtual bool operator>(const NodeData &) const = 0;
   virtual bool operator<=(const NodeData &) const = 0;
   virtual bool operator>=(const NodeData &) const = 0;
};

#endif

