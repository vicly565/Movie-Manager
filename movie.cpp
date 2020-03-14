// ------------------------------------------------ movie.cpp -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file is an abstract class for the movie type. This class is used for the dvd store inventory system
// and represents a movie within the business
// -------------------------------------------------------------------------------------------------------------------- 
// 
// Specifications: Every movie contains a the stock of the movie, movie type, title, director, and release year. 
// 
// Every movie has these PUBLIC FUNCTIONS:
//								virtual void display(); //method for printing out movie
//
//								in addition to this function, all movies have getters and setters
//								for all of its protected data values.
//
// Assumptions: This abstract class assumes that the user never intends on creating this base class, but instead
// assumes the user intends on creating one of the three subclasses (Comedy, Classic, or Drama).
// 
// --------------------------------------------------------------------------------------------------------------------

#include "movie.h"

Movie::~Movie()
{
}

// ------------------------------------Setters-----------------------------------------------
// ------------------------------------setStock----------------------------------------------- 
// Description
// setStock(int stock): sets this movie's stock to the integer passed in
// preconditions: none
//
// postconditions: The movie's stock is set
//
// --------------------------------------------------------------------------------------------
void Movie::setStock(int stock)
{
	this->stock = stock;
}

// ------------------------------------setDirector----------------------------------------------- 
// Description
// setDirector(string director): sets this movie's director to the string passed in
// preconditions: none
//
// postconditions: The movie's director is set
//
// --------------------------------------------------------------------------------------------
void Movie::setDirector(string director)
{
	this->director = director;
}

// ------------------------------------setTitle----------------------------------------------- 
// Description
// setTitle(string title): sets this movie's title to the string passed in
// preconditions: none
//
// postconditions: The movie's title is set
//
// --------------------------------------------------------------------------------------------
void Movie::setTitle(string title)
{
	this->title = title;
}

// ------------------------------------setReleaseYear--------------------------------------------
// Description
// setReleaseYear(int releaseYear): sets this movie's release year to the integer passed in
// preconditions: none
//
// postconditions: The movie's release year is set
//
// --------------------------------------------------------------------------------------------
void Movie::setReleaseYear(int releaseYear)
{
	this->releaseYear = releaseYear;
}

// ------------------------------------setTypeOfMovie--------------------------------------------
// Description
// setTypeOfMovie(char c): sets this movie's type to the char passed in
// preconditions: none
//
// postconditions: The movie's type is set
//
// --------------------------------------------------------------------------------------------
void Movie::setTypeOfMovie(char c)
{
	this->typeOfMovie = c;
}

// ------------------------------------setMajorActor----------------------------------------------- 
// Description
// setMajorActor(string actor): to be overriden in classic subclass. Exists so that the operator
// overloads can be used as pure virtual for all subclasses
// preconditions: none
//
// postconditions: none
//
// --------------------------------------------------------------------------------------------
void Movie::setMajorActor(string actor)
{

}

// ------------------------------------setMajorActor----------------------------------------------- 
// Description
// setMajorActor(int month): to be overriden in classic subclass. Exists so that the operator
// overloads can be used as pure virtual for all subclasses
// preconditions: none
//
// postconditions: none
//
// --------------------------------------------------------------------------------------------
void Movie::setReleaseMonth(int month)
{

}
// ------------------------------------End of Setters-------------------------------------------


// ------------------------------------Getters-----------------------------------------------
// ------------------------------------getStock----------------------------------------------- 
// Description
// getStock(): returns this movie's stock
// preconditions: none
//
// postconditions: The movie's stock is returned
//
// --------------------------------------------------------------------------------------------
int Movie::getStock() const
{
	return stock;
}

// ------------------------------------getDirector----------------------------------------------- 
// Description
// getDirector(): returns this movie's director
// preconditions: none
//
// postconditions: The movie's director is returned
//
// --------------------------------------------------------------------------------------------
string Movie::getDirector() const
{
	return director;
}

// ------------------------------------getTitle----------------------------------------------- 
// Description
// getTitle(): gets this movie's title
// preconditions: none
//
// postconditions: The movie's title is returned
//
// --------------------------------------------------------------------------------------------
string Movie::getTitle() const
{
	return this->title;
}

// ------------------------------------getReleaseYear--------------------------------------------
// Description
// getReleaseYear(): gets the year this movie was released in
// preconditions: none
//
// postconditions: The movie's release year is returned
//
// --------------------------------------------------------------------------------------------
int Movie::getReleaseYear() const
{
	return this->releaseYear;
}

// ------------------------------------getTypeOfMovie--------------------------------------------
// Description
// getTypeOfMovie(): gets the type of movie of this object
// preconditions: none
//
// postconditions: The movie's type is returned
//
// --------------------------------------------------------------------------------------------
char Movie::getTypeOfMovie() const
{
	return this->typeOfMovie;
}

// ------------------------------------getMajorActor----------------------------------------------- 
// Description
// getMajorActor(): to be overriden in classic subclass. Exists so that the operator
// overloads can be used as pure virtual for all subclasses.
// preconditions: none
//
// postconditions: returns NULL if called on any movie subclass that this method is not overridden
// within
//
// --------------------------------------------------------------------------------------------
string Movie::getMajorActor() const
{
	return NULL;
}

// ------------------------------------getMonth----------------------------------------------- 
// Description
// getMonth(): to be overriden in classic subclass. Exists so that the operator
// overloads can be used as pure virtual for all subclasses.
// preconditions: none
//
// postconditions: returns NULL if called on any movie subclass that this method is not overridden
// within
//
// --------------------------------------------------------------------------------------------
int Movie::getReleaseMonth() const
{
	return NULL;
}
// ------------------------------------End of Getters-------------------------------------------

// ------------------------------------display----------------------------------------------- 
// Description
// display(): Prints out the movie the way it was read in from file
// preconditions: none
//
// postconditions: The movie data is printed
//
// --------------------------------------------------------------------------------------------
void Movie::display()
{

	cout << this->getTypeOfMovie() << ", " << this->getStock() << ", ";
	cout << this->getDirector() << ", " << this->getTitle() << ", ";
	cout << this->getReleaseYear() << endl;
}
