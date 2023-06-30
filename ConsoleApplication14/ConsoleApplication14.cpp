//3.21 По входной последовательности целых чисел построить бинарное дерево.
//Найти вершины дерева, сумма значений непосредственных потомков которых максимальна.

#include <iostream>
#include <iomanip>
#include <locale.h>
#include <vector>

using namespace std;

struct TreeNode
{
  int info;
  TreeNode* left, *right;
};

// Прототипы функций
TreeNode* makeTree(int a[10], int& i);
void printTree(TreeNode * &root, const int level = 0);
int sumMaxTree(TreeNode * &root, int max);
bool searchMaxTree(TreeNode*& root, int const max, vector <int>& tops);

void main ()
{
	srand(time(NULL));
	setlocale(LC_ALL,"Russian");
	const int n = 21;
	int a[n];
	a[0] = 7;
	a[1] = 4;
	a[2] = 13;
	a[3] = 100;
	a[4] = 0;
	a[5] = 999;

	for (int i = 6; i < n; i++)
		a[i] = 0;

	for (int i = 6; i < n; i+=5)
	{
		a[i] = rand() % 50 - 25;
	}

	//for (int i = 3; i < n; i += 7)
	//{
	//	a[i] = rand() % 50 - 25;
	//}

	for (int i = 6; i < n; i += 4)
	{
		a[i] = rand() % 50 - 25;
	}

	//const int N = 21;
	//int a[N];
	//a[0] = z[0]; a[1] = z[1]; a[2] = z[2]; 
	//a[3] = 0; a[4] = 0;
	//a[5] = z[3];
	//a[6] = 0; a[7] = 0; 
	//a[8] = z[4]; a[9] = z[5];
	//a[10] = 0; a[11] = 0;
	//a[12] = z[6];
	//a[13] = z[7];
	//a[14] = 0; a[15] = 0;
	//a[17] = z[8]; a[16] = z[9];
	//a[18] = 0; a[19] = 0;
	//a[20] = z[10];

	int i = -1;
	cout << "Введем дерево" << endl;
	TreeNode* root= makeTree(a, i);

	cout<<"Введенное дерево:"<<endl;
	printTree(root);

	int max = sumMaxTree(root, 0);
	vector <int> tops;
	cout << "максимальная сумма поддеревьев = " << max << endl;
	searchMaxTree(root, max, tops);
	cout << "вершин(а) поддервья которых(ой) имеют наибольшую сумму:" << endl;
	for (auto const &c: tops)
		cout << c << endl;

	system("pause");
	return;
}

// Создание бинарного дерева
TreeNode* makeTree(int a[10], int& i)
{
	i++;
	if ((a[i] != 0) && (i < 21))
	{
		TreeNode *p = new TreeNode;
		p->info = a[i];

		cout << p->info << " -> левое поддерево вершины = ";
		p -> left = makeTree(a, i);

		cout << p->info << " -> правое поддерево вершины = ";
		p -> right = makeTree(a, i);
		return p; 
	}
	else
	{
		cout << "0" << endl;
		return NULL;
	}


}


// Вывод бинарного дерева на консоль
void printTree(TreeNode * &root, const int level)
{
  if (root)
  {
    printTree(root->left,level+1);
    cout<<setw(4*level)<< "" << root->info<<endl;
    printTree(root->right,level+1);
  }
  return;
}

// Функция возвращает сумму вершин бинарного дерева
int sumMaxTree(TreeNode* &root, int max)
{
	int S = 0;
	if (root)
	{
		if (root->right)
		{
			max = sumMaxTree(root->right, max);
			S += root->right->info;
		}
		if (root->left)
		{
			max = sumMaxTree(root->left, max);
			S += root->left->info;
		}
		if (S > max)
		{
			max = S;
		}
		return max;
	}
	else
		return 0;
}

bool searchMaxTree(TreeNode*& root, int const max, vector <int>&tops)
{
	int S = 0;
	if (root)
	{
		if (root->right)
		{
			searchMaxTree(root->right, max, tops);
			S += root->right->info;
		}
		if (root->left)
		{
			searchMaxTree(root->left, max, tops);
			S += root->left->info;
		}
		if (S == max)
		{
			tops.push_back(root->info);
		}
		return true;
	}
	else
		return false;
}
