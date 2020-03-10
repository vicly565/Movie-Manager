#pragma once
#include "movie.h"

using namespace std;
class Comedy : public Movie
{
	Comedy(int stock, string director, string title, int releaseYear);
	~Comedy();

	//operator overloads
	bool operator==(const Comedy& compared) const;
	bool operator!=(const Comedy& compared)const;
	bool operator>(const Comedy& compared) const;
	bool operator<(const Comedy& compared) const;
};

