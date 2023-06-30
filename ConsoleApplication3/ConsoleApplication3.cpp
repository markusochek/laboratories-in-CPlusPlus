/*
Шапка программы
постановока задачи:
3.3 Даны значения N элементов целочисленного массива.
Найти наиболее часто встречающееся число; 
если таковых будет несколько, то указать их все.
*/

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void main() 
{

	const short int N = 30, M = 30;
	int a[N], b[M], c[M];

	for (int i = 0; i < M; i++) 
	{

		b[i] = 0;
		c[i] = 0;

	}

	cout << "integer array" << endl;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{

		a[i] = rand() % M + 1;
		cout << setw(4) << a[i];

	}

	int k = 0, flag = 0;
	for (int i = 0; i < N; i++) 
	{
		flag = 0;
		for (int j = 0; j <= k; j++)
		{
			if (b[j] == a[i]) 
			{
				c[j]++;
				flag = 1;

			}

		}
	
		if (flag == 0)
		{
			b[k] = a[i];
			c[k]++;
			k++;
		}
		
	}

	cout << endl << "an array that outputs how many times a digit occurs (from 1 to 10)" << endl;
	int max = 0;
	for (int i = 0; i < M; i++)
	{
		cout << setw(4) << b[i];
		if ((c[i]) > max)
		{

			max = c[i];

		}

	}
	cout << endl;
	for (int i = 0; i < M; i++)
	{
		cout << setw(4) << c[i];
	}

	cout << endl << "the numbers that occur the most:" << endl;
	for (int i = 0; i < M; i++) 
	{

		if (max == c[i]) 
		{

			cout << b[i] << endl;

		}

	}

	system("pause");

}