// ------------------------------------------------ movie.h -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This header file is an abstract class for the movie type. This class is used for the dvd store inventory system
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

#pragma once
#include <iostream>
using namespace std;
class Movie
{
public:
	virtual ~Movie();

	//Setter methods
	virtual void setStock(int stock);
	virtual void setDirector(string director);
	virtual void setTitle(string title);
	virtual void setReleaseYear(int releaseYear);
	virtual void setTypeOfMovie(char c);
	virtual void setMajorActor(string actor);
	virtual void setReleaseMonth(int month);


	//Getter methods
	virtual int getStock()const;
	virtual string getDirector()const;
	virtual string getTitle()const;
	virtual int getReleaseYear()const;
	virtual char getTypeOfMovie()const;
	virtual string getMajorActor() const;
	virtual int getReleaseMonth()const;

	 //assignment operator overload
	virtual Movie& operator=(const Movie& rhs);

	//operator overloads as pure virtual to be implemented in subclasses
	virtual bool operator==(const Movie& other) const = 0;
	virtual bool operator!=(const Movie& other)const = 0;
	virtual bool operator>(const Movie& other) const = 0;
	virtual bool operator<(const Movie& other) const = 0;

	//to print out movies
	virtual void display();
protected:

	//movie data
	int stock;
	string director;
	string title;
	int releaseYear;
	char typeOfMovie;
};


