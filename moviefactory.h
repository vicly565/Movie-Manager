// ------------------------------------------------ moviefactory.h -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This header file contains a factory method to create movies of different types
// -------------------------------------------------------------------------------------------------------------------- 
// 
// Specifications: Each movie type is identified by C for classic, F for comedy, or D for drama
// 
// The movie factory has these PUBLIC FUNCTIONS:
//								static Movie* MakeMovie(istream& inStream);
//
// Assumptions: This factory method assumes the data within the text file is formatted correctly
// 
// --------------------------------------------------------------------------------------------------------------------
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

