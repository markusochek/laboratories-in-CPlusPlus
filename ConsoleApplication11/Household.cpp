#include "Household.h"
#include <iostream>

using namespace std;

void Household::write()
{
	cout << "number:" << this->number << " price:" << this->price;
}
int Household::getPrice()
{
	return this->price;
}
Household::Household(int number, int price)
{
	this->number = number;
	this->price = price;
}
Household::Household()
{
}
Household::~Household()
{
}