#pragma once
#include "Household.h"
#include "PowerConsumption.h"
class VacuumCleaner : public Household, public PowerConsumption
{
private:
	int type;
public:
	virtual void write();
	VacuumCleaner(int number, int price, int powerconsumption, int type);
	VacuumCleaner();
	~VacuumCleaner();
};

