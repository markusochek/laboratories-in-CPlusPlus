//5.21 Пусть дан некоторый список, назовём его основным.
// Индексом по ключу называется список адресов элементов основного списка, 
// выстроенный таким образом,
//  что эти адреса расположены в порядке не убыванию значений ключевого поля основного списка.
// Дан основной список cотрудников(Фамилия, Рост, IQ).
// Построить индекс по ключу "Рост" и индекс по ключу "IQ".
//	Вывести основной список по каждому из индексов.

#include "Employee.h"

using namespace std;

int main()
{
	list<Employee> List;
	Employee a;

	cout << "List:" << endl;
	a.addEmployee(List);
	cout << setw(10) << "fio" << setw(8) << "height" << setw(5) << "IQ" << endl;
	cout << List << endl;

	cout << "ListId:" << endl;
	list<Employee*> ListId;
	a.addEmployeeId(List, ListId);

	cout << setw(10) << "fio" << setw(8) << "height" << setw(5) << "IQ" << endl;
	cout << ListId << endl;

	cout << "List:" << endl;
	a.sortEmployeeHeight(List);
	cout << setw(10) << "fio" << setw(8) << "height" << setw(5) << "IQ" << endl;
	cout << List << endl;

	a.sortEmployeeIQ(List);
	cout << setw(10) << "fio" << setw(8) << "height" << setw(5) << "IQ" << endl;
	cout << List << endl;

	system("pause");
}