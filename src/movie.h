#pragma once
#include "media.h"

// -----------------------------------------------------------------------------
// Movie class: derived class of Media
//  -- has Title, release date, and format from Media
//  -- also has Director and genre
//  -- parent class of genres

static const int OUTPUT_MAX_LENGTH_DIRECTOR = 16;
static const int MOVIE_EARLIEST_DATE = 1850;
static const int CURRENT_YEAR = 2015;

class Movie : public Media
{
public:
	Movie();
	virtual ~Movie();
	

	// returns the director
	Person getDirector() const;
	// returns genre character
	char getGenre() const;
	// creates a clone of the movie
	virtual Movie* clone() const = 0;
	// returns new child movie
	virtual Movie* create() const = 0;
	// sets date of movie
	virtual bool setData(istream &) = 0;
	// sets sets just movie data
	bool setMovieData(istream &);
	// sets sorting data for movie
	virtual void setSortData(istream &) = 0;

protected:
	// director of the movie
	Person _director;
	// char representing genre
	char _genre;
};