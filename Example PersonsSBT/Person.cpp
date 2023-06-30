#include "Person.h"

Person::Person(string surName, string name, int inn, string phone)
{
	this->surName = surName;
	this->name = name;
	this->inn = inn;
	this->phone = phone;
}

Person::Person(Person & person)
{
	this->surName = person.surName;
	this->name = person.name;
	this->inn = person.inn;
	this->phone = person.phone;
}

Person::Person()
{
	this->surName ="";
	this->name = "";
	this->inn = 0;
	this->phone = "";
}

Person::~Person()
{
}

string Person::getSurName()
{
	return surName;
}

string Person::getName()
{
	return name;
}

int Person::getInn()
{
	return inn;
}

string Person::getPhone()
{
	return phone;
}

ostream & operator<<(ostream & cout, Person & person)
{
	return cout << setw(12) << person.surName
		<< setw(12) << person.name
		<< setw(10) << person.inn
		<< setw(10) << person.phone;
}


