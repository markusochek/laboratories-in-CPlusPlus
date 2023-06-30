#include "PowerConsumption.h"
#include <iostream>

using namespace std;

void PowerConsumption::write()
{
	cout << " powerconsumption:" << this->powerconsumption << " ";
}

PowerConsumption::PowerConsumption(int powerconsumption)
{
	this->powerconsumption = powerconsumption;
}
PowerConsumption::PowerConsumption()
{
}
PowerConsumption::~PowerConsumption()
{
}