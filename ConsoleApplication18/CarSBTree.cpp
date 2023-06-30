#include "CarSBTree.h"

CarSBTree::CarSBTree()
{
	root = nullptr;
}

CarSBTree::~CarSBTree()
{
	clear();
}

bool CarSBTree::insertNum(Car& car)
{
	return insertNumR(root, car);
}

bool CarSBTree::insertNumR(CarNode*& root, Car& car)
{
	if (root == nullptr)
	{
		root = new CarNode(car, nullptr, nullptr);
		return true;
	}
	else
	{
		if (car.getNum() < root->car.getNum())
			return insertNumR(root->left, car);
		else
			if (car.getNum() > root->car.getNum())
				return insertNumR(root->right, car);
			else
				return false;
	}
}

bool CarSBTree::searchNum(int key, Car & car)
{
	return searchNumR(root, key, car);
}

bool CarSBTree::searchNumR(CarNode*& root, int key, Car& car)
{
	if (root != nullptr)
	{
		if (root->car.getNum() == key)
		{
			car = root->car;
			return true;
		}
		else
			if (key < root->car.getNum())
				return searchNumR(root->left, key, car);
			else
				return searchNumR(root->right, key, car);
	}
	else
		return false;
}

void CarSBTree::searchDate(double key1, double key2)
{
	return searchDateR(root, key1, key2);
}

void CarSBTree::searchDateR(CarNode*& root, double key1, double key2)
{
	if (root)
	{
		searchDateR(root->left, key1, key2);
		if (root->car.getRelDate() >= key1 && root->car.getRelDate() <= key2)
		{
			cout << root->car << endl;
		}
		searchDateR(root->right, key1, key2);
	}
}

void CarSBTree::searchMark(string key)
{
	return searchMarkR(root, key);
}

void CarSBTree::searchMarkR(CarNode*& root, string key)
{
	if (root)
	{
		searchMarkR(root->left, key);
		if (root->car.getMark() == key)
		{
			cout << root->car << endl;
		}
		searchMarkR(root->right, key);
	}
}

ostream& operator<<(ostream& cout, CarSBTree& car)
{
	cout << "--------------------------------------------" << endl;
	return 	car.print(cout, car.root)
		 << "--------------------------------------------" << endl;

}

ostream& CarSBTree::print(ostream& cout, CarNode* root)
{
	if (root)
	{
		print(cout, root->left);
		cout << root->car << endl;
		print(cout, root->right);
	}
	return cout;
}

bool CarSBTree::erase(int key)
{
	return eraseCar(root, key);
}

bool CarSBTree::eraseCar(CarNode*& root, int key)
{
	{
		CarNode* delnode;

		if (root == nullptr)
			return false;
		else
		{
			if (key < root->car.getNum())
				return eraseCar(root->left, key);
			else
				if (key > root->car.getNum())
					return eraseCar(root->right, key);
				else
				{
					delnode = root;
					if (delnode->right == nullptr)
						root = delnode->left;
					else
						if (delnode->left == nullptr)
							root = delnode->right;
						else
							del(delnode->left, delnode);
					delete delnode;
					return true;
				}
		}
	}
}

void  CarSBTree::del(CarNode*& r, CarNode*& delnode)
{
	if (r->right)
		del(r->right, delnode);
	else
	{
		delnode->car = r->car;
		delnode = r;
		r = r->left;
	}
	return;
}

void CarSBTree::clear()
{
	clearSBTree(root);
	root = nullptr;
	return;
}

void CarSBTree::clearSBTree(CarNode* root)
{
	if (root != nullptr)
	{
		clearSBTree(root->left);
		clearSBTree(root->right);
		delete root;
	}
	return;
}

bool CarSBTree::insertModel(Car& car)
{
	return insertModelR(root, car);
}

bool CarSBTree::insertModelR(CarNode*& root, Car& car)
{
	if (root == nullptr)
	{
		root = new CarNode(car, nullptr, nullptr);
		return true;
	}
	else
	{
		if (car.getModel() < root->car.getModel())
			return insertModelR(root->left, car);
		else
			if (car.getModel() > root->car.getModel())
				return insertModelR(root->right, car);
			else
				return false;
	}
}