// ------------------------------------------------ classic.h -------------------------------------------------------
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
#pragma once
#include "movie.h"

using namespace std;

class Classic : public Movie
{
public:
	//constructor and destructor
	Classic(char type);

	//setters
	void setMajorActor(string actor);
	void setReleaseMonth(int month);

	//getters
	string getMajorActor() const;
	int getReleaseMonth()const;


	//operator overloads
	bool operator==(const Movie& other) const;
	bool operator!=(const Movie& other)const;
	bool operator>(const Movie& other) const;
	bool operator<(const Movie& other) const;

	//print out movie
	void display();
private:
	string majorActor;
	int releaseMonth;

};

