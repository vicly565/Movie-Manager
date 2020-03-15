#pragma once
#include "movie.h"

using namespace std;
class Comedy : public Movie
{
public:
	Comedy(char type);
	~Comedy();

	//operator overloads
	bool operator==(const Movie& other) const;
	bool operator!=(const Movie& other)const;
	bool operator>(const Movie& other) const;
	bool operator<(const Movie& other) const;

};

