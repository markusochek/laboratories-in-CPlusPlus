#include "VacuumCleaner.h"
#include <iostream>

using namespace std;

void VacuumCleaner::write()
{
	cout << "VacuumCleaner::write() of ";
	Household::write();
	PowerConsumption::write();
	cout <<" type:" << this->type << endl;
}
VacuumCleaner::VacuumCleaner(int number, int price, int powerconsumption, int type) : Household(number, price), PowerConsumption(powerconsumption)
{
	this->type = type;
}
VacuumCleaner::VacuumCleaner()
{
}
VacuumCleaner::~VacuumCleaner()
{
}