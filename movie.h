#pragma once
#include <iostream>
using namespace std;
class Movie
{
public:

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
	

	//operator overloads as pure virtual
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


