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
	//Вставка с ключем гос номер
	bool insertNum(Car& car);
	bool insertNumR(CarNode * & root, Car & car);
	//Поиск по гос номеру
	bool searchNum(int key, Car & car);
	bool searchNumR(CarNode*& root, int key, Car & car);
	//Поиск по дате выпуска
	void searchDate(double key1, double key2);
	void searchDateR(CarNode*& root, double key1, double key2);
	//Поиск всех авто одной марки
	void searchMark(string key);
	void searchMarkR(CarNode * & root, string key);
	//Упорядоченный вывод списка 
	friend ostream& operator<<(ostream& cout, CarSBTree & carSBTree);
	ostream& print(ostream & cout, CarNode * root);
	//
	bool erase(int key);
	bool eraseCar(CarNode * & root, int key);
	void  del(CarNode*& r, CarNode*& delnode);
	//
	void clear();
	void clearSBTree(CarNode* root);
	//Вставка с ключем модель
	bool insertModel(Car& car);
	bool insertModelR(CarNode*& root, Car& car);
};

