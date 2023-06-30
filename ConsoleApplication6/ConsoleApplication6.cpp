/*Постановка задачи:
3. Даны натуральные числа n, m (2<=m<=10).
Найти максимальную и минимальную цифры числа n
в записи этого числа в m-ичной системе счисления*/ 

#include <iostream>
#include <iomanip>

using namespace std;

int f(int n, int m, int max, int min)
{
	int nm;
	nm = n % m;
	if (nm > max)
	{
		max = nm;
	}
	if (nm < min)
	{
		min = nm;
	}
	cout << setw(4) << nm;
	n = n / m;
	if (n != 0)
	{
		return f(n, m, max, min);
	}
	cout << endl;
	cout << "the maximum value is " << max << endl;
	cout << "the minimum value is " << min << endl;
}

void main()
{
	int n, m; 
	cout << "enter a positive integer n " << endl;
	cin >> n;
	cout << "enter a positive integer m (2<=m<=10) " << endl;
	cin >> m;
	cout << "a number n in the number system m from right to left" << endl;
	int max, min, nm;
	min = m;
	max = -1;
	f(n, m, max, min);
	cout << endl;

	system("pause");
}