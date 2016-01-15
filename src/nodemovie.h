#pragma once
#ifndef NODEMOVIE_H
#define NODEMOVIE_H
#include "nodedata.h"
#include "movie.h"

// -----------------------------------------------------------------------------
// NodeMovie class: child class of NodeData
//  -- stores a movie in a tree
//  -- can print out data

class NodeMovie : public NodeData
{
public:
	NodeMovie();
	~NodeMovie();
	NodeMovie(Movie *);
	
	// returns movie data
	Movie* getMovie() const;
	// prints out movie
	void print(ostream &) const;

	// operator overloads
	bool operator==(const NodeData &) const;
	bool operator!=(const NodeData &) const;
	bool operator<(const NodeData &) const;
	bool operator>(const NodeData &) const;
	bool operator<=(const NodeData &) const;
	bool operator>=(const NodeData &) const;

private:
	// movie
	Movie *_data;
};
#endif