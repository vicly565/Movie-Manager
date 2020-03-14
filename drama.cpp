// ------------------------------------------------ drama.cpp -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class is a subclass of the movie class. The Drama class is meant to represent movies of the
// comedy genre for the business inventory system.
// -------------------------------------------------------------------------------------------------------------------- 
// 
// Specifications: Every Drama movie contains a the stock of the movie, movie type, title, director, and release year.
// 
// Every Drama movie uses methods defined in the movie class, and contains operator overloads
//
// Assumptions: This class assumes that all data is formatted correctly
// 
// --------------------------------------------------------------------------------------------------------------------

#include "drama.h"


// ------------------------------------Drama()----------------------------------------------- 
// Description
// Drama(char type): Creates a drama movie object with the type set
// preconditions: Movie base class exists
//
// postconditions: a Drama object is created
//
// -------------------------------------------------------------------------------------------- 
Drama::Drama(char type) {
	this->typeOfMovie = type;
}

// ------------------------------------~Drama()----------------------------------------------- 
// Description
// ~Drama(): Destructor for the movie class
// preconditions: Drama object exists
//
// postconditions: this object is deleted
//
// -------------------------------------------------------------------------------------------- 


// ------------------------------------Operator Overloads-------------------------------------------
// ------------------------------------Equals Operator Overload---------------------------------
// Description
//  bool operator==(const Movie& other) const: Checks if this drama movie is the same as the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns true if the two movies are equal, or false if they are not
//
// Assumptions: This method assumes that the user is passing in a movie of the drama type
//
// -------------------------------------------------------------------------------------------- 
bool Drama::operator==(const Movie& other) const
{
	//compares the director then movie title to see if they are equal
	if (director == other.getDirector()) {
		if (title == other.getTitle()) {
			return true;
		}
	}
	//if any of those conditionals are broken
	return false;
}

// ------------------------------------ Not Equals Operator Overload------------------------------
// Description
//  bool operator!=(const Movie& other) const: Checks if this drama movie is not the same as the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns false if the two movies are equal, or true if they are not
//
// Assumptions: This method assumes that the user is passing in a movie of the drama type
//
// -------------------------------------------------------------------------------------------- 
bool Drama::operator!=(const Movie& other) const
{
	//returns the opposite of the equals operator
	return !(*this == other);
}

// -------------------------------- Greater Than Operator Overload------------------------------
// Description
//  bool operator>(const Movie& other) const: Checks if this drama movie is greater than the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns true if this movie is greater than or false if it is
//					less than or equal to the movie
//
// Assumptions: This method assumes that the user is passing in a movie of the drama type.
// This method assumes the user wants the movies checked by director then titles.
//
// -------------------------------------------------------------------------------------------- 
bool Drama::operator>(const Movie& other) const
{
	//compare directors
	if (director != other.getDirector()) {
		return director.compare(other.getDirector()) > 0;
	}

	//if directors are equal compare titles
	return title.compare(other.getTitle()) > 0;

}

// -------------------------------- Less Than Operator Overload------------------------------
// Description
//  bool operator<(const Movie& other) const: Checks if this drama movie is less than the
//										other movie.
//
// preconditions: A movie must be passed in
//
// postconditions: This function returns true if this movie is less than or false if it is
//					greater than or equal to the movie
//
// Assumptions: This method assumes that the user is passing in a movie of the drama type.
// This method assumes the user wants the movies checked by director then titles.
//
// --------------------------------------------------------------------------------------------
bool Drama::operator<(const Movie& other) const
{
	//compare directors
	if (director != other.getDirector()) {
		return director.compare(other.getDirector()) < 0;
	}

	//if directors are equal, compare titles
	return title.compare(other.getTitle()) < 0;

}
// ------------------------------------End of Operator Overloads--------------------------------

