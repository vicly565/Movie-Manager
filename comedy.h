#pragma once
#include "movie.h"

using namespace std;
class Comedy : public Movie
{
	Comedy(int stock, string director, string title, int releaseYear);
	Comedy(const Comedy& theMovie);
	~Comedy();

	//operator overloads
	bool operator==(const Comedy& compared) const;
	bool operator!=(const Comedy& compared)const;
	bool operator>(const Comedy& compared) const;
	bool operator<(const Comedy& compared) const;

	//assignment operator
	Comedy operator=(const Comedy& theMovie);
};

