#pragma once

#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Employee
{
private:
	string fio;
	int height;
	int IQ;
public:
	Employee();
	~Employee();
	Employee(string fio, int height, int IQ);
	string getFio();
	int getHeight();
	int getIQ();
	int setIQ(int IQ);
	void addEmployee(list <Employee>& List);
	void addEmployeeId(list <Employee>& List, list <Employee*>& ListId);
	void sortEmployeeIQ(list <Employee>& List);
	void sortEmployeeHeight(list <Employee>& List);
	friend bool comparatorHeight(Employee& obj1, Employee& obj2);
	friend bool comparatorIQ(Employee& obj1, Employee& obj2);
	friend ostream& operator << (ostream& cout, const list<Employee>& l);
	friend ostream& operator << (ostream& cout, const list<Employee*>& l);
};
