#pragma once
#include "Household.h"
#include "PowerConsumption.h"
class FoodProcessor : public Household, public PowerConsumption
{
private:
	int nozzles;
public:
	virtual void write();
	FoodProcessor(int number, int price, int powerConsumption, int nozzles);
	FoodProcessor();
	~FoodProcessor();
};