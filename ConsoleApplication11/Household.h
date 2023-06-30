#pragma once
class Household
{
protected:
	int number;
	int price;
public:
	virtual void write() = 0;
	int getPrice();
	Household(int number, int price);
	Household();
	~Household();
};