/*******************************************************************
���������� �� ����������� �������� ������������� �������� ������������ ��������� 
������� ������: ��������������� ����� ���������� (�������� � ����������� ����),
������, �����, ��� � ����� ������� ����������. ��������� �������� ������ ������,
������ �������� �������� ��������. ����������:
�) ����� ���������� �� ���������;
�) ����� ����������� �� ���� ������� (����� ���� ��� � ��...�);
�) ����� ���� ����������� ������������ �����;
�) ������ ����� ������ �����������, ������������� �� ����������;
�) �������� ���������� �� ���������� �� ���������;
�) ���������� ������� ��������� ������ ������, ������ �������� �������� ������, �
������ ������ �����������, �������������� �� �������.
����: ������� �.�. ��-21
����: 02.11.2020
********************************************************************/

#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>

#include "Car.h"
#include "CarSBTree.h"

using namespace std;

int main()
{
	// ����������� �� ���������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Car a(39673, "Lada", "Calina", 2000.11);
	Car b(20587, "Porsche", "Macan", 2014.9);
	Car c(19534, "Skoda", "Octavia", 2014.3);
	Car d(95873, "Lada", "Priora", 1995.5);

	CarSBTree data;
	data.insertNum(a);
	data.insertNum(b);
	data.insertNum(c);
	data.insertNum(d);
	data.insertNum(*new Car(90213, "Niva", "Chevrolet", 1994.5));

	Car q;

	cout << "--������ ������ �����������:" << "\n" << data;

	int key = 39673;
	cout << "--����� �� ��� ������ " << key << endl;
	if (data.searchNum(key, q))
		cout << q << endl;
	else
		cout << "--����� �� ������" << endl;

	double key1 = 2010;
	double key2 = 2020;
	cout << "--����� �� ����, � " << key1 << " �� " << key2 << endl;
	data.searchDate(2010, 2020);

	string key3 = "Macan";
	cout << "--����� ����� " << key3 << endl;
	data.searchMark(key3);

	key = 95873;
	if (data.erase(key))
	{
		cout << "--�������� ������ � " << key << endl << "�������� ������: " << endl << data;
	}

	CarSBTree data1;
	Car z(94738, "Kia", "Rio", 2000.1);
	Car w(90598, "Toyota", "Qwe", 2010.5);
	Car e(32858, "Nissan", "Uew", 2015.7);
	Car r(99248, "Nissan", "Mfa", 2013.5);

	data1.insertModel(z);
	data1.insertModel(w);
	data1.insertModel(e);
	data1.insertModel(r);
	data1.insertModel(*new Car(97832, "Porshe", "Una", 2010.12));

	cout << "--����� ������ �����������, ��������������� �� ������: \n" << data1;

	data.clear();
	system("pause");
	return 0;
}