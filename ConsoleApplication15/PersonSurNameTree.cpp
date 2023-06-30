#include "PersonSurNameTree.h"

PersonSurNameTree::PersonSurNameTree()
{
	root = nullptr;
}

PersonSurNameTree::~PersonSurNameTree()
{
	clear();
}

bool PersonSurNameTree::insert(Person& person)
{
	return insertPerson(root, person);
}

bool PersonSurNameTree::insertPerson(PersonNode*& root, Person& person)
{
	if (root == nullptr)
	{
		root = new PersonNode(person, nullptr, nullptr);
		return true;
	}
	else
	{
		if (person.getSurName() <= root->person.getSurName())
			return insertPerson(root->left, person);
		else
			if (person.getSurName() > root->person.getSurName())
				return insertPerson(root->right, person);
	}
}

bool PersonSurNameTree::search(string keySurName, Person& person)
{
	return searchPerson(root, keySurName, person);
}

bool PersonSurNameTree::searchPerson(PersonNode*& root, string keySurName, Person& person)
{
	if (root != nullptr)
	{
		if (root->person.getSurName() == keySurName)
		{
			person = root->person;
			return true;
		}
		else
			if (keySurName < root->person.getSurName())
				return searchPerson(root->left, keySurName, person);
			else
				return searchPerson(root->right, keySurName, person);
	}
	else
		return false;
}

ostream& operator<<(ostream& cout, PersonSurNameTree& PersonSurNameTree)
{
	cout << "--------------------------------------------" << endl;
	return 	PersonSurNameTree.print(cout, PersonSurNameTree.root)
		<< "--------------------------------------------" << endl;

}

bool PersonSurNameTree::erase(string keySurName)
{
	return erasePerson(root, keySurName);
}

bool PersonSurNameTree::erasePerson(PersonNode*& root, string keySurName)
{
	{
		PersonNode* delnode;

		if (root == nullptr)
			return false;
		else
		{
			if (keySurName < root->person.getSurName())
				return erasePerson(root->left, keySurName);
			else
				if (keySurName > root->person.getSurName())
					return erasePerson(root->right, keySurName);
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

void  PersonSurNameTree::del(PersonNode*& r, PersonNode*& delnode)
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

void PersonSurNameTree::clear()
{
	clearSBTree(root);
	root = nullptr;
	return;
}

void PersonSurNameTree::clearSBTree(PersonNode* root)
{
	if (root != nullptr)
	{
		clearSBTree(root->left);
		clearSBTree(root->right);
		delete root;
	}
	return;
}


ostream& PersonSurNameTree::print(ostream& cout, PersonNode* root)
{
	if (root)
	{
		print(cout, root->left);
		cout << root->person << endl;
		print(cout, root->right);
	}
	return cout;
}
