/*
PersonSBTree - ������� �������� �������� ������ Person.
�������� ����������� � ��������� ��������� ������ ������ (Search Binary Tree)
��� ��������� ������������������.
����������� �������� �������, ������ � �������� ��������-������ � �������� ������.
*/
#pragma once
#include "Person.h"
#include <vector>

class PersonSBTree
{
private:
	struct PersonNode {
		Person person;
		PersonNode* left, * right;
		PersonNode(Person person, PersonNode* left, PersonNode* right) 
		{
			this->person = person;
			this->left = left;
			this->right = right;
		}
		PersonNode() 
		{
			this->person = person;
			this->left = nullptr;
			this->right = nullptr;
		}
	};

	PersonNode* root; // ������ ��������� ������ ������

public:
	PersonSBTree();
	~PersonSBTree();

	// ������� � ������ ����� �������, ������ ������� ������� �� ������� person
	// ���������� true � ������ ������� �������, � false, ���� ������ � ����� ������ � ������ ��� ����	
	bool insert(Person& person);

	// ����������� ������� ������� � ������ � ������ root ����� ������� 
	bool insertPerson(PersonNode*& root, Person& person);

	// ����� � ������ ������� �� ����� keyAccountNumber
	// ���������� 
	//   true � ������ ��������� ������, ��� ���� ����� �������� person ���������� ��������� ������;
	//   false, ���� ������� � ����� ������ � ������ �����������.	
	bool search(int keyAccountNumber, Person& person);
	bool searchSumSurName(string keySurName, Person persons[5], int& i, int& sum);
	//bool  searchSurName( string keySurName, Person& person);
	//bool  searchSurNameKey(int keyAccountNumber, string keySurName, Person& person);

	// ����������� ������� ������ � ������ � ������ root ������� � ������ keyAccountNumber
	bool  searchPerson(PersonNode*& root, int keyAccountNumber, Person& person);
	bool  searchPersonSurName(PersonNode*& root, string keySurName, Person persons[5], int& i, int& sum);

	// �������� � ������ ������� �� ����� keyAccountNumber
	// ���������� 
	//   true � ������ ��������� �������� �������;
	//   false, ���� ������� ������ � ����� ������ � ������ �����������.	
	bool  erase(int keyAccountNumber);

	// ����������� ������� ������ � �������� � ������ � ������ root ������� � ������ keyAccountNumber
	bool  erasePerson(PersonNode*& root, int keyAccountNumber);

	// ��������������� ������� �������� ������� �� ���. 
	//����������� � ������ �������� ������� � ����� ������������
	void  del(PersonNode*& r, PersonNode*& delnode);

	// ������� ��������� ������ 
	void clear();

	// ����������� ������� ������� ������ � ������ root
	void clearSBTree(PersonNode* root);

	friend ostream& operator<<(ostream& cout, PersonSBTree& personSBTree);

	ostream& print(ostream& cout, PersonNode* root);
};

