/*
Person - класс информационных объектов, каждый из которых хранит данные о персоне
*/
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{
private:
	string surName;
	string name;
	int inn;
	string phone;
public:
	Person(string surName, string name, int inn, string phone);
	Person(Person & person);
	Person();
	~Person();

	string getSurName();
	string getName();
	int getInn();
	string getPhone();

	friend ostream & operator<<(ostream & cout, Person & person);
};

