#pragma once
#include "movie.h"

using namespace std;

class Drama : public Movie
{
public:
	//constructor and destructor
	Drama(char type);
	~Drama();

	//operator overloads
	bool operator==(const Movie& other) const;
	bool operator!=(const Movie& other)const;
	bool operator>(const Movie& other) const;
	bool operator<(const Movie& other) const;
};

