#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Car
{
private:
	int num;
	string model;
	string mark;
	double relDate;
public:
	Car(int num, string model, string mark, double relDate);
	Car(Car & car);
	Car();
	~Car();

	int getNum();
	string getModel();
	string getMark();
	double getRelDate();

	friend ostream& operator<<(ostream & cout, Car & car);
};

