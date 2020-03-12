#include "moviefactory.h"

Movie* MovieFactory::make_movie(istream& inStream)
{
	//movie data
	char movietype;
	int stock;
	string director;
	string title;
	Movie* theMov;

	//in case we need to read in major actor
	//had to move up here since switch statement
	//was not working with this donw there
	string majorActorFirstName;
	string majorActorLastName;

	inStream >> movietype >> stock >> director >> title;

	switch (movietype) {
	case 'F':

		//if movie is a comedy we need to only get year
		theMov = new Comedy(movietype);
		int releaseYear;
		inStream >> releaseYear;
		theMov->setReleaseYear(releaseYear);
		break;

	case 'D':

		//if movie is drama we only need to get year
		theMov = new Drama(movietype);
		int releaseYear;
		inStream >> releaseYear;
		theMov->setReleaseYear(releaseYear);
		break;

	case 'C':

		//if movie is classic we need release month, year, and major actor
		theMov = new Classic(movietype);
		int month;
		int releaseYear;
		inStream >> majorActorFirstName;
		inStream >> majorActorLastName;
		inStream >> month;
		inStream >> releaseYear;
		theMov->setMajorActor((majorActorFirstName + " " + majorActorFirstName));
		theMov->setReleaseMonth(month);
		theMov->setReleaseYear(releaseYear);
		break;

	default:

		cerr << "Invlaid Movie Type: " << movietype << endl;
		return nullptr;
		break;

	}

	theMov->setStock(stock);
	theMov->setDirector(director);
	theMov->setTitle(title);

	return theMov;
}
