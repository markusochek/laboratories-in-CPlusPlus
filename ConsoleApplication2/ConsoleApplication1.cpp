/*
Шапка программы
Постановка задачи:
2.3 Дано натуральные числа n, m (2<=m<=16). 
Найти сумму и произведение цифр числа n 
в записи этого числа в m-ичной системе счисления
*/

#include <iostream>
#include <iomanip>

using namespace std;

void main() {

	cout << "enter a positive integer n " << endl;
	int n;
	cin >> n;

	cout << "enter a positive integer m (2<=m<=16) " << endl;
	short int m;
	cin >> m;

	int p = 1;
	int S = 0, P = 1;

	while (n >= m) {

		S = S + (n % m);
		P = P * (n % m);
		cout << n % m << setw(1);
		n = n / m;

	}

	S = S + n;
	P = P * n;
	cout << n % m << setw(1) << endl;
	cout << "the sum is equal to " << S << endl;
	cout << "the product is exactly " << P << endl;

	system("pause");

}