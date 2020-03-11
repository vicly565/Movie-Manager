#include "comedy.h"

Comedy::Comedy(int stock, string director, string title, int releaseYear) {
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->releaseYear = releaseYear;
}

Comedy::Comedy(const Comedy& theMovie)
{
	*this = theMovie;
}

Comedy::~Comedy()
{
}

bool Comedy::operator==(const Comedy& compared) const
{
	//compares the movie title, and release year to see if they are equal
	if (title == compared.getTitle()) {
			if (director == compared.getDirector()) {
				return true;
		}
	}
	//if any of those conditionals are broken
	return false;
}

bool Comedy::operator!=(const Comedy& compared) const
{
	return !(*this == compared);
}

bool Comedy::operator>(const Comedy& compared) const
{
	//if this title is less than the compared movie's title
	//and its less than the release year we can return false
	if (title <= compared.getTitle()) {
		if (releaseYear <= compared.getReleaseYear()) {
			return false;
		}
	}

	//otherwise the movie is greater than the compared movie
	return true;
}

bool Comedy::operator<(const Comedy& compared) const
{
	return !(*this > compared);
}

Comedy Comedy::operator=(const Comedy& theMovie)
{
	this->stock = theMovie.getStock();
	this->director = theMovie.getDirector();
	this->title = theMovie.getTitle();
	this->releaseYear = theMovie.getReleaseYear();
	return *this;
}
