// ------------------------------------------------ comedy.h -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This header file is a subclass of the movie class. The Comedy class is meant to represent movies of the
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

#pragma once
#include "movie.h"

using namespace std;
class Comedy : public Movie
{
public:
	//constructor and destructor
	Comedy(char type);
	~Comedy();

	//operator overloads
	bool operator==(const Movie& other) const;
	bool operator!=(const Movie& other)const;
	bool operator>(const Movie& other) const;
	bool operator<(const Movie& other) const;

};

