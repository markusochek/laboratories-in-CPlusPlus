#include "WashingMachine.h"
#include <iostream>

using namespace std;

void WashingMachine::write()
{
	cout << "WashingMachine::write() of ";
	Household::write();
	cout << " weight:" << this->weight << " power:" << this->power << endl;
}
WashingMachine::WashingMachine(int number, int price, int weight, int power) : Household(number, price)
{
	this->weight = weight;
	this->power = power;
}
WashingMachine::WashingMachine()
{
}
WashingMachine::~WashingMachine()
{
}