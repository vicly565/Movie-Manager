// ------------------------------------------------ classic.cpp -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This header file is a subclass of the movie class. The Classic class is meant to represent movies of the
// classic genre for the business inventory system.
// -------------------------------------------------------------------------------------------------------------------- 
// 
// Specifications: Every  Classic movie contains a the stock of the movie, movie type, title, director, and release year.
// and contains a major actor and release month
// 
// Every Classic movie has these PUBLIC FUNCTIONS in addition to the functions in the base class:
//								void display(); //method for printing out movie
//
//								in addition to this function, all classic movies have overridden getters and setters
//								for major actor and month
//
// Assumptions: This class assumes that all data is formatted correctly
// 
// --------------------------------------------------------------------------------------------------------------------

#include "classic.h"

// ------------------------------------Classic()----------------------------------------------- 
// Description
// Classic(char type): Creates a classic movie object with the type set
// preconditions: Movie base class exists
//
// postconditions: a Classic object is created
//
// -------------------------------------------------------------------------------------------- 
Classic::Classic(char type)
{
	this->typeOfMovie = type;
}

// ------------------------------------~Classic()----------------------------------------------- 
// Description
// ~Classic(): Destructor for the movie class
// preconditions: Classic object exists
//
// postconditions: this object is deleted
//
// -------------------------------------------------------------------------------------------- 



// ------------------------------------Setters-----------------------------------------------
// ------------------------------------setMajorActor----------------------------------------------- 
// Description
// setMajorActor(string actor): overloaded function to set this classic movie's major actor
// preconditions: none
//
// postconditions: The classic movie's major actor is set
//
// --------------------------------------------------------------------------------------------
void Classic::setMajorActor(string actor)
{
	this->majorActor = actor;
}

// ------------------------------------setMajorActor----------------------------------------------- 
// Description
// setReleaseMonth(int month): overloaded function to set this classic movie's release month
// preconditions: none
//
// postconditions: The classic movie's release month is set
//
// --------------------------------------------------------------------------------------------
void Classic::setReleaseMonth(int month)
{
	this->releaseMonth = month;
}
// ------------------------------------End of Setters-------------------------------------------

// ------------------------------------Getters-----------------------------------------------
// ------------------------------------getMajorActor----------------------------------------------- 
// Description
// getMajorActor(): overloaded function to get this classic movie's major actor
// preconditions: none
//
// postconditions: The classic movie's major actor is returned
//
// --------------------------------------------------------------------------------------------
string Classic::getMajorActor() const
{
	return this->majorActor;
}

// ------------------------------------getMajorActor----------------------------------------------- 
// Description
// getReleaseMonth(): overloaded function to get this classic movie's release month
// preconditions: none
//
// postconditions: The classic movie's release month is returned
//
// --------------------------------------------------------------------------------------------
int Classic::getReleaseMonth() const
{
	return this->releaseMonth;
}
// ------------------------------------End of getters-------------------------------------------

// ------------------------------------Operator Overloads-------------------------------------------
// ------------------------------------Assignment Operator Overload---------------------------------
// Description
//  Movie& operator=(Movie& rhs) const: copies all data values of the right hand movie to this movie
// preconditions: A movie must be passed in
//
// postconditions: This function returns a copy of the right hand movie
//
// -------------------------------------------------------------------------------------------- 
Movie& Classic::operator=(Movie& rhs)
{
	this->typeOfMovie = rhs.getTypeOfMovie();
	this->stock = rhs.getStock();
	this->director = rhs.getDirector();
	this->title = rhs.getTitle();
	this->releaseYear = rhs.getReleaseYear();
	this->releaseMonth = rhs.getReleaseMonth();
	this->majorActor = rhs.getMajorActor();
	return *this;
}

// ------------------------------------Equals Operator Overload---------------------------------
// Description
//  bool operator==(const Movie& other) const: Checks if this classic movie is the same as the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns true if the two movies are equal, or false if they are not
//
// Assumptions: This method assumes that the user is passing in a movie of the classic type
//
// -------------------------------------------------------------------------------------------- 
bool Classic::operator==(const Movie& other) const
{
	//compare the release date (first the year then the month)
	//and then compare the major actor to see if the two movies are equal
	if (releaseYear == other.getReleaseYear()) {
		if (releaseMonth == other.getReleaseMonth()) {
			if (majorActor == other.getMajorActor()) {
				return true;
			}
		}
	}

	//if any conditional is broken we return false
	return false;
}

// ------------------------------------ Not Equals Operator Overload------------------------------
// Description
//  bool operator!=(const Movie& other) const: Checks if this classic movie is not the same as the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns false if the two movies are equal, or true if they are not
//
// Assumptions: This method assumes that the user is passing in a movie of the classic type
//
// -------------------------------------------------------------------------------------------- 
bool Classic::operator!=(const Movie& other) const
{
	//return the opposite of the equals operator
	return !(*this == other);
}

// -------------------------------- Greater Than Operator Overload------------------------------
// Description
//  bool operator>(const Movie& other) const: Checks if this classic movie is greater than the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns true if this movie is greater than or false if it is
//					less than or equal to the movie
//
// Assumptions: This method assumes that the user is passing in a movie of the classic type.
// This method assumes the user wants the movies checked by release date then major actor
//
// -------------------------------------------------------------------------------------------- 
bool Classic::operator>(const Movie& other) const
{
	//compare the release years
	if (releaseYear != other.getReleaseYear()) {
		return releaseYear > other.getReleaseYear();
	}

	//if years are equal compare months
	if (releaseMonth != other.getReleaseMonth()) {
		return releaseMonth > other.getReleaseMonth();
	}

	//if months are equal compare major actors by first name
	return majorActor.compare(other.getMajorActor()) > 0;
}

// -------------------------------- Less Than Operator Overload------------------------------
// Description
//  bool operator<(const Movie& other) const: Checks if this classic movie is greater than the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns true if this movie is greater than or false if it is
//					greater than or equal to the movie
//
// Assumptions: This method assumes that the user is passing in a movie of the classic type.
// This method assumes the user wants the movies checked by release date then major actor
//
// --------------------------------------------------------------------------------------------
bool Classic::operator<(const Movie& other) const
{
	//compares the release years
	if (releaseYear != other.getReleaseYear()) {
		return releaseYear < other.getReleaseYear();
	}

	//if release year is equal compare months
	if (releaseMonth != other.getReleaseMonth()) {
		return releaseMonth < other.getReleaseMonth();
	}

	//if months are equal compare major actor instead
	return majorActor.compare(other.getMajorActor()) < 0;
}
// ------------------------------------End of Operator Overloads--------------------------------

// ------------------------------------display----------------------------------------------- 
// Description
// display(): Prints out the Classic movie the way it was read in from file
// preconditions: none
//
// postconditions: The classic movie data is printed
//
// --------------------------------------------------------------------------------------------
void Classic::display()
{

	cout << this->getTypeOfMovie() << ", " << this->getStock() << ", ";
	cout << this->getDirector() << ", " << this->getTitle() << ", ";
	cout << this->getMajorActor() << " " << this->getReleaseMonth() << " ";
	cout << this->getReleaseYear() << endl;
}


