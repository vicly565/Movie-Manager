#include "moviefactory.h"

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
