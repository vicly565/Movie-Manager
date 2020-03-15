// ------------------------------------------------ moviefactoy.cpp -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file contains a factory method to create movies of different types
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

#include "moviefactory.h"

// ------------------------------------MakeMovie----------------------------------------------- 
// Description
// MakeMovie(istream& inStream): reads in a line of text and creates a movie object based on the
// first character in that line of text
// preconditions: none
//
// postconditions: a pointer to the movie that is created is returned
//
// assumptions: This method assumes that the user will enter C for classic, F for comedy
// and D for drama. Any other charcter is considered an invalid movie type.
// This method assumes that the movies are formatted correctly to what was given in the program
// specifications
//
// --------------------------------------------------------------------------------------------
Movie* MovieFactory::MakeMovie(istream& inStream)
{
	//movie data we need to read in as a string
	//since we're using getline to read in
	string type;
	string stock;
	string director;
	string title;
	string releaseYear;

	//string we use to throw away a line of bad data
	string toss;

	//because get line only reads strings we need to
	//change the types from string to int or string to char
	char movietype;
	int stockNum;
	int yearNum;

	//movie we will be returning
	Movie* theMov;

	//switch statement doesnt allow
	//declaration of string within it
	//so we must declare these outside of the switch for classic
	string majorActorFirstName;
	string majorActorLastName;
	string month;
	int monthNum;

	//for everything we read up until the comma
	//then we need to ignore the space that comes after the comma
	getline(inStream, type,  ',');
	inStream.ignore();
	getline(inStream, stock, ',');
	inStream.ignore();
	getline(inStream, director, ',');
	inStream.ignore();
	getline(inStream, title, ',');
	inStream.ignore();

	//if there is a blank line in the code
	//we need to return null
	if (type == "") {
		return nullptr;
	}

	//cast the stock number and the movie type since we have raed thos in
	movietype = type.at(0);
	stockNum = stoi(stock);


	switch (movietype) {
	case 'F':
		theMov = new Comedy(movietype);

		//get the year turn it into an int and set the movie's year
		getline(inStream, releaseYear);
		yearNum = stoi(releaseYear);
		theMov->setReleaseYear(yearNum);

		break;

	case 'D':

		theMov = new Drama(movietype);

		//get the year turn it into an int and set the movie's year
		getline(inStream, releaseYear);
		yearNum = stoi(releaseYear);
		theMov->setReleaseYear(yearNum);

		break;

	case 'C':

		theMov = new Classic(movietype);

		//for classic we need to read until the space for every character
		//as no more commas exist here
		getline(inStream, majorActorFirstName, ' ');
		getline(inStream, majorActorLastName, ' ');
		getline(inStream, month, ' ');
		getline(inStream, releaseYear);

		//concatonate the actor's name
		theMov->setMajorActor((majorActorFirstName + " " + majorActorLastName));

		//case then set the month and year
		monthNum = stoi(month);
		yearNum = stoi(releaseYear);
		theMov->setReleaseMonth(monthNum);
		theMov->setReleaseYear(yearNum);
		break;

	default:

		cerr << "Invalid Movie Type: " << movietype << ", ";
		cout << "Can't create " << title << endl;
		//read the rest of the line to toss out the bad data
		getline(inStream, toss);
		return nullptr;
		break;

	}
	//set the general data that all movies ahve
	theMov->setStock(stockNum);
	theMov->setDirector(director);
	theMov->setTitle(title);

	return theMov;
}
