#include "PersonSBTree.h"

PersonSBTree::PersonSBTree()
{
	root = nullptr;
}

PersonSBTree::~PersonSBTree()
{
	clear();
}

bool PersonSBTree::insert(Person& person)
{
	return insertPerson(root, person);
}

bool PersonSBTree::insertPerson(PersonNode*& root, Person& person)
{
	if (root == nullptr)
	{
		root = new PersonNode(person, nullptr, nullptr);
		return true;
	}
	else
	{
		if (person.getAccountNumber() < root->person.getAccountNumber())
			return insertPerson(root->left, person);
		else
			if (person.getAccountNumber() > root->person.getAccountNumber())
				return insertPerson(root->right, person);
			else
				return false;
	}
}



bool PersonSBTree::search(int keyAccountNumber, Person& person)
{
	return searchPerson(root, keyAccountNumber, person);
}

bool PersonSBTree::searchSumSurName(string keySurName, Person persons[5], int& i, int& sum)
{
	return searchPersonSurName(root, keySurName, persons,  i,  sum);
}

bool PersonSBTree::searchPersonSurName(PersonNode*& root, string keySurName, Person persons[5], int& i, int& sum)
{
	if (root != nullptr)
	{
		searchPersonSurName(root->left, keySurName, persons, i, sum);
		searchPersonSurName(root->right, keySurName, persons, i, sum);
		if (root->person.getSurName() == keySurName)
		{

			{
				persons[i] = root->person;
				i++;
				sum += root->person.getAccountBalance();
				return true;
			}
		}
		else 
			return false;
	}
	else
		return false;
}

bool PersonSBTree::searchPerson(PersonNode*& root, int keyAccountNumber, Person& person)
{
	if (root != nullptr)
	{
		if (root->person.getAccountNumber() == keyAccountNumber)
		{
			person = root->person;
			return true;
		}
		else
			if (keyAccountNumber < root->person.getAccountNumber())
				return searchPerson(root->left, keyAccountNumber, person);
			else
				return searchPerson(root->right, keyAccountNumber, person);
	}
	else
		return false;
}

ostream& operator<<(ostream& cout, PersonSBTree& personSBTree)
{
	cout << "--------------------------------------------" << endl;
	return 	personSBTree.print(cout, personSBTree.root)
		<< "--------------------------------------------" << endl;

}

bool PersonSBTree::erase(int keyAccountNumber)
{
	return erasePerson(root, keyAccountNumber);
}

bool PersonSBTree::erasePerson(PersonNode*& root, int keyAccountNumber)
{
	//void DeleteNode(TreeNode * &p, int k)
	{
		PersonNode* delnode;

		if (root == nullptr)
			return false;
		else
		{
			if (keyAccountNumber < root->person.getAccountNumber())
				return erasePerson(root->left, keyAccountNumber);
			else
				if (keyAccountNumber > root->person.getAccountNumber())
					return erasePerson(root->right, keyAccountNumber);
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

void  PersonSBTree::del(PersonNode*& r, PersonNode*& delnode)
{
	if (r->right)
		del(r->right, delnode);
	else
	{
		delnode->person = r->person;
		delnode = r;
		r = r->left;
	}
	return;
}

void PersonSBTree::clear()
{
	clearSBTree(root);
	root = nullptr;
	return;
}

void PersonSBTree::clearSBTree(PersonNode* root)
{
	if (root != nullptr)
	{
		clearSBTree(root->left);
		clearSBTree(root->right);
		delete root;
	}
	return;
}


ostream& PersonSBTree::print(ostream& cout, PersonNode* root)
{
	if (root)
	{
		print(cout, root->left);
		cout << root->person << endl;
		print(cout, root->right);
	}
	return cout;
}
