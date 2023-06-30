#include "PersonSBTree.h"



PersonSBTree::PersonSBTree()
{
	root = nullptr;
}


PersonSBTree::~PersonSBTree()
{
	clear();
}

bool PersonSBTree::insert(Person & person)
{
	return insertPerson(root, person);
}

bool PersonSBTree::insertPerson(PersonNode * &root, Person & person)
{
	if (root == nullptr)
	{
		root = new PersonNode(person, nullptr, nullptr);
		return true;
	}
	else
	{
		if (person.getInn() < root->person.getInn()) 
			return insertPerson(root->left, person);
		else
			if (person.getInn() > root->person.getInn())
				return insertPerson(root->right, person);
			else
				return false;
	}	
}

bool PersonSBTree::search(int keyInn, Person & person)
{
	return searchPerson(root, keyInn, person);
}

bool PersonSBTree::searchPerson(PersonNode * & root, int keyInn, Person & person)
{
	if (root != nullptr)
	{
		if (root->person.getInn() == keyInn)
		{
			person = root->person;
			return true;
		}
		else
			if (keyInn < root->person.getInn())
				return searchPerson(root->left, keyInn, person);
			else
				return searchPerson(root->right, keyInn, person);
	}
	else
		return false;
}



ostream & operator<<(ostream & cout, PersonSBTree & personSBTree)
{
	cout << "--------------------------------------------" << endl;	
	return 	personSBTree.print(cout, personSBTree.root)
		 << "--------------------------------------------" << endl;
	
}

bool PersonSBTree::erase(int keyInn)
{
	return erasePerson(root, keyInn);
}

bool PersonSBTree::erasePerson(PersonNode *& root, int keyInn)
{
	//void DeleteNode(TreeNode * &p, int k)
	{
		PersonNode * delnode;

		if (root == nullptr)
			return false;
		else
		{
			if (keyInn < root->person.getInn())
				return erasePerson(root->left, keyInn);
			else
				if (keyInn > root->person.getInn())
					return erasePerson(root->right, keyInn);
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

void  PersonSBTree::del(PersonNode * & r, PersonNode * &delnode)
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

void PersonSBTree::clearSBTree(PersonNode * root)
{
	if (root != nullptr)
	{
		clearSBTree(root->left);
		clearSBTree(root->right);
		delete root;
	}
	return;
}


ostream & PersonSBTree::print(ostream & cout, PersonNode * root)
{
	if (root)
	{
		print(cout, root->left);
		cout << root->person << endl;
		print(cout, root->right);
	}
	return cout;
}
