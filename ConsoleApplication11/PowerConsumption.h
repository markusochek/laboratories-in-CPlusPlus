#pragma once
class PowerConsumption
{
protected:
	int powerconsumption;
public:
	virtual void write() = 0;
	PowerConsumption(int powerconsumption);
	PowerConsumption();
	~PowerConsumption();
};