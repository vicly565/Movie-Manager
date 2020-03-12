#pragma once
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
class MovieFactory
{
public:
	static Movie* make_movie(istream& inStream);
};

