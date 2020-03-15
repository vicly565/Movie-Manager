// ------------------------------------------------ comedy.cpp -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class is a subclass of the movie class. The Comedy class is meant to represent movies of the
// comedy genre for the business inventory system.
// -------------------------------------------------------------------------------------------------------------------- 
// 
// Specifications: Every Comedy movie contains a the stock of the movie, movie type, title, director, and release year.
// 
// Every Comedy movie uses methods defined in the movie class, and contains operator overloads
//
// Assumptions: This class assumes that all data is formatted correctly
// 
// --------------------------------------------------------------------------------------------------------------------

#include "comedy.h"


// ------------------------------------Comedy()----------------------------------------------- 
// Description
// Comedy(char type): Creates a comedy movie object with the type set
// preconditions: Movie base class exists
//
// postconditions: a Comedy object is created
//
// -------------------------------------------------------------------------------------------- 
Comedy::Comedy(char type) {
	this->typeOfMovie = type;
}

// ------------------------------------~Comedy()----------------------------------------------- 
// Description
// ~Comedy(): Destructor for the movie class
// preconditions: Comedy object exists
//
// postconditions: this object is deleted
//
// -------------------------------------------------------------------------------------------- 


// ------------------------------------Operator Overloads-------------------------------------------
// ------------------------------------Equals Operator Overload---------------------------------
// Description
//  bool operator==(const Movie& other) const: Checks if this comedy movie is the same as the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns true if the two movies are equal, or false if they are not
//
// Assumptions: This method assumes that the user is passing in a movie of the comedy type
//
// -------------------------------------------------------------------------------------------- 
bool Comedy::operator==(const Movie& other) const
{
	//compares the movie title, and release year to see if they are equal
	if (title == other.getTitle()) {
		if (releaseYear == other.getReleaseYear()) {
			return true;
		}
	}
	//if any of those conditionals are broken
	return false;
}

// ------------------------------------ Not Equals Operator Overload------------------------------
// Description
//  bool operator!=(const Movie& other) const: Checks if this comedy  movie is not the same as the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns false if the two movies are equal, or true if they are not
//
// Assumptions: This method assumes that the user is passing in a movie of the comedy type
//
// -------------------------------------------------------------------------------------------- 
bool Comedy::operator!=(const Movie& other) const
{
	//returns the opposite of the equal operator
	return !(*this == other);
}

// -------------------------------- Greater Than Operator Overload------------------------------
// Description
//  bool operator>(const Movie& other) const: Checks if this comedy movie is greater than the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns true if this movie is greater than or false if it is
//					less than or equal to the movie
//
// Assumptions: This method assumes that the user is passing in a movie of the comedy type.
// This method assumes the user wants the movies checked by title then release year.
//
// -------------------------------------------------------------------------------------------- 
bool Comedy::operator>(const Movie& other) const
{

	//if titles aren't equal compare them
	if (title != other.getTitle()) {
		return title.compare(other.getTitle()) > 0;
	}

	//otherwise compare years
	return releaseYear > other.getReleaseYear();
}

// -------------------------------- Less Than Operator Overload------------------------------
// Description
//  bool operator<(const Movie& other) const: Checks if this comedy movie is less than the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns true if this movie is less than or false if it is
//					greater than or equal to the movie
//
// Assumptions: This method assumes that the user is passing in a movie of the comedy type.
// This method assumes the user wants the movies checked by title then release year.
//
// --------------------------------------------------------------------------------------------
bool Comedy::operator<(const Movie& other) const
{

	//if titles aren't equal compare them
	if (title != other.getTitle()) {
		return title.compare(other.getTitle()) < 0;
	}

	//otherwise compare years
	return releaseYear < other.getReleaseYear();
}
// ------------------------------------End of Operator Overloads--------------------------------

