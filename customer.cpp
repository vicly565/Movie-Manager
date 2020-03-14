#include "customer.h"

Customer::Customer(int id, string lastName, string firstName)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
}

Customer::~Customer()
{
}

//bool Customer::addTransaction(Transaction t)
//{
	//history.push_back(t);
	//return true;
//}

void Customer::setId(int custId)
{
	id = custId;
}

void Customer::setLastName(string lastN)
{
	lastName = lastN;
}

void Customer::setFirstName(string firstN)
{
	firstName = firstN;
}

int Customer::getId() const
{
	return id;
}

string Customer::getLastName() const
{
	return lastName;
}

string Customer::getFirstName() const
{
	return firstName;
}

void Customer::display()
{
	cout << id << " " << lastName << " " << firstName;
}

ostream& operator<<(ostream& out, const Customer& cust)
{
	out << cust.getId() << " " << cust.getLastName() << " " << cust.getFirstName();
	return out;
}
