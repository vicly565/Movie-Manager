#include "transactionFactory.h"

Transaction* transactionFactory::make_Transaction(istream& inStream)
{
	//string values to read in from get line. doesnt need title, director and major actor since they are already string value
	string readTransactionType;
	string readCustomerID;
	string readMediaType;
	string readMovieType;
	string readReleaseMonth;
	string readReleaseYear;


	//converted data from get line
	char transactionType;
	int customerID;
	char mediaType;
	char movieType;

	string title;
	string director;
	int releaseMonth;//need this for classic movies
	int releaseYear;
	string majorActor;

	Transaction* insTransaction;


	getline(inStream, readTransactionType, ' ');
	transactionType = readTransactionType.at(0);
	cout << readTransactionType << endl;

	switch (transactionType) {
	//makes Borrow if the transaction type is B
	case 'B':
		insTransaction = new Borrow(transactionType);
		getline(inStream, readCustomerID, ' ');
		customerID = stoi(readCustomerID);
		//checks for correct customer id
		if (customerID < 1000 || customerID > 9999) {
			cerr << "Invalid Customer ID: " << customerID << endl;
			return nullptr;
			break;
		}

		insTransaction->setCustomerID(customerID);

		//read in media type
		getline(inStream, readMediaType, ' ');
		mediaType = readMediaType.at(0);

		//checks for correct media type
		if (mediaType != 'D') {
			cerr << "Invalid Media type " << mediaType << endl;
			return nullptr;
			break;
		}

		insTransaction->setMediaType(mediaType);

		//read in movie type
		getline(inStream, readMovieType, ' ');
		movieType = readMovieType.at(0);

		switch (movieType) {
		//checks for comedy movie type
		case 'F':
			//read in title
			getline(inStream, title, ',');
			insTransaction->setTitle(title);
			inStream.ignore();
			//read in realease year
			getline(inStream, readReleaseYear, ' ');
			releaseYear = stoi(readReleaseYear);
			insTransaction->setReleaseYear(releaseYear);
			break;

		//checks for drama movie type
		case 'D':
			//read in director
			getline(inStream, director, ',');
			insTransaction->setDirector(director);
			//read in title
			getline(inStream, title, ',');
			insTransaction->setTitle(title);
			break;

		//checks for classic movie type
		case 'C':
			getline(inStream, readReleaseMonth, ' ');
			releaseMonth = stoi(readReleaseMonth);
			insTransaction->setReleaseMonth(releaseMonth);
			
			getline(inStream, readReleaseYear, ' ');
			releaseYear = stoi(readReleaseYear);
			insTransaction->setReleaseYear(releaseYear);
			
			getline(inStream, majorActor);
			insTransaction->setMajorActor(majorActor);
			break;

		default:

			cerr << "Invlaid Movie Type: " << movieType << endl;
			return nullptr;
			break;

		}
		break;

	//makes Return if the transaction type is R, same implementation as borrow but made as a return
	case 'R':
		insTransaction = new Return(transactionType);
		getline(inStream, readCustomerID, ' ');
		customerID = stoi(readCustomerID);
		//checks for correct customer id
		if (customerID < 1000 || customerID > 9999) {
			cerr << "Invalid Customer ID: " << customerID << endl;
			return nullptr;
			break;
		}

		insTransaction->setCustomerID(customerID);

		getline(inStream, readMediaType, ' ');
		mediaType = readMediaType.at(0);

		//checks for correct media type
		if (mediaType != 'D') {
			cerr << "Invalid Media type " << mediaType << endl;
			return nullptr;
			break;
		}

		insTransaction->setMediaType(mediaType);

		getline(inStream, readMovieType, ' ');
		movieType = readMovieType.at(0);

		switch (movieType) {
			//checks for comedy movie type
		case 'F':
			getline(inStream, title, ',');
			insTransaction->setTitle(title);
			inStream.ignore();
			getline(inStream, readReleaseYear, ' ');
			releaseYear = stoi(readReleaseYear);
			insTransaction->setReleaseYear(releaseYear);
			break;

			//checks for drama movie type
		case 'D':
			getline(inStream, director, ',');
			insTransaction->setDirector(director);
			getline(inStream, title, ',');
			insTransaction->setTitle(title);
			break;

			//checks for classic movie type
		case 'C':
			getline(inStream, readReleaseMonth, ' ');
			releaseMonth = stoi(readReleaseMonth);
			insTransaction->setReleaseMonth(releaseMonth);

			getline(inStream, readReleaseYear, ' ');
			releaseYear = stoi(readReleaseYear);
			insTransaction->setReleaseYear(releaseYear);

			getline(inStream, majorActor);
			insTransaction->setMajorActor(majorActor);
			break;

		default:

			cerr << "Invlaid Movie Type: " << movieType << endl;
			return nullptr;
			break;

		}
		break;

	//makes inventory which is just "I" as the transaction type
	case 'I':
		insTransaction = new Inventory(transactionType);
		break;

	//makes History if the transaction type is H
	case 'H':		
		cout << "penis";
		insTransaction = new History(transactionType);
		getline(inStream, readCustomerID, ' ');
		customerID = stoi(readCustomerID);
		//checks for correct customer id
		if (customerID < 1000 || customerID > 9999) {
			cerr << "Invalid Customer ID: " << customerID << endl;
			return nullptr;
			break;
		}

		insTransaction->setCustomerID(customerID);
		break;

	//default for an invalid transaction type
	default:

		cerr << "Invalid Transaction type: " << transactionType << endl;
		return nullptr;
		break;

	}

	return insTransaction;
}
