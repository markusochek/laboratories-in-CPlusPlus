#include "Person.h"

//int accountNumber;
//string surName;
//int accountBalance;

Person::Person(int accountNumber, string surName, int accountBalance)
{
	this->accountNumber = accountNumber;
	this->surName = surName;
	this->accountBalance = accountBalance;
}

Person::Person(Person& person)
{
	this->accountNumber = person.accountNumber;
	this->surName = person.surName;
	this->accountBalance = person.accountBalance;
}

Person::Person()
{
	this->accountNumber = 0;
	this->surName = "";
	this->accountBalance = 0;
}

Person::~Person()
{
}

int Person::getAccountNumber()
{
	return accountNumber;
}

string Person::getSurName()
{
	return surName;
}

int Person::getAccountBalance()
{
	return accountBalance;
}

ostream& operator<<(ostream& cout, Person& person)
{
	return cout << setw(12) << person.accountNumber
		<< setw(12) << person.surName
		<< setw(10) << person.accountBalance;
}


