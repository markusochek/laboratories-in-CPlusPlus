/*
Шапка программы
Постановка задачи:
1.3 Даны действительные числа a, b, c. 
Определить, существует ли треугольник с такими сторонами,
и найти его площадь
*/

#include <iostream>//ввод и вывод
#include <iomanip>//форматирование вывода
#include <math.h>//для выполнения простых математических операций(с плавающей точкой)

using namespace std;

void main() {

	cout << "enter the first side" << endl;//cout - [write] endl - [ln]
	float a;// :real
	cin >> a;// read(a)

	cout << "enter the second side" << endl;
	float b;
	cin >> b;

	cout << "enter the third side" << endl;
	float c;
	cin >> c;

	if ((a < b + c) && (b < a + c) && (c < b + a)) {

		float p = (a + b + c) * 1 / 2;
		float S = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "the area of the triangle is equal to " << setw(8) << S << endl;

	}
	else {

		cout << "this triangle does not exist" << endl;

	}

	system("pause");

}
