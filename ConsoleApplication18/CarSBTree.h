#pragma once
#include "Car.h"

class CarSBTree
{
private:
	struct CarNode
	{
		Car car;
		CarNode* left, * right;
		CarNode(Car car, CarNode* left, CarNode* right)
		{
			this->car = car;
			this->left = left;
			this->right = right;
		}
		CarNode()
		{
			this->car = car;
			this->left = nullptr;
			this->right = nullptr;
		}
	};

	CarNode* root;

	//struct CarNodeModel
	//{
	//	Car car;
	//	CarNodeModel* left, * right;
	//	CarNodeModel(Car car, CarNodeModel* left, CarNodeModel* right)
	//	{
	//		this->car = car;
	//		this->left = left;
	//		this->right = right;
	//	}
	//	CarNodeModel()
	//	{
	//		this->car = car;
	//		this->left = nullptr;
	//		this->right = nullptr;
	//	}
	//};

	//CarNodeModel* rootM;

public:
	CarSBTree();
	~CarSBTree();
	//������� � ������ ��� �����
	bool insertNum(Car& car);
	bool insertNumR(CarNode * & root, Car & car);
	//����� �� ��� ������
	bool searchNum(int key, Car & car);
	bool searchNumR(CarNode*& root, int key, Car & car);
	//����� �� ���� �������
	void searchDate(double key1, double key2);
	void searchDateR(CarNode*& root, double key1, double key2);
	//����� ���� ���� ����� �����
	void searchMark(string key);
	void searchMarkR(CarNode * & root, string key);
	//������������� ����� ������ 
	friend ostream& operator<<(ostream& cout, CarSBTree & carSBTree);
	ostream& print(ostream & cout, CarNode * root);
	//
	bool erase(int key);
	bool eraseCar(CarNode * & root, int key);
	void  del(CarNode*& r, CarNode*& delnode);
	//
	void clear();
	void clearSBTree(CarNode* root);
	//������� � ������ ������
	bool insertModel(Car& car);
	bool insertModelR(CarNode*& root, Car& car);
};

