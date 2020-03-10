#include "movie.h"


Movie::Movie()
{
}

Movie::~Movie()
{
}

void Movie::setStock(int stock)
{
	this->stock = stock;
}

void Movie::setDirector(string director)
{
	this->director = director;
}

void Movie::setTitle(string title)
{
	this->title = title;
}

void Movie::setReleaseYear(int releaseYear)
{
	this->releaseYear = releaseYear;
}

void Movie::setTypeOfMovie(char c)
{
	this->typeOfMovie = c;
}

int Movie::getStock() const
{
	return stock;
}

string Movie::getDirector() const
{
	return director;
}

string Movie::getTitle() const
{
	return this->title;
}

int Movie::getReleaseYear() const
{
	return this->releaseYear;
}

char Movie::getTypeOfMovie() const
{
	return this->typeOfMovie;
}
