/*******************************************************************
��������� ������ ��������� ������:
���������� �������, ��������� � ������������� ���������� � ��������.
�� ������ ������� ������� ��������� ������: �������, ���, ���, ����� ��������.
�������� ����������� � �������� ������ ������ ("���� ������") � ������ ���.
����: �. �. ��������
����: 02.11.2020
********************************************************************/

#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>

#include "Person.h"
#include "PersonSBTree.h"

using namespace std;

int main()
{
	// ����������� �� ���������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	// ------ ������������ ���� ������ (�������� ������ ������) � ��������
	PersonSBTree dataBase;

	// ������� � ���� ������ ��������, ��������� ��� ���������
	Person p1("���������", "���", 2000, "44-44-44");
	dataBase.insert(p1);
	Person p2("Ը���", "����", 1000, "55-55-55");
	dataBase.insert(p2);
	
	// ������� � ���� ������ ��������, ��������� � ������������ ������
	dataBase.insert(*new Person("������", "���������", 4000, "66-66-66"));
	dataBase.insert(*new Person("�����", "���", 3000, "77-77-77"));

	dataBase.insert(*new Person("�������", "�������", 2500, "11-11-11"));
	dataBase.insert(*new Person("��������", "��������", 3500, "22-22-22"));


	cout << "���� ������:" << endl;
	cout << dataBase << endl;

	// ------ ����� � ���� ������ �� �����
	int key = 3500; // 1500
	if (dataBase.search(key, p1)) {
		cout << "����� ������� � ��� = " << key << " �������:" << endl;
		cout << p1 << endl << endl;
	}
	else
		cout << "����� ������� � ��� = " << key << " �� �������." << endl << endl;


	// ------ �������� ������� �� ���� ������ �� �����
	key = 3500; // 1500
	if (dataBase.erase(key)) {
		cout << "������� � ��� = " << key << " �������:" << endl;		
		cout << "���� ������:" << endl;
		cout << dataBase;
	}
	else
		cout << "��������� ������� � ��� = " << key << " �� ����������." << endl;

	dataBase.clear();

	system("pause");
	return 0;
}