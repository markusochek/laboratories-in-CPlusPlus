#include "Employee.h"

using namespace std;

Employee::Employee()
{
	this->fio = "";
	this->height = 0;
	this->IQ = 0;
}

Employee::Employee(string fio, int height, int IQ)
{
	this->fio = fio;
	this->height = height;
	this->IQ = IQ;
}

string Employee::getFio()
{
	return this->fio;
}

int Employee::getHeight()
{
	return this->height;
}

int Employee::getIQ()
{
	return this->IQ;
}

Employee::~Employee()
{
}

bool comparatorHeight(Employee& obj1, Employee& obj2) {
	return obj1.height < obj2.height;
}

bool comparatorIQ(Employee& obj1, Employee& obj2) {
	return obj1.IQ < obj2.IQ;
}

void Employee::sortEmployeeHeight(list <Employee>& List) {
	List.sort(comparatorHeight);
}

void Employee::sortEmployeeIQ(list <Employee>& List) {
	List.sort(comparatorIQ);
}

void Employee::addEmployee(list <Employee>& List) {
	int b = 0;
	int c = 0;
	const int N = 8;
	string fio[N]{ "Sagalaev", "Krotov", "Kurin", "Puskin", "Zubin", "Kotov", "Kuzmin", "Agafonov" };

	for (int i = 0; i < N; i++) {
		b = rand() % 30 + 170;
		c = rand() % 35 + 235;
		List.push_back(*new Employee(fio[i], b, c));
	}
}

void Employee::addEmployeeId(list <Employee>& List, list <Employee*>& ListId) {
	list<Employee>::iterator it = List.begin();
	while (it != List.end())
	{
		Employee* b = &*it;
		ListId.push_back(b);
		++it;
	}
}

ostream& operator << (ostream& cout, const list<Employee>& l)
{
	for (auto x : l)
	{
		cout << setw(10) << x.fio << " | " << setw(4) << x.height << " | " << setw(4) << x.IQ << endl;
	}
	return cout;
}


ostream& operator << (ostream& cout, const list<Employee*>& l)
{
	for (auto x : l)
	{
		cout << setw(10) << x->fio << " | " << setw(4) << x->height << " | " << setw(4) << x->IQ << endl;
	}
	return cout;
}