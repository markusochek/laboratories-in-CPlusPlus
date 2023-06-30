#include "Car.h"

Car::Car(int num, string model, string mark, double relDate)
{
	this->num = num;
	this->model = model;
	this->mark = mark;
	this->relDate = relDate;
}

Car::Car(Car& car)
{
	this->num = car.num;
	this->model = car.model;
	this->mark = car.mark;
	this->relDate = car.relDate;
}

Car::Car()
{
	this->num = 0;
	this->model = "";
	this->mark = "";
	this->relDate = 0;
}

Car::~Car()
{
}

int Car::getNum()
{
	return num;
}

string Car::getModel()
{
	return model;
}

string Car::getMark()
{
	return mark;
}

double Car::getRelDate()
{
	return relDate;
}

ostream& operator<<(ostream& cout, Car& car)
{
	return cout << car.num << "\n" << car.model << " "
			<< car.mark << "\n" << car.relDate << endl;
}