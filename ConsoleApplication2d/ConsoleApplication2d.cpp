// ConsoleApplication2d.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void main() {

	srand(time(NULL));
	vector<vector<int>> vv;
	vector<vector<int>> vvN;
	vector<int> v;
	vector <int> vN;

	for (int i = 0; i < 5; i++) {
		for (int i = 0; i < 5; i++) {
			v.push_back(rand() % 30);
		}
		vv.push_back(v);
		v.clear();
	}

	vector <vector<int>>::iterator it = vv.begin();

	vector<int>::iterator it2 = it->begin();

	vector<int>::iterator it3 = it->begin();

	vector<int>::iterator itd;

	for (auto x : vv) {
		for (auto y : *it) {
			cout << setw(4) << y;
		}
		it++;
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
		v.push_back(vv[4][i]);

	for (auto x : v) {
		cout << setw(4) << x;
	}

	cout << endl;

	cout << endl;

	int m = 0;

	it2 = v.begin();

	it3 = v.begin();

	it3++;

	while (it2 != v.end()) {

		itd = it2;

		itd++;

		it3 = itd;

		while (it3 != v.end()) {

			if (*it2 > *it3) {

				m = *it3;

				*it3 = *it2;

				*it2 = m;

			}

			it3++;

		}

		it2++;

	}

	for (auto x : v) {

		cout << setw(4) << x;

	}

	cout << endl;

	vvN = vv;

	int k = 0;

	m = 0;

	it2 = v.begin();

	while (it2 != v.end()) {

		for (int i = 0; i < 5; i++) {

			if (vv[4][i] == *it2) {

				k = i;

				break;

			}

		}

		for (int j = 0; j < 5; j++) {

			vvN[j][m] = vv[j][k];

		}

		it2++;

		m++;

	}

	cout << endl;

	it = vvN.begin();

	for (auto x : vvN) {

		for (auto y : *it) {

			cout << setw(4) << y;

		}

		it++;

		cout << endl;

	}

	cout << endl;

	system("pause");

}