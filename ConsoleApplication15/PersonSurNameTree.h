#pragma once
#include "Person.h"

class PersonSurNameTree
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
	PersonSurNameTree();
	~PersonSurNameTree();

	// ������� � ������ ����� �������, ������ ������� ������� �� ������� person
	// ���������� true � ������ ������� �������, � false, ���� ������ � ����� ������ � ������ ��� ����	
	bool insert(Person& person);

	// ����������� ������� ������� � ������ � ������ root ����� ������� 
	bool insertPerson(PersonNode*& root, Person& person);

	// ����� � ������ ������� �� ����� keyAccountNumber
	// ���������� 
	//   true � ������ ��������� ������, ��� ���� ����� �������� person ���������� ��������� ������;
	//   false, ���� ������� � ����� ������ � ������ �����������.	
	bool  search(string keySurName, Person& person);
	//bool  searchSurName( string keySurName, Person& person);
	//bool  searchSurNameKey(int keyAccountNumber, string keySurName, Person& person);

	// ����������� ������� ������ � ������ � ������ root ������� � ������ keyAccountNumber
	bool  searchPerson(PersonNode*& root, string keySurName, Person& person);
	//bool  searchPersonSurName(PersonNode*& root,int keyAccountNumber, string keySurName, Person& person);

	// �������� � ������ ������� �� ����� keyAccountNumber
	// ���������� 
	//   true � ������ ��������� �������� �������;
	//   false, ���� ������� ������ � ����� ������ � ������ �����������.	
	bool  erase(string keySurName);

	// ����������� ������� ������ � �������� � ������ � ������ root ������� � ������ keyAccountNumber
	bool  erasePerson(PersonNode*& root, string keySurName);

	// ��������������� ������� �������� ������� �� ���. 
	//����������� � ������ �������� ������� � ����� ������������
	void  del(PersonNode*& r, PersonNode*& delnode);

	// ������� ��������� ������ 
	void clear();

	// ����������� ������� ������� ������ � ������ root
	void clearSBTree(PersonNode* root);

	friend ostream& operator<<(ostream& cout, PersonSurNameTree& PersonSurNameTree);

	ostream& print(ostream& cout, PersonNode* root);
};


