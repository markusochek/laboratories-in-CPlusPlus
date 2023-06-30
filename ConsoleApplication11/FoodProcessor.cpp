#include "FoodProcessor.h"
#include <iostream>

using namespace std;

void FoodProcessor::write()
{
	cout << "FoodProcessor::write() of ";
	Household::write();
	PowerConsumption::write();
	cout << " nozzles:" << this->nozzles << endl;
	
}
FoodProcessor::FoodProcessor(int number, int price, int powerconsumption, int nozzles) : Household(number, price), PowerConsumption(powerconsumption)
{
	this->nozzles = nozzles;
}
FoodProcessor::FoodProcessor()
{
}
FoodProcessor::~FoodProcessor()
{
}
