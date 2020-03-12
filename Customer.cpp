#include "Customer.h"

Customer::Customer(int id, string lastName, string firstName)
{
	id = id;
	firstName = firstName;
	lastName = lastName;
}

Customer::~Customer()
{
}

bool Customer::addTransaction(Transaction t)
{
	history.push_back(t);
	return true;
}

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

ostream& operator<<(ostream& out, const Customer& cust)
{
	out << cust.getId() << " " << cust.getLastName() << " " << cust.getFirstName();
}
