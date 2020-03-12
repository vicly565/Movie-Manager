#include "movie.h"



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

void Movie::setMajorActor(string actor)
{
	
}

void Movie::setReleaseMonth(int month)
{

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

string Movie::getMajorActor() const
{
	return NULL;
}

int Movie::getReleaseMonth() const
{
	return NULL;
}

void Movie::display()
{

	cout << this->getTypeOfMovie() << ", " << this->getStock() << ", ";
	cout << this->getDirector() << ", " << this->getTitle() << ", ";
	cout << this->getReleaseYear() << endl;
}
