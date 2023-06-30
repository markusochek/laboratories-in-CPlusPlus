/*постановка задачи :
Натуральное число n (1<=n<=100) вводится с клавиатуры.
Целочисленный линейный массив a0, a1, …, an-1
заполняется случайными целыми числами из диапазона [0, n).
Требуется отсортировать массив по не убыванию.
Метод сортировки определяется вариантом в соответствии с таблицей № 1.
После сортировки вводится целое значение k,
требуется произвести поиск в массиве этого значения.
Алгоритм поиска определяется в таблице № 2.

3. Сортировка вставками с конца массива
(первыми занимают позиции элементы в конце массива)

3. Последовательный поиск по массиву справа налево */

#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	const int N = 100;
	int a[N];
	int i, j, k, temp;
	unsigned short int flag;
	
	cout << "array of random values" << endl;
	srand(time(NULL));
	for (int i = 0; i <= N - 1; i++)//ввод рандомных значений
	{
		a[i] = rand() % N;
		cout << setw(4) << a[i];
	}
	cout << endl;
	
	j = 0;
	for (int i = N - 2; i >= 0; i--) //сортировка
	{
		temp = a[i];
		j = i+1;
		while ((j < N) && (temp < a[j]))
		{
			a[j - 1] = a[j];
			j++;
		}
		a[j - 1] = temp;
	}
	
	cout << "sorted array from right to left in ascending order" << endl;
	for (int i = 0; i <= N - 1; i++)//вывод сортированного массива
	{
		cout << setw(4) << a[i];
	}
	cout << endl;
	
	cout << "enter the number you want to find" << endl;
	cin >> k;
	cout << endl;
	flag = 0;
	for (int i = N - 1; i >= 0; i--) //вывод сортированного массива
	{
		if (a[i] == k)
		{
			cout << i << endl;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "the number you are looking for is not in the sequence" << endl;
	}
	cout << endl;
	
	system("pause");

}

