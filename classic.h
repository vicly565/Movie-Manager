#pragma once
#include "movie.h"

using namespace std;

class Classic : public Movie
{
public:
	//constructor and destructor
	Classic(int stock, string director, string title, string majorActor, int releaseMonth, int releaseYear);
	~Classic();

	//setters
	void setMajorActor(string actor);
	void setReleaseMonth(int month);

	//getters
	string getMajorActor() const;
	int getReleaseMonth()const;

	//operator overloads
	bool operator==(const Classic& compared) const;
	bool operator!=(const Classic& compared)const;
	bool operator>(const Classic& compared) const;
	bool operator<(const Classic& compared) const;

private:
	string majorActor;
	int releaseMonth;

};

