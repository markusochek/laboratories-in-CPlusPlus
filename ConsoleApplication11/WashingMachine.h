#pragma once
#include "Household.h"
class WashingMachine: public Household
{
private:
	int weight;
	int power;
public:
	virtual void write();
	WashingMachine(int number, int price, int weight, int power);
	WashingMachine(); 
	~WashingMachine();
};

