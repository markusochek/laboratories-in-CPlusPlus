#pragma once
#include <string>
class Building
{
private:
	std::string address;
	int floors;
	int square;
public:
	Building();
	~Building();
	Building(std::string address, int floors, int square); 

	std::string getAddress();
	void setAddress(std::string address);
	int getFloors();
	void setFloors(int floors);
	int getSquare();
	void setSquare(int square);
};


