#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "Transaction.h"
using namespace std; 
class Customer
{
public:
	Customer(int id, string lastName, string firstName);
	~Customer();

	bool addTransaction(Transaction t);
	friend ostream& operator<<(ostream& out, const Customer& cust);

	void setId(int custId);
	void setLastName(string lastN);
	void setFirstName(string firstN);

	int getId()const;
	string getLastName()const;
	string getFirstName()const;

private:

	int id;
	string firstName;
	string lastName;
	vector<Transaction> history;
};

