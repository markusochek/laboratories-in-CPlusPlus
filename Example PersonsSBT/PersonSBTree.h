/*
PersonSBTree - ������� �������� �������� ������ Person. 
�������� ����������� � ��������� ��������� ������ ������ (Search Binary Tree) 
��� ��������� ������������������.
����������� �������� �������, ������ � �������� ��������-������ � �������� ������.
*/
#pragma once
#include "Person.h"

class PersonSBTree
{
private:
	struct PersonNode {
		Person person;
		PersonNode * left, *right;
		PersonNode(Person person, PersonNode * left, PersonNode * right) {
			this->person = person;
			this->left = left;
			this->right = right;
		}
		PersonNode() {
			this->person = person;
			this->left = nullptr;
			this->right = nullptr;
		}
	};

	PersonNode * root; // ������ ��������� ������ ������

public:
	PersonSBTree();
	~PersonSBTree();

	// ������� � ������ ����� �������, ������ ������� ������� �� ������� person
	// ���������� true � ������ ������� �������, � false, ���� ������ � ����� ������ � ������ ��� ����	
	bool insert(Person & person);

	// ����������� ������� ������� � ������ � ������ root ����� ������� 
	bool insertPerson(PersonNode * &root, Person & person);

	// ����� � ������ ������� �� ����� keyInn 
	// ���������� 
	//   true � ������ ��������� ������, ��� ���� ����� �������� person ���������� ��������� ������;
	//   false, ���� ������� � ����� ������ � ������ �����������.	
	bool  search(int keyInn, Person & person);

	// ����������� ������� ������ � ������ � ������ root ������� � ������ keyInn
	bool  searchPerson(PersonNode * & root, int keyInn, Person & person);

	// �������� � ������ ������� �� ����� keyInn 
	// ���������� 
	//   true � ������ ��������� �������� �������;
	//   false, ���� ������� ������ � ����� ������ � ������ �����������.	
	bool  erase(int keyInn);

	// ����������� ������� ������ � �������� � ������ � ������ root ������� � ������ keyInn
	bool  erasePerson(PersonNode * & root, int keyInn);

	// ��������������� ������� �������� ������� �� ���. 
	//����������� � ������ �������� ������� � ����� ������������
	void  del(PersonNode * & r, PersonNode * &delnode);

	// ������� ��������� ������ 
	void clear();

	// ����������� ������� ������� ������ � ������ root
	void clearSBTree(PersonNode * root);

	friend ostream & operator<<(ostream & cout, PersonSBTree & personSBTree);

	ostream & print(ostream & cout, PersonNode * root);
};

