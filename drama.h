#pragma once
#include "movie.h"

using namespace std;

class Drama : public Movie
{
	//constructor and destructor
	Drama(int stock, string director, string title, int releaseYear);
	Drama(const Drama& theMovie);
	~Drama();

	//operator overloads
	bool operator==(const Drama& compared) const;
	bool operator!=(const Drama& compared)const;
	bool operator>(const Drama& compared) const;
	bool operator<(const Drama& compared) const;

	//assignment operator
	Drama operator=(const Drama& theMovie);
};

