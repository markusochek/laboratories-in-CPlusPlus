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
	int accountNumber;
	string surName;
	int accountBalance;
public:
	Person(int accountNumber, string surName, int accountBalance);
	Person(Person& person);
	Person();
	~Person();

	int getAccountNumber();
	string getSurName();
	int getAccountBalance();

	friend ostream& operator<<(ostream& cout, Person& person);
};


