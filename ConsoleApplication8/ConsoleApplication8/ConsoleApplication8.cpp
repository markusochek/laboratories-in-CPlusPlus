/* Дано натуральное число m(1<m<=10).
Заполнить квадратную матрицу размера mxm целыми числами
0, 1, 2, 3, …, m^2–1 в соответствии со схемой расположения,
определенной вариантом в таблице № 3.*/
#include <iostream>
#include <iomanip>

using namespace std;
const int nmax = 10;
int Matrix[nmax][nmax];
void FillMatrix(int n)//вырисовывание матрицы 
{
	int k=1;
	for (int s = 0; s <= n - 1; s++)
	{
		if (s % 2 != 0)
		{
			for (int i = s; i >= 0; i--)
			{
				Matrix[i][s - i] = k;
				cout << "i=" << i << " s-i=" << s - i << endl;
				cout << "01" << endl;
				k++;
				for (int i = 0; i <= nmax - 1; i++)
				{
					for (int j = 0; j <= nmax - 1; j++)
					{
						cout << setw(4) << Matrix[i][j];
					}
					cout << endl;
				}
				cout << endl;
			}

		}
		else
		{
			for (int i = 0; i <= s; i++)
			{
				Matrix[i][s - i] = k;
				cout << "i=" << i << " s-i=" << s - i << endl;
				cout << "02" << endl;
				k++;
				for (int i = 0; i <= nmax - 1; i++)
				{
					for (int j = 0; j <= nmax - 1; j++)
					{
						cout << setw(4) << Matrix[i][j];
					}
					cout << endl;
				}
				cout << endl;
			}

		}
	}
	for (int s = n; s <= 2*n-2; s++)
	{
		if (s % 2 !=0)
		{
			for (int i = n - 1; i >= s - n + 1; i--)
			{
				Matrix[i][s - i] = k;
				cout << "i=" << i << " s-i=" << s - i << endl;
				cout << "03" << endl;
				k++;
				for (int i = 0; i <= nmax - 1; i++)
				{
					for (int j = 0; j <= nmax - 1; j++)
					{
						cout << setw(4) << Matrix[i][j];
					}
					cout << endl;
				}
				cout << endl;
			}

		}
		else
		{
			for (int i = s - n + 1; i <= n - 1; i++)
			{
				Matrix[i][s - i] = k;
				cout << "i=" << i << " s-i=" << s - i << endl;
				cout << "04" << endl;
				k++;
				for (int i = 0; i <= nmax - 1; i++)
				{
					for (int j = 0; j <= nmax - 1; j++)
					{
						cout << setw(4) << Matrix[i][j];
					}
					cout << endl;
				}
				cout << endl;
			}
		
		}
	}
 }
void vivod()
{
	for (int i = 0; i <= nmax - 1; i++)
	{
		for (int j = 0; j <= nmax - 1; j++)
		{
			cout << setw(4) << Matrix[i][j];
		}
		cout << endl;
	}
}
int main()
{
	int n;
	cout << "enter the number of values of the square array"<< endl;
	cin >> n;

	FillMatrix(n);
	vivod();
	exit;
}
