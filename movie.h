#pragma once
#include <iostream>
using namespace std;
class Movie
{
public:
	//constructor and destructor
	Movie();
	 ~Movie();

	//Getter methods
	virtual void setStock(int stock);
	virtual void setDirector(string director);
	virtual void setTitle(string title);
	virtual void setReleaseYear(int releaseYear);
	virtual void setTypeOfMovie(char c);

	//Setter methods
	virtual int getStock()const;
	virtual string getDirector()const;
	virtual string getTitle()const;
	virtual int getReleaseYear()const;
	virtual char getTypeOfMovie()const;
protected:

	//movie data
	int stock;
	string director;
	string title;
	int releaseYear;
	char typeOfMovie;
};


