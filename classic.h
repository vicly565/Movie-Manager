#pragma once
#include "movie.h"

using namespace std;

class Classic : public Movie
{
public:
	//constructor and destructor
	Classic(char type);
	~Classic();

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

