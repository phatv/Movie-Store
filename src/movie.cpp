#include "movie.h"
#include "comedy.h"

//------------------------------------------------------------------------------
// Constructor
Movie::Movie()
{
}

//------------------------------------------------------------------------------
// Destructor
Movie::~Movie()
{
}

//------------------------------------------------------------------------------
// getDirector
// returns director
Person Movie::getDirector() const
{
	return _director;
}

//------------------------------------------------------------------------------
// getGenre
// returns genre
char Movie::getGenre() const
{
	return _genre;
}

//------------------------------------------------------------------------------
// setMovieData
// sets movie director and title
bool Movie::setMovieData(istream &infile)
{
	// sets director
	string first, last;
	infile >> first;
	infile.get();
	getline(infile, last, ',');
	_director = Person(first, last);

	// sets title
	infile.get();
	getline(infile, _title, ',');
	infile.get();
	return true;
}