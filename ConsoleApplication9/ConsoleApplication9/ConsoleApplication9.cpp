/*Дано натуральное m (1<m<=10), целочисленный квадратный массив-матрица размера mxm.
Матрица заполнена случайными числами из диапазона [0, m^2)
Отсортировать элементы матрицы так чтобы при прохождении по схеме, 
указанной в таблице № 3, они были бы упорядочены по не убыванию. 
Метод сортировки тот же, что и в таблице № 1.*/

/*3 вариант*/

#include <iostream>
#include <iomanip>
using namespace std;
const int nmax = 10;
int Matrix[nmax][nmax];
int Matrix2[nmax*nmax];
void Random(int n)//ввод рандомных значений
{
	for (int i=0; i<=n-1; i++)
		for (int j = 0; j <= n-1; j++)
		{ 
			Matrix[i][j] = rand() % (n*n);
			Matrix2[n * i + j]=Matrix[i][j];
		}
}
void vivod()//вывод значений в матрице
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
void sort(int n)// сортировка одномерного массива
{
	for (int i = n*n - 2; i >= 0; i--) //сортировка
	{
		int j, k, temp;
		temp = Matrix2[i];
		j = i + 1;
		while ((j < n*n) && (temp < Matrix2[j]))
		{
			Matrix2[j - 1] = Matrix2[j];
			j++;
		}
		Matrix2[j - 1] = temp;
	}
	cout << "sorted array from right to left in ascending order" << endl;
	for (int i = 0; i <= n*n - 1; i++)//вывод сортированного массива
	{
		cout << setw(4) << Matrix2[i];
	}
	cout << endl;
}
void Coordinates(int k, int n, int& i, int& j)//нахождение координат числа k с помощью математических формул
{
	int s;
	int	min;
	int k1;
	int i1;
	int j1;
	if (k <= n * (n + 1) / 2 - 1)
	{
		s = trunc((-1 + sqrt(1 + 8 * k)) / 2);
		min = s * (s + 1) / 2;
		if (s % 2 != 0)
			i = s - (k - min);
		else
			i = k - min;
		j = s - i;
		cout << "i=" << i << " j =" << j << endl;
	}
	else
	{
		k1 = n * n - 1 - k;
		s= trunc((-1 + sqrt(1 + 8 * k1)) / 2);
		min = s * (s + 1) / 2;
		if (s % 2 != 0)
			i1 = s - (k1 - min);
		else
			i1 = k1 - min;
		j1 = s - i1;
		i = n - 1 - i1;
		j = n - 1 - j1;
		cout << "i=" << i << " j =" << j << endl;
	}
}
void FillMatrix2(int n)//вписывание отсортированного массива в новый массив по таблице №3
{
	int i = 0;
	int j = 0;
	for (int k = 0; k <= n * n - 1; k++)
	{
		Coordinates(k, n, i, j);
		Matrix[i][j] = Matrix2[k];
		vivod();
	}
}
int main()
{
	int n;
	cout << "enter the number of values of the square array" << endl;
	cin >> n;
	Random(n);
	vivod();
	sort(n);
	FillMatrix2(n);
	cout << endl;
	vivod();
	exit;
}