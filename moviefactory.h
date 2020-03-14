#pragma once
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include <string>

using namespace std;

class MovieFactory
{
public:
	static Movie* MakeMovie(istream& inStream);
};

